# GPS Tracking System

## Overview
A robust GPS tracking system designed for embedded applications, featuring real-time location tracking, building proximity detection, and user interface capabilities. This system is built with a layered architecture following embedded systems best practices.

## Features
- Real-time GPS location tracking
- Building proximity detection and identification
- LCD display interface for user interaction
- Buzzer notifications for proximity alerts
- UART communication for GPS module interface
- GPIO control for peripheral management
- System timer management

## Project Architecture
The project follows a layered architecture pattern:

### Application Layer (App)
- Main application logic
- Building location management
- System initialization and control
- User interface handling

### Hardware Abstraction Layer (HAL)
- **GPS Module**: GPS data acquisition and parsing
- **LCD**: Display interface for user information
- **Buzzer**: Audio feedback system
- **PORTF**: Port configuration and management

### Microcontroller Abstraction Layer (MCAL)
- **UART**: Serial communication interface
- **SPI**: Serial Peripheral Interface
- **GPIO**: General Purpose Input/Output control
- **SysticTimer**: System timing management

## Hardware Requirements
- Microcontroller (MCU)
- GPS Module
- LCD Display
- Buzzer
- Required power supply
- Supporting components (resistors, capacitors, etc.)

## Software Requirements
- Embedded C compiler
- IDE supporting embedded development
- GPS parsing libraries
- UART communication libraries

## Project Structure
```
GPS_Tracking_System/
├── App/
│   ├── App.c
│   └── App.h
├── HAL/
│   ├── BUZZER/
│   ├── GPS/
│   ├── LCD/
│   └── PORTF/
└── MCAL/
    ├── SPI/
    ├── SysticTimer/
    ├── UART/
    └── GPIO/
```

## Setup and Installation
1. Clone the repository
2. Configure your development environment
3. Set up the required hardware connections
4. Compile the project
5. Flash the program to your microcontroller

## Usage
1. Power on the system
2. Wait for GPS module initialization
3. The system will automatically start tracking location
4. LCD will display current location and nearby buildings
5. Buzzer will alert when approaching predefined buildings

## Contributing
Contributions are welcome! Please feel free to submit a Pull Request.


## License
This project is licensed under the MIT License - see the LICENSE file for details.


