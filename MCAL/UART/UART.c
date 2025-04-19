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
#include "../GPIO/GPIO.c"

/*
 * Description :
 * Initialize the required UART.
 */

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

/*
 * Description :
 * Configure the required UART.
 */

void UART_Config(const UART_ConfigType *Config_Ptr)
{
    switch (Config_Ptr->uart_number)
    {
    case UART0:
        SET_BIT(SYSCTL_RCGCUART, UART0); // Enable UART0 clock
        GPIO_Init(GPIO_PORTA);           // Initialize GPIO for UART0
        UART_Init(UART0);                // Initialize UART0

        UART0_CTL_R &= ~(UART_CTL_UARTEN); // disable the UART before configuration

        UART0_IBRD_R &= ~(UART_IBRD_MASK); // Clear before write
        UART0_IBRD_R = Config_Ptr->IBRD;   // set integer baud rate

        UART0_FBRD_R &= ~(UART_FBRD_MASK); // Clear before write
        UART0_FBRD_R = Config_Ptr->FBRD;   // set fractional baud rate

        UART0_LCRH_R &= ~((Config_Ptr->DataBits - 5) << UART_LCRH_WLEN); // Clear before write
        UART0_LCRH_R |= (Config_Ptr->DataBits - 5) << UART_LCRH_WLEN;    // set data format

        UART0_LCRH_R |= UART_LCRH_FEN; // Enable FIFOs

        if (Config_Ptr->parity == UART_PARITY_DISABLE)
        {
            UART0_LCRH_R &= ~(UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS); // disable parity
        }
        else if (Config_Ptr->parity == UART_PARITY_ODD)
        {
            UART0_LCRH_R |= (UART_LCRH_PEN | UART_LCRH_SPS) & (~UART_LCRH_EPS); // enable odd parity
        }
        else if (Config_Ptr->parity == UART_PARITY_EVEN)
        {
            UART0_LCRH_R |= UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS;
        }

        if (Config_Ptr->stop_bits == 2)
        {
            UART0_LCRH_R |= UART_LCRH_STP2; // set two stop bits
        }
        else
        {
            UART0_LCRH_R &= ~UART_LCRH_STP2; // set one stop bit
        }

        UART0_CTL_R |= (UART_CTL_UARTEN | UART_CTL_RXE | UART_CTL_TXE); // enable the UART after configuration
        break;

    case UART1:
        SET_BIT(SYSCTL_RCGCUART, UART1); // Enable UART1 clock
        GPIO_Init(GPIO_PORTB);           // Initialize GPIO for UART1
        UART_Init(UART1);                // Initialize UART1

        UART1_CTL_R &= ~(UART_CTL_UARTEN); // disable the UART before configuration

        UART1_IBRD_R &= ~(UART_IBRD_MASK); // Clear before write
        UART1_IBRD_R = Config_Ptr->IBRD;   // set integer baud rate

        UART1_FBRD_R &= ~(UART_FBRD_MASK); // Clear before write
        UART1_FBRD_R = Config_Ptr->FBRD;   // set fractional baud rate

        UART1_LCRH_R &= ~((Config_Ptr->DataBits - 5) << UART_LCRH_WLEN); // Clear before write
        UART1_LCRH_R |= (Config_Ptr->DataBits - 5) << UART_LCRH_WLEN;    // set data format

        UART1_LCRH_R |= UART_LCRH_FEN; // Enable FIFOs

        if (Config_Ptr->parity == UART_PARITY_DISABLE)
        {
            UART1_LCRH_R &= ~(UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS); // disable parity
        }
        else if (Config_Ptr->parity == UART_PARITY_ODD)
        {
            UART1_LCRH_R |= (UART_LCRH_PEN | UART_LCRH_SPS) & (~UART_LCRH_EPS); // enable odd parity
        }
        else if (Config_Ptr->parity == UART_PARITY_EVEN)
        {
            UART1_LCRH_R |= UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS;
        }

        if (Config_Ptr->stop_bits == 2)
        {
            UART1_LCRH_R |= UART_LCRH_STP2; // set two stop bits
        }
        else
        {
            UART1_LCRH_R &= ~UART_LCRH_STP2; // set one stop bit
        }

        UART1_CTL_R |= (UART_CTL_UARTEN | UART_CTL_RXE | UART_CTL_TXE); // enable the UART after configuration
        break;

    case UART2:
        SET_BIT(SYSCTL_RCGCUART, UART2);
        GPIO_Init(GPIO_PORTD);
        UART_Init(UART2);

        UART2_CTL_R &= ~(UART_CTL_UARTEN); // disable the UART before configuration

        UART2_IBRD_R &= ~(UART_IBRD_MASK); // Clear before write
        UART2_IBRD_R = Config_Ptr->IBRD;   // set integer baud rate

        UART2_FBRD_R &= ~(UART_FBRD_MASK); // Clear before write
        UART2_FBRD_R = Config_Ptr->FBRD;   // set fractional baud rate

        UART2_LCRH_R &= ~((Config_Ptr->DataBits - 5) << UART_LCRH_WLEN); // Clear before write
        UART2_LCRH_R |= (Config_Ptr->DataBits - 5) << UART_LCRH_WLEN;    // set data format

        UART2_LCRH_R |= UART_LCRH_FEN; // Enable FIFOs

        if (Config_Ptr->parity == UART_PARITY_DISABLE)
        {
            UART2_LCRH_R &= ~(UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS); // disable parity
        }
        else if (Config_Ptr->parity == UART_PARITY_ODD)
        {
            UART2_LCRH_R |= (UART_LCRH_PEN | UART_LCRH_SPS) & (~UART_LCRH_EPS); // enable odd parity
        }
        else if (Config_Ptr->parity == UART_PARITY_EVEN)
        {
            UART2_LCRH_R |= UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS;
        }

        if (Config_Ptr->stop_bits == 2)
        {
            UART2_LCRH_R |= UART_LCRH_STP2; // set two stop bits
        }
        else
        {
            UART2_LCRH_R &= ~UART_LCRH_STP2; // set one stop bit
        }
        UART2_CTL_R |= (UART_CTL_UARTEN | UART_CTL_RXE | UART_CTL_TXE); // enable the UART after configuration
        break;

    case UART3:
        SET_BIT(SYSCTL_RCGCUART, UART3);
        GPIO_Init(GPIO_PORTC);
        UART_Init(UART3);

        UART3_CTL_R &= ~(UART_CTL_UARTEN); // disable the UART before configuration

        UART3_IBRD_R &= ~(UART_IBRD_MASK); // Clear before write
        UART3_IBRD_R = Config_Ptr->IBRD;   // set integer baud rate

        UART3_FBRD_R &= ~(UART_FBRD_MASK); // Clear before write
        UART3_FBRD_R = Config_Ptr->FBRD;   // set fractional baud rate

        UART3_LCRH_R &= ~((Config_Ptr->DataBits - 5) << UART_LCRH_WLEN); // Clear before write
        UART3_LCRH_R |= (Config_Ptr->DataBits - 5) << UART_LCRH_WLEN;    // set data format

        UART3_LCRH_R |= UART_LCRH_FEN; // Enable FIFOs

        if (Config_Ptr->parity == UART_PARITY_DISABLE)
        {
            UART3_LCRH_R &= ~(UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS); // disable parity
        }

        else if (Config_Ptr->parity == UART_PARITY_ODD)
        {
            UART3_LCRH_R |= (UART_LCRH_PEN | UART_LCRH_SPS) & (~UART_LCRH_EPS); // enable odd parity
        }

        else if (Config_Ptr->parity == UART_PARITY_EVEN)
        {
            UART3_LCRH_R |= UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS;
        }

        if (Config_Ptr->stop_bits == 2)
        {
            UART3_LCRH_R |= UART_LCRH_STP2; // set two stop bits
        }
        else
        {
            UART3_LCRH_R &= ~UART_LCRH_STP2; // set one stop bit
        }

        UART3_CTL_R |= (UART_CTL_UARTEN | UART_CTL_RXE | UART_CTL_TXE); // enable the UART after configuration
        break;

    case UART4:
        SET_BIT(SYSCTL_RCGCUART, UART4);
        GPIO_Init(GPIO_PORTC);
        UART_Init(UART4);

        UART4_CTL_R &= ~(UART_CTL_UARTEN); // disable the UART before configuration

        UART4_IBRD_R &= ~(UART_IBRD_MASK); // Clear before write
        UART4_IBRD_R = Config_Ptr->IBRD;   // set integer baud rate

        UART4_FBRD_R &= ~(UART_FBRD_MASK); // Clear before write
        UART4_FBRD_R = Config_Ptr->FBRD;   // set fractional baud rate

        UART4_LCRH_R &= ~((Config_Ptr->DataBits - 5) << UART_LCRH_WLEN); // Clear before write
        UART4_LCRH_R |= (Config_Ptr->DataBits - 5) << UART_LCRH_WLEN;    // set data format

        UART4_LCRH_R |= UART_LCRH_FEN; // Enable FIFOs

        if (Config_Ptr->parity == UART_PARITY_DISABLE)
        {
            UART4_LCRH_R &= ~(UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS); // disable parity
        }
        else if (Config_Ptr->parity == UART_PARITY_ODD)
        {
            UART4_LCRH_R |= (UART_LCRH_PEN | UART_LCRH_SPS) & (~UART_LCRH_EPS); // enable odd parity
        }
        else if (Config_Ptr->parity == UART_PARITY_EVEN)
        {
            UART4_LCRH_R |= UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS;
        }

        if (Config_Ptr->stop_bits == 2)
        {
            UART4_LCRH_R |= UART_LCRH_STP2; // set two stop bits
        }
        else
        {
            UART4_LCRH_R &= ~UART_LCRH_STP2; // set one stop bit
        }
        UART4_CTL_R |= (UART_CTL_UARTEN | UART_CTL_RXE | UART_CTL_TXE); // enable the UART after configuration
        break;

    case UART5:
        SET_BIT(SYSCTL_RCGCUART, UART5); // Enable UART5 clock
        GPIO_Init(GPIO_PORTE);           // Initialize GPIO for UART5
        UART_Init(UART5);                // Initialize UART5

        UART5_CTL_R &= ~(UART_CTL_UARTEN); // disable the UART before configuration

        UART5_IBRD_R &= ~(UART_IBRD_MASK); // Clear before write
        UART5_IBRD_R = Config_Ptr->IBRD;   // set integer baud rate

        UART5_FBRD_R &= ~(UART_FBRD_MASK); // Clear before write
        UART5_FBRD_R = Config_Ptr->FBRD;   // set fractional baud rate

        UART5_LCRH_R &= ~((Config_Ptr->DataBits - 5) << UART_LCRH_WLEN); // Clear before write
        UART5_LCRH_R |= (Config_Ptr->DataBits - 5) << UART_LCRH_WLEN;    // set data format

        UART5_LCRH_R |= UART_LCRH_FEN; // Enable FIFOs

        if (Config_Ptr->parity == UART_PARITY_DISABLE)
        {
            UART5_LCRH_R &= ~(UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS); // disable parity
        }
        else if (Config_Ptr->parity == UART_PARITY_ODD)
        {
            UART5_LCRH_R |= (UART_LCRH_PEN | UART_LCRH_SPS) & (~UART_LCRH_EPS); // enable odd parity
        }
        else if (Config_Ptr->parity == UART_PARITY_EVEN)
        {
            UART5_LCRH_R |= UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS;
        }

        if (Config_Ptr->stop_bits == 2)
        {
            UART5_LCRH_R |= UART_LCRH_STP2; // set two stop bits
        }
        else
        {
            UART5_LCRH_R &= ~UART_LCRH_STP2; // set one stop bit
        }

        UART5_CTL_R |= (UART_CTL_UARTEN | UART_CTL_RXE | UART_CTL_TXE); // enable the UART after configuration

        break;

    case UART6:
        SET_BIT(SYSCTL_RCGCUART, UART6); // Enable UART6 clock
        GPIO_Init(GPIO_PORTD);           // Initialize GPIO for UART6
        UART_Init(UART6);                // Initialize UART6

        UART6_CTL_R &= ~(UART_CTL_UARTEN); // disable the UART before configuration

        UART6_IBRD_R &= ~(UART_IBRD_MASK); // Clear before write
        UART6_IBRD_R = Config_Ptr->IBRD;   // set integer baud rate

        UART6_FBRD_R &= ~(UART_FBRD_MASK); // Clear before write
        UART6_FBRD_R = Config_Ptr->FBRD;   // set fractional baud rate

        UART6_LCRH_R &= ~((Config_Ptr->DataBits - 5) << UART_LCRH_WLEN); // Clear before write
        UART6_LCRH_R |= (Config_Ptr->DataBits - 5) << UART_LCRH_WLEN;    // set data format

        UART6_LCRH_R |= UART_LCRH_FEN; // Enable FIFOs

        if (Config_Ptr->parity == UART_PARITY_DISABLE)
        {
            UART6_LCRH_R &= ~(UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS); // disable parity
        }
        else if (Config_Ptr->parity == UART_PARITY_ODD)
        {
            UART6_LCRH_R |= (UART_LCRH_PEN | UART_LCRH_SPS) & (~UART_LCRH_EPS); // enable odd parity
        }
        else if (Config_Ptr->parity == UART_PARITY_EVEN)
        {
            UART6_LCRH_R |= UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS;
        }

        if (Config_Ptr->stop_bits == 2)
        {
            UART6_LCRH_R |= UART_LCRH_STP2; // set two stop bits
        }
        else
        {
            UART6_LCRH_R &= ~UART_LCRH_STP2; // set one stop bit
        }

        UART6_CTL_R |= (UART_CTL_UARTEN | UART_CTL_RXE | UART_CTL_TXE); // enable the UART after configuration
        break;

    case UART7:
        SET_BIT(SYSCTL_RCGCUART, UART7); // Enable UART7 clock
        GPIO_Init(GPIO_PORTE);           // Initialize GPIO for UART7
        UART_Init(UART7);                // Initialize UART7

        UART7_CTL_R &= ~(UART_CTL_UARTEN); // disable the UART before configuration

        UART7_IBRD_R &= ~(UART_IBRD_MASK); // Clear before write
        UART7_IBRD_R = Config_Ptr->IBRD;   // set integer baud rate

        UART7_FBRD_R &= ~(UART_FBRD_MASK); // Clear before write
        UART7_FBRD_R = Config_Ptr->FBRD;   // set fractional baud rate

        UART7_LCRH_R &= ~((Config_Ptr->DataBits - 5) << UART_LCRH_WLEN); // Clear before write
        UART7_LCRH_R |= (Config_Ptr->DataBits - 5) << UART_LCRH_WLEN;    // set data format

        UART7_LCRH_R |= UART_LCRH_FEN; // Enable FIFOs

        if (Config_Ptr->parity == UART_PARITY_DISABLE)
        {
            UART7_LCRH_R &= ~(UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS); // disable parity
        }
        else if (Config_Ptr->parity == UART_PARITY_ODD)
        {
            UART7_LCRH_R |= (UART_LCRH_PEN | UART_LCRH_SPS) & (~UART_LCRH_EPS); // enable odd parity
        }
        else if (Config_Ptr->parity == UART_PARITY_EVEN)
        {
            UART7_LCRH_R |= UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS;
        }

        if (Config_Ptr->stop_bits == 2)
        {
            UART7_LCRH_R |= UART_LCRH_STP2; // set two stop bits
        }
        else
        {
            UART7_LCRH_R &= ~UART_LCRH_STP2; // set one stop bit
        }

        UART7_CTL_R |= (UART_CTL_UARTEN | UART_CTL_RXE | UART_CTL_TXE); // enable the UART after configuration
        break;
    }
}

/*
 * Description :
 * Check the read for the required UART.
 */

uint8 UART_ReadAvailable(UART_Select uart_number)
{

    switch (uart_number)
    {
    case UART0:
        return ((UART0_FR_R & UART_FR_RXFE) == (UART_FR_RXFE)) ? 1 : 0; // check if the receive FIFO is empty

    case UART1:
        return ((UART1_FR_R & UART_FR_RXFE) == (UART_FR_RXFE)) ? 1 : 0; // check if the receive FIFO is empty

    case UART2:
        return ((UART2_FR_R & UART_FR_RXFE) == (UART_FR_RXFE)) ? 1 : 0; // check if the receive FIFO is empty

    case UART3:
        return ((UART3_FR_R & UART_FR_RXFE) == (UART_FR_RXFE)) ? 1 : 0; // check if the receive FIFO is empty

    case UART4:
        return ((UART4_FR_R & UART_FR_RXFE) == (UART_FR_RXFE)) ? 1 : 0; // check if the receive FIFO is empty

    case UART5:
        return ((UART5_FR_R & UART_FR_RXFE) == (UART_FR_RXFE)) ? 1 : 0; // check if the receive FIFO is empty

    case UART6:
        return ((UART6_FR_R & UART_FR_RXFE) == (UART_FR_RXFE)) ? 1 : 0; // check if the receive FIFO is empty

    case UART7:
        return ((UART7_FR_R & UART_FR_RXFE) == (UART_FR_RXFE)) ? 1 : 0; // check if the receive FIFO is empty
    }
}

/*
 * Description :
 * Check the Send for the required UART.
 */

uint8 UART_SendAvailable(UART_Select uart_number)
{

    switch (uart_number)
    {
    case UART0:
        return ((UART0_FR_R & UART_FR_TXFF) == (UART_FR_TXFF)) ? 1 : 0; // check if the transmit FIFO is full

    case UART1:
        return ((UART1_FR_R & UART_FR_TXFF) == (UART_FR_TXFF)) ? 1 : 0; // check if the transmit FIFO is full

    case UART2:
        return ((UART2_FR_R & UART_FR_TXFF) == (UART_FR_TXFF)) ? 1 : 0; // check if the transmit FIFO is full

    case UART3:
        return ((UART3_FR_R & UART_FR_TXFF) == (UART_FR_TXFF)) ? 1 : 0; // check if the transmit FIFO is full

    case UART4:
        return ((UART4_FR_R & UART_FR_TXFF) == (UART_FR_TXFF)) ? 1 : 0; // check if the transmit FIFO is full

    case UART5:
        return ((UART5_FR_R & UART_FR_TXFF) == (UART_FR_TXFF)) ? 1 : 0; // check if the transmit FIFO is full

    case UART6:
        return ((UART7_FR_R & UART_FR_TXFF) == (UART_FR_TXFF)) ? 1 : 0; // check if the transmit FIFO is full

    case UART7:
        return ((UART7_FR_R & UART_FR_TXFF) == (UART_FR_TXFF)) ? 1 : 0; // check if the transmit FIFO is full
    }
}

/*
 * Description :
 * Functional responsible for send byte to another UART device.
 */
void UART_SendByte(UART_Select uart_number, const uint8 data)
{

    switch (uart_number)
    {
    case UART0:
        while ((UART_SendAvailable(UART0)))
            ;              // wait until the transmit FIFO is empty
        UART0_DR_R = data; // send the data
        break;

    case UART1:
        while ((UART_SendAvailable(UART1)))
            ;              // wait until the transmit FIFO is empty
        UART1_DR_R = data; // send the data
        break;

    case UART2:
        while ((UART_SendAvailable(UART2)))
            ;              // wait until the transmit FIFO is empty
        UART2_DR_R = data; // send the data
        break;

    case UART3:
        while ((UART_SendAvailable(UART3)))
            ;              // wait until the transmit FIFO is empty
        UART3_DR_R = data; // send the data
        break;

    case UART4:
        while ((UART_SendAvailable(UART4)))
            ;              // wait until the transmit FIFO is empty
        UART4_DR_R = data; // send the data
        break;

    case UART5:
        while ((UART_SendAvailable(UART5)))
            ;              // wait until the transmit FIFO is empty
        UART5_DR_R = data; // send the data
        break;

    case UART6:
        while ((UART_SendAvailable(UART6)))
            ;              // wait until the transmit FIFO is empty
        UART6_DR_R = data; // send the data
        break;

    case UART7:
        while (!(UART_SendAvailable(UART7)))
            ;              // wait until the transmit FIFO is empty
        UART7_DR_R = data; // send the data
        break;
    }
}

/*
 * Description :
 * Functional responsible for receive byte from another UART device.
 */
uint8 UART_recieveByte(UART_Select uart_number)
{

    switch (uart_number)
    {
    case UART0:
        while ((UART_ReadAvailable(UART0)))
            ;                                // wait until the receive FIFO is not empty
        return UART0_DR_R &= UART_DATA_MASK; // receive the data

    case UART1:
        while ((UART_ReadAvailable(UART1)))
            ;                                // wait until the receive FIFO is not empty
        return UART1_DR_R &= UART_DATA_MASK; // receive the data

    case UART2:
        while ((UART_ReadAvailable(UART2)))
            ;                                // wait until the receive FIFO is not empty
        return UART2_DR_R &= UART_DATA_MASK; // receive the data

    case UART3:
        while ((UART_ReadAvailable(UART3)))
            ;                                // wait until the receive FIFO is not empty
        return UART3_DR_R &= UART_DATA_MASK; // receive the data

    case UART4:
        while ((UART_ReadAvailable(UART4)))
            ;                                // wait until the receive FIFO is not empty
        return UART4_DR_R &= UART_DATA_MASK; // receive the data

    case UART5:
        while ((UART_ReadAvailable(UART5)))
            ;                                // wait until the receive FIFO is not empty
        return UART5_DR_R &= UART_DATA_MASK; // receive the data

    case UART6:
        while ((UART_ReadAvailable(UART6)))
            ;                                // wait until the receive FIFO is not empty
        return UART6_DR_R &= UART_DATA_MASK; // receive the data
    case UART7:
        while ((UART_ReadAvailable(UART7)))
            ;                                // wait until the receive FIFO is not empty
        return UART7_DR_R &= UART_DATA_MASK; // receive the data
    }
}

/*
 * Description :
 * Functional responsible for send string to another UART device.
 */
void UART_SendString(UART_Select uart_number, const uint8 *str)
{
    while (*str != '\0') // loop until the end of the string
    {
        UART_SendByte(uart_number, *str); // send each character
        str++;                            // move to the next character
    }
}

/*
 * Description :
 * Functional responsible for receive string from another UART device.
 */
void UART_recieveString(UART_Select uart_number, uint8 *buffer)
{
    int i = 0;  // index for the buffer
    uint8 data; // variable to store the received data

    while (1) // infinite loop
    {
        data = UART_recieveByte(uart_number); // receive the data
        if (data == '\0')                     // check if the end of the string is reached
        {
            break; // exit the loop
        }
        buffer[i] = data; // store the received data in the buffer
        i++;              // move to the next index
    }
    buffer[i] = '\0'; // add the null terminator to the end of the string
}