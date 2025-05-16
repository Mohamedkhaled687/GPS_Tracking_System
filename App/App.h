/******************************************************************************
 *
 * Module: App
 *
 * File Name: App.h
 *
 * Description: Header file for the Application
 *
 * Author: Hazem Youssef
 *
 *******************************************************************************/

#ifndef APP_H_
#define APP_H_

#include "../MCAL/UART/UART.h"
#include "../HAL/PORTF/PORTF.h"
#include "../MCAL/SysticTimer/SYSTICK.h"
#include "../HAL/LCD/LCD.h"
#include "../HAL/GPS/GPS.h"
#include "../HAL/BUZZER/BUZZER.h"
#include <string.h>
#include <stdio.h>

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* Building Structure Definition */
typedef struct
{
    char name[50];
    float latitude;
    float longitude;
} building;

/* Building Locations Array */
building buildings[];

/* Function Prototypes */
void SystemInit(void);

#endif /* APP_H_ */
