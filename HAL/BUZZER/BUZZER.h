/******************************************************************************
 *
 * Module: BUZZER
 *
 * File Name: BUZZER.h
 *
 * Description: Header file for the BUZZER DRIVER
 *
 * Author: Ahmed Mustafa
 *
 ******************************************************************************/

#include "..\..\MCAL\GPIO\GPIO.h"

#define BUZZER_PORT GPIO_PORTC
#define BUZZER_PIN PIN_4

#ifndef _BUZZER_H
#define _BUZZER_H

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description :
 * Initialize the buzzer
 */
void buzzer_init();

/*
 * Description :
 * Turn on the buzzer
 */
void buzzer_on();

/*
 * Description :
 * Turn off the buzzer
 */
void buzzer_off();

#endif