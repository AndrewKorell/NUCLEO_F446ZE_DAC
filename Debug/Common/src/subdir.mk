################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Common/src/sine_proc.c \
../Common/src/testables.c 

C_DEPS += \
./Common/src/sine_proc.d \
./Common/src/testables.d 

OBJS += \
./Common/src/sine_proc.o \
./Common/src/testables.o 


# Each subdirectory must supply rules for building sources it contributes
Common/src/%.o Common/src/%.su Common/src/%.cyclo: ../Common/src/%.c Common/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/git/STMProjects/Nucleo_446ZE/Personal_DAC_01/Common" -I"C:/git/STMProjects/Nucleo_446ZE/Personal_DAC_01/Common/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Common-2f-src

clean-Common-2f-src:
	-$(RM) ./Common/src/sine_proc.cyclo ./Common/src/sine_proc.d ./Common/src/sine_proc.o ./Common/src/sine_proc.su ./Common/src/testables.cyclo ./Common/src/testables.d ./Common/src/testables.o ./Common/src/testables.su

.PHONY: clean-Common-2f-src

