/******************************************************************************
 *
 * Module: BUZZER
 *
 * File Name: BUZZER.c
 *
 * Description: Source file for the BUZZER driver
 *
 * Author: Ahmed Mustafa
 *
 ******************************************************************************/

#include "BUZZER.h"

void buzzer_init()
{
    GPIO_Init(BUZZER_PORT);                                            // give the clock to the GPIO
    GPIO_Pin_Init(BUZZER_PORT, BUZZER_PIN);                            // give the clock to the pin
    GPIO_setupPinMode(BUZZER_PORT, BUZZER_PIN, Pull_down, PIN_OUTPUT); // set the pin as output
    GPIO_writePin(BUZZER_PORT, BUZZER_PIN, 0);                         // turn off the buzzer
}

void buzzer_on()
{
    GPIO_writePin(BUZZER_PORT, BUZZER_PIN, 1);
}

void buzzer_off()
{
    GPIO_writePin(BUZZER_PORT, BUZZER_PIN, 0);
}