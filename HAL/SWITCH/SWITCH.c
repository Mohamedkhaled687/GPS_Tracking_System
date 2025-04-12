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
    GPIO_Init(SWITCH_PORT);              // give the clock to the GPIO
    GPIO_Pin_Init(SWITCH_PORT, SW1_PIN); // Initialize the switch pin as input
    GPIO_Pin_Init(SWITCH_PORT, SW2_PIN); // Initialize the switch pin as input

    GPIO_setupPinMode(SWITCH_PORT, SW1_PIN, Pull_up, PIN_INPUT); // Set the switch pin as input with pull-up resistor
    GPIO_setupPinMode(SWITCH_PORT, SW2_PIN, Pull_up, PIN_INPUT); // Set the switch pin as input with pull-up resistor

    GPIO_writePin(SWITCH_PORT, SW1_PIN, LOGIC_HIGH); // Set the switch pin to high (not pressed)
    GPIO_writePin(SWITCH_PORT, SW2_PIN, LOGIC_HIGH); // Set the switch pin to high (not pressed)
}

/*
 * Description :
 * Read the state of the specified switch.
 */
uint8 SWITCH_Read(uint8 switch_num)
{
    uint8 state = 0; // Initialize the state variable

    switch (switch_num)
    {
    case SW1:
        state = GPIO_readPin(SWITCH_PORT, SW1_PIN); // Read the state of switch 1
        break;
    case SW2:
        state = GPIO_readPin(SWITCH_PORT, SW2_PIN); // Read the state of switch 2
        break;
    default:
        break;
    }

    return state; // Return the state of the switch
}