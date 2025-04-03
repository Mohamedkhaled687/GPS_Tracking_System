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
 *                             UART Registers                                   *
 *******************************************************************************/

/**** UART0 Registers *****/
// found in page 904 in Tiva C datasheet
#define UART0_BASE_ADDRESS (0x4000C000) // Base Address of UART0

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

// found in page 1351 in Tiva C datasheet
#define GPIO_PA0_UART0_RX 0x00000001 // PA0 is used for UART0 RX
#define GPIO_PA1_UART0_TX 0x00000002 // PA1 is used for UART0 TX

#define GPIO_PCTL_PA0_UART0_RX 0x00000001 // PA0 is used for UART0 RX
#define GPIO_PCTL_PA1_UART0_TX 0x00000010 // PA1 is used for UART0 TX

/**** UART1 Registers *****/

// found in page 904 in Tiva C datasheet

#define UART1_BASE_ADDRESS (0x4000D000) // Base Address of UART1

#define UART1_DR_R (*((volatile uint32 *)(UART1_BASE_ADDRESS + 0x000)))        // Data Register
#define UART1_FR_R (*((volatile uint32 *)(UART1_BASE_ADDRESS + 0x018)))        // Flag Register
#define UART1_RSR_R (*((volatile uint32 *)(UART1_BASE_ADDRESS + 0x004)))       // Receive Status/Error Clear Register
#define UART1_IBRD_R (*((volatile uint32 *)(UART1_BASE_ADDRESS + 0x024)))      // Integer Baud Rate Register
#define UART1_FBRD_R (*((volatile uint32 *)(UART1_BASE_ADDRESS + 0x028)))      // Fractional Baud Rate Register
#define UART1_LCRH_R (*((volatile uint32 *)(UART1_BASE_ADDRESS + 0x02C)))      // Line Control Register
#define UART1_CTL_R (*((volatile uint32 *)(UART1_BASE_ADDRESS + 0x030)))       // Control Register
#define UART1_IFLS_R (*((volatile uint32 *)(UART1_BASE_ADDRESS + 0x034)))      // Interrupt FIFO Level Select Register
#define UART1_IM_R (*((volatile uint32 *)(UART1_BASE_ADDRESS + 0x038)))        // Interrupt Mask Register
#define UART1_RIS_R (*((volatile uint32 *)(UART1_BASE_ADDRESS + 0x03C)))       // Raw Interrupt Status Register
#define UART1_MIS_R (*((volatile uint32 *)(UART1_BASE_ADDRESS + 0x040)))       // Masked Interrupt Status Register
#define UART1_ICR_R (*((volatile uint32 *)(UART1_BASE_ADDRESS + 0x044)))       // Interrupt Clear Register
#define UART1_DMACTL_R (*((volatile uint32 *)(UART1_BASE_ADDRESS + 0x048)))    // DMA Control Register
#define UART1_9BITADDR_R (*((volatile uint32 *)(UART1_BASE_ADDRESS + 0x0A4)))  // 9-Bit Self Address Register
#define UART1_9BITAMASK_R (*((volatile uint32 *)(UART1_BASE_ADDRESS + 0x0A8))) // 9-Bit Self Address Mask Register
#define UART1_PP_R (*((volatile uint32 *)(UART1_BASE_ADDRESS + 0xFC0)))        // Peripheral Properties Register
#define UART1_CC_R (*((volatile uint32 *)(UART1_BASE_ADDRESS + 0xFC8)))        // Clock Configuration Register

// found in page 1351 in Tiva C datasheet

#define GPIO_PB0_UART1_RX 0x00000001 // PB0 is used for UART1 RX
#define GPIO_PB1_UART1_TX 0x00000002 // PB1 is used for UART1 TX

#define GPIO_PCTL_PB0_UART1_RX 0x00000001 // PB0 is used for UART1 RX
#define GPIO_PCTL_PB1_UART1_TX 0x00000010 // PB1 is used for UART1 TX

/**** UART2 Registers *****/

// found in page 904 in Tiva C datasheet

#define UART2_BASE_ADDRESS (0x4000E000) // Base Address of UART2

#define UART2_DR_R (*((volatile uint32 *)(UART2_BASE_ADDRESS + 0x000)))        // Data Register
#define UART2_FR_R (*((volatile uint32 *)(UART2_BASE_ADDRESS + 0x018)))        // Flag Register
#define UART2_RSR_R (*((volatile uint32 *)(UART2_BASE_ADDRESS + 0x004)))       // Receive Status/Error Clear Register
#define UART2_IBRD_R (*((volatile uint32 *)(UART2_BASE_ADDRESS + 0x024)))      // Integer Baud Rate Register
#define UART2_FBRD_R (*((volatile uint32 *)(UART2_BASE_ADDRESS + 0x028)))      // Fractional Baud Rate Register
#define UART2_LCRH_R (*((volatile uint32 *)(UART2_BASE_ADDRESS + 0x02C)))      // Line Control Register
#define UART2_CTL_R (*((volatile uint32 *)(UART2_BASE_ADDRESS + 0x030)))       // Control Register
#define UART2_IFLS_R (*((volatile uint32 *)(UART2_BASE_ADDRESS + 0x034)))      // Interrupt FIFO Level Select Register
#define UART2_IM_R (*((volatile uint32 *)(UART2_BASE_ADDRESS + 0x038)))        // Interrupt Mask Register
#define UART2_RIS_R (*((volatile uint32 *)(UART2_BASE_ADDRESS + 0x03C)))       // Raw Interrupt Status Register
#define UART2_MIS_R (*((volatile uint32 *)(UART2_BASE_ADDRESS + 0x040)))       // Masked Interrupt Status Register
#define UART2_ICR_R (*((volatile uint32 *)(UART2_BASE_ADDRESS + 0x044)))       // Interrupt Clear Register
#define UART2_DMACTL_R (*((volatile uint32 *)(UART2_BASE_ADDRESS + 0x048)))    // DMA Control Register
#define UART2_9BITADDR_R (*((volatile uint32 *)(UART2_BASE_ADDRESS + 0x0A4)))  // 9-Bit Self Address Register
#define UART2_9BITAMASK_R (*((volatile uint32 *)(UART2_BASE_ADDRESS + 0x0A8))) // 9-Bit Self Address Mask Register
#define UART2_PP_R (*((volatile uint32 *)(UART2_BASE_ADDRESS + 0xFC0)))        // Peripheral Properties Register
#define UART2_CC_R (*((volatile uint32 *)(UART2_BASE_ADDRESS + 0xFC8)))        // Clock Configuration Register

// found in page 1351 in Tiva C datasheet

#define GPIO_PD6_UART2_RX 0x00000040 // PD6 is used for UART2 RX
#define GPIO_PD7_UART2_TX 0x00000080 // PD7 is used for UART2 TX

#define GPIO_PCTL_PD6_UART2_RX 0x01000000 // PD6 is used for UART2 RX
#define GPIO_PCTL_PD7_UART2_TX 0x10000000 // PD7 is used for UART2 TX

/**** UART3 Registers *****/

// found in page 904 in Tiva C datasheet

#define UART3_BASE_ADDRESS (0x4000F000) // Base Address of UART3

#define UART3_DR_R (*((volatile uint32 *)(UART3_BASE_ADDRESS + 0x000)))        // Data Register
#define UART3_FR_R (*((volatile uint32 *)(UART3_BASE_ADDRESS + 0x018)))        // Flag Register
#define UART3_RSR_R (*((volatile uint32 *)(UART3_BASE_ADDRESS + 0x004)))       // Receive Status/Error Clear Register
#define UART3_IBRD_R (*((volatile uint32 *)(UART3_BASE_ADDRESS + 0x024)))      // Integer Baud Rate Register
#define UART3_FBRD_R (*((volatile uint32 *)(UART3_BASE_ADDRESS + 0x028)))      // Fractional Baud Rate Register
#define UART3_LCRH_R (*((volatile uint32 *)(UART3_BASE_ADDRESS + 0x02C)))      // Line Control Register
#define UART3_CTL_R (*((volatile uint32 *)(UART3_BASE_ADDRESS + 0x030)))       // Control Register
#define UART3_IFLS_R (*((volatile uint32 *)(UART3_BASE_ADDRESS + 0x034)))      // Interrupt FIFO Level Select Register
#define UART3_IM_R (*((volatile uint32 *)(UART3_BASE_ADDRESS + 0x038)))        // Interrupt Mask Register
#define UART3_RIS_R (*((volatile uint32 *)(UART3_BASE_ADDRESS + 0x03C)))       // Raw Interrupt Status Register
#define UART3_MIS_R (*((volatile uint32 *)(UART3_BASE_ADDRESS + 0x040)))       // Masked Interrupt Status Register
#define UART3_ICR_R (*((volatile uint32 *)(UART3_BASE_ADDRESS + 0x044)))       // Interrupt Clear Register
#define UART3_DMACTL_R (*((volatile uint32 *)(UART3_BASE_ADDRESS + 0x048)))    // DMA Control Register
#define UART3_9BITADDR_R (*((volatile uint32 *)(UART3_BASE_ADDRESS + 0x0A4)))  // 9-Bit Self Address Register
#define UART3_9BITAMASK_R (*((volatile uint32 *)(UART3_BASE_ADDRESS + 0x0A8))) // 9-Bit Self Address Mask Register
#define UART3_PP_R (*((volatile uint32 *)(UART3_BASE_ADDRESS + 0xFC0)))        // Peripheral Properties Register
#define UART3_CC_R (*((volatile uint32 *)(UART3_BASE_ADDRESS + 0xFC8)))        // Clock Configuration Register

// found in page 1351 in Tiva C datasheet

#define GPIO_PC6_UART3_RX 0x00000040 // PC6 is used for UART3 RX
#define GPIO_PC7_UART3_TX 0x00000080 // PC7 is used for UART3 TX

#define GPIO_PCTL_PC6_UART3_RX 0x01000000 // PC6 is used for UART3 RX
#define GPIO_PCTL_PC7_UART3_TX 0x10000000 // PC7 is used for UART3 TX

/**** UART4 Registers *****/

// found in page 904 in Tiva C datasheet
#define UART4_BASE_ADDRESS (0x40010000) // Base Address of UART4

#define UART4_DR_R (*((volatile uint32 *)(UART4_BASE_ADDRESS + 0x000)))        // Data Register
#define UART4_FR_R (*((volatile uint32 *)(UART4_BASE_ADDRESS + 0x018)))        // Flag Register
#define UART4_RSR_R (*((volatile uint32 *)(UART4_BASE_ADDRESS + 0x004)))       // Receive Status/Error Clear Register
#define UART4_IBRD_R (*((volatile uint32 *)(UART4_BASE_ADDRESS + 0x024)))      // Integer Baud Rate Register
#define UART4_FBRD_R (*((volatile uint32 *)(UART4_BASE_ADDRESS + 0x028)))      // Fractional Baud Rate Register
#define UART4_LCRH_R (*((volatile uint32 *)(UART4_BASE_ADDRESS + 0x02C)))      // Line Control Register
#define UART4_CTL_R (*((volatile uint32 *)(UART4_BASE_ADDRESS + 0x030)))       // Control Register
#define UART4_IFLS_R (*((volatile uint32 *)(UART4_BASE_ADDRESS + 0x034)))      // Interrupt FIFO Level Select Register
#define UART4_IM_R (*((volatile uint32 *)(UART4_BASE_ADDRESS + 0x038)))        // Interrupt Mask Register
#define UART4_RIS_R (*((volatile uint32 *)(UART4_BASE_ADDRESS + 0x03C)))       // Raw Interrupt Status Register
#define UART4_MIS_R (*((volatile uint32 *)(UART4_BASE_ADDRESS + 0x040)))       // Masked Interrupt Status Register
#define UART4_ICR_R (*((volatile uint32 *)(UART4_BASE_ADDRESS + 0x044)))       // Interrupt Clear Register
#define UART4_DMACTL_R (*((volatile uint32 *)(UART4_BASE_ADDRESS + 0x048)))    // DMA Control Register
#define UART4_9BITADDR_R (*((volatile uint32 *)(UART4_BASE_ADDRESS + 0x0A4)))  // 9-Bit Self Address Register
#define UART4_9BITAMASK_R (*((volatile uint32 *)(UART4_BASE_ADDRESS + 0x0A8))) // 9-Bit Self Address Mask Register
#define UART4_PP_R (*((volatile uint32 *)(UART4_BASE_ADDRESS + 0xFC0)))        // Peripheral Properties Register
#define UART4_CC_R (*((volatile uint32 *)(UART4_BASE_ADDRESS + 0xFC8)))        // Clock Configuration Register

// found in page 1351 in Tiva C datasheet

#define GPIO_PC4_UART4_RX 0x00000010 // PC4 is used for UART4 RX
#define GPIO_PC5_UART4_TX 0x00000020 // PC5  is used for UART4 TX

#define GPIO_PCTL_PC4_UART4_RX 0x00010000 // PC4 is used for UART4 RX
#define GPIO_PCTL_PC5_UART4_TX 0x00100000 // PC5 is used for UART4 TX

/**** UART5 Registers *****/

// found in page 904 in Tiva C datasheet

#define UART5_BASE_ADDRESS (0x40011000) // Base Address of UART5

#define UART5_DR_R (*((volatile uint32 *)(UART5_BASE_ADDRESS + 0x000)))        // Data Register
#define UART5_FR_R (*((volatile uint32 *)(UART5_BASE_ADDRESS + 0x018)))        // Flag Register
#define UART5_RSR_R (*((volatile uint32 *)(UART5_BASE_ADDRESS + 0x004)))       // Receive Status/Error Clear Register
#define UART5_IBRD_R (*((volatile uint32 *)(UART5_BASE_ADDRESS + 0x024)))      // Integer Baud Rate Register
#define UART5_FBRD_R (*((volatile uint32 *)(UART5_BASE_ADDRESS + 0x028)))      // Fractional Baud Rate Register
#define UART5_LCRH_R (*((volatile uint32 *)(UART5_BASE_ADDRESS + 0x02C)))      // Line Control Register
#define UART5_CTL_R (*((volatile uint32 *)(UART5_BASE_ADDRESS + 0x030)))       // Control Register
#define UART5_IFLS_R (*((volatile uint32 *)(UART5_BASE_ADDRESS + 0x034)))      // Interrupt FIFO Level Select Register
#define UART5_IM_R (*((volatile uint32 *)(UART5_BASE_ADDRESS + 0x038)))        // Interrupt Mask Register
#define UART5_RIS_R (*((volatile uint32 *)(UART5_BASE_ADDRESS + 0x03C)))       // Raw Interrupt Status Register
#define UART5_MIS_R (*((volatile uint32 *)(UART5_BASE_ADDRESS + 0x040)))       // Masked Interrupt Status Register
#define UART5_ICR_R (*((volatile uint32 *)(UART5_BASE_ADDRESS + 0x044)))       // Interrupt Clear Register
#define UART5_DMACTL_R (*((volatile uint32 *)(UART5_BASE_ADDRESS + 0x048)))    // DMA Control Register
#define UART5_9BITADDR_R (*((volatile uint32 *)(UART5_BASE_ADDRESS + 0x0A4)))  // 9-Bit Self Address Register
#define UART5_9BITAMASK_R (*((volatile uint32 *)(UART5_BASE_ADDRESS + 0x0A8))) // 9-Bit Self Address Mask Register
#define UART5_PP_R (*((volatile uint32 *)(UART5_BASE_ADDRESS + 0xFC0)))        // Peripheral Properties Register
#define UART5_CC_R (*((volatile uint32 *)(UART5_BASE_ADDRESS + 0xFC8)))        // Clock Configuration Register

// found in page 1351 in Tiva C datasheet

#define GPIO_PE4_UART5_RX 0x00000010 // PE4 is used for UART4 RX
#define GPIO_PE5_UART5_TX 0x00000020 // PE5 is used for UART4 TX

#define GPIO_PCTL_PE4_UART5_RX 0x00010000 // PE4 is used for UART4 RX
#define GPIO_PCTL_PE5_UART5_TX 0x00100000 // PE5 is used for UART4 TX

/**** UART6 Registers *****/

// found in page 904 in Tiva C datasheet

#define UART6_BASE_ADDRESS (0x40062000) // Base Address of UART6

#define UART6_DR_R (*((volatile uint32 *)(UART6_BASE_ADDRESS + 0x000)))        // Data Register
#define UART6_FR_R (*((volatile uint32 *)(UART6_BASE_ADDRESS + 0x018)))        // Flag Register
#define UART6_RSR_R (*((volatile uint32 *)(UART6_BASE_ADDRESS + 0x004)))       // Receive Status/Error Clear Register
#define UART6_IBRD_R (*((volatile uint32 *)(UART6_BASE_ADDRESS + 0x024)))      // Integer Baud Rate Register
#define UART6_FBRD_R (*((volatile uint32 *)(UART6_BASE_ADDRESS + 0x028)))      // Fractional Baud Rate Register
#define UART6_LCRH_R (*((volatile uint32 *)(UART6_BASE_ADDRESS + 0x02C)))      // Line Control Register
#define UART6_CTL_R (*((volatile uint32 *)(UART6_BASE_ADDRESS + 0x030)))       // Control Register
#define UART6_IFLS_R (*((volatile uint32 *)(UART6_BASE_ADDRESS + 0x034)))      // Interrupt FIFO Level Select Register
#define UART6_IM_R (*((volatile uint32 *)(UART6_BASE_ADDRESS + 0x038)))        // Interrupt Mask Register
#define UART6_RIS_R (*((volatile uint32 *)(UART6_BASE_ADDRESS + 0x03C)))       // Raw Interrupt Status Register
#define UART6_MIS_R (*((volatile uint32 *)(UART6_BASE_ADDRESS + 0x040)))       // Masked Interrupt Status Register
#define UART6_ICR_R (*((volatile uint32 *)(UART6_BASE_ADDRESS + 0x044)))       // Interrupt Clear Register
#define UART6_DMACTL_R (*((volatile uint32 *)(UART6_BASE_ADDRESS + 0x048)))    // DMA Control Register
#define UART6_9BITADDR_R (*((volatile uint32 *)(UART6_BASE_ADDRESS + 0x0A4)))  // 9-Bit Self Address Register
#define UART6_9BITAMASK_R (*((volatile uint32 *)(UART6_BASE_ADDRESS + 0x0A8))) // 9-Bit Self Address Mask Register
#define UART6_PP_R (*((volatile uint32 *)(UART6_BASE_ADDRESS + 0xFC0)))        // Peripheral Properties Register
#define UART6_CC_R (*((volatile uint32 *)(UART6_BASE_ADDRESS + 0xFC8)))        // Clock Configuration Register

// found in page 1351 in Tiva C datasheet

#define GPIO_PD4_UART6_RX 0x00000001 // PD4 is used for UART6 RX
#define GPIO_PD5_UART6_TX 0x00000002 // PD5 is used for UART6 TX

#define GPIO_PCTL_PD4_UART6_RX 0x00010000 // PD4 is used for UART6 RX
#define GPIO_PCTL_PD5_UART6_TX 0x00100000 // PD5 is used for UART6 TX

/**** UART7 Registers *****/

// found in page 904 in Tiva C datasheet

#define UART7_BASE_ADDRESS (0x40063000) // Base Address of UART7

#define UART7_DR_R (*((volatile uint32 *)(UART7_BASE_ADDRESS + 0x000)))        // Data Register
#define UART7_FR_R (*((volatile uint32 *)(UART7_BASE_ADDRESS + 0x018)))        // Flag Register
#define UART7_RSR_R (*((volatile uint32 *)(UART7_BASE_ADDRESS + 0x004)))       // Receive Status/Error Clear Register
#define UART7_IBRD_R (*((volatile uint32 *)(UART7_BASE_ADDRESS + 0x024)))      // Integer Baud Rate Register
#define UART7_FBRD_R (*((volatile uint32 *)(UART7_BASE_ADDRESS + 0x028)))      // Fractional Baud Rate Register
#define UART7_LCRH_R (*((volatile uint32 *)(UART7_BASE_ADDRESS + 0x02C)))      // Line Control Register
#define UART7_CTL_R (*((volatile uint32 *)(UART7_BASE_ADDRESS + 0x030)))       // Control Register
#define UART7_IFLS_R (*((volatile uint32 *)(UART7_BASE_ADDRESS + 0x034)))      // Interrupt FIFO Level Select Register
#define UART7_IM_R (*((volatile uint32 *)(UART7_BASE_ADDRESS + 0x038)))        // Interrupt Mask Register
#define UART7_RIS_R (*((volatile uint32 *)(UART7_BASE_ADDRESS + 0x03C)))       // Raw Interrupt Status Register
#define UART7_MIS_R (*((volatile uint32 *)(UART7_BASE_ADDRESS + 0x040)))       // Masked Interrupt Status Register
#define UART7_ICR_R (*((volatile uint32 *)(UART7_BASE_ADDRESS + 0x044)))       // Interrupt Clear Register
#define UART7_DMACTL_R (*((volatile uint32 *)(UART7_BASE_ADDRESS + 0x048)))    // DMA Control Register
#define UART7_9BITADDR_R (*((volatile uint32 *)(UART7_BASE_ADDRESS + 0x0A4)))  // 9-Bit Self Address Register
#define UART7_9BITAMASK_R (*((volatile uint32 *)(UART7_BASE_ADDRESS + 0x0A8))) // 9-Bit Self Address Mask Register
#define UART7_PP_R (*((volatile uint32 *)(UART7_BASE_ADDRESS + 0xFC0)))        // Peripheral Properties Register
#define UART7_CC_R (*((volatile uint32 *)(UART7_BASE_ADDRESS + 0xFC8)))        // Clock Configuration Register

// found in page 1351 in Tiva C datasheet

#define GPIO_PE0_UART7_RX 0x00000001 // PE0 is used for UART7 RX
#define GPIO_PE1_UART7_TX 0x00000002 // PE1 is used for UART7 TX

#define GPIO_PCTL_PE0_UART7_RX 0x00000001 // PE0 is used for UART7 RX
#define GPIO_PCTL_PE1_UART7_TX 0x00000010 // PE1 is used for UART7 TX

#endif