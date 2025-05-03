/******************************************************************************
 *
 * Module: Main
 *
 * File Name: main.c
 *
 * Description: Test code for LCD driver
 *
 * Author: Mohamed Khaled
 *
 *******************************************************************************/

#include "stdio.h"
#include "stdint.h"
#include "../HAL/LCD/LCD.c"
#include "../MCAL/SysticTimer/SYSTICK.h"
#include "../HAL/PORTF/PORTF.c"

void SystemInit() {};

int main(void)
{
    uint8 i = 0;
    LCD_init();
    SysTick_Init();
    PORTF_LEDS_Init();

    PORTF_SetLedValue(RED, LED_ON);
    SysTick_DelayMs(2000);
    PORTF_SetLedValue(RED, LED_OFF);
    PORTF_SetLedValue(GREEN, LED_ON);
    SysTick_DelayMs(2000);
    PORTF_SetLedValue(GREEN, LED_OFF);
    PORTF_SetLedValue(BLUE, LED_ON);
    SysTick_DelayMs(2000);
    PORTF_SetLedValue(BLUE, LED_OFF);

    /* Display welcome message */
    LCD_displayStringRowColumn(0, 0, "LCD Test Program");
    LCD_displayStringRowColumn(1, 0, "By Mohamed");
    SysTick_DelayMs(2000);

    /* Clear screen and test cursor movement */
    LCD_clearScreen();
    LCD_displayStringRowColumn(0, 0, "Cursor Test");
    LCD_displayStringRowColumn(1, 5, "Position");
    SysTick_DelayMs(2000);

    /* Test number display */
    LCD_clearScreen();
    LCD_displayStringRowColumn(0, 0, "Number Test:"); // Display "Number Test:"
    LCD_moveCursor(1, 0);
    LCD_intgerToString(123.45); // Display 123.45
    SysTick_DelayMs(2000);

    /* Test scrolling text */
    LCD_clearScreen();
    LCD_displayStringRowColumn(0, 0, "Scrolling Text");
    LCD_displayStringRowColumn(1, 0, "Hello World!");
    SysTick_DelayMs(1000);

    /* Move text to different positions */
    for (i = 0; i < 4; i++)
    {
        LCD_clearScreen();
        LCD_displayStringRowColumn(0, i * 4, "Hello");
        LCD_displayStringRowColumn(1, i * 4, "World!");
        SysTick_DelayMs(1000);
    }

    /* Final test - clear and show ready message */
    LCD_clearScreen();
    LCD_displayStringRowColumn(0, 0, "Test Complete!");
    LCD_displayStringRowColumn(1, 0, "LCD Ready");
    SysTick_DelayMs(2000);

    while (1)
    {
        /* Main loop - keep the program running */
    }

    return 0;
}