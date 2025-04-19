/******************************************************************************
 *
 * Module: PORTF
 *
 * File Name : PORTF.h
 *
 * Description: Header File for Tiva C PortF Driver
 *
 * Author: Bassam Hussam
 *
 *******************************************************************************/

#include "PORTF.h"
#include "../../MCAL/GPIO/GPIO.c"

/*
 * Description :
 * Initialize the LEDs of PORTF.
 */
void PORTF_LEDS_Init(void)
{
    GPIO_Init(GPIO_PORTF);
    GPIO_PORTF_CR_R |= LEDS_MASK;     // Allow changing pin 3,2,1 in portF
    GPIO_PORTF_AMSEL_R &= ~LEDS_MASK; // disable the analog function
    GPIO_PORTF_PCTL_R &= ~0x0000FFF0; // GPIO CLEAR BIT PCTL
    GPIO_PORTF_AFSEL_R &= ~LEDS_MASK; // disable the alternate function
    GPIO_PORTF_DIR_R |= LEDS_MASK;    // Pin 1,2,3 is output
    GPIO_PORTF_DEN_R |= LEDS_MASK;
    GPIO_PORTF_DATA_R &= ~LEDS_MASK; // intialize pins 1,2,3 to be off
}

/*
 * Description :
 * Initialize the Switches of PORTF.
 */
void PORTF_SW1_SW2_Init(void)
{
    GPIO_Init(GPIO_PORTF);

    GPIO_PORTF_CR_R |= SW_MASK;       // setting pin p4 to change
    GPIO_PORTF_AMSEL_R &= ~SW_MASK;   // disable analog function
    GPIO_PORTF_PCTL_R &= ~0x000F000F; // GPIO CLEAR BIT PCTL
    GPIO_PORTF_AFSEL_R &= ~SW_MASK;   // disable alterante function
    GPIO_PORTF_DIR_R &= ~SW_MASK;     // DIR--> 0->input & 1->output
    GPIO_PORTF_PUR_R |= SW_MASK;      // active low
    GPIO_PORTF_DEN_R |= SW_MASK;      // Enable digital for sw1
}

/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 */
uint8 PORTF_GetSwitchValue(uint8 SWITCH)
{
    return GPIO_readPin(GPIO_PORTF, SWITCH);
}

/*
 * Description :
 * Set the value for the required pin, it should be Logic High or Logic Low.
 */
void PORTF_SetLedValue(uint8 LedColor, uint8 LedState)
{ // LedState-->ON OR OFF
    switch (LedColor)
    {
    case RED:
        GPIO_writePin(GPIO_PORTF, PIN_1, LedState);
        break;

    case BLUE:
        GPIO_writePin(GPIO_PORTF, PIN_2, LedState);
        break;

    case GREEN:
        GPIO_writePin(GPIO_PORTF, PIN_3, LedState);
        break;

    default:
        break;
    }
}

/*
 * Description :
 * Toggle the value for the required pin.
 */
void PORTF_led_Toggle(uint8 LED_PIN)
{
    TOGGLE_BIT(GPIO_PORTF_DATA_R, LED_PIN);
}

/*
 * Description :
 * Turn off the LEDs of PORTF.
 */
void PORTF_leds_Off()
{
    GPIO_PORTF_DATA_R &= ~(LEDS_MASK);
}