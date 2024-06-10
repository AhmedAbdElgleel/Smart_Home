/******************************************************************************
 *
 * Module: Smoke Sensor
 *
 * File Name: Smoke_Sensor.h
 *
 * Description: Header file for MQ2 Smoke Detection Sensor
 *
 * Author: Ahmed Abdelgleel
 ******************************************************************************/

#ifndef SMOKE_SENSOR_H_
#define SMOKE_SENSOR_H_
#define DIGITAL_HIGH_STATE 1
#define DIGITAL_LOW_STATE 0
#include "std_types.h"  /* Include standard types header file */
#include "common_macros.h"

typedef enum
{
    ANALOG,  /* Enumeration value for analog mode */
    DIGITAL  /* Enumeration value for digital mode */
} smokeSensorMode;

typedef struct
{
    uint8 readingPinPort_ID;  /* Variable for reading pin port */
    uint8 readingPin_ID;      /* Variable for reading pin */
	smokeSensorMode sensorMode;  /* Variable for reading pin port */
} smokeSensorConfig;

/* Function declarations */
void smoke_sensor_init(const smokeSensorConfig * Config_Ptr);  /* Initialize smoke sensor */
uint8 smoke_sensor_read(const smokeSensorConfig * smokeSensorReadingConfig_Ptr);  /* Read smoke sensor value */

#endif /* SMOKE_SENSOR_H_ */
