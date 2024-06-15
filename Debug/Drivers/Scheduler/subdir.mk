################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Scheduler/Scheduler.c 

C_DEPS += \
./Drivers/Scheduler/Scheduler.d 

OBJS += \
./Drivers/Scheduler/Scheduler.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Scheduler/%.o Drivers/Scheduler/%.su Drivers/Scheduler/%.cyclo: ../Drivers/Scheduler/%.c Drivers/Scheduler/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Core/OS_Task -I../Drivers/System_Timer -I"../Drivers/Scheduler" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Scheduler

clean-Drivers-2f-Scheduler:
	-$(RM) ./Drivers/Scheduler/Scheduler.cyclo ./Drivers/Scheduler/Scheduler.d ./Drivers/Scheduler/Scheduler.o ./Drivers/Scheduler/Scheduler.su

.PHONY: clean-Drivers-2f-Scheduler

