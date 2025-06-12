################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../vglite/font/mcufont/decoder/mf_bwfont.c \
../vglite/font/mcufont/decoder/mf_encoding.c \
../vglite/font/mcufont/decoder/mf_font.c \
../vglite/font/mcufont/decoder/mf_justify.c \
../vglite/font/mcufont/decoder/mf_kerning.c \
../vglite/font/mcufont/decoder/mf_rlefont.c \
../vglite/font/mcufont/decoder/mf_scaledfont.c \
../vglite/font/mcufont/decoder/mf_wordwrap.c 

C_DEPS += \
./vglite/font/mcufont/decoder/mf_bwfont.d \
./vglite/font/mcufont/decoder/mf_encoding.d \
./vglite/font/mcufont/decoder/mf_font.d \
./vglite/font/mcufont/decoder/mf_justify.d \
./vglite/font/mcufont/decoder/mf_kerning.d \
./vglite/font/mcufont/decoder/mf_rlefont.d \
./vglite/font/mcufont/decoder/mf_scaledfont.d \
./vglite/font/mcufont/decoder/mf_wordwrap.d 

OBJS += \
./vglite/font/mcufont/decoder/mf_bwfont.o \
./vglite/font/mcufont/decoder/mf_encoding.o \
./vglite/font/mcufont/decoder/mf_font.o \
./vglite/font/mcufont/decoder/mf_justify.o \
./vglite/font/mcufont/decoder/mf_kerning.o \
./vglite/font/mcufont/decoder/mf_rlefont.o \
./vglite/font/mcufont/decoder/mf_scaledfont.o \
./vglite/font/mcufont/decoder/mf_wordwrap.o 


# Each subdirectory must supply rules for building sources it contributes
vglite/font/mcufont/decoder/%.o: ../vglite/font/mcufont/decoder/%.c vglite/font/mcufont/decoder/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__NEWLIB__ -DCPU_MIMXRT1176DVMAA -DCPU_MIMXRT1176DVMAA_cm7 -DXIP_BOOT_HEADER_DCD_ENABLE=1 -DUSE_SDRAM -DDATA_SECTION_IS_CACHEABLE=1 -DSDK_DEBUGCONSOLE=1 -DXIP_EXTERNAL_FLASH=1 -DXIP_BOOT_HEADER_ENABLE=1 -DLV_CONF_INCLUDE_SIMPLE=1 -DFSL_SDK_DRIVER_QUICK_ACCESS_ENABLE=1 -DMCUXPRESSO_SDK -DSDK_I2C_BASED_COMPONENT_USED=1 -DVG_COMMAND_CALL=1 -DVG_TARGET_FAST_CLEAR=0 -DSERIAL_PORT_TYPE_UART=1 -DSDK_OS_FREE_RTOS -DCR_INTEGER_PRINTF -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DTRIOX_BOARD_CONFIG=1 -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\source" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\video" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\touchpanel" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\vglite\inc" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\vglite\font" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\vglite\font\mcufont\decoder" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\vglite\VGLite\rtos" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\vglite\VGLiteKernel" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\vglite\VGLiteKernel\rtos" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\device" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\utilities" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\component\uart" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\component\serial_manager" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\component\lists" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\startup" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\xip" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\board" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\CMSIS" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\generated" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\generated\guider_customer_fonts" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\generated\guider_fonts" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\source\application\includes" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\RTE\header" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\lvgl\lvgl" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\lvgl\lvgl\src" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\lvgl\lvgl\src\font" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\lvgl" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\Services\freertos-kernel\include" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\Services\freertos-kernel\portable\GCC\ARM_CM4F" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -Wno-format -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m7 -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-vglite-2f-font-2f-mcufont-2f-decoder

clean-vglite-2f-font-2f-mcufont-2f-decoder:
	-$(RM) ./vglite/font/mcufont/decoder/mf_bwfont.d ./vglite/font/mcufont/decoder/mf_bwfont.o ./vglite/font/mcufont/decoder/mf_encoding.d ./vglite/font/mcufont/decoder/mf_encoding.o ./vglite/font/mcufont/decoder/mf_font.d ./vglite/font/mcufont/decoder/mf_font.o ./vglite/font/mcufont/decoder/mf_justify.d ./vglite/font/mcufont/decoder/mf_justify.o ./vglite/font/mcufont/decoder/mf_kerning.d ./vglite/font/mcufont/decoder/mf_kerning.o ./vglite/font/mcufont/decoder/mf_rlefont.d ./vglite/font/mcufont/decoder/mf_rlefont.o ./vglite/font/mcufont/decoder/mf_scaledfont.d ./vglite/font/mcufont/decoder/mf_scaledfont.o ./vglite/font/mcufont/decoder/mf_wordwrap.d ./vglite/font/mcufont/decoder/mf_wordwrap.o

.PHONY: clean-vglite-2f-font-2f-mcufont-2f-decoder

