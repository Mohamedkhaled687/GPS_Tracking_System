/******************************************************************************
 *
 * Module: TFT and SSI
 *
 * File Name : TFT.h
 *
 * Description: Header File for Tiva C TFT and SSI
 *
 * Author: Ahmed Mustafa
 *
 *******************************************************************************/

 #include "HAL\TFT\TFT.h"
 #include "HAL\TFT\TFT.c"
 #include "MCAL/SSI/SSI.h"
 
 //30.064079790586238, 31.279363300577383 | 30.064139590172832, 31.279339980915793
 void SystemInit() {};
 //char GPS_output[80] = "$GPRMC,123519.00,A,4807.038,N,01131.000,E,022.4,084.4,230394,003.1,W*6A";
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
 uint8 i;
 TFT_init();
 
 while(1) {
     
     for (i = 0; i < 50; i++) {
         SSI_Send(SSI0, &i);
         delay_ms(10);
     }
     
 }
 
     return 0; // Return success
 }