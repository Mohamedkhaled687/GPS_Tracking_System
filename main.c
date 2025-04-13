#include "stdio.h"
#include "HAL/LED/LED.c"
#include "HAL/SWITCH/SWITCH.c"
#include "MCAL\GPIO\GPIO.c"
#include "MCAL\UART\UART.c"

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

    LED_Init();    // Initialize the LED module
    SWITCH_Init(); // Initialize the switch module

    while (1)
    {
        switch_state = SWITCH_Read(SW_1); // Read the state of switch 1

        // Detect a falling edge (button just pressed)
        if ((switch_state == 0) && (buttonPressedFlag == 0))
        {
            delay_ms(50);               // Debounce delay to filter out bouncing
            if (SWITCH_Read(SW_1) == 0) // Confirm button is still pressed after delay
            {
                UART_SendByte(UART0, '5'); // Send one '5' over UART
                LED_on(RED);               // Optionally turn on the LED
                buttonPressedFlag = 1;     // Set flag indicating button press handled
            }
        }
        // When the button is released, reset the flag
        else if (switch_state == 1)
        {
            LED_off(RED); // Turn off the LED when the button is released
            buttonPressedFlag = 0;
        }
    }

    return 0; // Return success
}