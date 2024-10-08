################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ThirdParty/FreeRTOS/MemMang/heap_4.c 

OBJS += \
./ThirdParty/FreeRTOS/MemMang/heap_4.o 

C_DEPS += \
./ThirdParty/FreeRTOS/MemMang/heap_4.d 


# Each subdirectory must supply rules for building sources it contributes
ThirdParty/FreeRTOS/MemMang/%.o ThirdParty/FreeRTOS/MemMang/%.su ThirdParty/FreeRTOS/MemMang/%.cyclo: ../ThirdParty/FreeRTOS/MemMang/%.c ThirdParty/FreeRTOS/MemMang/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103x6 -c -I"C:/Users/Lenovo/STM32CubeIDE/RTOS_Workspace/STM32F103_FreeRTOS/ThirdParty/SEGGER/SEGGER" -I"C:/Users/Lenovo/STM32CubeIDE/RTOS_Workspace/STM32F103_FreeRTOS/ThirdParty/SEGGER/Config" -I"C:/Users/Lenovo/STM32CubeIDE/RTOS_Workspace/STM32F103_FreeRTOS/ThirdParty/SEGGER/OS" -I../Core/Inc -I"C:/Users/Lenovo/STM32CubeIDE/RTOS_Workspace/STM32F103_FreeRTOS/ThirdParty/FreeRTOS" -I"C:/Users/Lenovo/STM32CubeIDE/RTOS_Workspace/STM32F103_FreeRTOS/ThirdParty/FreeRTOS/portable/GCC/ARM_CM3" -I"C:/Users/Lenovo/STM32CubeIDE/RTOS_Workspace/STM32F103_FreeRTOS/ThirdParty/FreeRTOS/include" -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Lenovo/STM32CubeIDE/RTOS_Workspace/STM32F103C8_RTOS/ThirdParty/FreeRTOS/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-ThirdParty-2f-FreeRTOS-2f-MemMang

clean-ThirdParty-2f-FreeRTOS-2f-MemMang:
	-$(RM) ./ThirdParty/FreeRTOS/MemMang/heap_4.cyclo ./ThirdParty/FreeRTOS/MemMang/heap_4.d ./ThirdParty/FreeRTOS/MemMang/heap_4.o ./ThirdParty/FreeRTOS/MemMang/heap_4.su

.PHONY: clean-ThirdParty-2f-FreeRTOS-2f-MemMang

