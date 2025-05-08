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
#define BUZZER_PIN  PIN_4



#ifndef _BUZZER_H
#define _BUZZER_H

/*************************************************************
 * *********************PROTOTYPES**************************** 
**************************************************************
 */

 void buzzer_init();

 void buzzer_on();

 void buzzer_off();


#endif