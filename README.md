# Smart Home Project

## Overview

Welcome to the Smart Home Project! This project aims to enhance home safety and comfort through the integration of two sub-systems: a fire emergency system and a smart room temperature control system. By leveraging sensors, actuators, and an embedded control unit (ECU), our system provides a comprehensive solution for fire detection and temperature management.

## Real Time Hardware

[Click_Here](https://drive.google.com/file/d/1GV_VvAUBhk1NinG84aoPqFBGor-79fjs/view?t=3)


## Sub-Systems

### 1. Fire Emergency System

The Fire Emergency System is designed to detect fire incidents and take immediate action to mitigate the risk. This system includes:

- **Flame Sensor**: Detects the presence of fire.
- **Smoke Sensor**: Detects the presence of smoke.
- **Water Pump**: Activates to extinguish the fire.
- **Buzzer**: Sounds an alarm to alert occupants of the fire.

#### Functionality

1. **Fire Detection**: The flame sensor and smoke sensor continuously monitor for signs of fire.
2. **Interrupt Signal**: Upon detecting fire or smoke, the sensors send interrupt signals to the ECU.
3. **Emergency Response**: The ECU processes the interrupt signals and activates the water pump.
4. **Fire Extinguishing**: The water pump operates until the sensors detect that the fire has been extinguished and there is no smoke.
5. **Alarm Activation**: Simultaneously, the buzzer is activated to alert the occupants.

### 2. Smart Room Temperature Control System

The Smart Room Temperature Control System ensures a comfortable living environment by dynamically adjusting the speed of a fan based on the room temperature. This system includes:

- **Temperature Sensor**: Measures the current room temperature.
- **Fan**: Adjusts its speed according to the temperature.

#### Functionality

1. **Temperature Monitoring**: The temperature sensor continuously measures the room temperature.
2. **Speed Control**: The ECU adjusts the speed of the fan based on the temperature readings. As the temperature increases, the fan speed increases proportionally to maintain a comfortable room environment.

## Components

- **ATmega32 Microcontroller (ECU)**: Central unit that processes signals from the sensors and controls the actuators (water pump, buzzer, and fan).
- **Flame Sensor**: Detects fire and sends an interrupt signal to the ECU.
- **Smoke Sensor**: Detects smoke and sends an interrupt signal to the ECU.
- **Water Pump**: Activates to spray water and extinguish the fire.
- **Buzzer**: Sounds an alarm when a fire or smoke is detected.
- **Temperature Sensor**: Measures room temperature.
- **Fan**: Adjusts speed based on the room temperature.

## Installation and Setup

1. **Hardware Connections**:
   - Connect the flame sensor and smoke sensor to the designated input pins on the ATmega32 microcontroller.
   - Connect the water pump and buzzer to the output pins on the ATmega32 microcontroller.
   - Connect the temperature sensor to the input pin on the ATmega32 microcontroller.
   - Connect the fan to the output pin on the ATmega32 microcontroller.

2. **Software Configuration**:
   - Load the provided firmware onto the ATmega32 microcontroller.
   - Ensure that the sensor calibration values are correctly set in the firmware.

3. **Testing**:
   - Simulate a fire scenario to ensure that the flame sensor, smoke sensor, water pump, and buzzer are working correctly.
   - Adjust the room temperature to verify that the fan speed changes appropriately.

## Usage

- **Fire Emergency System**: This system operates automatically. In the event of a fire, it will activate without any user intervention.
- **Smart Room Temperature Control**: This system also operates automatically, adjusting the fan speed based on the current room temperature.

## Maintenance

- **Regularly test the flame sensor, smoke sensor, and water pump to ensure they are functioning correctly**.
- **Calibrate the temperature sensor periodically to maintain accurate temperature readings**.
- **Ensure that the fan and buzzer are in good working condition**.

## Troubleshooting

- **If the fire emergency system does not activate**:
  - Check the connection between the flame sensor, smoke sensor, and the ATmega32 microcontroller.
  - Verify that the water pump and buzzer are properly connected and powered.
  
- **If the fan does not adjust speed according to the temperature**:
  - Ensure the temperature sensor is correctly connected and functioning.
  - Verify that the fan control logic in the firmware is working as expected.

---

**Contact Information**: For further assistance, please send a message to me via LinkedIn: [Ahmed Abdelgleel](https://www.linkedin.com/in/ahmed-abdelgleel-95a675252/)
