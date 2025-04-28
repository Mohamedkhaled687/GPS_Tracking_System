/******************************************************************************
 *
 * Module: Systick Timer
 *
 * File Name : SYSTICK.c
 *
 * Description: Source File for Tiva C Systick Driver
 *
 * Author: Houssam Magdy
 *
 *******************************************************************************/

#include "SYSTICK.h"

/*
 * Description: Initialize the SysTick driver
 *              - Disable SysTick IRQ
 *              - Use processor clock source
 *              - Set reload value to 16000 - 1
 *              - Clear current value
 *              - Enable SysTick
 */

void SysTick_Init(void)
{
    SYSTICK_CTRL = 0;
    SYSTICK_RELOAD = 16000 - 1;
    SYSTICK_CURRENT = 0;
    SYSTICK_CTRL |= SYSTICK_CTRL_ENABLE_MASK | SYSTICK_CTRL_CLKSOURCE_MASK;
}

/*
 * Description: Delay function using SysTick
 *              - Initialize SysTick
 *              - Wait for the SysTick to count down
 */

void SysTick_DelayMs(uint32 ms)
{
    uint32 i;
    for (i = 0; i < ms; i++)
    {
        SysTick_Init(); /* Initialize SysTick */
        while ((SYSTICK_CTRL & SYSTICK_CTRL_COUNTFLAG_MASK) == 0)
            ;
    }
}