################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CDD/lvgl/src/widgets/lv_arc.c \
../CDD/lvgl/src/widgets/lv_bar.c \
../CDD/lvgl/src/widgets/lv_btn.c \
../CDD/lvgl/src/widgets/lv_btnmatrix.c \
../CDD/lvgl/src/widgets/lv_canvas.c \
../CDD/lvgl/src/widgets/lv_checkbox.c \
../CDD/lvgl/src/widgets/lv_dropdown.c \
../CDD/lvgl/src/widgets/lv_img.c \
../CDD/lvgl/src/widgets/lv_label.c \
../CDD/lvgl/src/widgets/lv_line.c \
../CDD/lvgl/src/widgets/lv_objx_templ.c \
../CDD/lvgl/src/widgets/lv_roller.c \
../CDD/lvgl/src/widgets/lv_slider.c \
../CDD/lvgl/src/widgets/lv_switch.c \
../CDD/lvgl/src/widgets/lv_table.c \
../CDD/lvgl/src/widgets/lv_textarea.c 

C_DEPS += \
./CDD/lvgl/src/widgets/lv_arc.d \
./CDD/lvgl/src/widgets/lv_bar.d \
./CDD/lvgl/src/widgets/lv_btn.d \
./CDD/lvgl/src/widgets/lv_btnmatrix.d \
./CDD/lvgl/src/widgets/lv_canvas.d \
./CDD/lvgl/src/widgets/lv_checkbox.d \
./CDD/lvgl/src/widgets/lv_dropdown.d \
./CDD/lvgl/src/widgets/lv_img.d \
./CDD/lvgl/src/widgets/lv_label.d \
./CDD/lvgl/src/widgets/lv_line.d \
./CDD/lvgl/src/widgets/lv_objx_templ.d \
./CDD/lvgl/src/widgets/lv_roller.d \
./CDD/lvgl/src/widgets/lv_slider.d \
./CDD/lvgl/src/widgets/lv_switch.d \
./CDD/lvgl/src/widgets/lv_table.d \
./CDD/lvgl/src/widgets/lv_textarea.d 

OBJS += \
./CDD/lvgl/src/widgets/lv_arc.o \
./CDD/lvgl/src/widgets/lv_bar.o \
./CDD/lvgl/src/widgets/lv_btn.o \
./CDD/lvgl/src/widgets/lv_btnmatrix.o \
./CDD/lvgl/src/widgets/lv_canvas.o \
./CDD/lvgl/src/widgets/lv_checkbox.o \
./CDD/lvgl/src/widgets/lv_dropdown.o \
./CDD/lvgl/src/widgets/lv_img.o \
./CDD/lvgl/src/widgets/lv_label.o \
./CDD/lvgl/src/widgets/lv_line.o \
./CDD/lvgl/src/widgets/lv_objx_templ.o \
./CDD/lvgl/src/widgets/lv_roller.o \
./CDD/lvgl/src/widgets/lv_slider.o \
./CDD/lvgl/src/widgets/lv_switch.o \
./CDD/lvgl/src/widgets/lv_table.o \
./CDD/lvgl/src/widgets/lv_textarea.o 


# Each subdirectory must supply rules for building sources it contributes
CDD/lvgl/src/widgets/%.o: ../CDD/lvgl/src/widgets/%.c CDD/lvgl/src/widgets/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__NEWLIB__ -DCPU_MIMXRT1176DVMAA -DCPU_MIMXRT1176DVMAA_cm7 -DXIP_BOOT_HEADER_DCD_ENABLE=1 -DUSE_SDRAM -DDATA_SECTION_IS_CACHEABLE=1 -DSDK_DEBUGCONSOLE=1 -DXIP_EXTERNAL_FLASH=1 -DXIP_BOOT_HEADER_ENABLE=1 -DLV_CONF_INCLUDE_SIMPLE=1 -DFSL_SDK_DRIVER_QUICK_ACCESS_ENABLE=1 -DMCUXPRESSO_SDK -DSDK_I2C_BASED_COMPONENT_USED=1 -DVG_COMMAND_CALL=1 -DVG_TARGET_FAST_CLEAR=0 -DSERIAL_PORT_TYPE_UART=1 -DSDK_OS_FREE_RTOS -DCR_INTEGER_PRINTF -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DTRIOX_BOARD_CONFIG=1 -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\source" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\video" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\touchpanel" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\vglite\inc" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\vglite\font" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\vglite\font\mcufont\decoder" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\vglite\VGLite\rtos" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\vglite\VGLiteKernel" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\vglite\VGLiteKernel\rtos" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\device" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\utilities" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\component\uart" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\component\serial_manager" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\component\lists" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\startup" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\xip" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\board" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\freertos\freertos-kernel\include" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\freertos\freertos-kernel\portable\GCC\ARM_CM4F" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\CMSIS" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\generated" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\custom" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\generated\guider_customer_fonts" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\generated\guider_fonts" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\rlottie" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\source\application\includes" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\RTE\header" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\CDD\lvgl" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\CDD\lvgl\src" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\CDD\lvgl\src\font" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\CDD" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -Wno-format -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m7 -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-CDD-2f-lvgl-2f-src-2f-widgets

clean-CDD-2f-lvgl-2f-src-2f-widgets:
	-$(RM) ./CDD/lvgl/src/widgets/lv_arc.d ./CDD/lvgl/src/widgets/lv_arc.o ./CDD/lvgl/src/widgets/lv_bar.d ./CDD/lvgl/src/widgets/lv_bar.o ./CDD/lvgl/src/widgets/lv_btn.d ./CDD/lvgl/src/widgets/lv_btn.o ./CDD/lvgl/src/widgets/lv_btnmatrix.d ./CDD/lvgl/src/widgets/lv_btnmatrix.o ./CDD/lvgl/src/widgets/lv_canvas.d ./CDD/lvgl/src/widgets/lv_canvas.o ./CDD/lvgl/src/widgets/lv_checkbox.d ./CDD/lvgl/src/widgets/lv_checkbox.o ./CDD/lvgl/src/widgets/lv_dropdown.d ./CDD/lvgl/src/widgets/lv_dropdown.o ./CDD/lvgl/src/widgets/lv_img.d ./CDD/lvgl/src/widgets/lv_img.o ./CDD/lvgl/src/widgets/lv_label.d ./CDD/lvgl/src/widgets/lv_label.o ./CDD/lvgl/src/widgets/lv_line.d ./CDD/lvgl/src/widgets/lv_line.o ./CDD/lvgl/src/widgets/lv_objx_templ.d ./CDD/lvgl/src/widgets/lv_objx_templ.o ./CDD/lvgl/src/widgets/lv_roller.d ./CDD/lvgl/src/widgets/lv_roller.o ./CDD/lvgl/src/widgets/lv_slider.d ./CDD/lvgl/src/widgets/lv_slider.o ./CDD/lvgl/src/widgets/lv_switch.d ./CDD/lvgl/src/widgets/lv_switch.o ./CDD/lvgl/src/widgets/lv_table.d ./CDD/lvgl/src/widgets/lv_table.o ./CDD/lvgl/src/widgets/lv_textarea.d ./CDD/lvgl/src/widgets/lv_textarea.o

.PHONY: clean-CDD-2f-lvgl-2f-src-2f-widgets

