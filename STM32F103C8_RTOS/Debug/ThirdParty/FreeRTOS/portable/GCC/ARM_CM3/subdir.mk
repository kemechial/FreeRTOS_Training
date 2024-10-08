################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ThirdParty/FreeRTOS/portable/GCC/ARM_CM3/port.c 

OBJS += \
./ThirdParty/FreeRTOS/portable/GCC/ARM_CM3/port.o 

C_DEPS += \
./ThirdParty/FreeRTOS/portable/GCC/ARM_CM3/port.d 


# Each subdirectory must supply rules for building sources it contributes
ThirdParty/FreeRTOS/portable/GCC/ARM_CM3/%.o ThirdParty/FreeRTOS/portable/GCC/ARM_CM3/%.su ThirdParty/FreeRTOS/portable/GCC/ARM_CM3/%.cyclo: ../ThirdParty/FreeRTOS/portable/GCC/ARM_CM3/%.c ThirdParty/FreeRTOS/portable/GCC/ARM_CM3/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -DSTM32F103x8 -DSTM32F103x6 -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Lenovo/STM32CubeIDE/RTOS_Workspace/STM32F103C8_RTOS/ThirdParty/SEGGER/SEGGER" -I"C:/Users/Lenovo/STM32CubeIDE/RTOS_Workspace/STM32F103C8_RTOS/ThirdParty/SEGGER/Config" -I"C:/Users/Lenovo/STM32CubeIDE/RTOS_Workspace/STM32F103C8_RTOS/ThirdParty/SEGGER/OS" -I"C:/Users/Lenovo/STM32CubeIDE/RTOS_Workspace/STM32F103C8_RTOS/ThirdParty/FreeRTOS" -I"C:/Users/Lenovo/STM32CubeIDE/RTOS_Workspace/STM32F103C8_RTOS/ThirdParty/FreeRTOS/portable/GCC/ARM_CM3" -I"C:/Users/Lenovo/STM32CubeIDE/RTOS_Workspace/STM32F103C8_RTOS/ThirdParty/FreeRTOS/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-ThirdParty-2f-FreeRTOS-2f-portable-2f-GCC-2f-ARM_CM3

clean-ThirdParty-2f-FreeRTOS-2f-portable-2f-GCC-2f-ARM_CM3:
	-$(RM) ./ThirdParty/FreeRTOS/portable/GCC/ARM_CM3/port.cyclo ./ThirdParty/FreeRTOS/portable/GCC/ARM_CM3/port.d ./ThirdParty/FreeRTOS/portable/GCC/ARM_CM3/port.o ./ThirdParty/FreeRTOS/portable/GCC/ARM_CM3/port.su

.PHONY: clean-ThirdParty-2f-FreeRTOS-2f-portable-2f-GCC-2f-ARM_CM3

