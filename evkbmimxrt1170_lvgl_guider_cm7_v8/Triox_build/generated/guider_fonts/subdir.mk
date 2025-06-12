################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../generated/guider_fonts/lv_font_MIMXRT1170EVKB_100.c \
../generated/guider_fonts/lv_font_MIMXRT1170EVKB_30.c \
../generated/guider_fonts/lv_font_MIMXRT1170EVKB_50.c \
../generated/guider_fonts/lv_font_MIMXRT1170EVKB_75.c \
../generated/guider_fonts/lv_font_montserratMedium_16.c \
../generated/guider_fonts/lv_font_speedometerValue_200.c 

C_DEPS += \
./generated/guider_fonts/lv_font_MIMXRT1170EVKB_100.d \
./generated/guider_fonts/lv_font_MIMXRT1170EVKB_30.d \
./generated/guider_fonts/lv_font_MIMXRT1170EVKB_50.d \
./generated/guider_fonts/lv_font_MIMXRT1170EVKB_75.d \
./generated/guider_fonts/lv_font_montserratMedium_16.d \
./generated/guider_fonts/lv_font_speedometerValue_200.d 

OBJS += \
./generated/guider_fonts/lv_font_MIMXRT1170EVKB_100.o \
./generated/guider_fonts/lv_font_MIMXRT1170EVKB_30.o \
./generated/guider_fonts/lv_font_MIMXRT1170EVKB_50.o \
./generated/guider_fonts/lv_font_MIMXRT1170EVKB_75.o \
./generated/guider_fonts/lv_font_montserratMedium_16.o \
./generated/guider_fonts/lv_font_speedometerValue_200.o 


# Each subdirectory must supply rules for building sources it contributes
generated/guider_fonts/%.o: ../generated/guider_fonts/%.c generated/guider_fonts/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__NEWLIB__ -DCPU_MIMXRT1176DVMAA -DCPU_MIMXRT1176DVMAA_cm7 -DXIP_BOOT_HEADER_DCD_ENABLE=1 -DUSE_SDRAM -DDATA_SECTION_IS_CACHEABLE=1 -DSDK_DEBUGCONSOLE=1 -DXIP_EXTERNAL_FLASH=1 -DXIP_BOOT_HEADER_ENABLE=1 -DLV_CONF_INCLUDE_SIMPLE=1 -DFSL_SDK_DRIVER_QUICK_ACCESS_ENABLE=1 -DMCUXPRESSO_SDK -DSDK_I2C_BASED_COMPONENT_USED=1 -DVG_COMMAND_CALL=1 -DVG_TARGET_FAST_CLEAR=0 -DSERIAL_PORT_TYPE_UART=1 -DSDK_OS_FREE_RTOS -DCR_INTEGER_PRINTF -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DTRIOX_BOARD_CONFIG=1 -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\source" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\video" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\touchpanel" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\vglite\inc" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\vglite\font" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\vglite\font\mcufont\decoder" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\vglite\VGLite\rtos" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\vglite\VGLiteKernel" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\vglite\VGLiteKernel\rtos" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\device" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\utilities" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\component\uart" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\component\serial_manager" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\component\lists" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\startup" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\xip" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\board" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\CMSIS" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\generated" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\generated\guider_customer_fonts" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\generated\guider_fonts" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\source\application\includes" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\RTE\header" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\lvgl\lvgl" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\lvgl\lvgl\src" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\lvgl\lvgl\src\font" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\lvgl" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\Services\freertos-kernel\include" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\Services\freertos-kernel\portable\GCC\ARM_CM4F" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -Wno-format -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m7 -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-generated-2f-guider_fonts

clean-generated-2f-guider_fonts:
	-$(RM) ./generated/guider_fonts/lv_font_MIMXRT1170EVKB_100.d ./generated/guider_fonts/lv_font_MIMXRT1170EVKB_100.o ./generated/guider_fonts/lv_font_MIMXRT1170EVKB_30.d ./generated/guider_fonts/lv_font_MIMXRT1170EVKB_30.o ./generated/guider_fonts/lv_font_MIMXRT1170EVKB_50.d ./generated/guider_fonts/lv_font_MIMXRT1170EVKB_50.o ./generated/guider_fonts/lv_font_MIMXRT1170EVKB_75.d ./generated/guider_fonts/lv_font_MIMXRT1170EVKB_75.o ./generated/guider_fonts/lv_font_montserratMedium_16.d ./generated/guider_fonts/lv_font_montserratMedium_16.o ./generated/guider_fonts/lv_font_speedometerValue_200.d ./generated/guider_fonts/lv_font_speedometerValue_200.o

.PHONY: clean-generated-2f-guider_fonts

