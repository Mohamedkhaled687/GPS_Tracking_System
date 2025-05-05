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
#include "../../MCAL/SSI/SSI.h"
#include "../../LIB/std_types.h"

void TFT_init() {
    SSI_Init(SSI_MODULE_0, SSI0);

    GPIO_Init(TFT_PORT_PA);
    GPIO_Init(TFT_PORT_PD);

    GPIO_Pin_Init(TFT_PORT_PA, TFT_RST_Pin);
    GPIO_Pin_Init(TFT_PORT_PA, TFT_DC_Pin);
    GPIO_Pin_Init(TFT_PORT_PD, TFT_CS_Pin);
    GPIO_Pin_Init(TFT_PORT_PD, TFT_BL_Pin);
    
    GPIO_setupPinMode(TFT_PORT_PA, TFT_RST_Pin, Pull_down, PIN_OUTPUT);
    GPIO_setupPinMode(TFT_PORT_PA, TFT_DC_Pin, Pull_down, PIN_OUTPUT);
    GPIO_setupPinMode(TFT_PORT_PD, TFT_CS_Pin, Pull_down, PIN_OUTPUT);
    GPIO_setupPinMode(TFT_PORT_PD, TFT_BL_Pin, Pull_down, PIN_OUTPUT);

    
}
/**
 * DATA MODE
 */
void Set_DC_High() {
    GPIO_writePin(TFT_PORT_PA, TFT_DC_Pin, LOGIC_HIGH);
}

/**
 * COMMAND MODE
 */
void Set_DC_Low() {
    GPIO_writePin(TFT_PORT_PA, TFT_DC_Pin, LOGIC_LOW);
}

/**
 * DEACTIVATE CS
 */
void Set_CS_High() {
    GPIO_writePin(TFT_PORT_PD, TFT_CS_Pin, LOGIC_HIGH);
}

/**
 * ACTIVATE CS
 */
void Set_CS_Low() {
    GPIO_writePin(TFT_PORT_PD, TFT_CS_Pin, LOGIC_LOW);
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
    SSI_Send(command);
    Set_CS_High();
}

void TFT_writeData(uint8 *data) {
    Set_DC_High();
    Set_CS_Low();
    SSI_Send(SSI_Module_0, data, 1);
    Set_CS_High();
}