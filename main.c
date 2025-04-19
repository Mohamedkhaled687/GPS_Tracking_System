/******************************************************************************
 *
 * Module: LED
 *
 * File Name : LED.h
 *
 * Description: Header File for Tiva C LED Driver
 *
 * Author: Mohamed Khaled
 *
 *******************************************************************************/

#include "stdio.h"
#include "MCAL\UART\UART.c"
#include "HAL\PORTF\PORTF.c"

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
    PORTF_SW1_SW2_Init();
    PORTF_LEDS_Init();

    while (1)
    {
        if (PORTF_GetSwitchValue(SW1) == SW_PRESSED) // Check if SW1 is pressed
        {
            delay_ms(30); // Debounce delay
            PORTF_led_Toggle(RED);
        }
    }

    return 0; // Return success
}