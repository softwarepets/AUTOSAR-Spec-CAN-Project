/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../lvgl/lvgl/lvgl.h"

typedef struct
{
  
	lv_obj_t *baseScreen;
	bool baseScreen_del;
	lv_obj_t *baseScreen_controllerIndicationContainer;
	lv_obj_t *baseScreen_arrowButtons;
	lv_obj_t *baseScreen_controllerIndicationAlert;
	lv_obj_t *baseScreen_statusBarWidget;
	lv_obj_t *baseScreen_warnings;
	lv_obj_t *baseScreen_messageInbox;
	lv_obj_t *baseScreen_missedCall;
	lv_obj_t *baseScreen_phoneBluetooth;
	lv_obj_t *baseScreen_PhoneBattery;
	lv_obj_t *baseScreen_phoneNetworkSignal;
	lv_obj_t *baseScreen_menuWidget;
	lv_obj_t *baseScreen_MenuCategory;
	lv_obj_t *baseScreen_menuSelectedCategory;
	lv_obj_t *baseScreen_menuSelectedCategoryIcon;
	lv_obj_t *baseScreen_menuCategoryIcons;
	lv_obj_t *baseScreen_tripSettings;
	lv_obj_t *baseScreen_vehicleData;
	lv_obj_t *baseScreen_bluetoothSettings;
	lv_obj_t *baseScreen_preferences;
	lv_obj_t *baseScreen_rideModeData;
	lv_obj_t *baseScreen_menuMainArea;
	lv_obj_t *baseScreen_menuTypeEleven;
	lv_obj_t *baseScreen_Document;
	lv_obj_t *baseScreen_documentLabel;
	lv_obj_t *baseScreen_menuTypeTen;
	lv_obj_t *baseScreen_year;
	lv_obj_t *baseScreen_yearBackground;
	lv_obj_t *baseScreen_yearUpArrow;
	lv_obj_t *baseScreen_yearDownArrow;
	lv_obj_t *baseScreen_yearText;
	lv_obj_t *baseScreen_month;
	lv_obj_t *baseScreen_monthBackground;
	lv_obj_t *baseScreen_monthUpArrow;
	lv_obj_t *baseScreen_monthDownArrow;
	lv_obj_t *baseScreen_monthText;
	lv_obj_t *baseScreen_date;
	lv_obj_t *baseScreen_dateBackground;
	lv_obj_t *baseScreen_dateUpArrow;
	lv_obj_t *baseScreen_dateDownArrow;
	lv_obj_t *baseScreen_dateText;
	lv_obj_t *baseScreen_menuTypeNine;
	lv_obj_t *baseScreen_ampm;
	lv_obj_t *baseScreen_ampmBackground;
	lv_obj_t *baseScreen_ampmUpArrow;
	lv_obj_t *baseScreen_ampmDownArrow;
	lv_obj_t *baseScreen_ampmText;
	lv_obj_t *baseScreen_minute;
	lv_obj_t *baseScreen_mmBackground;
	lv_obj_t *baseScreen_mmUpArrow;
	lv_obj_t *baseScreen_mmDownArrow;
	lv_obj_t *baseScreen_mmText;
	lv_obj_t *baseScreen_hour;
	lv_obj_t *baseScreen_hhBackground;
	lv_obj_t *baseScreen_hhUpArrow;
	lv_obj_t *baseScreen_hhDownArrow;
	lv_obj_t *baseScreen_hhText;
	lv_obj_t *baseScreen_menuTypeEight;
	lv_obj_t *baseScreen_BrightnessLevel10;
	lv_obj_t *baseScreen_BrightnessLevel9;
	lv_obj_t *baseScreen_BrightnessLevel8;
	lv_obj_t *baseScreen_BrightnessLevel7;
	lv_obj_t *baseScreen_BrightnessLevel6;
	lv_obj_t *baseScreen_BrightnessLevel5;
	lv_obj_t *baseScreen_BrightnessLevel4;
	lv_obj_t *baseScreen_BrightnessLevel3;
	lv_obj_t *baseScreen_BrightnessLevel2;
	lv_obj_t *baseScreen_BrightnessLevel1;
	lv_obj_t *baseScreen_menuTypeSeven;
	lv_obj_t *baseScreen_pairingKey;
	lv_obj_t *baseScreen_menuTypeSix;
	lv_obj_t *baseScreen_speedAlertBackground;
	lv_obj_t *baseScreen_arrowUp;
	lv_obj_t *baseScreen_arrowDown;
	lv_obj_t *baseScreen_speedlimitUnit;
	lv_obj_t *baseScreen_speedLimitValue;
	lv_obj_t *baseScreen_menuTypeFive;
	lv_obj_t *baseScreen_topSpeedUnit;
	lv_obj_t *baseScreen_topSpeedLabel;
	lv_obj_t *baseScreen_topSpeedValue;
	lv_obj_t *baseScreen_averageSpeedUnit;
	lv_obj_t *baseScreen_averageSpeedValue;
	lv_obj_t *baseScreen_averageSpeedLabel;
	lv_obj_t *baseScreen_menuTypeFour;
	lv_obj_t *baseScreen_serviceDaysValue;
	lv_obj_t *baseScreen_serviceDaysUnit;
	lv_obj_t *baseScreen_serviceDistanceUnit;
	lv_obj_t *baseScreen_serviceDistanceValue;
	lv_obj_t *baseScreen_dividers;
	lv_obj_t *baseScreen_lastServiceLabel;
	lv_obj_t *baseScreen_serviceDateUnit;
	lv_obj_t *baseScreen_serviceDateValue;
	lv_obj_t *baseScreen_serviceDateLabel;
	lv_obj_t *baseScreen_menuTypeThree;
	lv_obj_t *baseScreen_loading;
	lv_obj_t *baseScreen_loadingText;
	lv_obj_t *baseScreen_menuTypeTwo;
	lv_obj_t *baseScreen_containerOne;
	lv_obj_t *baseScreen_widgetMenuType3Label1;
	lv_obj_t *baseScreen_widgetMenuType3Unit;
	lv_obj_t *baseScreen_widgetMenuType3Value;
	lv_obj_t *baseScreen_containerTwo;
	lv_obj_t *baseScreen_widgetMenuType3Label2;
	lv_obj_t *baseScreen_widgetMenuType3Unit2;
	lv_obj_t *baseScreen_widgetMenuType3Value2;
	lv_obj_t *baseScreen_containerThree;
	lv_obj_t *baseScreen_widgetMenuType3Label3;
	lv_obj_t *baseScreen_widgetMenuType3Unit3;
	lv_obj_t *baseScreen_widgetMenuType3Value3;
	lv_obj_t *baseScreen_containerFour;
	lv_obj_t *baseScreen_widgetMenuType3Label4;
	lv_obj_t *baseScreen_widgetMenuType3Unit4;
	lv_obj_t *baseScreen_widgetMenuType3Value4;
	lv_obj_t *baseScreen_containerFive;
	lv_obj_t *baseScreen_widgetMenuType3Label5;
	lv_obj_t *baseScreen_widgetMenuType3Unit5;
	lv_obj_t *baseScreen_widgetMenuType3Value5;
	lv_obj_t *baseScreen_containerSix;
	lv_obj_t *baseScreen_widgetMenuType3Label6;
	lv_obj_t *baseScreen_widgetMenuType3Unit6;
	lv_obj_t *baseScreen_widgetMenuType3Value6;
	lv_obj_t *baseScreen_resetButton;
	lv_obj_t *baseScreen_menuTypeOne;
	lv_obj_t *baseScreen_optionOne;
	lv_obj_t *baseScreen_optionTwo;
	lv_obj_t *baseScreen_optionThree;
	lv_obj_t *baseScreen_optionFour;
	lv_obj_t *baseScreen_optionFive;
	lv_obj_t *baseScreen_toggle;
	lv_obj_t *baseScreen_menuHeading;
	lv_obj_t *baseScreen_menuScrollBar;
	lv_obj_t *baseScreen_scroll2Div;
	lv_obj_t *baseScreen_scroll3Div;
	lv_obj_t *baseScreen_ringArea;
	lv_obj_t *baseScreen_speedometerWidget;
	lv_obj_t *baseScreen_speedometerScale;
	lv_obj_t *baseScreen_speedometerNeedle;
	lv_obj_t *baseScreen_speedometerRing;
	lv_obj_t *baseScreen_speedometerValue;
	lv_obj_t *baseScreen_speedometerUnit;
	lv_obj_t *baseScreen_batteryWidget;
	lv_obj_t *baseScreen_segment1;
	lv_obj_t *baseScreen_segment2;
	lv_obj_t *baseScreen_segment3;
	lv_obj_t *baseScreen_segment4;
	lv_obj_t *baseScreen_segment5;
	lv_obj_t *baseScreen_segment6;
	lv_obj_t *baseScreen_segment7;
	lv_obj_t *baseScreen_segment8;
	lv_obj_t *baseScreen_segment9;
	lv_obj_t *baseScreen_segment10;
	lv_obj_t *baseScreen_gearIndicatorsWidget;
	lv_obj_t *baseScreen_gearIndicatorArrow;
	lv_obj_t *baseScreen_gearIndicatorValue;
	lv_obj_t *baseScreen_rideModeWidget;
	lv_obj_t *baseScreen_powerImage;
	lv_obj_t *baseScreen_autoImage;
	lv_obj_t *baseScreen_ecoImage;
	lv_obj_t *baseScreen_batteryValueGroup;
	lv_obj_t *baseScreen_batteryValue;
	lv_obj_t *baseScreen_batteryIcon;
	lv_obj_t *baseScreen_widgetWindow;
	lv_obj_t *baseScreen_fourthWidget;
	lv_obj_t *baseScreen_widgetFourBackground;
	lv_obj_t *baseScreen_widgetFourUnit;
	lv_obj_t *baseScreen_widgetFourValue;
	lv_obj_t *baseScreen_widgetFourLabel;
	lv_obj_t *baseScreen_widgetFourValue2;
	lv_obj_t *baseScreen_widgetFourUnit2;
	lv_obj_t *baseScreen_divider;
	lv_obj_t *baseScreen_thirdWidget;
	lv_obj_t *baseScreen_widgetThreeBackground;
	lv_obj_t *baseScreen_widgethreeUnit;
	lv_obj_t *baseScreen_widgetThreeValue;
	lv_obj_t *baseScreen_widgetThreeLabel;
	lv_obj_t *baseScreen_secondWidget;
	lv_obj_t *baseScreen_widgetTwoBackground;
	lv_obj_t *baseScreen_widgetTwoUnit;
	lv_obj_t *baseScreen_widgetTwoValue;
	lv_obj_t *baseScreen_widgetTwoLabel;
	lv_obj_t *baseScreen_phoneCall_Navigation;
	lv_obj_t *baseScreen_Navigation;
	lv_obj_t *baseScreen_ETA;
	lv_obj_t *baseScreen_turnbyTurnSign;
	lv_obj_t *baseScreen_turningDistance;
	lv_obj_t *baseScreen_distance;
	lv_obj_t *baseScreen_PhoneCall;
	lv_obj_t *baseScreen_RejectCallButton;
	lv_obj_t *baseScreen_rejectTextButton;
	lv_obj_t *baseScreen_AcceptCallButton;
	lv_obj_t *baseScreen_acceptCallButton;
	lv_obj_t *baseScreen_ProfileIcon;
	lv_obj_t *baseScreen_callerName;
	lv_obj_t *baseScreen_callTime;
	lv_obj_t *baseScreen_callAcceptRejectInfo;
	lv_obj_t *baseScreen_callerNumber;
	lv_obj_t *baseScreen_bluetoothWidgetType;
	lv_obj_t *baseScreen_speedometerMenuWidget;
	lv_obj_t *baseScreen_speedometermenuUnit;
	lv_obj_t *baseScreen_speedometerMenuValue;
	lv_obj_t *baseScreen_batteryMenuWidget;
	lv_obj_t *baseScreen_batteryMenuIcon;
	lv_obj_t *baseScreen_batteryMenuvalue;
	lv_obj_t *baseScreen_firstWidget;
	lv_obj_t *baseScreen_widgetOneBackground;
	lv_obj_t *baseScreen_widgetOneUnit;
	lv_obj_t *baseScreen_widgetOneValue;
	lv_obj_t *baseScreen_widgetOneLabel;
	lv_obj_t *baseScreen_clusterTime;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_move_animation(void * var, int32_t duration, int32_t delay, int32_t x_end, int32_t y_end, lv_anim_path_cb_t path_cb,
                       uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                       lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

void ui_scale_animation(void * var, int32_t duration, int32_t delay, int32_t width, int32_t height, lv_anim_path_cb_t path_cb,
                        uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                        lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

void ui_img_zoom_animation(void * var, int32_t duration, int32_t delay, int32_t zoom, lv_anim_path_cb_t path_cb,
                           uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                           lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

void ui_img_rotate_animation(void * var, int32_t duration, int32_t delay, lv_coord_t x, lv_coord_t y, int32_t rotate,
                   lv_anim_path_cb_t path_cb, uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time,
                   uint32_t playback_delay, lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

void init_scr_del_flag(lv_ui *ui);

void setup_ui(lv_ui *ui);


extern lv_ui guider_ui;


void setup_scr_baseScreen(lv_ui *ui);

LV_IMG_DECLARE(_screenBackground_1280x720);
LV_IMG_DECLARE(_arrows_alpha_48x48);
LV_IMG_DECLARE(_waringsIcon_alpha_50x50);
LV_IMG_DECLARE(_messagesIcon_alpha_50x50);
LV_IMG_DECLARE(_missedcallIcon_alpha_50x50);
LV_IMG_DECLARE(_bluetoothIcon_alpha_50x50);
LV_IMG_DECLARE(_batteryFullIcon_alpha_50x50);
LV_IMG_DECLARE(_batteryLowIcon_alpha_50x50);
LV_IMG_DECLARE(_batteryMidIcon_alpha_50x50);
LV_IMG_DECLARE(_batteryAverageIcon_alpha_50x50);
LV_IMG_DECLARE(_batteryTooLowIcon_alpha_50x50);
LV_IMG_DECLARE(_Signal0Icon_alpha_50x50);
LV_IMG_DECLARE(_Signal1Icon_alpha_50x50);
LV_IMG_DECLARE(_Signal2Icon_alpha_50x50);
LV_IMG_DECLARE(_Signal3Icon_alpha_50x50);
LV_IMG_DECLARE(_Signal4Icon_alpha_50x50);
LV_IMG_DECLARE(_menuSelectedCategoryIcon_alpha_150x144);
LV_IMG_DECLARE(_Trips_alpha_72x72);
LV_IMG_DECLARE(_Vehicle_alpha_72x72);
LV_IMG_DECLARE(_bluetoothConnectivity_alpha_72x72);
LV_IMG_DECLARE(_Preference_alpha_72x72);
LV_IMG_DECLARE(_Mode_alpha_72x72);
LV_IMG_DECLARE(_screenBackground_alpha_1280x720);
LV_IMG_DECLARE(_timePickerInactive_alpha_300x150);
LV_IMG_DECLARE(_arrowWhite_alpha_54x54);
LV_IMG_DECLARE(_arrowWhite_alpha_54x54);
LV_IMG_DECLARE(_timePickerActive_alpha_150x150);
LV_IMG_DECLARE(_arrowWhite_alpha_54x54);
LV_IMG_DECLARE(_arrowWhite_alpha_54x54);
LV_IMG_DECLARE(_timePickerSelected_alpha_150x150);
LV_IMG_DECLARE(_arrowWhite_alpha_54x54);
LV_IMG_DECLARE(_arrowWhite_alpha_54x54);
LV_IMG_DECLARE(_timePickerInactive_alpha_200x150);
LV_IMG_DECLARE(_arrowWhite_alpha_54x54);
LV_IMG_DECLARE(_arrowWhite_alpha_54x54);
LV_IMG_DECLARE(_timePickerActive_alpha_200x150);
LV_IMG_DECLARE(_arrowWhite_alpha_54x54);
LV_IMG_DECLARE(_arrowWhite_alpha_54x54);
LV_IMG_DECLARE(_timePickerSelected_alpha_200x150);
LV_IMG_DECLARE(_arrowWhite_alpha_54x54);
LV_IMG_DECLARE(_arrowWhite_alpha_54x54);
LV_IMG_DECLARE(_barEmpty_alpha_100x45);
LV_IMG_DECLARE(_barEmpty_alpha_100x45);
LV_IMG_DECLARE(_barEmpty_alpha_100x45);
LV_IMG_DECLARE(_barEmpty_alpha_100x45);
LV_IMG_DECLARE(_barEmpty_alpha_100x45);
LV_IMG_DECLARE(_barEmpty_alpha_100x45);
LV_IMG_DECLARE(_barEmpty_alpha_100x45);
LV_IMG_DECLARE(_barEmpty_alpha_100x45);
LV_IMG_DECLARE(_barEmpty_alpha_100x45);
LV_IMG_DECLARE(_barFill_alpha_100x45);
LV_IMG_DECLARE(_timePickerSelected_alpha_200x150);
LV_IMG_DECLARE(_arrowWhite_alpha_54x54);
LV_IMG_DECLARE(_arrowWhite_alpha_54x54);
LV_IMG_DECLARE(_barFill_alpha_10x100);
LV_IMG_DECLARE(_loadingIcon_alpha_75x75);
LV_IMG_DECLARE(_toggleIcon_alpha_75x75);
LV_IMG_DECLARE(_scrol2Div_alpha_10x320);
LV_IMG_DECLARE(_scroll3Div_alpha_10x210);
LV_IMG_DECLARE(_speedometerBackground_alpha_508x506);
LV_IMG_DECLARE(_speedometerNeedle_alpha_507x507);
LV_IMG_DECLARE(_speedometerRing_alpha_801x602);
LV_IMG_DECLARE(_1_alpha_120x110);
LV_IMG_DECLARE(_2_alpha_126x98);
LV_IMG_DECLARE(_3_alpha_128x85);
LV_IMG_DECLARE(_4_alpha_128x68);
LV_IMG_DECLARE(_5_alpha_123x51);
LV_IMG_DECLARE(_6_alpha_124x51);
LV_IMG_DECLARE(_7_alpha_127x72);
LV_IMG_DECLARE(_8_alpha_128x88);
LV_IMG_DECLARE(_9_alpha_125x101);
LV_IMG_DECLARE(_10_alpha_119x112);
LV_IMG_DECLARE(_gearindicatorArrow_alpha_37x33);
LV_IMG_DECLARE(_power_alpha_189x211);
LV_IMG_DECLARE(_auto_alpha_130x208);
LV_IMG_DECLARE(_eco_alpha_189x211);
LV_IMG_DECLARE(_powerIcon_alpha_48x48);
LV_IMG_DECLARE(_widgetbackground_alpha_400x120);
LV_IMG_DECLARE(_barFill_alpha_5x50);
LV_IMG_DECLARE(_widgetbackground_alpha_400x120);
LV_IMG_DECLARE(_widgetbackground_alpha_400x120);
LV_IMG_DECLARE(_takeNextRamp_alpha_256x256);
LV_IMG_DECLARE(_turnType_curveLeft_alpha_256x256);
LV_IMG_DECLARE(_turnType_curveRight_alpha_256x256);
LV_IMG_DECLARE(_turnType_flyOver_alpha_256x256);
LV_IMG_DECLARE(_turnType_forkLeft_alpha_256x256);
LV_IMG_DECLARE(_turnType_forkRight_alpha_256x256);
LV_IMG_DECLARE(_turnType_goStraight_alpha_256x256);
LV_IMG_DECLARE(_turnType_keepLane_alpha_256x256);
LV_IMG_DECLARE(_turnType_keepLeft_alpha_256x256);
LV_IMG_DECLARE(_turnType_keepRight_alpha_256x256);
LV_IMG_DECLARE(_turnType_RampLeft_alpha_256x256);
LV_IMG_DECLARE(_turnType_RampRight_alpha_256x256);
LV_IMG_DECLARE(_turnType_roundAboutLeft_alpha_256x256);
LV_IMG_DECLARE(_turnType_roundAboutRight_alpha_256x256);
LV_IMG_DECLARE(_turnType_subWay_alpha_256x256);
LV_IMG_DECLARE(_turnType_turnLeft_alpha_256x256);
LV_IMG_DECLARE(_turnType_turnRight_alpha_256x256);
LV_IMG_DECLARE(_turnType_turnSharplyLeft_alpha_256x256);
LV_IMG_DECLARE(_turnType_turnSharplyRight_alpha_256x256);
LV_IMG_DECLARE(_turnType_turnSlightlyLeft_alpha_256x256);
LV_IMG_DECLARE(_turnType_turnSlightlyRight_alpha_256x256);
LV_IMG_DECLARE(_turnType_uTurnLeft_alpha_256x256);
LV_IMG_DECLARE(_turnType_uTurnRight_alpha_256x256);
LV_IMG_DECLARE(_Profile_alpha_100x100);
LV_IMG_DECLARE(_powerIcon_alpha_64x64);
LV_IMG_DECLARE(_widgetbackground_alpha_400x120);

LV_FONT_DECLARE(lv_font_MIMXRT1170EVKB_30)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_MIMXRT1170EVKB_75)
LV_FONT_DECLARE(lv_font_MIMXRT1170EVKB_100)
LV_FONT_DECLARE(lv_font_MIMXRT1170EVKB_50)
LV_FONT_DECLARE(lv_font_speedometerValue_200)


#ifdef __cplusplus
}
#endif
#endif
