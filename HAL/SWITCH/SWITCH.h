/***********************************void SWITCH_Init(void);
*******************************************
*
* Module: SWITCH
*
* File Name : SWITCH.h
*
* Description: Header File for Tiva C SWITCH Driver
*
* Author: Mohamed Khaled
*
*******************************************************************************/

#ifndef SWITCH_H_
#define SWITCH_H_

#include "../../LIB/common_macros.h"
#include "../../LIB/std_types.h"
#include "../../MCAL/GPIO/GPIO.h"

/*******************************************************************************
 *                                Definations                                  *
 *******************************************************************************/

#define SWITCH_PORT GPIO_PORTF

#define SW1 1
#define SW2 2

#define SW1_PIN PIN_4
#define SW2_PIN PIN_0

/*******************************************************************************
 *                               Functions Prototype                            *
 *******************************************************************************/

/*
 * Description :
 * Initialize the SWITCH Module.
 */

/*
 * Description :
 * Read the state of the specified switch.
 */

uint8 SWITCH_Read(uint8 switch_num);

#endif