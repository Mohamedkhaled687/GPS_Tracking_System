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
