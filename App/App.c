/******************************************************************************
 * @file           : App.c
 * @brief          : Source File for the Application
 * @author         : Mohamed Khaled
 *
 *******************************************************************************/

#include "App.h"

/* Building Locations Array Definition */
building buildings[] = {
    {"Credit", 30.063461114241612, 31.278327899164317},
    {"BasketBall", 30.063638749294025, 31.278715838272472},
    {"Soccer small", 30.063378152706836, 31.278837633108754},
    {"11 Yard Soccer", 30.06377148736959, 31.279527803850137},
    {"Hall A", 30.064167728242268, 31.28024825706133},
    {"Hall C", 30.06365434529334, 31.280481697164205},
    {"Architecture", 30.0640269, 31.280439},
    {"Mosque", 30.064662991956737, 31.280400696189105},
    {"Luban Workshop", 30.06337551683726, 31.279622342709416},
    {"ASU Racing Team", 30.063157864471684, 31.27894232153854},
    {"Main Building SA", 30.0650748204795, 31.278655203367112},
    {"Main Building 2", 30.064769331464166, 31.277942478027704},
    {"Main Building 3", 30.06522252511632, 31.279310881797013},
    {"Fountain", 30.065573993459477, 31.278439547682293},
    {"Workshop 1", 30.063967515677223, 31.27839374964577},
    {"Workshop 2", 30.064190046314668, 31.279082792656933},
    {"Workshop 3", 30.064500417158847, 31.27993986743512}};

void SystemInit() {};

int main(void)
{
    /* Variable Definitions */
    uint8 switch_state = 1;              // Assume 1 means not pressed, 0 means pressed
    uint8 switch2_state = 1;             // State of SW2
    uint8 buttonPressedFlag = 0;         // Edge-detection flag for SW1
    uint8 button2PressedFlag = 0;        // Edge-detection flag for SW2
    uint8 i = 0;                         // Loop counter
    float min_distance = 999999.0;       // Initialize with a large number
    char closest_building[50] = "";      // Store name of closest building
    char prev_closest_building[50] = ""; // Store previous closest building
    float current_distance;              // Current distance to building
    float total_distance = 0.0;          // Total distance traveled
    float prev_lat = 0.0;                // Previous latitude
    float prev_long = 0.0;               // Previous longitude
    uint8 first_point = 1;               // Flag for first GPS point
    char gpsString[32];                  // Buffer to hold the formatted string

    /* UART Configuration Structures */
    UART_ConfigType UART0_Configurations; // UART0 configuration structure

    /* Configure UART0 settings */
    UART0_Configurations.uart_number = UART0; // Set UART number
    UART0_Configurations.DataBits = 8;        // 8 data bits
    UART0_Configurations.parity = 0;          // No parity
    UART0_Configurations.stop_bits = 1;       // 1 stop bit
    UART0_Configurations.IBRD = 104;          // Integer Baud Rate (for 9600 baud with 16 MHz clock)
    UART0_Configurations.FBRD = 11;           // Fractional Baud Rate

    /* Initialize Hardware */
    UART_Config(&UART0_Configurations);

    PORTF_SW1_SW2_Init();
    PORTF_LEDS_Init();
    LCD_init();
    SysTick_Init();
    buzzer_init();

    LCD_clearScreen();
    LCD_displayStringRowColumn(0, 0, "Closest Building:");

    while (1)
    {
        Get_GPRMC();
        parse_GPRMC();
        switch_state = PORTF_GetSwitchValue(SW1);  // Read the state of switch 1
        switch2_state = PORTF_GetSwitchValue(SW2); // Read the state of switch 2

        // Calculate distance between consecutive points
        if (!first_point)
        {
            float point_distance = Calculate_Distance(convertToDegree(prev_lat), convertToDegree(prev_long));
            total_distance += point_distance;
        }
        prev_lat = lat1;
        prev_long = long1;
        first_point = 0;

        // Calculate distances to all buildings
        min_distance = 999999.0; // Reset minimum distance
        for (i = 0; i < sizeof(buildings) / sizeof(buildings[0]); i++)
        {
            current_distance = Calculate_Distance(buildings[i].latitude, buildings[i].longitude);
            if (current_distance < min_distance)
            {
                min_distance = current_distance;
                strcpy(closest_building, buildings[i].name);
            }
        }

        // Check if closest building has changed
        if (strcmp(closest_building, prev_closest_building) != 0)
        {
            // Clear screen and update display
            LCD_clearScreen();
            LCD_displayStringRowColumn(0, 0, "Closest Building:");
            LCD_displayStringRowColumn(1, 0, closest_building);

            // Activate buzzer
            buzzer_on();
            SysTick_DelayMs(2000);
            buzzer_off();

            // Update previous closest building
            strcpy(prev_closest_building, closest_building);
        }

        /* Handle SW1 press */
        if ((switch_state == SW_PRESSED) && (buttonPressedFlag == 0))
        {
            // Format coordinates with 6 decimal places and send
            sprintf(gpsString, "%.6f,%.6f\n", convertToDegree(lat1), convertToDegree(long1));
            UART_SendString(UART0, gpsString);

            PORTF_SetLedValue(RED, LED_ON);
            buttonPressedFlag = 1;
        }
        else if (switch_state == SW_NOT_PRESSED)
        {
            PORTF_SetLedValue(RED, LED_OFF);
            buttonPressedFlag = 0;
        }

        /* Handle SW2 press */
        if ((switch2_state == SW_PRESSED) && (button2PressedFlag == 0))
        {
            LCD_clearScreen();
            LCD_displayStringRowColumn(0, 0, "Total Distance:");
            LCD_moveCursor(1, 0);
            LCD_intgerToString(total_distance);
            SysTick_DelayMs(2000); // Display for 2 seconds
            LCD_clearScreen();
            LCD_displayStringRowColumn(0, 0, "Closest Building:");
            LCD_displayStringRowColumn(1, 0, closest_building);
            button2PressedFlag = 1;
        }
        else if (switch2_state == SW_NOT_PRESSED)
        {
            button2PressedFlag = 0;
        }
    }

    return 0;
}