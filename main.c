/******************************************************************************
 *
 * Module: Application
 *
 * File Name : main.c
 *
 *******************************************************************************/

#include "stdio.h"
#include "HAL/LED/LED.h"
#include "HAL/SWITCH/SWITCH.h"

int main()
{

    LED_Init();    // Initialize the LED module
    SWITCH_Init(); // Initialize the switch module

    while (1)
    {
        LED_on(GREEN); // Turn on the green LED
    }
}