################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/G5Datagrams.c \
../Src/header.c \
../Src/init.c \
../Src/main.c \
../Src/path.c \
../Src/process_packet.c \
../Src/stm32f4xx_hal_msp.c \
../Src/stm32f4xx_it.c \
../Src/system_stm32f4xx.c \
../Src/uart_buffer.c \
../Src/uart_isr.c 

OBJS += \
./Src/G5Datagrams.o \
./Src/header.o \
./Src/init.o \
./Src/main.o \
./Src/path.o \
./Src/process_packet.o \
./Src/stm32f4xx_hal_msp.o \
./Src/stm32f4xx_it.o \
./Src/system_stm32f4xx.o \
./Src/uart_buffer.o \
./Src/uart_isr.o 

C_DEPS += \
./Src/G5Datagrams.d \
./Src/header.d \
./Src/init.d \
./Src/main.d \
./Src/path.d \
./Src/process_packet.d \
./Src/stm32f4xx_hal_msp.d \
./Src/stm32f4xx_it.d \
./Src/system_stm32f4xx.d \
./Src/uart_buffer.d \
./Src/uart_isr.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DSTM32F410Rx -DUSE_HAL_DRIVER -I"E:/embedded/e_GES/Inc" -I"E:/embedded/e_GES/Drivers/STM32F4xx_HAL_Driver/Inc" -I"E:/embedded/e_GES/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"E:/embedded/e_GES/Drivers/CMSIS/Include" -I"E:/embedded/e_GES/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


