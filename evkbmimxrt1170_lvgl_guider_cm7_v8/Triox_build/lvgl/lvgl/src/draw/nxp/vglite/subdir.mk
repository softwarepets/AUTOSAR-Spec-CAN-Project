################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/lvgl/src/draw/nxp/vglite/lv_draw_vglite.c \
../lvgl/lvgl/src/draw/nxp/vglite/lv_draw_vglite_arc.c \
../lvgl/lvgl/src/draw/nxp/vglite/lv_draw_vglite_blend.c \
../lvgl/lvgl/src/draw/nxp/vglite/lv_draw_vglite_line.c \
../lvgl/lvgl/src/draw/nxp/vglite/lv_draw_vglite_rect.c \
../lvgl/lvgl/src/draw/nxp/vglite/lv_vglite_buf.c \
../lvgl/lvgl/src/draw/nxp/vglite/lv_vglite_utils.c 

C_DEPS += \
./lvgl/lvgl/src/draw/nxp/vglite/lv_draw_vglite.d \
./lvgl/lvgl/src/draw/nxp/vglite/lv_draw_vglite_arc.d \
./lvgl/lvgl/src/draw/nxp/vglite/lv_draw_vglite_blend.d \
./lvgl/lvgl/src/draw/nxp/vglite/lv_draw_vglite_line.d \
./lvgl/lvgl/src/draw/nxp/vglite/lv_draw_vglite_rect.d \
./lvgl/lvgl/src/draw/nxp/vglite/lv_vglite_buf.d \
./lvgl/lvgl/src/draw/nxp/vglite/lv_vglite_utils.d 

OBJS += \
./lvgl/lvgl/src/draw/nxp/vglite/lv_draw_vglite.o \
./lvgl/lvgl/src/draw/nxp/vglite/lv_draw_vglite_arc.o \
./lvgl/lvgl/src/draw/nxp/vglite/lv_draw_vglite_blend.o \
./lvgl/lvgl/src/draw/nxp/vglite/lv_draw_vglite_line.o \
./lvgl/lvgl/src/draw/nxp/vglite/lv_draw_vglite_rect.o \
./lvgl/lvgl/src/draw/nxp/vglite/lv_vglite_buf.o \
./lvgl/lvgl/src/draw/nxp/vglite/lv_vglite_utils.o 


# Each subdirectory must supply rules for building sources it contributes
lvgl/lvgl/src/draw/nxp/vglite/%.o: ../lvgl/lvgl/src/draw/nxp/vglite/%.c lvgl/lvgl/src/draw/nxp/vglite/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__NEWLIB__ -DCPU_MIMXRT1176DVMAA -DCPU_MIMXRT1176DVMAA_cm7 -DXIP_BOOT_HEADER_DCD_ENABLE=1 -DUSE_SDRAM -DDATA_SECTION_IS_CACHEABLE=1 -DSDK_DEBUGCONSOLE=1 -DXIP_EXTERNAL_FLASH=1 -DXIP_BOOT_HEADER_ENABLE=1 -DLV_CONF_INCLUDE_SIMPLE=1 -DFSL_SDK_DRIVER_QUICK_ACCESS_ENABLE=1 -DMCUXPRESSO_SDK -DSDK_I2C_BASED_COMPONENT_USED=1 -DVG_COMMAND_CALL=1 -DVG_TARGET_FAST_CLEAR=0 -DSERIAL_PORT_TYPE_UART=1 -DSDK_OS_FREE_RTOS -DCR_INTEGER_PRINTF -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DTRIOX_BOARD_CONFIG=1 -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\source" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\video" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\touchpanel" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\vglite\inc" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\vglite\font" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\vglite\font\mcufont\decoder" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\vglite\VGLite\rtos" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\vglite\VGLiteKernel" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\vglite\VGLiteKernel\rtos" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\device" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\utilities" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\component\uart" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\component\serial_manager" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\component\lists" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\startup" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\xip" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\board" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\CMSIS" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\generated" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\generated\guider_customer_fonts" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\generated\guider_fonts" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\source\application\includes" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\RTE\header" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\lvgl\lvgl" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\lvgl\lvgl\src" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\lvgl\lvgl\src\font" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\lvgl" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\Services\freertos-kernel\include" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\Services\freertos-kernel\portable\GCC\ARM_CM4F" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -Wno-format -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m7 -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-lvgl-2f-lvgl-2f-src-2f-draw-2f-nxp-2f-vglite

clean-lvgl-2f-lvgl-2f-src-2f-draw-2f-nxp-2f-vglite:
	-$(RM) ./lvgl/lvgl/src/draw/nxp/vglite/lv_draw_vglite.d ./lvgl/lvgl/src/draw/nxp/vglite/lv_draw_vglite.o ./lvgl/lvgl/src/draw/nxp/vglite/lv_draw_vglite_arc.d ./lvgl/lvgl/src/draw/nxp/vglite/lv_draw_vglite_arc.o ./lvgl/lvgl/src/draw/nxp/vglite/lv_draw_vglite_blend.d ./lvgl/lvgl/src/draw/nxp/vglite/lv_draw_vglite_blend.o ./lvgl/lvgl/src/draw/nxp/vglite/lv_draw_vglite_line.d ./lvgl/lvgl/src/draw/nxp/vglite/lv_draw_vglite_line.o ./lvgl/lvgl/src/draw/nxp/vglite/lv_draw_vglite_rect.d ./lvgl/lvgl/src/draw/nxp/vglite/lv_draw_vglite_rect.o ./lvgl/lvgl/src/draw/nxp/vglite/lv_vglite_buf.d ./lvgl/lvgl/src/draw/nxp/vglite/lv_vglite_buf.o ./lvgl/lvgl/src/draw/nxp/vglite/lv_vglite_utils.d ./lvgl/lvgl/src/draw/nxp/vglite/lv_vglite_utils.o

.PHONY: clean-lvgl-2f-lvgl-2f-src-2f-draw-2f-nxp-2f-vglite

