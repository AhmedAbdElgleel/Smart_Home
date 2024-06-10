/*
 ================================================================================================================================
 * File Name   : water_pumb.h
 *
 * Module Name : water_pumb
 *
 * Author Name : Ahmed Abdelgleel
 ================================================================================================================================
 */
#ifndef WATER_PUMB_H_
#define WATER_PUMB_H_

#include "std_types.h"


/*******************************************************************************
 *                               Definition                                    *
 *******************************************************************************/


#define WATER_PUMB_PORT_ID 		PORTC_ID
#define WATER_PUMB_PIN_ID  	    PIN4_ID

#define STOP_ROTATION					0
#define START_ROTATION					1

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/* Description:
 * The Function to initialize the Pumb pin and setup the direction for the Pumb
 * via using GPIO driver.
 */
void Pumb_init(void);

/* Description:
 * The function that rotate the pumb or stop it
 */
void pumb_rotateControl(uint8 a_state);

#endif /* WATER_PUMB_H_ */
