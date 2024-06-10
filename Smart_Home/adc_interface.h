/*
 ================================================================================================================================
 * File Name   : adc_interface.h
 *
 * Module Name : adc_interface
 *
 * Created On  : Oct 13, 2023
 *
 * Author Name : Ahmed Abd Elgleel
 ================================================================================================================================
 */
#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include"std_types.h"

/*******************************************************************************
 *                              	Definition		                           *
 *******************************************************************************/
#define USE_ADC_IN_INTERRUPT_MODE		FALSE

#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56
/*******************************************************************************
 *                              	   ENUMS			                       *
 *******************************************************************************/

/* an enum to choose our reference voltage, use it with ADMUX*/
typedef enum
{
	AREF_VOLT=0,AVCC_VOLT=64,RESERVED,INTERNAL_VOLT=192
}ADC_ReferenceVolatge;

/*enum to Choose ADC frequency (prescaler) to make it between 50kHz~200kHz as Fadc = Fcpu / N */
typedef enum
{
	F_CPU_2,F_CPU_2_AGAIN,F_CPU_4,F_CPU_8,F_CPU_16,F_CPU_32,F_CPU_64,F_CPU_128
}ADC_Prescaler;


/*******************************************************************************
 *                             Structures & Union			                   *
 *******************************************************************************/

/* a structure to use it to configure our ADC with function ADC_init*/
typedef struct
{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;


#if USE_ADC_IN_INTERRUPT_MODE

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/
/* Extern Public global variables to be used by other modules */
extern volatile uint16 g_adcResult;
#endif

/*******************************************************************************
 *                             Functions Prototype			                   *
 *******************************************************************************/

/* Description :
 * Function to initiate the ADC module
 * 1. Setup the ADC reference voltage.
 * 2. Setup the ADC prescaler.
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);

#if(USE_ADC_IN_INTERRUPT_MODE==FALSE)
/* Description :
 * Function to read the value of certain channel
 * It is Synchronous Function
 */
uint16 ADC_readChannel(uint8 channel_num);
#else
/* Description :
 * Function to Start  the value of certain channel
 * It is ASynchronous Function
 */
void ADC_readChannel(uint8 channel_num);
#endif
#endif /* ADC_INTERFACE_H_ */
