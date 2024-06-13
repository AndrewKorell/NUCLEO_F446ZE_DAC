################################################################################
# Automatically-generated file. Do not edit!
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
Common/src/%.o: ../Common/src/%.c Common/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C Compiler'
	gcc -I"C:\git\STMProjects\Nucleo_446ZE\Personal_DAC_01\Common\inc" -I"C:\git\STMProjects\Nucleo_446ZE\Personal_DAC_01\Drivers\STM32F4xx_HAL_Driver\Inc" -I"C:\git\STMProjects\Nucleo_446ZE\Personal_DAC_01\Core\Inc" -I"C:\git\STMProjects\Nucleo_446ZE\Personal_DAC_01\Drivers\CMSIS\Device\ST\STM32F4xx\Include" -O0 -g3 -Wall -Wcast-align -c -fmessage-length=0 -v -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Common-2f-src

clean-Common-2f-src:
	-$(RM) ./Common/src/sine_proc.d ./Common/src/sine_proc.o ./Common/src/testables.d ./Common/src/testables.o

.PHONY: clean-Common-2f-src

