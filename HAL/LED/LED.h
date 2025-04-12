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
#define RED_LED 1
#define GREEN_LED 2
#define BLUE_LED 3

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

void LED_on(uint8 led_num);

/*
 * Description :
 * Turn off the specified LED.
 */

void LED_off(uint8 led_num);

/*
 * Description :
 * Toggle the specified LED.
 */
void LED_toggle(uint8 led_num);

#endif /* LED_H_ */