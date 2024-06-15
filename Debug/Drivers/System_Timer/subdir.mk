################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/System_Timer/System_Timer.c 

C_DEPS += \
./Drivers/System_Timer/System_Timer.d 

OBJS += \
./Drivers/System_Timer/System_Timer.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/System_Timer/%.o Drivers/System_Timer/%.su Drivers/System_Timer/%.cyclo: ../Drivers/System_Timer/%.c Drivers/System_Timer/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Core/OS_Task -I../Drivers/System_Timer -I"../Drivers/Scheduler" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-System_Timer

clean-Drivers-2f-System_Timer:
	-$(RM) ./Drivers/System_Timer/System_Timer.cyclo ./Drivers/System_Timer/System_Timer.d ./Drivers/System_Timer/System_Timer.o ./Drivers/System_Timer/System_Timer.su

.PHONY: clean-Drivers-2f-System_Timer

