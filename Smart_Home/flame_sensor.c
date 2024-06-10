/*
 ================================================================================================================================
 * File Name   : flame_sensor.c
 *
 * Module Name : flame_sensor
 *
 * Created On  : May 12, 2024
 *
 * Author Name : Ahmed Abdelgleel
 ================================================================================================================================
 */

#include<avr/io.h>
#include<avr/interrupt.h>
#include"std_types.h"
#include"flame_sensor.h"
void (*g_ptr2func)() = NULL_PTR;

void flame_init(){
    SREG |= (1<<7);        // enable global intrupt
    GICR|=(1<<INT2);      // enable INT2
    MCUCSR&=~(1<<ISC2);
}

void flame_setCallBack(void (*ptr2func)()){
	if(ptr2func != NULL_PTR){
		g_ptr2func = ptr2func;
	}

}

ISR(INT2_vect){
	if(g_ptr2func != NULL_PTR){
		g_ptr2func();
	}
}
