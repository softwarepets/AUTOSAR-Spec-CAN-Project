################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/fsl_anatop_ai.c \
../drivers/fsl_cache.c \
../drivers/fsl_clock.c \
../drivers/fsl_common.c \
../drivers/fsl_common_arm.c \
../drivers/fsl_dcdc.c \
../drivers/fsl_dmamux.c \
../drivers/fsl_edma.c \
../drivers/fsl_elcdif.c \
../drivers/fsl_flexcan.c \
../drivers/fsl_flexspi.c \
../drivers/fsl_flexspi_edma.c \
../drivers/fsl_gpc.c \
../drivers/fsl_gpio.c \
../drivers/fsl_lcdifv2.c \
../drivers/fsl_lpi2c.c \
../drivers/fsl_lpuart.c \
../drivers/fsl_mipi_dsi.c \
../drivers/fsl_mu.c \
../drivers/fsl_pmu.c \
../drivers/fsl_pxp.c \
../drivers/fsl_snvs_hp.c \
../drivers/fsl_snvs_lp.c \
../drivers/fsl_soc_mipi_csi2rx.c \
../drivers/fsl_soc_src.c 

C_DEPS += \
./drivers/fsl_anatop_ai.d \
./drivers/fsl_cache.d \
./drivers/fsl_clock.d \
./drivers/fsl_common.d \
./drivers/fsl_common_arm.d \
./drivers/fsl_dcdc.d \
./drivers/fsl_dmamux.d \
./drivers/fsl_edma.d \
./drivers/fsl_elcdif.d \
./drivers/fsl_flexcan.d \
./drivers/fsl_flexspi.d \
./drivers/fsl_flexspi_edma.d \
./drivers/fsl_gpc.d \
./drivers/fsl_gpio.d \
./drivers/fsl_lcdifv2.d \
./drivers/fsl_lpi2c.d \
./drivers/fsl_lpuart.d \
./drivers/fsl_mipi_dsi.d \
./drivers/fsl_mu.d \
./drivers/fsl_pmu.d \
./drivers/fsl_pxp.d \
./drivers/fsl_snvs_hp.d \
./drivers/fsl_snvs_lp.d \
./drivers/fsl_soc_mipi_csi2rx.d \
./drivers/fsl_soc_src.d 

OBJS += \
./drivers/fsl_anatop_ai.o \
./drivers/fsl_cache.o \
./drivers/fsl_clock.o \
./drivers/fsl_common.o \
./drivers/fsl_common_arm.o \
./drivers/fsl_dcdc.o \
./drivers/fsl_dmamux.o \
./drivers/fsl_edma.o \
./drivers/fsl_elcdif.o \
./drivers/fsl_flexcan.o \
./drivers/fsl_flexspi.o \
./drivers/fsl_flexspi_edma.o \
./drivers/fsl_gpc.o \
./drivers/fsl_gpio.o \
./drivers/fsl_lcdifv2.o \
./drivers/fsl_lpi2c.o \
./drivers/fsl_lpuart.o \
./drivers/fsl_mipi_dsi.o \
./drivers/fsl_mu.o \
./drivers/fsl_pmu.o \
./drivers/fsl_pxp.o \
./drivers/fsl_snvs_hp.o \
./drivers/fsl_snvs_lp.o \
./drivers/fsl_soc_mipi_csi2rx.o \
./drivers/fsl_soc_src.o 


# Each subdirectory must supply rules for building sources it contributes
drivers/%.o: ../drivers/%.c drivers/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__NEWLIB__ -DCPU_MIMXRT1176DVMAA -DCPU_MIMXRT1176DVMAA_cm7 -DXIP_BOOT_HEADER_DCD_ENABLE=1 -DUSE_SDRAM -DDATA_SECTION_IS_CACHEABLE=1 -DSDK_DEBUGCONSOLE=1 -DXIP_EXTERNAL_FLASH=1 -DXIP_BOOT_HEADER_ENABLE=1 -DLV_CONF_INCLUDE_SIMPLE=1 -DFSL_SDK_DRIVER_QUICK_ACCESS_ENABLE=1 -DMCUXPRESSO_SDK -DSDK_I2C_BASED_COMPONENT_USED=1 -DVG_COMMAND_CALL=1 -DVG_TARGET_FAST_CLEAR=0 -DSERIAL_PORT_TYPE_UART=1 -DSDK_OS_FREE_RTOS -DCR_INTEGER_PRINTF -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DTRIOX_BOARD_CONFIG=1 -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\source" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\video" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\drivers" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\touchpanel" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\vglite\inc" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\vglite\font" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\vglite\font\mcufont\decoder" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\vglite\VGLite\rtos" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\vglite\VGLiteKernel" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\vglite\VGLiteKernel\rtos" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\lvgl\lvgl" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\lvgl\lvgl\src" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\lvgl\lvgl\src\font" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\lvgl" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\device" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\utilities" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\component\uart" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\component\serial_manager" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\component\lists" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\startup" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\xip" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\board" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\freertos\freertos-kernel\include" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\freertos\freertos-kernel\portable\GCC\ARM_CM4F" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\CMSIS" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\generated" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\custom" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\generated\guider_customer_fonts" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\generated\guider_fonts" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\rlottie" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\source\application\includes" -I"C:\Users\subas\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkbmimxrt1170_lvgl_guider_cm7_v8\RTE\header" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -Wno-format -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m7 -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-drivers

clean-drivers:
	-$(RM) ./drivers/fsl_anatop_ai.d ./drivers/fsl_anatop_ai.o ./drivers/fsl_cache.d ./drivers/fsl_cache.o ./drivers/fsl_clock.d ./drivers/fsl_clock.o ./drivers/fsl_common.d ./drivers/fsl_common.o ./drivers/fsl_common_arm.d ./drivers/fsl_common_arm.o ./drivers/fsl_dcdc.d ./drivers/fsl_dcdc.o ./drivers/fsl_dmamux.d ./drivers/fsl_dmamux.o ./drivers/fsl_edma.d ./drivers/fsl_edma.o ./drivers/fsl_elcdif.d ./drivers/fsl_elcdif.o ./drivers/fsl_flexcan.d ./drivers/fsl_flexcan.o ./drivers/fsl_flexspi.d ./drivers/fsl_flexspi.o ./drivers/fsl_flexspi_edma.d ./drivers/fsl_flexspi_edma.o ./drivers/fsl_gpc.d ./drivers/fsl_gpc.o ./drivers/fsl_gpio.d ./drivers/fsl_gpio.o ./drivers/fsl_lcdifv2.d ./drivers/fsl_lcdifv2.o ./drivers/fsl_lpi2c.d ./drivers/fsl_lpi2c.o ./drivers/fsl_lpuart.d ./drivers/fsl_lpuart.o ./drivers/fsl_mipi_dsi.d ./drivers/fsl_mipi_dsi.o ./drivers/fsl_mu.d ./drivers/fsl_mu.o ./drivers/fsl_pmu.d ./drivers/fsl_pmu.o ./drivers/fsl_pxp.d ./drivers/fsl_pxp.o ./drivers/fsl_snvs_hp.d ./drivers/fsl_snvs_hp.o ./drivers/fsl_snvs_lp.d ./drivers/fsl_snvs_lp.o ./drivers/fsl_soc_mipi_csi2rx.d ./drivers/fsl_soc_mipi_csi2rx.o ./drivers/fsl_soc_src.d ./drivers/fsl_soc_src.o

.PHONY: clean-drivers

