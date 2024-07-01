# Smart Health Monitoring System

The Smart Health Monitoring System was built to measure the vital parameters of neonate which could effectively help doctors to interpret the disease quickly reducing the cost of costly equipments.

## Table of Contents

- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Requirements](#requirements)
- [Hardware Requirements](#hardware-requirements)
- [Circuit Diagram](#circuit-diagram)
- [Usage](#usage)
- [Features](#features)


## Prerequisities

Before you begin, ensure you have met the following requirements
- Arduino IDE 
```
# Use the below link to install Arduino IDE
https://www.arduino.cc/en/software
```

- ESP8266 Board (should be installed within Arduino IDE)
```
# Use the below link to walkthrough the installation process of ESP8266 board in Arduino IDE
https://www.instructables.com/Steps-to-Setup-Arduino-IDE-for-NODEMCU-ESP8266-WiF/
```

- Blynk IoT App (Both in mobile and web)
```
# Use the below link to walkthrough the installation process of Blynk IoT Application
https://iotcircuithub.com/blynk-iot-platform-setup-esp8266-esp32/
```

## Installation

Type or copy the below code in your terminal to pull the repo files to your computer 

```bash
# Clone the repository
git clone https://github.com/AL-MD-BILAL/Smart-Health-Monitoring-System.git

# Change directory to the Smart-Health-Monitoring-System directory
cd Smart-Health-Monitoring-System
```

## Requirements

The required libraries for working of the code are 
```
- Wire.h
- MAX30100_PulseOximeter.h
- ESP8266WiFi.h
- BlynkSimpleEsp8266.h
- WifiClient.h
- MPU6050.h

Note : All of the above mentional libraries should be installed inside Arduino IDE via Library Manager (Sketch > Include Library > Manage Libraries) or in the form of zip files.
```

## Hardware Requirements

The Hardware required for working of the code include
```
- ESP8266 Board
- MAX30100 sensor
- MPU6050 Sensor
- Breadboard
- Jumper Wires
```

## Circuit Diagram
![Circuit Diagram](https://www.electronicwings.com/storage/PlatformSection/TopicContent/486/description/MAX30100%20Interfacing%20with%20NodeMCU(0).png)


## Usage

To use the project follow the steps given below

```
1. Setup Arduino IDE with the prerequisites
2. Install the required libraries
3. Connect the hardware components using the above circuit diagram
4. Either Download the code and make the required changes as stated inside the code with the help or comments or copy paste the code in your Arduino IDE and make required changes
5. Compile and upload the code to ESP8266 using USB cable
6. Check the output in your serial monitor or Blynk IoT Application

Note : Make sure your mobile hotspot is turned on inorder to transmit the data from ESP8266 to your Blynk Iot Application 
```

## Features

The features of the project are as follows
- Continous Monitoring
- Cost Efficient
- Timely alerts via SMS or Email
- User friendly GUI 
