/*
 * Copyright 2019-2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef LVGL_SUPPORT_H
#define LVGL_SUPPORT_H

#include <stdint.h>
#include "display_support.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#define LCD_WIDTH             DEMO_BUFFER_WIDTH
#define LCD_HEIGHT            DEMO_BUFFER_HEIGHT
#define LCD_FB_BYTE_PER_PIXEL DEMO_BUFFER_BYTE_PER_PIXEL
#define DEMO_USE_ROTATE 1

#define LV_ATTRIBUTE_LARGE_CONST __attribute__((section("AssetsData")))

/*******************************************************************************
 * API
 ******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

void lv_port_pre_init(void);
void lv_port_disp_init(void);
void lv_port_indev_init(void);

#if defined(__cplusplus)
}
#endif

#endif /*LVGL_SUPPORT_H */
