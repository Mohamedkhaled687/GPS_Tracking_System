/******************************************************************************
 *
 * Module: UART
 *
 * File Name : UART.c
 *
 * Description: Source File for Tiva C UART Driver
 *
 * Author: Mohamed Khaled
 *
 *******************************************************************************/

#include "UART.h"
#include <stdint.h>
#include "../GPIO/GPIO.h"

void UART_Init(UART_Select uart_number)
{

    switch (uart_number)
    {
    case UART0:
        GPIO_PORTA_CR_R |= GPIO_PA0_UART0_RX | GPIO_PA1_UART0_TX;             // allow changes to the pin
        GPIO_PORTA_AFSEL_R |= GPIO_PA0_UART0_RX | GPIO_PA1_UART0_TX;          // enable alternate function
        GPIO_PORTA_PCTL_R |= GPIO_PCTL_PA0_UART0_RX | GPIO_PCTL_PA1_UART0_TX; // select the alternate function
        GPIO_PORTA_DIR_R |= GPIO_PA1_UART0_TX;                                // set the Tx as output
        GPIO_PORTA_DIR_R &= ~GPIO_PA0_UART0_RX;                               // set the Rx as input
        GPIO_PORTA_AMSEL_R &= ~(GPIO_PA0_UART0_RX | GPIO_PA1_UART0_TX);       // disable analog mode
        GPIO_PORTA_DEN_R |= GPIO_PA0_UART0_RX | GPIO_PA1_UART0_TX;            // enable digital mode
        break;

    case UART1:
        GPIO_PORTB_CR_R |= GPIO_PB0_UART1_RX | GPIO_PB1_UART1_TX;             // allow changes to the pin
        GPIO_PORTB_AFSEL_R |= GPIO_PB0_UART1_RX | GPIO_PB1_UART1_TX;          // enable alternate function
        GPIO_PORTB_PCTL_R |= GPIO_PCTL_PB0_UART1_RX | GPIO_PCTL_PB1_UART1_TX; // select the alternate function
        GPIO_PORTB_DIR_R |= GPIO_PB1_UART1_TX;                                // set the Tx as output
        GPIO_PORTB_DIR_R &= ~GPIO_PB0_UART1_RX;                               // set the Rx as input
        GPIO_PORTB_AMSEL_R &= ~(GPIO_PB0_UART1_RX | GPIO_PB1_UART1_TX);       // disable analog mode
        GPIO_PORTB_DEN_R |= GPIO_PB0_UART1_RX | GPIO_PB1_UART1_TX;            // enable digital mode
        break;

    case UART2:
        GPIO_PORTD_CR_R |= GPIO_PD6_UART2_RX | GPIO_PD7_UART2_TX;             // allow changes to the pin
        GPIO_PORTD_AFSEL_R |= GPIO_PD6_UART2_RX | GPIO_PD7_UART2_TX;          // enable alternate function
        GPIO_PORTD_PCTL_R |= GPIO_PCTL_PD6_UART2_RX | GPIO_PCTL_PD7_UART2_TX; // select the alternate function
        GPIO_PORTD_DIR_R |= GPIO_PD7_UART2_TX;                                // set the Tx as output
        GPIO_PORTD_DIR_R &= ~GPIO_PD6_UART2_RX;                               // set the Rx as input
        GPIO_PORTD_AMSEL_R &= ~(GPIO_PD6_UART2_RX | GPIO_PD7_UART2_TX);       // disable analog mode
        GPIO_PORTD_DEN_R |= GPIO_PD6_UART2_RX | GPIO_PD7_UART2_TX;            // enable digital mode
        break;

    case UART3:
        GPIO_PORTC_CR_R |= GPIO_PC6_UART3_RX | GPIO_PC7_UART3_TX;             // allow changes to the pin
        GPIO_PORTC_AFSEL_R |= GPIO_PC6_UART3_RX | GPIO_PC7_UART3_TX;          // enable alternate function
        GPIO_PORTC_PCTL_R |= GPIO_PCTL_PC6_UART3_RX | GPIO_PCTL_PC7_UART3_TX; // select the alternate function
        GPIO_PORTC_DIR_R |= GPIO_PC7_UART3_TX;                                // set the Tx as output
        GPIO_PORTC_DIR_R &= ~GPIO_PC6_UART3_RX;                               // set the Rx as input
        GPIO_PORTC_AMSEL_R &= ~(GPIO_PC6_UART3_RX | GPIO_PC7_UART3_TX);       // disable analog mode
        GPIO_PORTC_DEN_R |= GPIO_PC6_UART3_RX | GPIO_PC7_UART3_TX;            // enable digital mode
        break;

    case UART4:
        GPIO_PORTC_CR_R |= GPIO_PC4_UART4_RX | GPIO_PC5_UART4_TX;             // allow changes to the pin
        GPIO_PORTC_AFSEL_R |= GPIO_PC4_UART4_RX | GPIO_PC5_UART4_TX;          // enable alternate function
        GPIO_PORTC_PCTL_R |= GPIO_PCTL_PC4_UART4_RX | GPIO_PCTL_PC5_UART4_TX; // select the alternate function
        GPIO_PORTC_DIR_R |= GPIO_PC5_UART4_TX;                                // set the Tx as output
        GPIO_PORTC_DIR_R &= ~GPIO_PC4_UART4_RX;                               // set the Rx as input
        GPIO_PORTC_AMSEL_R &= ~(GPIO_PC4_UART4_RX | GPIO_PC5_UART4_TX);       // disable analog mode
        GPIO_PORTC_DEN_R |= GPIO_PC4_UART4_RX | GPIO_PC5_UART4_TX;            // enable digital mode
        break;

    case UART5:
        GPIO_PORTE_CR_R |= GPIO_PE4_UART5_RX | GPIO_PE5_UART5_TX;             // allow changes to the pin
        GPIO_PORTE_AFSEL_R |= GPIO_PE4_UART5_RX | GPIO_PE5_UART5_TX;          // enable alternate function
        GPIO_PORTE_PCTL_R |= GPIO_PCTL_PE4_UART5_RX | GPIO_PCTL_PE5_UART5_TX; // select the alternate function
        GPIO_PORTE_DIR_R |= GPIO_PE5_UART5_TX;                                // set the Tx as output
        GPIO_PORTE_DIR_R &= ~GPIO_PE4_UART5_RX;                               // set the Rx as input
        GPIO_PORTE_AMSEL_R &= ~(GPIO_PE4_UART5_RX | GPIO_PE5_UART5_TX);       // disable analog mode
        GPIO_PORTE_DEN_R |= GPIO_PE4_UART5_RX | GPIO_PE5_UART5_TX;            // enable digital mode
        break;

    case UART6:
        GPIO_PORTD_CR_R |= GPIO_PD4_UART6_RX | GPIO_PD5_UART6_TX;             // allow changes to the pin
        GPIO_PORTD_AFSEL_R |= GPIO_PD4_UART6_RX | GPIO_PD5_UART6_TX;          // enable alternate function
        GPIO_PORTD_PCTL_R |= GPIO_PCTL_PD4_UART6_RX | GPIO_PCTL_PD5_UART6_TX; // select the alternate function
        GPIO_PORTD_DIR_R |= GPIO_PD5_UART6_TX;                                // set the Tx as output
        GPIO_PORTD_DIR_R &= ~(GPIO_PD4_UART6_RX);                             // set the Rx as input
        GPIO_PORTD_AMSEL_R &= ~(GPIO_PD4_UART6_RX | GPIO_PD5_UART6_TX);       // disable analog mode
        GPIO_PORTE_DEN_R |= GPIO_PD4_UART6_RX | GPIO_PD5_UART6_TX;            // enable digital mode
        break;

    case UART7:
        GPIO_PORTE_CR_R |= GPIO_PE0_UART7_RX | GPIO_PE1_UART7_TX;             // allow changes to the pin
        GPIO_PORTE_AFSEL_R |= GPIO_PE0_UART7_RX | GPIO_PE1_UART7_TX;          // enable alternate function
        GPIO_PORTE_PCTL_R |= GPIO_PCTL_PE0_UART7_RX | GPIO_PCTL_PE1_UART7_TX; // select the alternate function
        GPIO_PORTE_DIR_R |= GPIO_PE1_UART7_TX;                                // set the Tx as output
        GPIO_PORTE_DIR_R &= ~GPIO_PE0_UART7_RX;                               // set the Rx as input
        GPIO_PORTE_AMSEL_R &= ~(GPIO_PE0_UART7_RX | GPIO_PE1_UART7_TX);       // disable analog mode
        GPIO_PORTE_DEN_R |= GPIO_PE0_UART7_RX | GPIO_PE1_UART7_TX;            // enable digital mode
        break;
    }
}
