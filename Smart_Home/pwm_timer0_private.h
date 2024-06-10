/*
 ================================================================================================================================
 * File Name   : pwm_timer0_private.h
 *
 * Module Name : pwm_timer0_private
 *
 * Created On  : Oct 13, 2023
 *
 * Author Name : Ahmed Abd Elgleel
 ================================================================================================================================
 */
#ifndef PWM_TIMER0_PRIVATE_H_
#define PWM_TIMER0_PRIVATE_H_
#include "std_types.h"
/*******************************************************************************
 *                  Registers type structure declaration                       *
 *******************************************************************************/

/* TIMER0 TCNT0  Register type structure declarations */
typedef union
{
	uint8 Byte;
	struct
	{
		uint8 BIT0:1;
		uint8 BIT1:1;
		uint8 BIT2:1;
		uint8 BIT3:1;
		uint8 BIT4:1;
		uint8 BIT5:1;
		uint8 BIT6:1;
		uint8 BIT7:1;
	}Bits;
}TIMER0_TCNT0_Reg_Type;

/* TIMER0 OCR0  Register type structure declarations */
typedef union
{
	uint8 Byte;
	struct
	{
		uint8 BIT0:1;
		uint8 BIT1:1;
		uint8 BIT2:1;
		uint8 BIT3:1;
		uint8 BIT4:1;
		uint8 BIT5:1;
		uint8 BIT6:1;
		uint8 BIT7:1;
	}Bits;
}TIMER0_OCR0_Reg_Type;

/* TIMER0 TCCR0 Register type structure declarations */
typedef union
{
	uint8 Byte;
	struct
	{
		uint8 CS00_BIT:1;
		uint8 CS01_BIT:1;
		uint8 CS02_BIT:1;
		uint8 WGM01_BIT:1;
		uint8 COM00_BIT:1;
		uint8 COM01_BIT:1;
		uint8 WGM00_BIT:1;
		uint8 FOC0_BIT:1;
	}Bits;
}TIMER0_TCCR0_Reg_Type;

/*******************************************************************************
 * Registers definitions for each type struct in the memory mapped Registers   *
 *******************************************************************************/

/*TIMER0 TCNT0  Register*/
#define TIMER0_TCNT0_REG  (*((volatile TIMER0_TCNT0_Reg_Type * const)0x0052))

/*TIMER0 TCCR0  Register*/
#define TIMER0_TCCR0_REG  (*((volatile TIMER0_TCCR0_Reg_Type * const)0x0053))

/*TIMER0 OCR0  Register*/
#define TIMER0_OCR0_REG  (*((volatile TIMER0_OCR0_Reg_Type * const)0x005C))


#endif /* PWM_TIMER0_PRIVATE_H_ */
