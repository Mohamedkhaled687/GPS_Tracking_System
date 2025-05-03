/******************************************************************************
 *
 * Module: TFT
 *
 * File Name: TFT.c
 *
 * Description: Source file for the TFT driver
 *
 * Author: Ahmed Mustafa
 *
 ******************************************************************************/

#include "TFT.h"
#include "../../MCAL/GPIO/GPIO.h"
#include "../../MCAL/SPI/SPI.h"
#include "../../LIB/std_types.h"

void TFT_init() {
    GPIO_Init(TFT_PORT_PA);
    GPIO_Init(TFT_PORT_PB);
    GPIO_Init(TFT_PORT_PC);

    GPIO_Pin_Init(TFT_PORT_PA, TFT_CLK_Pin);
    GPIO_Pin_Init(TFT_PORT_PA, TFT_MOSI_Pin);
    GPIO_Pin_Init(TFT_PORT_PA, TFT_RST_Pin);
    GPIO_Pin_Init(TFT_PORT_PC, TFT_DC_Pin);
    GPIO_Pin_Init(TFT_PORT_PB, TFT_CS_Pin);
    
    GPIO_setupPinMode(TFT_PORT_PA, TFT_CLK_Pin, Pull_down, PIN_OUTPUT);
    GPIO_setupPinMode(TFT_PORT_PA, TFT_MOSI_Pin, Pull_down, PIN_OUTPUT);
    GPIO_setupPinMode(TFT_PORT_PA, TFT_RST_Pin, Pull_down, PIN_OUTPUT);
    GPIO_setupPinMode(TFT_PORT_PC, TFT_DC_Pin, Pull_down, PIN_OUTPUT);
    GPIO_setupPinMode(TFT_PORT_PB, TFT_CS_Pin, Pull_down, PIN_OUTPUT);

    GPIO_PORTA_PCTL_R &= ~(0xF << 20); //Clear PortA Pin 5 PCTL
    GPIO_PORTA_PCTL_R |= (0x02 << 20); //Set PortA Pin 5 to SSI0Tx

    GPIO_PORTA_PCTL_R &= ~(0xF << 8); //Clear PortA Pin 2
    GPIO_PORTA_PCTL_R |= (0x2 << 8); //Set PortA Pin 2 to SSI0CLK

    GPIO_PORTC_PCTL_R &= ~(0xF << 28); //Clear PC7 PCTL to use as a normal input output


    SSI_Init(SSI_Module_0);
}
/**
 * DATA MODE
 */
void Set_DC_High() {
    GPIO_writePin(TFT_PORT_PC, TFT_DC_Pin, LOGIC_HIGH);
}

/**
 * COMMAND MODE
 */
void Set_DC_Low() {
    GPIO_writePin(TFT_PORT_PC, TFT_DC_Pin, LOGIC_LOW);
}

/**
 * DEACTIVATE CS
 */
void Set_CS_High() {
    GPIO_writePin(TFT_PORT_PB, TFT_CS_Pin, LOGIC_HIGH);
}

/**
 * ACTIVATE CS
 */
void Set_CS_Low() {
    GPIO_writePin(TFT_PORT_PB, TFT_CS_Pin, LOGIC_LOW);
}

/**
 * DEACTIVATE RESET
 */
void Set_RST_High() {
    GPIO_writePin(TFT_PORT_PA, TFT_RST_Pin, LOGIC_HIGH);
}

/**
 * ACTIVATE RESET
 */
void Set_RST_Low() {
    GPIO_writePin(TFT_PORT_PA, TFT_RST_Pin, LOGIC_LOW);
}

void TFT_writeCommand(uint8 *command) {
    Set_DC_Low();
    Set_CS_Low();
    SSI_Send(SSI_Module_0, command, 1);
    Set_CS_High();
}

void TFT_writeData(uint8 *data) {
    Set_DC_High();
    Set_CS_Low();
    SSI_Send(SSI_Module_0, data, 1);
    Set_CS_High();
}