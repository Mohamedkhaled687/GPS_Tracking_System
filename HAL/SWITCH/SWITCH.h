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

typedef enum
{
    SW_1 = 4, /**< Switch 1 */
    SW_2 = 0  /**< Switch 2 */
} SWITCHES;

/*******************************************************************************
 *                               Functions Prototype                            *
 *******************************************************************************/

/*
 * Description :
 * Initialize the SWITCH Module.
 */

void SWITCH_Init(void);

/*
 * Description :
 * Read the state of the specified switch.
 */

uint8 SWITCH_Read(uint8 switch_num);

#endif