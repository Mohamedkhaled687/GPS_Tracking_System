/******************************************************************************
 *
 * Module: LED
 *
 * File Name : LED.h
 *
 * Description: Header File for Tiva C LED Driver
 *
 * Author: Mohamed Khaled
 *
 *******************************************************************************/

 #include "stdio.h"
 #include "MCAL\UART\UART.c"
 #include "HAL\PORTF\PORTF.c"
 #include "HAL\GPS\GPS.c"
 //30.064079790586238, 31.279363300577383 | 30.064139590172832, 31.279339980915793
 void SystemInit() {};
 char GPS_output[80] = "123519.00,A,30.064139,N,31.279339,E,022.4,084.4,230394,003.1,W*6A";
 
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
    float distance;
	char i;
    UART_ConfigType UART_Configurations; // UART configuration structure

    // Configure UART settings
    UART_Configurations.uart_number = UART0; // Set UART number
    UART_Configurations.DataBits = 8;        // 8 data bits
    UART_Configurations.parity = 0;          // No parity
    UART_Configurations.stop_bits = 1;       // 1 stop bit
    UART_Configurations.IBRD = 104;          // Integer Baud Rate (for 9600 baud with 16 MHz clock)
    UART_Configurations.FBRD = 11;           // Fractional Baud Rate
    UART_Config(&UART_Configurations); // Initialize UART with settings
    
     PORTF_SW1_SW2_Init();
     PORTF_LEDS_Init();
     while (1)
     {
        UART_sendString(UART0, GPS_output);
        Get_GPRMC();
        parseGPRMC();
        distance = Calculate_Distance();
        if (distance > 37) {
                PORTF_led_Toggle(RED);
        }
        else {
                PORTF_led_Toggle(GREEN);
        }
     }
 
     return 0; // Return success
 }