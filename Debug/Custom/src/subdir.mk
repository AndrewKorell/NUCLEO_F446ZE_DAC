################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Custom/src/sine_proc.c 

C_DEPS += \
./Custom/src/sine_proc.d 

OBJS += \
./Custom/src/sine_proc.o 


# Each subdirectory must supply rules for building sources it contributes
Custom/src/%.o Custom/src/%.su Custom/src/%.cyclo: ../Custom/src/%.c Custom/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/git/STMProjects/Nucleo_446ZE/Personal_DAC_01/Custom/inc" -I"C:/git/STMProjects/Nucleo_446ZE/Personal_DAC_01/Custom" -I"C:/git/STMProjects/Nucleo_446ZE/Personal_DAC_01/Common" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Custom-2f-src

clean-Custom-2f-src:
	-$(RM) ./Custom/src/sine_proc.cyclo ./Custom/src/sine_proc.d ./Custom/src/sine_proc.o ./Custom/src/sine_proc.su

.PHONY: clean-Custom-2f-src

