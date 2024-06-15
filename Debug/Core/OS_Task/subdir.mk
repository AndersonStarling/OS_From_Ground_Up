################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/OS_Task/OS_Task.c 

C_DEPS += \
./Core/OS_Task/OS_Task.d 

OBJS += \
./Core/OS_Task/OS_Task.o 


# Each subdirectory must supply rules for building sources it contributes
Core/OS_Task/%.o Core/OS_Task/%.su Core/OS_Task/%.cyclo: ../Core/OS_Task/%.c Core/OS_Task/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Core/OS_Task -I../Drivers/System_Timer -I"../Drivers/Scheduler" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-OS_Task

clean-Core-2f-OS_Task:
	-$(RM) ./Core/OS_Task/OS_Task.cyclo ./Core/OS_Task/OS_Task.d ./Core/OS_Task/OS_Task.o ./Core/OS_Task/OS_Task.su

.PHONY: clean-Core-2f-OS_Task

