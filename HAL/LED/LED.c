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
#include "../../MCAL/GPIO/GPIO.c"

/*
 * Description :
 * Initialize the LED Module.
 */
void LED_Init(void)
{
    GPIO_Init(LED_PORT);            // give the clock to the GPIO
    GPIO_Pin_Init(LED_PORT, RED);   // Initialize the red LED pin as output
    GPIO_Pin_Init(LED_PORT, BLUE);  // Initialize the blue LED pin as output
    GPIO_Pin_Init(LED_PORT, GREEN); // Initialize the green LED pin as output

    GPIO_setupPinMode(LED_PORT, RED, Floating, PIN_OUTPUT);   // Set the red LED pin as output
    GPIO_setupPinMode(LED_PORT, BLUE, Floating, PIN_OUTPUT);  // Set the blue LED pin as output
    GPIO_setupPinMode(LED_PORT, GREEN, Floating, PIN_OUTPUT); // Set the green LED pin as output

    GPIO_writePin(LED_PORT, RED, LOGIC_LOW);   // Turn off the red LED
    GPIO_writePin(LED_PORT, BLUE, LOGIC_LOW);  // Turn off the blue LED
    GPIO_writePin(LED_PORT, GREEN, LOGIC_LOW); // Turn off the green LED
}

/*
 * Description :
 * Turn on the specified LED.
 */
void LED_on(COLORS color)
{
    switch (color)
    {
    case RED:
        GPIO_writePin(LED_PORT, RED, LOGIC_HIGH); // Turn on the red LED
        break;
    case BLUE:
        GPIO_writePin(LED_PORT, BLUE, LOGIC_HIGH); // Turn on the blue LED
        break;
    case GREEN:
        GPIO_writePin(LED_PORT, GREEN, LOGIC_HIGH); // Turn on the green LED
        break;
    default:
        break;
    }
}
/*
 * Description :
 * Turn off the specified LED.
 */
void LED_off(COLORS color)
{
    switch (color)
    {
    case RED:
        GPIO_writePin(LED_PORT, RED, LOGIC_LOW); // Turn off the red LED
        break;
    case BLUE:
        GPIO_writePin(LED_PORT, BLUE, LOGIC_LOW); // Turn off the blue LED
        break;
    case GREEN:
        GPIO_writePin(LED_PORT, GREEN, LOGIC_LOW); // Turn off the green LED
        break;
    default:
        break;
    }
}
/*
 * Description :
 * Toggle the specified LED.
 */
void LED_toggle(COLORS color)
{
    switch (color)
    {
    case RED:
        GPIO_writePin(LED_PORT, RED, !GPIO_readPin(LED_PORT, RED)); // Toggle the red LED
        break;
    case BLUE:
        GPIO_writePin(LED_PORT, BLUE, !GPIO_readPin(LED_PORT, BLUE)); // Toggle the blue LED
        break;
    case GREEN:
        GPIO_writePin(LED_PORT, GREEN, !GPIO_readPin(LED_PORT, GREEN)); // Toggle the green LED
        break;
    default:
        break;
    }
}