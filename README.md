# Arduino-Based Predictive Maintenance System for Industrial Motors

## Overview

This project presents an Arduino-based Predictive Maintenance System designed for industrial motor monitoring. The system continuously monitors motor operating conditions using temperature and vibration measurements to detect potential faults before they result in equipment failure.

The implementation demonstrates the fundamental concepts of predictive maintenance used in modern industries, where machine condition data is analyzed to identify abnormal behavior and reduce unexpected downtime.

The system provides real-time status indication through LEDs, an audible alarm, and motor control actions based on detected operating conditions.

---

## Features

* Real-time temperature monitoring using a TMP36 temperature sensor
* Vibration fault simulation using a push button
* Motor condition classification:

  * Healthy
  * Warning
  * Fault
* Visual status indication using LEDs
* Audible fault alarm using a buzzer
* Automatic motor shutdown during fault conditions
* Serial Monitor output for real-time diagnostics
* DC motor control through an L293D motor driver

---

## Hardware Components

| Component                | Quantity |
| ------------------------ | -------- |
| Arduino Uno R3           | 1        |
| TMP36 Temperature Sensor | 1        |
| Push Button              | 1        |
| L293D Motor Driver IC    | 1        |
| DC Motor                 | 1        |
| Piezo Buzzer             | 1        |
| Green LED                | 1        |
| Red LED                  | 1        |
| 220Ω Resistors           | 2        |
| Breadboard               | 1        |
| Jumper Wires             | Several  |

---

## System Operation

### Healthy Condition

* Temperature < 40°C
* No vibration detected

Actions:

* Green LED ON
* Motor Running
* Buzzer OFF

---

### Warning Condition

* Temperature between 40°C and 80°C

OR

* Vibration detected

Actions:

* Red LED ON
* Motor Running
* Buzzer OFF

---

### Fault Condition

* Temperature > 80°C

Actions:

* Red LED ON
* Buzzer ON
* Motor Stopped

---

## Pin Configuration

| Arduino Pin | Function                         |
| ----------- | -------------------------------- |
| A0          | TMP36 Temperature Sensor         |
| D7          | Vibration Simulation Push Button |
| D8          | Green LED                        |
| D9          | L293D Motor Control Input 4      |
| D11         | L293D Motor Control Input 3      |
| D12         | Red LED                          |
| D13         | Buzzer                           |

---

## Software Requirements

* Arduino IDE
* Tinkercad Circuits (for simulation)

---

## Simulation

The project was developed and tested using Tinkercad Circuits.

The TMP36 sensor is used to simulate motor temperature, while a push button is used to emulate vibration events because Tinkercad does not provide an SW-420 vibration sensor.

---

## Applications

* Industrial motor monitoring
* Predictive maintenance systems
* Manufacturing automation
* Equipment health monitoring
* Educational embedded systems projects

---

## Future Improvements

* Integration of a real vibration sensor (SW-420 or MPU6050)
* LCD/OLED status display
* IoT-based cloud monitoring
* Data logging and analytics
* Machine learning-based fault prediction
* Wireless monitoring using ESP32

---

## Author

RGPM RAMMANDALA 

Department of Electrical and Electronic Engineering

University of Jaffna

---

## License

This project is intended for educational and academic purposes.
