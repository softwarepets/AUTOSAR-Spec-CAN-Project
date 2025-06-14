/*
 * Copyright 2019-2023 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "lvgl_support.h"

#include "../lvgl/lvgl/lvgl.h"
#if defined(SDK_OS_FREE_RTOS)
#include "../Services/freertos-kernel/include/FreeRTOS.h"
#include "../Services/freertos-kernel/include/semphr.h"
#endif
#include "board.h"

#include "../Mcal/fsl_gpio.h"
#include "../Mcal/fsl_cache.h"
#include "fsl_debug_console.h"

#if (DEMO_PANEL == DEMO_PANEL_RASPI_7INCH)
#include "../Mcal/fsl_lpi2c.h"
#include "fsl_ft5406_rt.h"
#else
#include "fsl_gt911.h"
#endif

#if LV_USE_GPU_NXP_VG_LITE
#include "vg_lite.h"
#include "vglite_support.h"
#endif

#if LV_USE_GPU_NXP_PXP
#include "../lvgl/lvgl/src/draw/nxp/pxp/lv_draw_pxp_blend.h"
#endif

#if (DEMO_DISPLAY_CONTROLLER == DEMO_DISPLAY_CONTROLLER_LCDIFV2)
#include "../Mcal/fsl_lcdifv2.h"
#else
#include "../Mcal/fsl_elcdif.h"
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Ratate panel or not. */
#ifndef DEMO_USE_ROTATE
#if LV_USE_GPU_NXP_PXP
#define DEMO_USE_ROTATE 1
#else
#define DEMO_USE_ROTATE 0
#endif
#endif

/* Cache line size. */
#ifndef FSL_FEATURE_L2CACHE_LINESIZE_BYTE
#define FSL_FEATURE_L2CACHE_LINESIZE_BYTE 0
#endif
#ifndef FSL_FEATURE_L1DCACHE_LINESIZE_BYTE
#define FSL_FEATURE_L1DCACHE_LINESIZE_BYTE 0
#endif

#if (FSL_FEATURE_L2CACHE_LINESIZE_BYTE > FSL_FEATURE_L1DCACHE_LINESIZE_BYTE)
#define DEMO_CACHE_LINE_SIZE FSL_FEATURE_L2CACHE_LINESIZE_BYTE
#else
#define DEMO_CACHE_LINE_SIZE FSL_FEATURE_L1DCACHE_LINESIZE_BYTE
#endif

#if (DEMO_CACHE_LINE_SIZE > FRAME_BUFFER_ALIGN)
#define DEMO_FB_ALIGN DEMO_CACHE_LINE_SIZE
#else
#define DEMO_FB_ALIGN FRAME_BUFFER_ALIGN
#endif

#if (LV_ATTRIBUTE_MEM_ALIGN_SIZE > DEMO_FB_ALIGN)
#undef DEMO_FB_ALIGN
#define DEMO_FB_ALIGN LV_ATTRIBUTE_MEM_ALIGN_SIZE
#endif

#define DEMO_FB_SIZE \
    (((DEMO_BUFFER_WIDTH * DEMO_BUFFER_HEIGHT * LCD_FB_BYTE_PER_PIXEL) + DEMO_FB_ALIGN - 1) & ~(DEMO_FB_ALIGN - 1))

#if DEMO_USE_ROTATE
#define LVGL_BUFFER_WIDTH  DEMO_BUFFER_HEIGHT
#define LVGL_BUFFER_HEIGHT DEMO_BUFFER_WIDTH
#else
#define LVGL_BUFFER_WIDTH  DEMO_BUFFER_WIDTH
#define LVGL_BUFFER_HEIGHT DEMO_BUFFER_HEIGHT
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void DEMO_FlushDisplay(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p);

#if (LV_USE_GPU_NXP_VG_LITE || LV_USE_GPU_NXP_PXP)
static void DEMO_CleanInvalidateCache(lv_disp_drv_t *disp_drv);
#endif

static void DEMO_InitTouch(void);

static void DEMO_ReadTouch(lv_indev_drv_t *drv, lv_indev_data_t *data);

static void DEMO_BufferSwitchOffCallback(void *param, void *switchOffBuffer);

#if (DEMO_PANEL != DEMO_PANEL_RASPI_7INCH)
static void BOARD_PullMIPIPanelTouchResetPin(bool pullUp);

static void BOARD_ConfigMIPIPanelTouchIntPin(gt911_int_pin_mode_t mode);
#endif

static void DEMO_WaitBufferSwitchOff(void);

#if ((LV_COLOR_DEPTH == 8) || (LV_COLOR_DEPTH == 1))
/*
 * To support 8 color depth and 1 color depth with this board, color palette is
 * used to map 256 color to 2^16 color.
 */
static void DEMO_SetLcdColorPalette(void);
#endif

/*******************************************************************************
 * Variables
 ******************************************************************************/
SDK_ALIGN(static uint8_t s_frameBuffer[2][DEMO_FB_SIZE], DEMO_FB_ALIGN);
#if DEMO_USE_ROTATE
SDK_ALIGN(static uint8_t s_lvglBuffer[1][DEMO_FB_SIZE], DEMO_FB_ALIGN);
#endif

#if __CORTEX_M == 4
#define DEMO_FLUSH_DCACHE() L1CACHE_CleanInvalidateSystemCache()
#else
#if DEMO_USE_ROTATE
#define DEMO_FLUSH_DCACHE() SCB_CleanInvalidateDCache_by_Addr(s_lvglBuffer[0], DEMO_FB_SIZE)
#else
#define DEMO_FLUSH_DCACHE() SCB_CleanInvalidateDCache()
#endif
#endif

#if defined(SDK_OS_FREE_RTOS)
static SemaphoreHandle_t s_transferDone;
#else
static volatile bool s_transferDone;
#endif

#if DEMO_USE_ROTATE
/*
 * When rotate is used, LVGL stack draws in one buffer (s_lvglBuffer), and LCD
 * driver uses two buffers (s_frameBuffer) to remove tearing effect.
 */
static void *volatile s_inactiveFrameBuffer;
#endif
#if (DEMO_PANEL != DEMO_PANEL_RASPI_7INCH)
static gt911_handle_t s_touchHandle;
static const gt911_config_t s_touchConfig = {
    .I2C_SendFunc     = BOARD_MIPIPanelTouch_I2C_Send,
    .I2C_ReceiveFunc  = BOARD_MIPIPanelTouch_I2C_Receive,
    .pullResetPinFunc = BOARD_PullMIPIPanelTouchResetPin,
    .intPinFunc       = BOARD_ConfigMIPIPanelTouchIntPin,
    .timeDelayMsFunc  = VIDEO_DelayMs,
    .touchPointNum    = 1,
    .i2cAddrMode      = kGT911_I2cAddrMode0,
    .intTrigMode      = kGT911_IntRisingEdge,
};
static int s_touchResolutionX;
static int s_touchResolutionY;
#else
static ft5406_rt_handle_t touch_handle;
#endif
/*******************************************************************************
 * Code
 ******************************************************************************/

#if ((LV_COLOR_DEPTH == 8) || (LV_COLOR_DEPTH == 1))
static void DEMO_SetLcdColorPalette(void)
{
    /*
     * To support 8 color depth and 1 color depth with this board, color palette is
     * used to map 256 color to 2^16 color.
     *
     * LVGL 1-bit color depth still uses 8-bit per pixel, so the palette size is the
     * same with 8-bit color depth.
     */
    uint32_t palette[256];

#if (LV_COLOR_DEPTH == 8)
    lv_color_t color;
    color.full = 0U;

    /* RGB332 map to RGB888 */
    for (int i = 0; i < 256U; i++)
    {
        palette[i] =
            ((uint32_t)color.ch.blue << 6U) | ((uint32_t)color.ch.green << 13U) | ((uint32_t)color.ch.red << 21U);
        color.full++;
    }

#elif (LV_COLOR_DEPTH == 1)
    for (int i = 0; i < 256U;)
    {
        /*
         * Pixel map:
         * 0bXXXXXXX1 -> 0xFFFFFF
         * 0bXXXXXXX0 -> 0x000000
         */
        palette[i] = 0x000000U;
        i++;
        palette[i] = 0xFFFFFFU;
        i++;
    }
#endif

#if (DEMO_DISPLAY_CONTROLLER == DEMO_DISPLAY_CONTROLLER_ELCDIF)
    ELCDIF_UpdateLut(LCDIF, kELCDIF_Lut0, 0, palette, 256);
    ELCDIF_EnableLut(LCDIF, true);
#else
    LCDIFV2_SetLut(LCDIFV2, 0, palette, 256, false);
#endif
}
#endif

void lv_port_pre_init(void)
{
}

void lv_port_disp_init(void)
{
    static lv_disp_draw_buf_t disp_buf;

    memset(s_frameBuffer, 0, sizeof(s_frameBuffer));
#if DEMO_USE_ROTATE
    memset(s_lvglBuffer, 0, sizeof(s_lvglBuffer));
    lv_disp_draw_buf_init(&disp_buf, s_lvglBuffer[0], NULL, DEMO_BUFFER_WIDTH * DEMO_BUFFER_HEIGHT);
#else
    lv_disp_draw_buf_init(&disp_buf, s_frameBuffer[0], s_frameBuffer[1], DEMO_BUFFER_WIDTH * DEMO_BUFFER_HEIGHT);
#endif

    status_t status;
    dc_fb_info_t fbInfo;

#if LV_USE_GPU_NXP_VG_LITE
    /* Initialize GPU. */
    BOARD_PrepareVGLiteController();
#endif

    /*-------------------------
     * Initialize your display
     * -----------------------*/
    BOARD_PrepareDisplayController();

    status = g_dc.ops->init(&g_dc);
    if (kStatus_Success != status)
    {
        assert(0);
    }

#if ((LV_COLOR_DEPTH == 8) || (LV_COLOR_DEPTH == 1))
    DEMO_SetLcdColorPalette();
#endif

    g_dc.ops->getLayerDefaultConfig(&g_dc, 0, &fbInfo);
    fbInfo.pixelFormat = DEMO_BUFFER_PIXEL_FORMAT;
    fbInfo.width       = DEMO_BUFFER_WIDTH;
    fbInfo.height      = DEMO_BUFFER_HEIGHT;
    fbInfo.startX      = DEMO_BUFFER_START_X;
    fbInfo.startY      = DEMO_BUFFER_START_Y;
    fbInfo.strideBytes = DEMO_BUFFER_STRIDE_BYTE;
    g_dc.ops->setLayerConfig(&g_dc, 0, &fbInfo);

    g_dc.ops->setCallback(&g_dc, 0, DEMO_BufferSwitchOffCallback, NULL);

#if defined(SDK_OS_FREE_RTOS)
    s_transferDone = xSemaphoreCreateBinary();
    if (NULL == s_transferDone)
    {
        PRINTF("Frame semaphore create failed\r\n");
        assert(0);
    }
#else
    s_transferDone = false;
#endif

#if DEMO_USE_ROTATE
    /* s_frameBuffer[1] is first shown in the panel, s_frameBuffer[0] is inactive. */
    s_inactiveFrameBuffer = (void *)s_frameBuffer[0];
#endif

    /* lvgl starts render in frame buffer 0, so show frame buffer 1 first. */
    g_dc.ops->setFrameBuffer(&g_dc, 0, (void *)s_frameBuffer[1]);

    /* Wait for frame buffer sent to display controller video memory. */
    if ((g_dc.ops->getProperty(&g_dc) & kDC_FB_ReserveFrameBuffer) == 0)
    {
        DEMO_WaitBufferSwitchOff();
    }

    g_dc.ops->enableLayer(&g_dc, 0);

    /*-----------------------------------
     * Register the display in LittlevGL
     *----------------------------------*/

    static lv_disp_drv_t disp_drv; /*Descriptor of a display driver*/
    lv_disp_drv_init(&disp_drv);   /*Basic initialization*/

    /*Set up the functions to access to your display*/

    /*Set the resolution of the display*/
    disp_drv.hor_res = LVGL_BUFFER_WIDTH;
    disp_drv.ver_res = LVGL_BUFFER_HEIGHT;

    /*Used to copy the buffer's content to the display*/
    disp_drv.flush_cb = DEMO_FlushDisplay;

#if (LV_USE_GPU_NXP_VG_LITE || LV_USE_GPU_NXP_PXP)
    disp_drv.clean_dcache_cb = DEMO_CleanInvalidateCache;
#endif

    /*Set a display buffer*/
    disp_drv.draw_buf = &disp_buf;

    /* Partial refresh */
    disp_drv.full_refresh = 1;

    /*Finally register the driver*/
    lv_disp_drv_register(&disp_drv);

#if LV_USE_GPU_NXP_VG_LITE
    if (vg_lite_init(DEFAULT_VG_LITE_TW_WIDTH, DEFAULT_VG_LITE_TW_HEIGHT) != VG_LITE_SUCCESS)
    {
        PRINTF("VGLite init error. STOP.");
        vg_lite_close();
        while (1)
            ;
    }

    if (vg_lite_set_command_buffer_size(VG_LITE_COMMAND_BUFFER_SIZE) != VG_LITE_SUCCESS)
    {
        PRINTF("VGLite set command buffer. STOP.");
        vg_lite_close();
        while (1)
            ;
    }
#endif
}

static void DEMO_BufferSwitchOffCallback(void *param, void *switchOffBuffer)
{
#if defined(SDK_OS_FREE_RTOS)
    BaseType_t taskAwake = pdFALSE;

    xSemaphoreGiveFromISR(s_transferDone, &taskAwake);
    portYIELD_FROM_ISR(taskAwake);
#else
    s_transferDone = true;
#endif

#if DEMO_USE_ROTATE
    s_inactiveFrameBuffer = switchOffBuffer;
#endif
}

#if (LV_USE_GPU_NXP_VG_LITE || LV_USE_GPU_NXP_PXP)
static void DEMO_CleanInvalidateCache(lv_disp_drv_t *disp_drv)
{
    DEMO_FLUSH_DCACHE();
}
#endif

static void DEMO_WaitBufferSwitchOff(void)
{
#if defined(SDK_OS_FREE_RTOS)
    if (xSemaphoreTake(s_transferDone, portMAX_DELAY) != pdTRUE)
    {
        PRINTF("Display flush failed\r\n");
        assert(0);
    }
#else
    while (false == s_transferDone)
    {
    }
    s_transferDone = false;
#endif
}

static void DEMO_FlushDisplay(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p)
{
#if DEMO_USE_ROTATE

    /*
     * Work flow:
     *
     * 1. Wait for the available inactive frame buffer to draw.
     * 2. Draw the ratated frame to inactive buffer.
     * 3. Pass inactive to LCD controller to show.
     */

    static bool firstFlush = true;

    /* Only wait for the first time. */
    if (firstFlush)
    {
        firstFlush = false;
    }
    else
    {
        /* Wait frame buffer. */
        DEMO_WaitBufferSwitchOff();
    }

    /* Copy buffer. */
    void *inactiveFrameBuffer = s_inactiveFrameBuffer;
    SCB_CleanInvalidateDCache_by_Addr(inactiveFrameBuffer, DEMO_FB_SIZE);

#if LV_USE_GPU_NXP_PXP /* Use PXP to rotate the panel. */
    lv_area_t dest_area = {
        .x1 = 0,
        .x2 = DEMO_BUFFER_HEIGHT - 1,
        .y1 = 0,
        .y2 = DEMO_BUFFER_WIDTH - 1,
    };

    lv_gpu_nxp_pxp_blit(((lv_color_t *)inactiveFrameBuffer), &dest_area, DEMO_BUFFER_WIDTH, color_p, area,
                        lv_area_get_width(area), LV_OPA_COVER, LV_DISP_ROT_270);
    /* Fix the race issue between PXP and Display controller when VG_Lite is enabled */
#if LV_USE_GPU_NXP_VG_LITE
    lv_gpu_nxp_pxp_wait();
#endif

#else /* Use CPU to rotate the panel. */
    for (uint32_t y = 0; y < LVGL_BUFFER_HEIGHT; y++)
    {
        for (uint32_t x = 0; x < LVGL_BUFFER_WIDTH; x++)
        {
            ((lv_color_t *)inactiveFrameBuffer)[(DEMO_BUFFER_HEIGHT - x) * DEMO_BUFFER_WIDTH + y] =
                color_p[y * LVGL_BUFFER_WIDTH + x];
        }
    }
#endif

    SCB_CleanInvalidateDCache_by_Addr(inactiveFrameBuffer, DEMO_FB_SIZE);

    g_dc.ops->setFrameBuffer(&g_dc, 0, inactiveFrameBuffer);

    /* IMPORTANT!!!
     * Inform the graphics library that you are ready with the flushing*/
    lv_disp_flush_ready(disp_drv);

#else  /* DEMO_USE_ROTATE */
    SCB_CleanInvalidateDCache_by_Addr(color_p, DEMO_FB_SIZE);

    g_dc.ops->setFrameBuffer(&g_dc, 0, (void *)color_p);

    DEMO_WaitBufferSwitchOff();

    /* IMPORTANT!!!
     * Inform the graphics library that you are ready with the flushing*/
    lv_disp_flush_ready(disp_drv);
#endif /* DEMO_USE_ROTATE */
}

void lv_port_indev_init(void)
{
    static lv_indev_drv_t indev_drv;

    /*------------------
     * Touchpad
     * -----------------*/

    /*Initialize your touchpad */
    DEMO_InitTouch();

    /*Register a touchpad input device*/
    lv_indev_drv_init(&indev_drv);
    indev_drv.type    = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = DEMO_ReadTouch;
    lv_indev_drv_register(&indev_drv);
}

#if (DEMO_PANEL != DEMO_PANEL_RASPI_7INCH)
static void BOARD_PullMIPIPanelTouchResetPin(bool pullUp)
{
    if (pullUp)
    {
        GPIO_PinWrite(BOARD_MIPI_PANEL_TOUCH_RST_GPIO, BOARD_MIPI_PANEL_TOUCH_RST_PIN, 1);
    }
    else
    {
        GPIO_PinWrite(BOARD_MIPI_PANEL_TOUCH_RST_GPIO, BOARD_MIPI_PANEL_TOUCH_RST_PIN, 0);
    }
}

static void BOARD_ConfigMIPIPanelTouchIntPin(gt911_int_pin_mode_t mode)
{
    if (mode == kGT911_IntPinInput)
    {
        BOARD_MIPI_PANEL_TOUCH_INT_GPIO->GDIR &= ~(1UL << BOARD_MIPI_PANEL_TOUCH_INT_PIN);
    }
    else
    {
        if (mode == kGT911_IntPinPullDown)
        {
            GPIO_PinWrite(BOARD_MIPI_PANEL_TOUCH_INT_GPIO, BOARD_MIPI_PANEL_TOUCH_INT_PIN, 0);
        }
        else
        {
            GPIO_PinWrite(BOARD_MIPI_PANEL_TOUCH_INT_GPIO, BOARD_MIPI_PANEL_TOUCH_INT_PIN, 1);
        }

        BOARD_MIPI_PANEL_TOUCH_INT_GPIO->GDIR |= (1UL << BOARD_MIPI_PANEL_TOUCH_INT_PIN);
    }
}
#endif

#if (DEMO_PANEL == DEMO_PANEL_RASPI_7INCH)
/*Initialize your touchpad*/
static void DEMO_InitTouch(void)
{
    status_t status;
    lpi2c_master_config_t masterConfig;

    LPI2C_MasterGetDefaultConfig(&masterConfig);

    /* Change the default baudrate configuration */
    masterConfig.baudRate_Hz = 100000;

    /* Initialize the I2C master peripheral */
    LPI2C_MasterInit(BOARD_MIPI_PANEL_TOUCH_I2C_BASEADDR, &masterConfig, BOARD_MIPI_PANEL_TOUCH_I2C_CLOCK_FREQ);

    /* Initialize touch panel controller */
    status = FT5406_RT_Init(&touch_handle, BOARD_MIPI_PANEL_TOUCH_I2C_BASEADDR);
    if (status != kStatus_Success)
    {
        PRINTF("Touch panel init failed\n");
    }
}

/* Will be called by the library to read the touchpad */
static void DEMO_ReadTouch(lv_indev_drv_t *drv, lv_indev_data_t *data)
{
    touch_event_t touch_event;
    static int touch_x = 0;
    static int touch_y = 0;

    data->state = LV_INDEV_STATE_REL;

    if (kStatus_Success == FT5406_RT_GetSingleTouch(&touch_handle, &touch_event, &touch_x, &touch_y))
    {
        if ((touch_event == kTouch_Down) || (touch_event == kTouch_Contact))
        {
            data->state = LV_INDEV_STATE_PR;
        }
    }

    /*Set the last pressed coordinates*/
    data->point.x = (DEMO_PANEL_WIDTH - touch_x);
    data->point.y = (DEMO_PANEL_HEIGHT - touch_y);
}
#else
/*Initialize your touchpad*/
static void DEMO_InitTouch(void)
{
    status_t status;

    const gpio_pin_config_t resetPinConfig = {
        .direction = kGPIO_DigitalOutput, .outputLogic = 0, .interruptMode = kGPIO_NoIntmode};
    GPIO_PinInit(BOARD_MIPI_PANEL_TOUCH_INT_GPIO, BOARD_MIPI_PANEL_TOUCH_INT_PIN, &resetPinConfig);
    GPIO_PinInit(BOARD_MIPI_PANEL_TOUCH_RST_GPIO, BOARD_MIPI_PANEL_TOUCH_RST_PIN, &resetPinConfig);

    status = GT911_Init(&s_touchHandle, &s_touchConfig);

    if (kStatus_Success != status)
    {
        PRINTF("Touch IC initialization failed\r\n");
        assert(false);
    }

    GT911_GetResolution(&s_touchHandle, &s_touchResolutionX, &s_touchResolutionY);
}

/* Will be called by the library to read the touchpad */
static void DEMO_ReadTouch(lv_indev_drv_t *drv, lv_indev_data_t *data)
{
    static int touch_x = 0;
    static int touch_y = 0;

    if (kStatus_Success == GT911_GetSingleTouch(&s_touchHandle, &touch_x, &touch_y))
    {
        data->state = LV_INDEV_STATE_PR;
    }
    else
    {
        data->state = LV_INDEV_STATE_REL;
    }

    /*Set the last pressed coordinates*/
#if DEMO_USE_ROTATE
    data->point.x = DEMO_PANEL_HEIGHT - (touch_y * DEMO_PANEL_HEIGHT / s_touchResolutionY);
    data->point.y = touch_x * DEMO_PANEL_WIDTH / s_touchResolutionX;
#else
    data->point.x = touch_x * DEMO_PANEL_WIDTH / s_touchResolutionX;
    data->point.y = touch_y * DEMO_PANEL_HEIGHT / s_touchResolutionY;
#endif
}
#endif
