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
#include "HAL\PORTF\PORTF.c"
#include "MCAL\SysticTimer\SYSTICK.h"

void SystemInit() {};

void delay_ms(uint32 ms)
{
    volatile uint32 count;
    while (ms--)
    {
        for (count = 16000; count > 0; count--)
        {
            // Empty loop for delay
        }
    }
}

int main(void)
{
    uint8 switch_state = 1;      // Assume 1 means not pressed, 0 means pressed
    uint8 buttonPressedFlag = 0; // Edge-detection flag

    PORTF_SW1_SW2_Init();
    PORTF_LEDS_Init();
    SysTick_Init();

    while (1)
    {
        PORTF_SetLedValue(BLUE, LED_ON);
        SysTick_DelayMs(1000);
        PORTF_SetLedValue(BLUE, LED_OFF);
    }

    return 0; // Return success
}