/******************************************************************************
 * @file           : GpsTest.c
 * @brief          : Source File for testing the GPs driver
 * @author         : Ahmed Mostafa
 *
 *******************************************************************************/

#include "stdio.h"
#include "MCAL\UART\UART.c"
#include "HAL\PORTF\PORTF.c"
#include "HAL\LCD\LCD.c"
#include "HAL\GPS\GPS.c"

void SystemInit() {};

int main(void)
{
  UART_ConfigType UART2_Configurations; // UART2 configuration structure

  // Configure UART2 settings (same configuration as UART0)
  UART2_Configurations.uart_number = UART2;
  UART2_Configurations.DataBits = 8;
  UART2_Configurations.parity = 0;
  UART2_Configurations.stop_bits = 1;
  UART2_Configurations.IBRD = 104;
  UART2_Configurations.FBRD = 11;

  // Initialize both UARTs
  UART_Config(&UART2_Configurations);
  PORTF_SW1_SW2_Init();
  PORTF_LEDS_Init();
  LCD_init(); // Initialize LCD

  // Display static labels
  LCD_displayStringRowColumn(0, 0, "lat = ");
  LCD_displayStringRowColumn(1, 0, "long = ");

  while (1)
  {
    Get_GPRMC();
    parse_GPRMC();

    // Update only the coordinate values
    LCD_moveCursor(0, 6); // Move cursor after "lat = "
    LCD_intgerToString(convertToDegree(lat1));

    LCD_moveCursor(1, 6); // Move cursor after "long = "
    LCD_intgerToString(convertToDegree(long1));
  }

  return 0; // Return success
}