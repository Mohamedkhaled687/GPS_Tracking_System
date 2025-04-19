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

#endif 
