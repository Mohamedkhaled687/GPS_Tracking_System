/******************************************************************************
 * @file           : UartTest.c
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

void SystemInit() {};

typedef struct
{
    char name[50];
    float latitude;
    float longitude;
} building;

building buildings[] = {
    {"Credit", 30.063440, 31.278323},
    {"BasketBall", 30.063635, 31.278717},
    {"Soccer small", 30.063375, 31.278837},
    {"Hall A", 30.064168, 31.280241},
    {"Hall C", 30.063649, 31.280469},
    {"Architecture", 30.064109, 31.280698},
    {"Mosque", 30.064658, 31.280397},
    {"Luban Workshop", 30.063333, 31.279728},
    {"ASU Racing Team", 30.063115, 31.279050},
    {"Main Building Student Affairs", 30.065045, 31.278707},
    {"Main Building 2", 30.064801, 31.277951},
    {"Main Building 3", 30.065204, 31.279293},
    {"Fountain", 30.065553, 31.278418},
    {"Mechanical Workshops 1", 30.063900, 31.278303},
    {"Mechanical Workshops 2", 30.063898, 31.278311},
    {"Mechanical Workshops 3", 30.064436, 31.279791}};

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

        // Calculate distances to all buildings
        float min_distance = 999999.0;  // Initialize with a large number
        char closest_building[50] = ""; // Store name of closest building
        float current_distance;

        // Calculate distance to each building
        for (int i = 0; i < sizeof(buildings) / sizeof(buildings[0]); i++)
        {
            current_distance = Calculate_Distance(buildings[i].latitude, buildings[i].longitude);
            if (current_distance < min_distance)
            {
                min_distance = current_distance;
                strcpy(closest_building, buildings[i].name);
            }
        }

        // Display closest building on two lines
        LCD_clearScreen();
        LCD_displayStringRowColumn(0, 0, "Closest Building:");
        LCD_displayStringRowColumn(1, 0, closest_building);

        // GUI
        if (switch_state == SW_PRESSED) // If switch is pressed
        {
            SysTick_DelayMs(30);        // Debounce delay
            if (buttonPressedFlag == 0) // Only send once per press
            {
                // Format coordinates with 6 decimal places and send
                sprintf(gpsString, "%.6f,%.6f\n", convertToDegree(lat1), convertToDegree(long1));
                UART_SendString(UART0, gpsString);
                buttonPressedFlag = 1; // Set flag to prevent multiple sends
            }
            PORTF_SetLedValue(RED, LED_ON); // Turn on red LED while pressed
        }
        else // Switch is not pressed
        {
            PORTF_SetLedValue(RED, LED_OFF); // Turn off red LED
            buttonPressedFlag = 0;           // Reset flag for next press
        }
    }

    return 0; // Return success
}