/******************************************************************************
 * @file           : SystickTest.c
 * @brief          : Source File for testing the SysTick driver
 * @author         : Hussam Magdey
 *
 *******************************************************************************/

#include "stdio.h"
#include "..\HAL\PORTF\PORTF.c"
#include "..\MCAL\SysticTimer\SYSTICK.h"

void SystemInit() {};

int main(void)
{
    PORTF_LEDS_Init(); // Initialize the LEDs
    SysTick_Init();    // Initialize the SysTick

    while (1)
    {
        PORTF_SetLedValue(BLUE, LED_ON);  // Turn on the blue LED
        SysTick_DelayMs(1000);            // Delay for 1 second
        PORTF_SetLedValue(BLUE, LED_OFF); // Turn off the blue LED
        SysTick_DelayMs(1000);            // Delay for 1 second
    }

    return 0; // Return success
}