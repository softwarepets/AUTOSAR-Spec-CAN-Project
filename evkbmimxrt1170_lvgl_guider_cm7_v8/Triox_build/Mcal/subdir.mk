################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Mcal/fsl_anatop_ai.c \
../Mcal/fsl_cache.c \
../Mcal/fsl_clock.c \
../Mcal/fsl_common.c \
../Mcal/fsl_common_arm.c \
../Mcal/fsl_dcdc.c \
../Mcal/fsl_dmamux.c \
../Mcal/fsl_edma.c \
../Mcal/fsl_elcdif.c \
../Mcal/fsl_flexcan.c \
../Mcal/fsl_flexspi.c \
../Mcal/fsl_flexspi_edma.c \
../Mcal/fsl_gpc.c \
../Mcal/fsl_gpio.c \
../Mcal/fsl_lcdifv2.c \
../Mcal/fsl_lpi2c.c \
../Mcal/fsl_lpuart.c \
../Mcal/fsl_mipi_dsi.c \
../Mcal/fsl_mu.c \
../Mcal/fsl_pmu.c \
../Mcal/fsl_pxp.c \
../Mcal/fsl_snvs_hp.c \
../Mcal/fsl_snvs_lp.c \
../Mcal/fsl_soc_mipi_csi2rx.c \
../Mcal/fsl_soc_src.c 

C_DEPS += \
./Mcal/fsl_anatop_ai.d \
./Mcal/fsl_cache.d \
./Mcal/fsl_clock.d \
./Mcal/fsl_common.d \
./Mcal/fsl_common_arm.d \
./Mcal/fsl_dcdc.d \
./Mcal/fsl_dmamux.d \
./Mcal/fsl_edma.d \
./Mcal/fsl_elcdif.d \
./Mcal/fsl_flexcan.d \
./Mcal/fsl_flexspi.d \
./Mcal/fsl_flexspi_edma.d \
./Mcal/fsl_gpc.d \
./Mcal/fsl_gpio.d \
./Mcal/fsl_lcdifv2.d \
./Mcal/fsl_lpi2c.d \
./Mcal/fsl_lpuart.d \
./Mcal/fsl_mipi_dsi.d \
./Mcal/fsl_mu.d \
./Mcal/fsl_pmu.d \
./Mcal/fsl_pxp.d \
./Mcal/fsl_snvs_hp.d \
./Mcal/fsl_snvs_lp.d \
./Mcal/fsl_soc_mipi_csi2rx.d \
./Mcal/fsl_soc_src.d 

OBJS += \
./Mcal/fsl_anatop_ai.o \
./Mcal/fsl_cache.o \
./Mcal/fsl_clock.o \
./Mcal/fsl_common.o \
./Mcal/fsl_common_arm.o \
./Mcal/fsl_dcdc.o \
./Mcal/fsl_dmamux.o \
./Mcal/fsl_edma.o \
./Mcal/fsl_elcdif.o \
./Mcal/fsl_flexcan.o \
./Mcal/fsl_flexspi.o \
./Mcal/fsl_flexspi_edma.o \
./Mcal/fsl_gpc.o \
./Mcal/fsl_gpio.o \
./Mcal/fsl_lcdifv2.o \
./Mcal/fsl_lpi2c.o \
./Mcal/fsl_lpuart.o \
./Mcal/fsl_mipi_dsi.o \
./Mcal/fsl_mu.o \
./Mcal/fsl_pmu.o \
./Mcal/fsl_pxp.o \
./Mcal/fsl_snvs_hp.o \
./Mcal/fsl_snvs_lp.o \
./Mcal/fsl_soc_mipi_csi2rx.o \
./Mcal/fsl_soc_src.o 


# Each subdirectory must supply rules for building sources it contributes
Mcal/%.o: ../Mcal/%.c Mcal/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__NEWLIB__ -DCPU_MIMXRT1176DVMAA -DCPU_MIMXRT1176DVMAA_cm7 -DXIP_BOOT_HEADER_DCD_ENABLE=1 -DUSE_SDRAM -DDATA_SECTION_IS_CACHEABLE=1 -DSDK_DEBUGCONSOLE=1 -DXIP_EXTERNAL_FLASH=1 -DXIP_BOOT_HEADER_ENABLE=1 -DLV_CONF_INCLUDE_SIMPLE=1 -DFSL_SDK_DRIVER_QUICK_ACCESS_ENABLE=1 -DMCUXPRESSO_SDK -DSDK_I2C_BASED_COMPONENT_USED=1 -DVG_COMMAND_CALL=1 -DVG_TARGET_FAST_CLEAR=0 -DSERIAL_PORT_TYPE_UART=1 -DSDK_OS_FREE_RTOS -DCR_INTEGER_PRINTF -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DTRIOX_BOARD_CONFIG=1 -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\source" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\video" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\touchpanel" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\vglite\inc" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\vglite\font" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\vglite\font\mcufont\decoder" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\vglite\VGLite\rtos" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\vglite\VGLiteKernel" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\vglite\VGLiteKernel\rtos" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\device" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\utilities" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\component\uart" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\component\serial_manager" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\component\lists" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\startup" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\xip" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\board" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\CMSIS" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\generated" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\generated\guider_customer_fonts" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\generated\guider_fonts" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\source\application\includes" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\RTE\header" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\lvgl\lvgl" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\lvgl\lvgl\src" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\lvgl\lvgl\src\font" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\lvgl" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\Services\freertos-kernel\include" -I"D:\middleware\evkbmimxrt1170_lvgl_guider_cm7_v8\Services\freertos-kernel\portable\GCC\ARM_CM4F" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -Wno-format -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m7 -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Mcal

clean-Mcal:
	-$(RM) ./Mcal/fsl_anatop_ai.d ./Mcal/fsl_anatop_ai.o ./Mcal/fsl_cache.d ./Mcal/fsl_cache.o ./Mcal/fsl_clock.d ./Mcal/fsl_clock.o ./Mcal/fsl_common.d ./Mcal/fsl_common.o ./Mcal/fsl_common_arm.d ./Mcal/fsl_common_arm.o ./Mcal/fsl_dcdc.d ./Mcal/fsl_dcdc.o ./Mcal/fsl_dmamux.d ./Mcal/fsl_dmamux.o ./Mcal/fsl_edma.d ./Mcal/fsl_edma.o ./Mcal/fsl_elcdif.d ./Mcal/fsl_elcdif.o ./Mcal/fsl_flexcan.d ./Mcal/fsl_flexcan.o ./Mcal/fsl_flexspi.d ./Mcal/fsl_flexspi.o ./Mcal/fsl_flexspi_edma.d ./Mcal/fsl_flexspi_edma.o ./Mcal/fsl_gpc.d ./Mcal/fsl_gpc.o ./Mcal/fsl_gpio.d ./Mcal/fsl_gpio.o ./Mcal/fsl_lcdifv2.d ./Mcal/fsl_lcdifv2.o ./Mcal/fsl_lpi2c.d ./Mcal/fsl_lpi2c.o ./Mcal/fsl_lpuart.d ./Mcal/fsl_lpuart.o ./Mcal/fsl_mipi_dsi.d ./Mcal/fsl_mipi_dsi.o ./Mcal/fsl_mu.d ./Mcal/fsl_mu.o ./Mcal/fsl_pmu.d ./Mcal/fsl_pmu.o ./Mcal/fsl_pxp.d ./Mcal/fsl_pxp.o ./Mcal/fsl_snvs_hp.d ./Mcal/fsl_snvs_hp.o ./Mcal/fsl_snvs_lp.d ./Mcal/fsl_snvs_lp.o ./Mcal/fsl_soc_mipi_csi2rx.d ./Mcal/fsl_soc_mipi_csi2rx.o ./Mcal/fsl_soc_src.d ./Mcal/fsl_soc_src.o

.PHONY: clean-Mcal

