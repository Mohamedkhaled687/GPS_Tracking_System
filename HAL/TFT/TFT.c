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
#include "../MCAL/GPIO/GPIO.h"
#include "../MCAL/SPI/SPI.h"

void TFT_init() {
    GPIO_Init(TFT_PORT);
    

    GPIO_Pin_Init(TFT_PORT, TFT_DC_Pin);
    GPIO_Pin_Init(TFT_PORT, TFT_CS_Pin);
    GPIO_Pin_Init(TFT_PORT, TFT_RST_Pin);
    GPIO_Pin_Init(TFT_PORT, TFT_CLK_Pin);
    GPIO_Pin_Init(TFT_PORT, TFT_MOSI_Pin);
    GPIO_PORTA_PCTL_R |= 0x02;

    GPIO_setupPinMode(TFT_PORT, TFT_DC_Pin, Pull_down, PIN_OUTPUT);
    GPIO_setupPinMode(TFT_PORT, TFT_CS_Pin, Pull_down, PIN_OUTPUT);
    GPIO_setupPinMode(TFT_PORT, TFT_RST_Pin, Pull_down, PIN_OUTPUT);
    GPIO_setupPinMode(TFT_PORT, TFT_CLK_Pin, Pull_down, PIN_OUTPUT);
    GPIO_setupPinMode(TFT_PORT, TFT_MOSI_Pin, Pull_down, PIN_OUTPUT);

    SSI_Init(SSI0);
}
/**
 * DATA MODE
 */
void Set_DC_High() {
    GPIO_writePin(TFT_PORT, TFT_DC_Pin, LOGIC_HIGH);
}

/**
 * COMMAND MODE
 */
void Set_DC_Low() {
    GPIO_writePin(TFT_PORT, TFT_DC_Pin, LOGIC_LOW);
}

/**
 * DEACTIVATE CS
 */
void Set_CS_High() {
    GPIO_writePin(TFT_PORT, TFT_CS_Pin, LOGIC_HIGH);
}

/**
 * ACTIVATE CS
 */
void Set_CS_Low() {
    GPIO_writePin(TFT_PORT, TFT_CS_Pin, LOGIC_LOW);
}

/**
 * DEACTIVATE RESET
 */
void Set_RST_High() {
    GPIO_writePin(TFT_PORT, TFT_RST_Pin, LOGIC_HIGH);
}

/**
 * ACTIVATE RESET
 */
void Set_RST_Low() {
    GPIO_writePin(TFT_PORT, TFT_RST_Pin, LOGIC_LOW);
}

void TFT_writeCommand(uint8_t command) {
    Set_DC_Low();
    Set_CS_Low();
    SSI_Send(SSI0, command, 1);
    Set_CS_High();
}

void TFT_writeData(uint8_t data) {
    Set_DC_High();
    Set_CS_Low();
    SSI_Send(SSI0, data, 1);
    Set_CS_High();
}