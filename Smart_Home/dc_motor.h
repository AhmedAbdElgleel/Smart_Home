/*
 ================================================================================================================================
 * File Name   : dc_motor.h
 *
 * Module Name : dc_motor
 *
 * Created On  : Oct 13, 2023
 *
 * Author Name : Ahmed Abd Elgleel
 ================================================================================================================================
 */
#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "std_types.h"


/*******************************************************************************
 *                               Definition                                    *
 *******************************************************************************/
#define USE_FIRST_DC_MOTOR_WITH_CONTROL_SPEED
/*#define USE_SECOND_DC_MOTOR_WITH_CONTROL_SPEED*/


#define DC_MOTOR_PORT_ID 				PORTB_ID
#define FIRST_DC_MOTOR_IN1_PIN_ID 		PIN0_ID
#define FIRST_DC_MOTOR_IN2_PIN_ID 		PIN1_ID
#define SECOND_DC_MOTOR_IN3_PIN_ID 		PIN3_ID
#define SECOND_DC_MOTOR_IN4_PIN_ID 		PIN4_ID

#define DC_MOTOR_ENABLE_PORT_ID 		PORTB_ID
#define FIRST_DC_MOTOR_ENABLE_PIN_ID  	PIN3_ID
#define SECOND_DC_MOTOR_ENABLE_PIN_ID  	PIN3_ID

#define FIRST_DC_MOTOR		1
#define SECOND_DC_MOTOR		2

#define STOP_ROTATION			0
#define ROTATE_CLOCKWISE		1
#define ROTATE_ANTI_CLOCKWISE	2

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/* Description:
 * The Function to initialize the motors pin and setup the direction for the two motor
 * via using GPIO driver.
 */
void DcMOTOR_init(void);

/* Description:
 * The function that rotate the DC Motor clock wise ,anti-clockwise or stop the motor
 * In this Function we can control the speed via using PWM
 */
#if defined(USE_FIRST_DC_MOTOR_WITH_CONTROL_SPEED) ||defined( USE_SECOND_DC_MOTOR_WITH_CONTROL_SPEED)
void DCMOTOR_rotateWithControl(uint8 a_state,uint8 a_speed,uint8 a_motorNum );
#endif

/* Description:
 * The function that rotate the DC Motor clock wise ,anti-clockwise or stop the motor
 * In this Function we cannot control the speed where
 * in case clockwise and anti-clockwise the motor will rotate with max speed
 */
#if defined(USE_FIRST_DC_MOTOR_WITHOUT_CONTROL_SPEED) || defined( USE_SECOND_DC_MOTOR_WITHOUT_CONTROL_SPEED)
void DCMOTOR_rotateWithoutControl(uint8 a_state,uint8 a_motorNum)
#endif

#endif /* DC_MOTOR_H_ */
