/******************************************************************************
 *
 * Module: Buzzer
 *
 * File Name: buzzer.h
 *
 * Description: header file for the buzzer driver
 *
 * Author: Ahmed Abdelgleel
 *******************************************************************************/
#ifndef BUZZER_H_
#define BUZZER_H_

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define BUZZER_PIN  PIN5_ID
#define BUZZER_PORT PORTC_ID

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
/*
 * Description :
 * A function to initialize the buzzer
 */
void Buzzer_init(void);

/*
 * Description :
 * A function to turn on the buzzer
 */
void Buzzer_on(void);

/*
 * Description :
 * A function to turn off the buzzer
 */
void Buzzer_off(void);

#endif /* BUZZER_H_ */
