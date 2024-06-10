################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../adc.c \
../buzzer.c \
../dc_motor.c \
../flame_sensor.c \
../gpio.c \
../lcd.c \
../lm35_sensor.c \
../main.c \
../pwm_timer0.c \
../red_led.c \
../smoke_sensor.c \
../water_pumb.c 

OBJS += \
./adc.o \
./buzzer.o \
./dc_motor.o \
./flame_sensor.o \
./gpio.o \
./lcd.o \
./lm35_sensor.o \
./main.o \
./pwm_timer0.o \
./red_led.o \
./smoke_sensor.o \
./water_pumb.o 

C_DEPS += \
./adc.d \
./buzzer.d \
./dc_motor.d \
./flame_sensor.d \
./gpio.d \
./lcd.d \
./lm35_sensor.d \
./main.d \
./pwm_timer0.d \
./red_led.d \
./smoke_sensor.d \
./water_pumb.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


