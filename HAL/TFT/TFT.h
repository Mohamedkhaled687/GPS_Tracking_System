/******************************************************************************
 *
 * Module: TFT
 *
 * File Name: TFT.h
 *
 * Description: Header file for the TFT driver
 *
 * Author: Ahmed Mustafa
 *
 ******************************************************************************/
#ifndef _TFT_H_
#define _TFT_H_
#include <stdint.h>
#include "../../LIB/std_types.h"

// USED UP PORTS
//PortB 4 5 6 7
//PortE 1 2 3

//TFT COMMANDS
#define TFT_SWRESET     0x01 //Software Reset
#define TFT_SLPOUT      0x11 //Sleep Out (Wake up display)
#define TFT_DISPON      0x29 //Display On
#define TFT_CASET       0x2A //Set Column Address Range
#define TFT_RASET       0x2B //Set Row Address Range
#define TFT_RAMWR       0x2C //Write to display RAM
#define TFT_MADCTL      0x36 //Memory Access Control
#define TFT_COLMOD      0x3A //Interface pixel format (e.g. RGB565)

/**
 * PINS CONNECTIONS AND PORT
 */

#define TFT_PORT_PA   GPIO_PORTA     //TFT PORT A
#define TFT_PORT_PD   GPIO_PORTD     //TFT PORT A
#define TFT_CLK_Pin      PIN_2          //TFT CLK PIN
#define TFT_RST_Pin      PIN_3          //TFT RESET PIN
#define TFT_DC_Pin       PIN_4          //TFT DATA/COMMAND PIN PB8
#define TFT_MOSI_Pin     PIN_5          //TFT RECIEVER PIN
#define TFT_CS_Pin       PIN_7          //Activate Chip PIN
#define TFT_BL_Pin       PIN_6          //Activate BL Pin (has to be set to 1 always)

/**
 * MACROS FOR CLEARING AND SETTING PCTL TO SSI
 */
#define PORTA_PIN5_CLEARMASK ~(0xF << 20)
#define PORTA_PIN5_SSI0TX (0x2 << 20)
#define PORTA_PIN2_CLEARMASK ~(0xF << 8)
#define PORTA_PIN2_SSI0CLK (0x2 << 8)
#define PORTD_PIN7_CLEARMASK ~(0xF << 28)


/*          PROTOTYPES           */

/*
 * Initialize TFT with Pins
 */
void TFT_init(void);  // Initialize Port A for TFT pin configuration

/**There are 2 Types of DC
 * 0 -----------> Command
 * 1 -----------> Data
 * You set to 0 and send your data and the device will consider them commands
 * Then you set to 1 and send your data and it will be read as Data
 */
/** PIN CONTROL FUNCTIONS FOR DC, CS, RST */

/**
 * DATA MODE
 */
void Set_DC_High(void);   // Set DC pin high (Data mode)

/**
 * COMMAND MODE
 */
void Set_DC_Low(void);    // Set DC pin low (Command mode)
/**
 * DEACTIVATE CHIP
 */
void Set_CS_High(void);   // Set CS pin high (Deactivate chip)
/**
 * ACTIVATE CHIP
 */
void Set_CS_Low(void);    // Set CS pin low (Activate chip)

/**
 * RESET OFF
 */
void Set_RST_High(void);  // Set RST pin high (Reset off)

/**
 * RESET ON
 */

void Set_RST_Low(void);   // Set RST pin low (Reset on)

// SPI control functions for communication with TFT
void TFT_writeCommand(uint8 *command);  // Send command to TFT
void TFT_writeData(uint8 *data);       // Send data to TFT
#endif