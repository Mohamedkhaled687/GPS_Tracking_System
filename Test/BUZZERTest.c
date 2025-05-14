/******************************************************************************
 * @file           : BuzzerTest.c
 * @brief          : Source File for testing the GPIO driver
 * @author         : Mohamed Khaled
 *
 *******************************************************************************/

#include "stdio.h"
#include "MCAL\UART\UART.c"
#include "HAL\PORTF\PORTF.c"
#include "MCAL\SysticTimer\SYSTICK.h"
#include "HAL\LCD\LCD.c"
#include "HAL\GPS\GPS.c"
#include "HAL\BUZZER\BUZZER.h"

void SystemInit() {};

int main(void)
{

    // Initialize both UARTs
    PORTF_LEDS_Init();
    SysTick_Init();
    buzzer_init();

    while (1)
    {
        PORTF_SetLedValue(RED, LED_ON);
        SysTick_DelayMs(1000);
        PORTF_SetLedValue(RED, LED_OFF);
        SysTick_DelayMs(1000);
        buzzer_on();
        SysTick_DelayMs(1000);
        buzzer_off();
        SysTick_DelayMs(1000);
    }
}