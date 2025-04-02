/******************************************************************************
 *
 * Module: UART
 *
 * File Name : UART.h
 *
 * Description: Header File for Tiva C UART Driver
 *
 * Author: Mohamed Khaled
 *
 *******************************************************************************/

#ifndef UART_H_
#define UART_H_

#include "../../LIB/common_macros.h"
#include "../../LIB/std_types.h"

/*******************************************************************************
 *                             Addresses                                       *
 *******************************************************************************/

/**** UART0 Registers *****/

#define UART0_BASE_ADDRESS (0x4000C000)

#define UART0_DR_R (*((volatile uint32 *)(UART0_BASE_ADDRESS + 0x000)))        // Data Register
#define UART0_FR_R (*((volatile uint32 *)(UART0_BASE_ADDRESS + 0x018)))        // Flag Register
#define UART0_RSR_R (*((volatile uint32 *)(UART0_BASE_ADDRESS + 0x004)))       // Receive Status/Error Clear Register
#define UART0_IBRD_R (*((volatile uint32 *)(UART0_BASE_ADDRESS + 0x024)))      // Integer Baud Rate Register
#define UART0_FBRD_R (*((volatile uint32 *)(UART0_BASE_ADDRESS + 0x028)))      // Fractional Baud Rate Register
#define UART0_LCRH_R (*((volatile uint32 *)(UART0_BASE_ADDRESS + 0x02C)))      // Line Control Register
#define UART0_CTL_R (*((volatile uint32 *)(UART0_BASE_ADDRESS + 0x030)))       // Control Register
#define UART0_IFLS_R (*((volatile uint32 *)(UART0_BASE_ADDRESS + 0x034)))      // Interrupt FIFO Level Select Register
#define UART0_IM_R (*((volatile uint32 *)(UART0_BASE_ADDRESS + 0x038)))        // Interrupt Mask Register
#define UART0_RIS_R (*((volatile uint32 *)(UART0_BASE_ADDRESS + 0x03C)))       // Raw Interrupt Status Register
#define UART0_MIS_R (*((volatile uint32 *)(UART0_BASE_ADDRESS + 0x040)))       // Masked Interrupt Status Register
#define UART0_ICR_R (*((volatile uint32 *)(UART0_BASE_ADDRESS + 0x044)))       // Interrupt Clear Register
#define UART0_DMACTL_R (*((volatile uint32 *)(UART0_BASE_ADDRESS + 0x048)))    // DMA Control Register
#define UART0_9BITADDR_R (*((volatile uint32 *)(UART0_BASE_ADDRESS + 0x0A4)))  // 9-Bit Self Address Register
#define UART0_9BITAMASK_R (*((volatile uint32 *)(UART0_BASE_ADDRESS + 0x0A8))) // 9-Bit Self Address Mask Register
#define UART0_PP_R (*((volatile uint32 *)(UART0_BASE_ADDRESS + 0xFC0)))        // Peripheral Properties Register
#define UART0_CC_R (*((volatile uint32 *)(UART0_BASE_ADDRESS + 0xFC8)))        // Clock Configuration Register

#define GPIO_PA0_UART0_RX 0x00000001 // PA0 is used for UART0 RX
#define GPIO_PA1_UART0_TX 0x00000002 // PA1 is used for UART0 TX

#define GPIO_PCTL_PA0_UART0_RX 0x00000001 // PA0 is used for UART0 RX
#define GPIO_PCTL_PA1_UART0_TX 0x00000010 // PA1 is used for UART0 TX

#endif