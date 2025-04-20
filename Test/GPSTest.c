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
 
 int main(void)
 {
		 float distance;
		 char i;
     PORTF_SW1_SW2_Init();
     PORTF_LEDS_Init();
     while (1)
     {
        for (i = 0; i < 80; i++) {
            if (GPS_output[i] == '*') {
                break;
            }
            GPS[i] = GPS_output[i];
        }
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