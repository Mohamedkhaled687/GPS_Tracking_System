/******************************************************************************
 * @file           : GUITest.c
 * @brief          : Source File for testing the GUI driver
 * @author         : Mohamed Khaled
 *
 *******************************************************************************/

#include "stdio.h"
#include "..\MCAL\UART\UART.h"
#include "..\MCAL\SysticTimer\SYSTICK.h"
#include "..\HAL\LCD\LCD.h"
#include "..\HAL\GPS\GPS.h"
#include "..\HAL\PORTF\PORTF.h"

void SystemInit() {};

int main(void)
{
    uint8 switch_state = 1;      // Assume 1 means not pressed, 0 means pressed
    uint8 buttonPressedFlag = 0; // Edge-detection flag
    char gpsString[32];          // Buffer to hold the formatted string

    UART_ConfigType UART0_Configurations; // UART0 configuration structure
    UART_ConfigType UART2_Configurations; // UART2 configuration structure

    // Configure UART0 settings
    UART0_Configurations.uart_number = UART0; // Set UART number
    UART0_Configurations.DataBits = 8;        // 8 data bits
    UART0_Configurations.parity = 0;          // No parity
    UART0_Configurations.stop_bits = 1;       // 1 stop bit
    UART0_Configurations.IBRD = 104;          // Integer Baud Rate (for 9600 baud with 16 MHz clock)
    UART0_Configurations.FBRD = 11;           // Fractional Baud Rate

    // Configure UART2 settings (same configuration as UART0)
    UART2_Configurations.uart_number = UART2;
    UART2_Configurations.DataBits = 8;
    UART2_Configurations.parity = 0;
    UART2_Configurations.stop_bits = 1;
    UART2_Configurations.IBRD = 104;
    UART2_Configurations.FBRD = 11;

    // Initialize both UARTs
    UART_Config(&UART0_Configurations);
    UART_Config(&UART2_Configurations);
    PORTF_SW1_SW2_Init();
    PORTF_LEDS_Init();
    LCD_init(); // Initialize LCD
    SysTick_Init();

    // Display static labels
    LCD_displayStringRowColumn(0, 0, "lat = ");
    LCD_displayStringRowColumn(1, 0, "long = ");

    while (1)
    {
        Get_GPRMC();
        parse_GPRMC();
        switch_state = PORTF_GetSwitchValue(SW1); // Read the state of switch 1

        // Update only the coordinate values
        LCD_moveCursor(0, 6); // Move cursor after "lat = "
        LCD_intgerToString(convertToDegree(lat1));

        LCD_moveCursor(1, 6); // Move cursor after "long = "
        LCD_intgerToString(convertToDegree(long1));

        // Send coordinates to GUI by UART0 when SW1 is pressed
        if ((switch_state == SW_PRESSED) && (buttonPressedFlag == 0))
        {
            // Format coordinates with 6 decimal places and send
            sprintf(gpsString, "%.6f,%.6f\n", convertToDegree(lat1), convertToDegree(long1));
            UART_SendString(UART0, gpsString);

            PORTF_SetLedValue(RED, LED_ON); // Optionally turn on the LED

            buttonPressedFlag = 1; // Set the flag to indicate button is pressed
        }
        else if (switch_state == SW_NOT_PRESSED)
        {
            PORTF_SetLedValue(RED, LED_OFF); // Turn off the LED when button is released
            buttonPressedFlag = 0;           // Reset the flag when button is released
        }
    }
}