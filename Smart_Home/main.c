/*
 ================================================================================================================================
 * File Name   : main.c
 *
 * Description : Smart Home System
 *
 * Author Name : Ahmed Abdelgleel
 ================================================================================================================================
 */

#include "adc_interface.h"
#include "lm35_sensor.h"
#include "dc_motor.h"
#include "Internal_mapping_register_private.h" /* To use the SREG Register */
#include "smoke_sensor.h"
#include <util/delay.h>
#include "flame_sensor.h"
#include "water_pumb.h"
#include "buzzer.h"
#include "red_led.h"
#include "lcd.h"
#include <avr/io.h>

#define DEVELOPMENT_MODE 0
#define PRODUCTION_MODE  1
#define MODE DEVELOPMENT_MODE

#define AUTO 0
#define USER 1
#define PROBLEM 1
#define OKEY 0

uint8 g_flameFlag = OKEY;
uint8 g_smokeFlag = OKEY;
uint8 g_bluetooth = '\0';
uint8 g_mode_LM = AUTO;
uint8 g_mode_LDR = AUTO;
uint8 *displayString[2];

#define FAN_OFF    '0'
#define FAN_ON_25  '1'
#define FAN_ON_50  '2'
#define FAN_ON_75  '3'
#define FAN_ON_100 '4'

#define SEND_TEMP  '5'
#define LED_ON     '6'
#define LED_OFF    '7'
#define FAN_AUTO   '8'
#define LED_AUTO   '9'

void flame_callBack();

int main(void) {
	uint8 temp;
	uint8 fan1State;
	uint8 ldr_read;
	ADC_ConfigType ADC_Configurations = {INTERNAL_VOLT, F_CPU_128};

	/* Enable interrupts by setting I-bit */
	SREG_REG.Bits.I_Bit = 1;

	RED_LED_init();

	/* Initialize ADC driver */
	ADC_init(&ADC_Configurations);

	/* Initialize Motor driver */
	DcMOTOR_init();

	/* Init Smoke sensor */
	smokeSensorConfig smoke_conf = {3, 7, DIGITAL};
	smoke_sensor_init(&smoke_conf);

	flame_init();
	flame_setCallBack(flame_callBack);

	Buzzer_init();
	Pumb_init();

	/* Initialize LCD driver */
	LCD_init();
	LCD_clearScreen();

	while (1) {
		/* Get the ADC values */
		temp = LM35_getTemperature();
		ldr_read = ADC_readChannel(7);
		if ((smoke_sensor_read(&smoke_conf) == DIGITAL_LOW_STATE)||(g_flameFlag == PROBLEM)) {
			Buzzer_on();
			pumb_rotateControl(START_ROTATION);
			LCD_displayStringRowColumn(1, 0, "!DANGER DETECTED!");
			while((!(PIND & (1<<PD7))) ||(PINB & (1<<PB2))){} // wait until switch is released
			g_smokeFlag = OKEY;
			g_flameFlag = OKEY;

		}
		if ((smoke_sensor_read(&smoke_conf) == DIGITAL_HIGH_STATE)&&(g_flameFlag == OKEY))
		{
			Buzzer_off();
			pumb_rotateControl(STOP_ROTATION);
			LCD_displayStringRowColumn(1, 0, "!SAFETY DETECTED!");
		}




		/*********************************************************************************
		 * Control The Fan
		 *********************************************************************************/
		/* Control the duty cycle of the output PWM signal (Fan Speed) based on the temperature value */
		if (temp >= 120) {
			/* Rotates the motor with 100% from its speed */
			DCMOTOR_rotateWithControl(ROTATE_CLOCKWISE, 100, FIRST_DC_MOTOR);
			fan1State = ROTATE_CLOCKWISE;
		} else if (temp >= 90) {
			/* Rotates the motor with 75% from its speed */
			DCMOTOR_rotateWithControl(ROTATE_CLOCKWISE, 75, FIRST_DC_MOTOR);
			fan1State = ROTATE_CLOCKWISE;
		} else if (temp >= 60) {
			/* Rotates the motor with 50% from its speed */
			DCMOTOR_rotateWithControl(ROTATE_CLOCKWISE, 50, FIRST_DC_MOTOR);
			fan1State = ROTATE_CLOCKWISE;
		} else if (temp >= 30) {
			/* Rotates the motor with 25% from its speed */
			DCMOTOR_rotateWithControl(ROTATE_CLOCKWISE, 25, FIRST_DC_MOTOR);
			fan1State = ROTATE_CLOCKWISE;
		} else {
			/* Stop the motor */
			DCMOTOR_rotateWithControl(STOP_ROTATION, 0, FIRST_DC_MOTOR);
			fan1State = STOP_ROTATION;
		}

		if (ldr_read > 150) {
			RED_LED_on();
		} else {
			RED_LED_off();
		}

#if MODE == DEVELOPMENT_MODE
		/* Display the temperature and FAN state */
		if (fan1State == STOP_ROTATION) {
			LCD_moveCursor(0, 0);
			LCD_displayString("FAN is OFF");
		} else {
			LCD_moveCursor(0, 0);
			LCD_displayString("FAN is ON ");
		}

		/* Display the temperature value every time at same position */
		LCD_moveCursor(0, 11);
		if (temp >= 100) {
			LCD_intgerToString(temp);
		} else {
			LCD_intgerToString(temp);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}
		/* Display this string "Temp =   C" only one time on LCD at the second row */
		LCD_moveCursor(0, 14);
		LCD_displayString("C");
#endif
	}
}

void flame_callBack()
{
	g_flameFlag = PROBLEM;
}
