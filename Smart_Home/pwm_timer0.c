/*
 ================================================================================================================================
 * File Name   : pwm_timer0.c
 *
 * Module Name : PWM
 *
 * Description: Source file for the AVR PWM-Timer0 driver
 *
 * Created On  : Oct 13, 2023
 *
 * Author Name : Ahmed Abd Elgleel
 ================================================================================================================================
 */

#include "pwm_timer0.h"
#include "gpio_interface.h"
#include "pwm_timer0_private.h"

/*
 * Description :
 * Initialize the PWM module by:
 * 1. Trigger Timer0 with PWM Mode.
 * 2. Setup the PWM mode with Non-Inverting.
 * 3. Setup the prescaler with F_CPU/8
 * 4. Setup the compare value based on the required input duty cycle
 * 5. Setup the direction for OC0 as output pin
 */
void PWM_Timer0_Start(uint8 duty_cycle)
{
	/* Timer0 initial value */
	TIMER0_TCNT0_REG.Byte=0;

	/* Set Compare value */
	TIMER0_OCR0_REG.Byte  = ((uint32)(duty_cycle* 255) / 100);

	/*
	 * Configure Timer0 control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	TIMER0_TCCR0_REG.Bits.WGM00_BIT=1;
	TIMER0_TCCR0_REG.Bits.WGM01_BIT=1;
	TIMER0_TCCR0_REG.Bits.COM01_BIT=1;
	TIMER0_TCCR0_REG.Bits.CS00_BIT=1;

	/* Configure PB3/ OC0 as output pin --> pin where the PWM signal is generated from Timer0 */
	GPIO_setupPinDirection(TIMER0_OCO_PORT_ID,TIMER0_OCO_PIN_ID,PIN_OUTPUT);
}



