/*
 * Copyright 2024 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
 * accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
 * activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
 * comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
 * terms, then you may not retain, install, activate or otherwise use the software.
 */

#include "widgets_init.h"
#include <stdlib.h>


__attribute__((unused)) void kb_event_cb (lv_event_t *e) {
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t *kb = lv_event_get_target(e);
	if(code == LV_EVENT_READY || code == LV_EVENT_CANCEL){
		lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
	}
}

__attribute__((unused)) void ta_event_cb (lv_event_t *e) {
	lv_event_code_t code = lv_event_get_code(e);
#if LV_USE_KEYBOARD || LV_USE_ZH_KEYBOARD
	lv_obj_t *ta = lv_event_get_target(e);
#endif
	lv_obj_t *kb = lv_event_get_user_data(e);
	if (code == LV_EVENT_FOCUSED || code == LV_EVENT_CLICKED)
	{
#if LV_USE_ZH_KEYBOARD != 0
		lv_zh_keyboard_set_textarea(kb, ta);
#endif
#if LV_USE_KEYBOARD != 0
		lv_keyboard_set_textarea(kb, ta);
#endif
		lv_obj_move_foreground(kb);
		lv_obj_clear_flag(kb, LV_OBJ_FLAG_HIDDEN);
	}
	if (code == LV_EVENT_CANCEL || code == LV_EVENT_DEFOCUSED)
	{

#if LV_USE_ZH_KEYBOARD != 0
		lv_zh_keyboard_set_textarea(kb, ta);
#endif
#if LV_USE_KEYBOARD != 0
		lv_keyboard_set_textarea(kb, ta);
#endif
		lv_obj_move_background(kb);
		lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
	}
}

#if LV_USE_ANALOGCLOCK != 0
void clock_count(int *hour, int *min, int *sec)
{
	(*sec)++;
	if(*sec == 60)
	{
		*sec = 0;
		(*min)++;
	}
	if(*min == 60)
	{
		*min = 0;
		if(*hour < 12)
		{
			(*hour)++;
		} else {
			(*hour)++;
			*hour = *hour %12;
		}
	}
}
#endif


extern int baseScreen_widgetMenuType3Value2_hour_value;
extern int baseScreen_widgetMenuType3Value2_min_value;
extern int baseScreen_widgetMenuType3Value2_sec_value;

void baseScreen_widgetMenuType3Value2_timer(lv_timer_t *timer)
{
	clock_count_24(&baseScreen_widgetMenuType3Value2_hour_value, &baseScreen_widgetMenuType3Value2_min_value, &baseScreen_widgetMenuType3Value2_sec_value);
	if (lv_obj_is_valid(guider_ui.baseScreen_widgetMenuType3Value2))
	{
		lv_dclock_set_text_fmt(guider_ui.baseScreen_widgetMenuType3Value2, "%d:%02d:%02d", baseScreen_widgetMenuType3Value2_hour_value, baseScreen_widgetMenuType3Value2_min_value, baseScreen_widgetMenuType3Value2_sec_value);
	}
}

extern int baseScreen_clusterTime_hour_value;
extern int baseScreen_clusterTime_min_value;
extern int baseScreen_clusterTime_sec_value;
extern char baseScreen_clusterTime_meridiem[];

extern int baseScreen_clusterTime_BLE_hour_value;
extern int baseScreen_clusterTime_BLE_min_value;
extern int baseScreen_clusterTime_BLE_sec_value;

void baseScreen_clusterTime_timer(lv_timer_t *timer)
{
	if(BLE_STATUS)	{
		clock_count_12(&baseScreen_clusterTime_BLE_hour_value, &baseScreen_clusterTime_BLE_min_value, &baseScreen_clusterTime_BLE_sec_value, baseScreen_clusterTime_meridiem);
		if (lv_obj_is_valid(guider_ui.baseScreen_clusterTime))
		{
			lv_dclock_set_text_fmt(guider_ui.baseScreen_clusterTime, "%d:%02d:%02d %s", baseScreen_clusterTime_BLE_hour_value, baseScreen_clusterTime_BLE_min_value, baseScreen_clusterTime_BLE_sec_value, baseScreen_clusterTime_meridiem);
		}
	}	else	{
		clock_count_12(&baseScreen_clusterTime_hour_value, &baseScreen_clusterTime_min_value, &baseScreen_clusterTime_sec_value, baseScreen_clusterTime_meridiem);
		if (lv_obj_is_valid(guider_ui.baseScreen_clusterTime))
		{
			lv_dclock_set_text_fmt(guider_ui.baseScreen_clusterTime, "%d:%02d:%02d %s", baseScreen_clusterTime_hour_value, baseScreen_clusterTime_min_value, baseScreen_clusterTime_sec_value, baseScreen_clusterTime_meridiem);
		}
	}

}

