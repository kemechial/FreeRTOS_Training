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
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I"C:/Users/Lenovo/STM32CubeIDE/RTOS_Workspace/STM32F401_TASK005_FreeRTOS_ISR/ThirdParty/SEGGER/Rec" -I"C:/Users/Lenovo/STM32CubeIDE/RTOS_Workspace/STM32F401_TASK005_FreeRTOS_ISR/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F" -I"C:/Users/Lenovo/STM32CubeIDE/RTOS_Workspace/STM32F401_TASK005_FreeRTOS_ISR/ThirdParty/SEGGER/OS" -I"C:/Users/Lenovo/STM32CubeIDE/RTOS_Workspace/STM32F401_TASK005_FreeRTOS_ISR/ThirdParty/FreeRTOS" -I"C:/Users/Lenovo/STM32CubeIDE/RTOS_Workspace/STM32F401_TASK005_FreeRTOS_ISR/ThirdParty/FreeRTOS/include" -I"C:/Users/Lenovo/STM32CubeIDE/RTOS_Workspace/STM32F401_TASK005_FreeRTOS_ISR/ThirdParty/SEGGER/SEGGER" -I"C:/Users/Lenovo/STM32CubeIDE/RTOS_Workspace/STM32F401_TASK005_FreeRTOS_ISR/ThirdParty/SEGGER/Config" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-ThirdParty-2f-FreeRTOS-2f-MemMang

clean-ThirdParty-2f-FreeRTOS-2f-MemMang:
	-$(RM) ./ThirdParty/FreeRTOS/MemMang/heap_4.cyclo ./ThirdParty/FreeRTOS/MemMang/heap_4.d ./ThirdParty/FreeRTOS/MemMang/heap_4.o ./ThirdParty/FreeRTOS/MemMang/heap_4.su

.PHONY: clean-ThirdParty-2f-FreeRTOS-2f-MemMang

