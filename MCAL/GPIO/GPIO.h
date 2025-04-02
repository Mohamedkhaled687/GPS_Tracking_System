/******************************************************************************
 *
 * Module: GPIO
 *
 * File Name : GPIO.h
 *
 * Description: Header File for Tiva C GPIO Driver
 *
 * Author: Mohamed Khaled
 *
 *******************************************************************************/

#ifndef GPIO_H_
#define GPIO_H_

#include "../../LIB/common_macros.h"
#include "../../LIB/std_types.h"

/*******************************************************************************
 *                            System Definitions                               *
 *******************************************************************************/

#define SYSTEM_CLOCK 80000000UL // 8 MHz

/*******************************************************************************
 *                                Addresses                                  *
 *******************************************************************************/

#define RCGCGPIO (*((volatile uint32 *)0x400FE608)) // GPIO Run Mode Clock Gating Control Register found in page 234 in Tiva C datasheet
#define PRGPIO (*((volatile uint32 *)0x400FEA08))   // GPIO Peripheral Ready Register found in page 236 in Tiva C datasheet

// Base address found in page 659 in Tiva C datasheet

#define GPIO_PORTA_APB_BASE_ADDRESS (0x40004000)
#define GPIO_PORTB_APB_BASE_ADDRESS (0x40005000)
#define GPIO_PORTC_APB_BASE_ADDRESS (0x40006000)
#define GPIO_PORTD_APB_BASE_ADDRESS (0x40007000)
#define GPIO_PORTE_APB_BASE_ADDRESS (0x40024000)
#define GPIO_PORTF_APB_BASE_ADDRESS (0x40025000)

// GPIO Register found in page 660 in Tiva C datasheet

/****** GPIO Direction Register ******/

#define GPIO_PORTA_DIR_R (*((volatile uint32 *)(GPIO_PORTA_APB_BASE_ADDRESS + 0x400)))
#define GPIO_PORTB_DIR_R (*((volatile uint32 *)(GPIO_PORTB_APB_BASE_ADDRESS + 0x400)))
#define GPIO_PORTC_DIR_R (*((volatile uint32 *)(GPIO_PORTC_APB_BASE_ADDRESS + 0x400)))
#define GPIO_PORTD_DIR_R (*((volatile uint32 *)(GPIO_PORTD_APB_BASE_ADDRESS + 0x400)))
#define GPIO_PORTE_DIR_R (*((volatile uint32 *)(GPIO_PORTE_APB_BASE_ADDRESS + 0x400)))
#define GPIO_PORTF_DIR_R (*((volatile uint32 *)(GPIO_PORTF_APB_BASE_ADDRESS + 0x400)))

/****** GPIO Alternate Function Select ******/

#define GPIO_PORTA_AFSEL_R (*((volatile uint32 *)(GPIO_PORTA_APB_BASE_ADDRESS + 0x420)))
#define GPIO_PORTB_AFSEL_R (*((volatile uint32 *)(GPIO_PORTB_APB_BASE_ADDRESS + 0x420)))
#define GPIO_PORTC_AFSEL_R (*((volatile uint32 *)(GPIO_PORTC_APB_BASE_ADDRESS + 0x420)))
#define GPIO_PORTD_AFSEL_R (*((volatile uint32 *)(GPIO_PORTD_APB_BASE_ADDRESS + 0x420)))
#define GPIO_PORTE_AFSEL_R (*((volatile uint32 *)(GPIO_PORTE_APB_BASE_ADDRESS + 0x420)))
#define GPIO_PORTF_AFSEL_R (*((volatile uint32 *)(GPIO_PORTF_APB_BASE_ADDRESS + 0x420)))

/****** GPIO Digital Enable Register ******/
#define GPIO_PORTA_DEN_R (*((volatile uint32 *)(GPIO_PORTA_APB_BASE_ADDRESS + 0x51C)))
#define GPIO_PORTB_DEN_R (*((volatile uint32 *)(GPIO_PORTB_APB_BASE_ADDRESS + 0x51C)))
#define GPIO_PORTC_DEN_R (*((volatile uint32 *)(GPIO_PORTC_APB_BASE_ADDRESS + 0x51C)))
#define GPIO_PORTD_DEN_R (*((volatile uint32 *)(GPIO_PORTD_APB_BASE_ADDRESS + 0x51C)))
#define GPIO_PORTE_DEN_R (*((volatile uint32 *)(GPIO_PORTE_APB_BASE_ADDRESS + 0x51C)))
#define GPIO_PORTF_DEN_R (*((volatile uint32 *)(GPIO_PORTF_APB_BASE_ADDRESS + 0x51C)))

/****** GPIO Data Register ******/
#define GPIO_PORTA_DATA_R (*((volatile uint32 *)(GPIO_PORTA_APB_BASE_ADDRESS + 0x3FC)))
#define GPIO_PORTB_DATA_R (*((volatile uint32 *)(GPIO_PORTB_APB_BASE_ADDRESS + 0x3FC)))
#define GPIO_PORTC_DATA_R (*((volatile uint32 *)(GPIO_PORTC_APB_BASE_ADDRESS + 0x3FC)))
#define GPIO_PORTD_DATA_R (*((volatile uint32 *)(GPIO_PORTD_APB_BASE_ADDRESS + 0x3FC)))
#define GPIO_PORTE_DATA_R (*((volatile uint32 *)(GPIO_PORTE_APB_BASE_ADDRESS + 0x3FC)))
#define GPIO_PORTF_DATA_R (*((volatile uint32 *)(GPIO_PORTF_APB_BASE_ADDRESS + 0x3FC)))

/****** GPIO Pull Up Register ******/
#define GPIO_PORTA_PUR_R (*((volatile uint32 *)(GPIO_PORTA_APB_BASE_ADDRESS + 0x510)))
#define GPIO_PORTB_PUR_R (*((volatile uint32 *)(GPIO_PORTB_APB_BASE_ADDRESS + 0x510)))
#define GPIO_PORTC_PUR_R (*((volatile uint32 *)(GPIO_PORTC_APB_BASE_ADDRESS + 0x510)))
#define GPIO_PORTD_PUR_R (*((volatile uint32 *)(GPIO_PORTD_APB_BASE_ADDRESS + 0x510)))
#define GPIO_PORTE_PUR_R (*((volatile uint32 *)(GPIO_PORTE_APB_BASE_ADDRESS + 0x510)))
#define GPIO_PORTF_PUR_R (*((volatile uint32 *)(GPIO_PORTF_APB_BASE_ADDRESS + 0x510)))

/****** GPIO Pull Down Register ******/
#define GPIO_PORTA_PDR_R (*((volatile uint32 *)(GPIO_PORTA_APB_BASE_ADDRESS + 0x514)))
#define GPIO_PORTB_PDR_R (*((volatile uint32 *)(GPIO_PORTB_APB_BASE_ADDRESS + 0x514)))
#define GPIO_PORTC_PDR_R (*((volatile uint32 *)(GPIO_PORTC_APB_BASE_ADDRESS + 0x514)))
#define GPIO_PORTD_PDR_R (*((volatile uint32 *)(GPIO_PORTD_APB_BASE_ADDRESS + 0x514)))
#define GPIO_PORTE_PDR_R (*((volatile uint32 *)(GPIO_PORTE_APB_BASE_ADDRESS + 0x514)))
#define GPIO_PORTF_PDR_R (*((volatile uint32 *)(GPIO_PORTF_APB_BASE_ADDRESS + 0x514)))

/******* GPIO Peripheral Selection Register *******/
#define GPIO_PORTA_PCTL_R (*((volatile uint32 *)(GPIO_PORTA_APB_BASE_ADDRESS + 0x52C)))
#define GPIO_PORTB_PCTL_R (*((volatile uint32 *)(GPIO_PORTB_APB_BASE_ADDRESS + 0x52C)))
#define GPIO_PORTC_PCTL_R (*((volatile uint32 *)(GPIO_PORTC_APB_BASE_ADDRESS + 0x52C)))
#define GPIO_PORTD_PCTL_R (*((volatile uint32 *)(GPIO_PORTD_APB_BASE_ADDRESS + 0x52C)))
#define GPIO_PORTE_PCTL_R (*((volatile uint32 *)(GPIO_PORTE_APB_BASE_ADDRESS + 0x52C)))
#define GPIO_PORTF_PCTL_R (*((volatile uint32 *)(GPIO_PORTF_APB_BASE_ADDRESS + 0x52C)))

/****** GPIO Lock Register ******/
#define GPIO_PORTA_LOCK_R (*((volatile uint32 *)(GPIO_PORTA_APB_BASE_ADDRESS + 0x520)))
#define GPIO_PORTB_LOCK_R (*((volatile uint32 *)(GPIO_PORTB_APB_BASE_ADDRESS + 0x520)))
#define GPIO_PORTC_LOCK_R (*((volatile uint32 *)(GPIO_PORTC_APB_BASE_ADDRESS + 0x520)))
#define GPIO_PORTD_LOCK_R (*((volatile uint32 *)(GPIO_PORTD_APB_BASE_ADDRESS + 0x520)))
#define GPIO_PORTE_LOCK_R (*((volatile uint32 *)(GPIO_PORTE_APB_BASE_ADDRESS + 0x520)))
#define GPIO_PORTF_LOCK_R (*((volatile uint32 *)(GPIO_PORTF_APB_BASE_ADDRESS + 0x520)))

/****** GPIO Commit Register ******/
#define GPIO_PORTA_CR_R (*(volatile uint32 *)(GPIO_PORTA_APB_BASE_ADDRESS + 0x524))
#define GPIO_PORTB_CR_R (*(volatile uint32 *)(GPIO_PORTB_APB_BASE_ADDRESS + 0x524))
#define GPIO_PORTC_CR_R (*(volatile uint32 *)(GPIO_PORTC_APB_BASE_ADDRESS + 0x524))
#define GPIO_PORTD_CR_R (*(volatile uint32 *)(GPIO_PORTD_APB_BASE_ADDRESS + 0x524))
#define GPIO_PORTE_CR_R (*(volatile uint32 *)(GPIO_PORTE_APB_BASE_ADDRESS + 0x524))
#define GPIO_PORTF_CR_R (*(volatile uint32 *)(GPIO_PORTF_APB_BASE_ADDRESS + 0x524))

/*******************************************************************************
 *                                Definations                                  *
 *******************************************************************************/

#define PIN_0 0
#define PIN_1 1
#define PIN_2 2
#define PIN_3 3
#define PIN_4 4
#define PIN_5 5
#define PIN_6 6
#define PIN_7 7

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

typedef enum
{
    GPIO_PORTA,
    GPIO_PORTB,
    GPIO_PORTC,
    GPIO_PORTD,
    GPIO_PORTE,
    GPIO_PORTF
} GPIO_PortType;

typedef enum
{
    PIN_INPUT,
    PIN_OUTPUT
} GPIO_PinDirectionType;

typedef enum
{
    PORT_INPUT,
    PORT_OUTPUT = 0xFF
} GPIO_PortDirectionType;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

void GPIO_Init(GPIO_PortType port); // give the clock to the GPIO

/*
 * Description :
 * Setup the direction of the required pin input/output.
 */
void GPIO_setupPinDirection(GPIO_PortType port, uint8 pin, GPIO_PinDirectionType direction);

/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 */
uint8 GPIO_readPin(GPIO_PortType port, uint8 pin);

/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 */

void GPIO_writePin(GPIO_PortType port, uint8 pin, uint8 value);

#endif /* GPIO_H_ */
