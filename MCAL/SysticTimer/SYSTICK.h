/******************************************************************************
 *
 * Module: Systick Timer
 *
 * File Name : SYSTICK.h
 *
 * Description: Header File for Tiva C Systick Driver
 *
 * Author: Houssam Magdy
 *
 *******************************************************************************/

#ifndef SYSTICK_H_
#define SYSTICK_H_

#include "../../LIB/std_types.h"

/*******************************************************************************
 *                              Addresses                                      *
 *******************************************************************************/

#define SYSTICK_BASE_ADDRESS 0xE000E000
#define SYSTICK_CTRL (*((volatile uint32 *)(SYSTICK_BASE_ADDRESS + 0x10)))
#define SYSTICK_RELOAD (*((volatile uint32 *)(SYSTICK_BASE_ADDRESS + 0x14)))
#define SYSTICK_CURRENT (*((volatile uint32 *)(SYSTICK_BASE_ADDRESS + 0x18)))

/*******************************************************************************
 *                              Definitions                                    *
 *******************************************************************************/

#define SYSTICK_CTRL_ENABLE_MASK 0x00000001    /**< Bit 0 : Counter Enable */
#define SYSTICK_CTRL_TICKINT_MASK 0x00000002   /**< Bit 1 : Interrupt Enable */
#define SYSTICK_CTRL_CLKSOURCE_MASK 0x00000004 /**< Bit 2 : Clock Source */
#define SYSTICK_CTRL_COUNTFLAG_MASK 0x00010000 /**< Bit 16: Count Flag */

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/**
 * Function desciption:
 * Initializes the SysTick timer.
 * - Uses system clock.
 * - Disables interrupts.
 */
void SysTick_Init(void);

/**
 * Function desciption:
 * Delays execution for the specified number of milliseconds.
 * ms Number of milliseconds to delay.
 */
void SysTick_DelayMs(uint32 ms);

#endif // SYSTICK_H_
