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

#ifndef PORTF_HEADER
#define PORTF_HEADER

#include "../../LIB/common_macros.h"
#include "../../LIB/std_types.h"

/*******************************************************************************
 *                                Definations                                  *
 *******************************************************************************/

#define PF_MASK 0x20
#define LEDS_MASK 0x0E
#define SW_MASK 0x11

#define RED_LED 0x02
#define BLUE_LED 0x04
#define GREEN_LED 0x08

#define SW1 4
#define SW2 0
#define SW_NOT_PRESSED 1
#define SW_PRESSED 0

// led state
#define LED_ON 1
#define LED_OFF 0

// led color state(PIN NO.)
#define RED 1
#define BLUE 2
#define GREEN 3


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Setup the Mode of the required pin input/output.
 * Initialize the clock for the portF.
 * Unlock the portF pins.
 * Allow changing the pin 1,2,3 in portF.
 */
void PORTF_LEDS_Init(void);

/*
 * Description :
 * Setup the Mode of the required pin input/output.
 */

void PORTF_SW1_SW2_Init(void);

/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 */
uint8 PORTF_GetSwitchValue(uint8 SW);

/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 */

void PORTF_SetLedValue(uint8 LedColor, uint8 LedState); // LedState-->ON OR OFF According Led Color

#endif 
