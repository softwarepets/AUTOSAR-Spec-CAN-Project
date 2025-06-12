################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CDD/lvgl/src/extra/widgets/carousel/lv_carousel.c 

C_DEPS += \
./CDD/lvgl/src/extra/widgets/carousel/lv_carousel.d 

OBJS += \
./CDD/lvgl/src/extra/widgets/carousel/lv_carousel.o 


# Each subdirectory must supply rules for building sources it contributes
CDD/lvgl/src/extra/widgets/carousel/%.o: ../CDD/lvgl/src/extra/widgets/carousel/%.c CDD/lvgl/src/extra/widgets/carousel/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__NEWLIB__ -DCPU_MIMXRT1176DVMAA -DCPU_MIMXRT1176DVMAA_cm7 -DXIP_BOOT_HEADER_DCD_ENABLE=1 -DUSE_SDRAM -DDATA_SECTION_IS_CACHEABLE=1 -DSDK_DEBUGCONSOLE=1 -DXIP_EXTERNAL_FLASH=1 -DXIP_BOOT_HEADER_ENABLE=1 -DLV_CONF_INCLUDE_SIMPLE=1 -DFSL_SDK_DRIVER_QUICK_ACCESS_ENABLE=1 -DMCUXPRESSO_SDK -DSDK_I2C_BASED_COMPONENT_USED=1 -DVG_COMMAND_CALL=1 -DVG_TARGET_FAST_CLEAR=0 -DSERIAL_PORT_TYPE_UART=1 -DSDK_OS_FREE_RTOS -DCR_INTEGER_PRINTF -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DTRIOX_BOARD_CONFIG=1 -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\source" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\video" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\touchpanel" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\vglite\inc" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\vglite\font" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\vglite\font\mcufont\decoder" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\vglite\VGLite\rtos" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\vglite\VGLiteKernel" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\vglite\VGLiteKernel\rtos" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\device" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\utilities" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\component\uart" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\component\serial_manager" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\component\lists" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\startup" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\xip" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\board" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\freertos\freertos-kernel\include" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\freertos\freertos-kernel\portable\GCC\ARM_CM4F" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\CMSIS" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\generated" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\custom" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\generated\guider_customer_fonts" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\generated\guider_fonts" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\rlottie" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\source\application\includes" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\RTE\header" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\CDD\lvgl" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\CDD\lvgl\src" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\CDD\lvgl\src\font" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\CDD" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -Wno-format -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m7 -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-CDD-2f-lvgl-2f-src-2f-extra-2f-widgets-2f-carousel

clean-CDD-2f-lvgl-2f-src-2f-extra-2f-widgets-2f-carousel:
	-$(RM) ./CDD/lvgl/src/extra/widgets/carousel/lv_carousel.d ./CDD/lvgl/src/extra/widgets/carousel/lv_carousel.o

.PHONY: clean-CDD-2f-lvgl-2f-src-2f-extra-2f-widgets-2f-carousel

