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
