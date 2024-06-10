/******************************************************************************
 *
 * Module: Smoke Sensor
 *
 * File Name: Smoke_Sensor.c
 *
 * Description: Source file for MQ2 Smoke Detection Sensor
 *
 * Author: Ahmed Abdelgleel
 ******************************************************************************/
#include "smoke_sensor.h"
#include "gpio_interface.h"
void smoke_sensor_init(const smokeSensorConfig * Config_Ptr)
{
	GPIO_setupPinDirection(Config_Ptr->readingPinPort_ID, Config_Ptr->readingPin_ID,PIN_INPUT);

}
uint8 smoke_sensor_read(const smokeSensorConfig * smokeSensorReadingConfig_Ptr)
{
	uint8 smokeSensorReading;
	smokeSensorReading = GPIO_readPin(smokeSensorReadingConfig_Ptr->readingPinPort_ID,smokeSensorReadingConfig_Ptr->readingPin_ID);
	return smokeSensorReading;
}
