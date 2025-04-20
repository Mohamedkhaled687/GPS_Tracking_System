/******************************************************************************
 *
 * Module: Systic Timer
 *
 * File Name : SYSTICK.h
 *
 * Description: Header File for Tiva C SYSTICK Driver
 *
 * Author: Hussam Magdy
 *
 *******************************************************************************/

#ifndef SYSTICK_H_
#define SYSTICK_H_

#include "../../LIB/std_types.h"

/*******************************************************************************
 *                                Addresses                                  *
 *******************************************************************************/

#define NVIC_ST_CTRL_R (*((volatile uint32 *)0xE000E010))    // Control and Status Register
#define NVIC_ST_RELOAD_R (*((volatile uint32 *)0xE000E014))  // Reload Value Register
#define NVIC_ST_CURRENT_R (*((volatile uint32 *)0xE000E018)) // Current Value Register

// HWREG macro to access memory-mapped registers
#define HWREG(x) (*((volatile uint32 *)(x)))

// Access macros for SysTick registers
#define SYSTICK_CTRL HWREG(NVIC_ST_CTRL_R)
#define SYSTICK_RELOAD HWREG(NVIC_ST_RELOAD_R)
#define SYSTICK_CURRENT HWREG(NVIC_ST_CURRENT_R)

// SysTick control register bit definitions
#define SYSTICK_ENABLE 0x01      // Bit 0: Counter enable
#define SYSTICK_INT_DISABLE 0x00 // Bit 1: Interrupt disabled
#define SYSTICK_CLK_SRC_SYS 0x04 // Bit 2: Use processor clock

/*******************************************************************************
 *                                Functions Prototypes                          *
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
/**
 * Function desciption:
 * Delays execution for the specified number of microseconds .
 * ms Number of microseconds to delay.
 */
void SysTick_DelayUs(uint32 us);

#endif // SYSTICK_H_
