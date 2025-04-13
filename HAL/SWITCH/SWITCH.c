/******************************************************************************
 *
 * Module: SWITCH
 *
 * File Name : SWITCH.c
 *
 * Description: Source File for Tiva C SWITCH Driver
 *
 * Author: Mohamed Khaled
 *
 *******************************************************************************/

#include "SWITCH.h"

/*
 * Description :
 * Initialize the SWITCH Module.
 */

void SWITCH_Init(void)
{
    GPIO_Init(SWITCH_PORT);           // give the clock to the GPIO
    GPIO_Pin_Init(SWITCH_PORT, SW_1); // Initialize the switch 1 pin as input
    GPIO_Pin_Init(SWITCH_PORT, SW_2); // Initialize the switch 2 pin as input

    GPIO_setupPinMode(SWITCH_PORT, SW_1, Pull_up, PIN_INPUT); // Set the switch 1 pin as input with pull-up resistor
    GPIO_setupPinMode(SWITCH_PORT, SW_2, Pull_up, PIN_INPUT); // Set the switch 2 pin as input with pull-up resistor

    GPIO_writePin(SWITCH_PORT, SW_1, LOGIC_HIGH); // Set the switch 1 pin to high (not pressed)
    GPIO_writePin(SWITCH_PORT, SW_2, LOGIC_HIGH); // Set the switch 2 pin to high (not pressed)
}

/*
 * Description :
 * Read the state of the specified switch.
 */

uint8 SWITCH_Read(uint8 switch_num)
{
    uint8 value = 0;
    switch (switch_num)
    {
    case SW_1:
        value = GPIO_readPin(SWITCH_PORT, SW_1); // Read the state of switch 1
        break;
    case SW_2:
        value = GPIO_readPin(SWITCH_PORT, SW_2); // Read the state of switch 2
        break;
    default:
        break;
    }
    return value; // Return the state of the switch
}
