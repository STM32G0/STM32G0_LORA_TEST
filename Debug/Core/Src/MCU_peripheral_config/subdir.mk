################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/MCU_peripheral_config/clock_config.c \
../Core/Src/MCU_peripheral_config/interrupt_config.c \
../Core/Src/MCU_peripheral_config/pin_config.c \
../Core/Src/MCU_peripheral_config/system_config.c \
../Core/Src/MCU_peripheral_config/uart_config.c 

OBJS += \
./Core/Src/MCU_peripheral_config/clock_config.o \
./Core/Src/MCU_peripheral_config/interrupt_config.o \
./Core/Src/MCU_peripheral_config/pin_config.o \
./Core/Src/MCU_peripheral_config/system_config.o \
./Core/Src/MCU_peripheral_config/uart_config.o 

C_DEPS += \
./Core/Src/MCU_peripheral_config/clock_config.d \
./Core/Src/MCU_peripheral_config/interrupt_config.d \
./Core/Src/MCU_peripheral_config/pin_config.d \
./Core/Src/MCU_peripheral_config/system_config.d \
./Core/Src/MCU_peripheral_config/uart_config.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/MCU_peripheral_config/%.o Core/Src/MCU_peripheral_config/%.su: ../Core/Src/MCU_peripheral_config/%.c Core/Src/MCU_peripheral_config/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G071xx -c -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc/MCU_peripheral_config -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-MCU_peripheral_config

clean-Core-2f-Src-2f-MCU_peripheral_config:
	-$(RM) ./Core/Src/MCU_peripheral_config/clock_config.d ./Core/Src/MCU_peripheral_config/clock_config.o ./Core/Src/MCU_peripheral_config/clock_config.su ./Core/Src/MCU_peripheral_config/interrupt_config.d ./Core/Src/MCU_peripheral_config/interrupt_config.o ./Core/Src/MCU_peripheral_config/interrupt_config.su ./Core/Src/MCU_peripheral_config/pin_config.d ./Core/Src/MCU_peripheral_config/pin_config.o ./Core/Src/MCU_peripheral_config/pin_config.su ./Core/Src/MCU_peripheral_config/system_config.d ./Core/Src/MCU_peripheral_config/system_config.o ./Core/Src/MCU_peripheral_config/system_config.su ./Core/Src/MCU_peripheral_config/uart_config.d ./Core/Src/MCU_peripheral_config/uart_config.o ./Core/Src/MCU_peripheral_config/uart_config.su

.PHONY: clean-Core-2f-Src-2f-MCU_peripheral_config

