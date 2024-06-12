################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Testing/test_main.cpp 

OBJS += \
./Testing/test_main.o 

CPP_DEPS += \
./Testing/test_main.d 


# Each subdirectory must supply rules for building sources it contributes
Testing/%.o Testing/%.su Testing/%.cyclo: ../Testing/%.cpp Testing/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/git/STMProjects/Nucleo_446ZE/Personal_DAC_01/Common" -I"C:/git/STMProjects/Nucleo_446ZE/Personal_DAC_01/Testing" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Testing

clean-Testing:
	-$(RM) ./Testing/test_main.cyclo ./Testing/test_main.d ./Testing/test_main.o ./Testing/test_main.su

.PHONY: clean-Testing

