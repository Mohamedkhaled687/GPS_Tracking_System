/******************************************************************************
 * @file           : GPIOTest.c
 * @brief          : Source File for testing the GPIO driver
 * @author         : Bassam Hussam
 *
 *******************************************************************************/

#include "stdio.h"
#include "..\HAL\PORTF\PORTF.c"

void SystemInit() {};

void delay_ms(uint32 ms)
{
    volatile uint32 count;
    while (ms--)
    {
        for (count = 0; count < 4000; count++)
        {
        } // adjust for your clock speed
    }
}

int main(void)
{
    PORTF_LEDS_Init();     // Initialize the PORTF LEDs
    PORTF_SWITCHES_Init(); // Initialize the PORTF Switches

    while (1)
    {

        if (PORTF_ReadSwitch(SW1) == SW_PRESSED) // Check if SW2 is pressed
        {
            PORTF_SetLed(GREEN_LED, LED_ON); // Turn on the green LED
        }
        else
        {
            PORTF_SetLed(GREEN_LED, LED_OFF); // Turn off the green LED
        }

        return 0; // Return success
    }
}
