/*
 ================================================================================================================================
 * File Name   : water_pumb.c
 *
 * Module Name : water_pumb
 *
 * Author Name : Ahmed Abdelgleel
 ================================================================================================================================
 */
#include "water_pumb.h"
#include "gpio_interface.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/* Description:
 * The Function to initialize the Pumb pin and setup the direction for the Pumb
 * via using GPIO driver.
 */
void Pumb_init(void)
{

	/*define Enable pin of first motor as output pin*/
	GPIO_setupPinDirection(WATER_PUMB_PORT_ID, WATER_PUMB_PIN_ID, PIN_OUTPUT);

}


/* Description:
 * The function that rotate the pumb or stop it
 */
void pumb_rotateControl(uint8 a_state)
{
	if(STOP_ROTATION==a_state)
	{
		GPIO_writePin(WATER_PUMB_PORT_ID, WATER_PUMB_PIN_ID, LOGIC_LOW);
	}
	else if(START_ROTATION==a_state)
	{
		GPIO_writePin(WATER_PUMB_PORT_ID, WATER_PUMB_PIN_ID, LOGIC_HIGH);
	}

	else
	{
		/*Do Nothing*/
	}

}
