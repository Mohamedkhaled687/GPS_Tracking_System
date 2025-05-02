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

int main(void)
{

    PORTF_SW1_SW2_Init();
    PORTF_LEDS_Init();
    SysTick_Init();

    while (1)
    {
        PORTF_SetLedValue(BLUE, LED_ON);
        SysTick_DelayMs(1000);
        PORTF_SetLedValue(BLUE, LED_OFF);
        SysTick_DelayMs(1000);
    }

    return 0; // Return success
}