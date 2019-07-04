################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Gen5/Gen5_comms.c \
../Src/Gen5/Gen5_init.c \
../Src/Gen5/spi1_drivers.c 

OBJS += \
./Src/Gen5/Gen5_comms.o \
./Src/Gen5/Gen5_init.o \
./Src/Gen5/spi1_drivers.o 

C_DEPS += \
./Src/Gen5/Gen5_comms.d \
./Src/Gen5/Gen5_init.d \
./Src/Gen5/spi1_drivers.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Gen5/%.o: ../Src/Gen5/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DSTM32F410Rx -DUSE_HAL_DRIVER -DUSE_FULL_LL_DRIVER -I"E:/embedded/e_GES/Inc" -I"E:/embedded/e_GES/Drivers/STM32F4xx_HAL_Driver/Inc" -I"E:/embedded/e_GES/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"E:/embedded/e_GES/Drivers/CMSIS/Include" -I"E:/embedded/e_GES/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


