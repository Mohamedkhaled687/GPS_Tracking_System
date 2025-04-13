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

#ifndef LED_H_

#define LED_H_

#include "../../LIB/common_macros.h"
#include "../../LIB/std_types.h"
#include "../../MCAL/GPIO/GPIO.h"

/*******************************************************************************
 *                                Definations                                  *
 *******************************************************************************/

#define LED_PORT GPIO_PORTF
typedef enum
{
    RED = 1, /**< Red LED */
    BLUE,    /**< Blue LED */
    GREEN    /**< Green LED */
} COLORS;

/*******************************************************************************
 *                               Functions Prototype                            *
 *******************************************************************************/

/*
 * Description :
 * Initialize the LED Module.
 */
void LED_Init(void);

/*
 * Description :
 * Turn on the specified LED.
 */
void LED_on(COLORS color);

/*
 * Description :
 * Turn off the specified LED.
 */
void LED_off(COLORS color);

/*
 * Description :
 * Toggle the specified LED.
 */

void LED_toggle(COLORS color);

#endif /* LED_H_ */
