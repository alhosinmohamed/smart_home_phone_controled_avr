################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Dio_Prog.c \
../Lcd_Prog.c \
../Stpr_Prog.c \
../UART_Prog.c \
../main.c 

OBJS += \
./Dio_Prog.o \
./Lcd_Prog.o \
./Stpr_Prog.o \
./UART_Prog.o \
./main.o 

C_DEPS += \
./Dio_Prog.d \
./Lcd_Prog.d \
./Stpr_Prog.d \
./UART_Prog.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


