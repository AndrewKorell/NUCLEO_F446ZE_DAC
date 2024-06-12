################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Core/Startup/startup_stm32f446zetx.s 

S_DEPS += \
./Core/Startup/startup_stm32f446zetx.d 

OBJS += \
./Core/Startup/startup_stm32f446zetx.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Startup/%.o: ../Core/Startup/%.s Core/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -I"C:/git/STMProjects/Nucleo_446ZE/Personal_DAC_01/Common" -I"C:/git/STMProjects/Nucleo_446ZE/Personal_DAC_01/Testing" -I"C:/git/STMProjects/Nucleo_446ZE/Personal_DAC_01/Common/inc" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Core-2f-Startup

clean-Core-2f-Startup:
	-$(RM) ./Core/Startup/startup_stm32f446zetx.d ./Core/Startup/startup_stm32f446zetx.o

.PHONY: clean-Core-2f-Startup

