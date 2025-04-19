/******************************************************************************
 * @file           : UartTest.c
 * @brief          : Source File for testing the GPIO driver
 * @author         : Bassam Hussam
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
    UART_ConfigType UART_Configurations; // UART configuration structure
    uint8 switch_state = 1;              // Assume 1 means not pressed, 0 means pressed
    uint8 buttonPressedFlag = 0;         // Edge-detection flag

    // Configure UART settings
    UART_Configurations.uart_number = UART0; // Set UART number
    UART_Configurations.DataBits = 8;        // 8 data bits
    UART_Configurations.parity = 0;          // No parity
    UART_Configurations.stop_bits = 1;       // 1 stop bit
    UART_Configurations.IBRD = 104;          // Integer Baud Rate (for 9600 baud with 16 MHz clock)
    UART_Configurations.FBRD = 11;           // Fractional Baud Rate

    UART_Config(&UART_Configurations); // Initialize UART with settings
    PORTF_SW1_SW2_Init();
    PORTF_LEDS_Init();

    while (1)
    {
        switch_state = PORTF_GetSwitchValue(SW1); // Read the state of switch 1

        // Detect a falling edge (button just pressed)
        if ((switch_state == SW_PRESSED) && (buttonPressedFlag == 0))
        {
            delay_ms(30);
            UART_SendByte(UART0, '5');      // Send one '5' over UART
            PORTF_SetLedValue(RED, LED_ON); // Optionally turn on the LED
            buttonPressedFlag = 1;          // Set the flag to indicate button is pressed
        }
        else if (switch_state == SW_NOT_PRESSED)
        {
            PORTF_SetLedValue(RED, LED_OFF); // Turn off the LED when button is released
            buttonPressedFlag = 0;           // Reset the flag when button is released
        }
    }

    return 0; // Return success
}