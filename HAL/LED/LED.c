/******************************************************************************
 *
 * Module: LED
 *
 * File Name : LED.c
 *
 * Description: Source File for Tiva C LED Driver
 *
 * Author: Mohamed Khaled
 *
 *******************************************************************************/

#include "LED.h"

/*
 * Description :
 * Initialize the LED Module.
 */
void LED_Init(void)
{
    GPIO_Init(LED_PORT); // give the clock to the GPIO

    GPIO_Pin_Init(LED_PORT, RED_LED);   // initialize the red LED pin
    GPIO_Pin_Init(LED_PORT, GREEN_LED); // initialize the green LED pin
    GPIO_Pin_Init(LED_PORT, BLUE_LED);  // initialize the blue LED pin

    GPIO_setupPinMode(LED_PORT, RED_LED, Pull_down, PIN_OUTPUT);   // set the red LED pin as output
    GPIO_setupPinMode(LED_PORT, GREEN_LED, Pull_down, PIN_OUTPUT); // set the green LED pin as output
    GPIO_setupPinMode(LED_PORT, BLUE_LED, Pull_down, PIN_OUTPUT);  // set the blue LED pin as output

    GPIO_writePin(LED_PORT, RED_LED, LOGIC_LOW);   // turn off the red LED
    GPIO_writePin(LED_PORT, GREEN_LED, LOGIC_LOW); // turn off the green LED
    GPIO_writePin(LED_PORT, BLUE_LED, LOGIC_LOW);  // turn off the blue LED
}

/*
 * Description :
 * Turn on the specified LED.
 */
void LED_on(uint8 led_num)
{

    switch (led_num)
    {
    case RED_LED:
        GPIO_writePin(LED_PORT, RED_LED, LOGIC_HIGH); // turn on the red LED
        break;
    case GREEN_LED:
        GPIO_writePin(LED_PORT, GREEN_LED, LOGIC_HIGH); // turn on the green LED
        break;
    case BLUE_LED:
        GPIO_writePin(LED_PORT, BLUE_LED, LOGIC_HIGH); // turn on the blue LED
        break;
    default:
        break;
    }
}

/*
 * Description :
 * Turn off the specified LED.
 */
void LED_off(uint8 led_num)
{

    switch (led_num)
    {
    case RED_LED:
        GPIO_writePin(LED_PORT, RED_LED, LOGIC_LOW); // turn off the red LED
        break;
    case GREEN_LED:
        GPIO_writePin(LED_PORT, GREEN_LED, LOGIC_LOW); // turn off the green LED
        break;
    case BLUE_LED:
        GPIO_writePin(LED_PORT, BLUE_LED, LOGIC_LOW); // turn off the blue LED
        break;
    default:
        break;
    }
}
/*
 * Description :
 * Toggle the specified LED.
 */
void LED_toggle(uint8 led_num)
{

    switch (led_num)
    {
    case RED_LED:
        GPIO_writePin(LED_PORT, RED_LED, !GPIO_readPin(LED_PORT, RED_LED)); // toggle the red LED
        break;
    case GREEN_LED:
        GPIO_writePin(LED_PORT, GREEN_LED, !GPIO_readPin(LED_PORT, GREEN_LED)); // toggle the green LED
        break;
    case BLUE_LED:
        GPIO_writePin(LED_PORT, BLUE_LED, !GPIO_readPin(LED_PORT, BLUE_LED)); // toggle the blue LED
        break;
    default:
        break;
    }
}
