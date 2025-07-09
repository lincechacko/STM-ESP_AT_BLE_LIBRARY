################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/BOARD/bsp.c 

OBJS += \
./Drivers/BSP/BOARD/bsp.o 

C_DEPS += \
./Drivers/BSP/BOARD/bsp.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/BOARD/%.o Drivers/BSP/BOARD/%.su Drivers/BSP/BOARD/%.cyclo: ../Drivers/BSP/BOARD/%.c Drivers/BSP/BOARD/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Lince/STM32CubeIDE/workspace_1.19.0/STM-ESP_AT_BLE_LIBRARY/Drivers/BSP/BOARD" -I"C:/Users/Lince/STM32CubeIDE/workspace_1.19.0/STM-ESP_AT_BLE_LIBRARY/Drivers/BSP/ESP_COMM" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-BOARD

clean-Drivers-2f-BSP-2f-BOARD:
	-$(RM) ./Drivers/BSP/BOARD/bsp.cyclo ./Drivers/BSP/BOARD/bsp.d ./Drivers/BSP/BOARD/bsp.o ./Drivers/BSP/BOARD/bsp.su

.PHONY: clean-Drivers-2f-BSP-2f-BOARD

