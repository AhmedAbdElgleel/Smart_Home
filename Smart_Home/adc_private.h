/*
 ================================================================================================================================
 * File Name   : adc_private.h
 *
 * Module Name : adc_private
 *
 * Created On  : Oct 13, 2023
 *
 * Author Name : Ahmed Abd Elgleel
 ================================================================================================================================
 */
#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_
#include "std_types.h"
/*******************************************************************************
 *                  Registers type structure declaration                       *
 *******************************************************************************/

/* ADC  Register ADMUX type structure declarations */
typedef union
{
	uint8 Byte;
	struct
	{
		uint8 MUX0_BIT :1;
		uint8 MUX1_BIT :1;
		uint8 MUX2_BIT :1;
		uint8 MUX3_BIT :1;
		uint8 MUX4_BIT :1;
		uint8 ADLAR_BIT:1;
		uint8 REFS0_BIT:1;
		uint8 REFS1_BIT:1;
	}Bits;
}ADC_ADMUX_Reg_Type;

/* ADC  Register ADCSRA type structure declarations */
typedef union
{
	uint8 Byte;
	struct
	{
		uint8 ADPS0_BIT :1;
		uint8 ADPS1_BIT :1;
		uint8 ADPS2_BIT :1;
		uint8 ADIE_BIT  :1;
		uint8 ADIF_BIT  :1;
		uint8 ADATE_BIT :1;
		uint8 ADSC_BIT  :1;
		uint8 ADEN_BIT  :1;
	}Bits;
}ADC_ADCSRA_Reg_Type;

/* ADC  Register ADC(ADCH,ADCL) type structure declarations */
typedef union
{
	uint16 Two_Bytes;
	struct
	{
		uint8 ADC0_BIT :1;
		uint8 ADC1_BIT :1;
		uint8 ADC2_BIT :1;
		uint8 ADC3_BIT :1;
		uint8 ADC4_BIT :1;
		uint8 ADC5_BIT :1;
		uint8 ADC6_BIT :1;
		uint8 ADC7_BIT :1;
		uint8 ADC8_BIT :1;
		uint8 ACD9_BIT :1;
		uint8 	   :1;
		uint8 	   :1;
		uint8 	   :1;
		uint8      :1;
		uint8 	   :1;
		uint8 	   :1;
	}Bits;
}ADC_Data_Reg_Type;

/*******************************************************************************
 * Registers definitions for each type struct in the memory mapped Registers   *
 *******************************************************************************/

/*ADC Data Register*/
#define ADC_ADC_REG  (*((volatile ADC_Data_Reg_Type * const)0x0024))

/*ADCSRA control and statue Register*/
#define ADC_ADCSRA_REG  (*((volatile ADC_ADCSRA_Reg_Type * const)0x0026))

/*ADMUX Register*/
#define ADC_ADMUX_REG   (*((volatile ADC_ADMUX_Reg_Type * const)0x0027))


#endif /* ADC_PRIVATE_H_ */
