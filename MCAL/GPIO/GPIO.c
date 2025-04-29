/******************************************************************************
 *
 * Module: GPIO
 *
 * File Name: gpio.c
 *
 * Description: Source file for the Tiva C GPIO driver
 *
 * Author: Mohamed Khaled
 *
 *******************************************************************************/

#include "GPIO.h"

/*
 * Description :
 * give the clock to the GPIO.
 */

void GPIO_Init(GPIO_PortType port)
{

    switch (port)
    {
    case GPIO_PORTA:
        SET_BIT(RCGCGPIO, GPIO_PORTA);
        while (BIT_IS_CLEAR(PRGPIO, GPIO_PORTA))
            ;                              // wait until the clock is enabled
        GPIO_PORTA_LOCK_R = GPIO_LOCK_KEY; // unlock the GPIO port
        break;

    case GPIO_PORTB:
        SET_BIT(RCGCGPIO, GPIO_PORTB);
        while (BIT_IS_CLEAR(PRGPIO, GPIO_PORTB))
            ;                              // wait until the clock is enabled for GPIOB
        GPIO_PORTB_LOCK_R = GPIO_LOCK_KEY; // unlock the GPIO port
        break;

    case GPIO_PORTC:
        SET_BIT(RCGCGPIO, GPIO_PORTC);
        while (BIT_IS_CLEAR(PRGPIO, GPIO_PORTC))
            ;                              // wait until the clock is enabled for GPIOC
        GPIO_PORTC_LOCK_R = GPIO_LOCK_KEY; // unlock the GPIO port
        break;

    case GPIO_PORTD:
        SET_BIT(RCGCGPIO, GPIO_PORTD);
        while (BIT_IS_CLEAR(PRGPIO, GPIO_PORTD))
            ;                              // wait until the clock is enabled for GPIOD
        GPIO_PORTD_LOCK_R = GPIO_LOCK_KEY; // unlock the GPIO port
        break;

    case GPIO_PORTE:
        SET_BIT(RCGCGPIO, GPIO_PORTE);
        while (BIT_IS_CLEAR(PRGPIO, GPIO_PORTE))
            ;                              // wait until the clock is enabled for GPIOE
        GPIO_PORTE_LOCK_R = GPIO_LOCK_KEY; // unlock the GPIO port
        break;

    case GPIO_PORTF:
        SET_BIT(RCGCGPIO, GPIO_PORTF);
        while (BIT_IS_CLEAR(PRGPIO, GPIO_PORTF))
            ;                              // wait until the clock is enabled for GPIOF
        GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY; // unlock the GPIO port
        break;
    }
}

/*
 * Description :
 * Initialize the GPIO given pin.
 */

void GPIO_Pin_Init(GPIO_PortType port, uint32 pin)
{

    switch (port)
    {
    case GPIO_PORTA:
        SET_BIT(GPIO_PORTA_CR_R, pin);      // allow changes to the pin
        CLEAR_BIT(GPIO_PORTA_AMSEL_R, pin); // disable analog mode
        CLEAR_BIT(GPIO_PORTA_AFSEL_R, pin); // disable alternate function
        break;

    case GPIO_PORTB:
        SET_BIT(GPIO_PORTB_CR_R, pin);      // allow changes to the pin
        CLEAR_BIT(GPIO_PORTB_AMSEL_R, pin); // disable analog mode
        CLEAR_BIT(GPIO_PORTB_AFSEL_R, pin); // disable alternate function
        break;

    case GPIO_PORTC:
        SET_BIT(GPIO_PORTC_CR_R, pin);      // allow changes to the pin
        CLEAR_BIT(GPIO_PORTC_AMSEL_R, pin); // disable analog mode
        CLEAR_BIT(GPIO_PORTC_AFSEL_R, pin); // disable alternate function
        break;

    case GPIO_PORTD:
        SET_BIT(GPIO_PORTD_CR_R, pin);      // allow changes to the pin
        CLEAR_BIT(GPIO_PORTD_AMSEL_R, pin); // disable analog mode
        CLEAR_BIT(GPIO_PORTD_AFSEL_R, pin); // disable alternate function
        break;

    case GPIO_PORTE:
        SET_BIT(GPIO_PORTE_CR_R, pin);      // allow changes to the pin
        CLEAR_BIT(GPIO_PORTE_AMSEL_R, pin); // disable analog mode
        CLEAR_BIT(GPIO_PORTE_AFSEL_R, pin); // disable alternate function
        break;

    case GPIO_PORTF:
        SET_BIT(GPIO_PORTF_CR_R, pin);      // allow changes to the pin
        CLEAR_BIT(GPIO_PORTF_AMSEL_R, pin); // disable analog mode
        CLEAR_BIT(GPIO_PORTF_AFSEL_R, pin); // disable alternate function
        break;
    }
}

/*
 * Description :
 * Setup the Mode of the required pin input/output.
 */

void GPIO_setupPinMode(GPIO_PortType port, uint8 pin, GPIO_Polarity_Select Polarity, GPIO_PinDirectionType direction)
{

    switch (port)
    {
    case GPIO_PORTA:
        if (direction == PIN_OUTPUT)
        {
            SET_BIT(GPIO_PORTA_DIR_R, pin); // set the pin as output
        }
        else
        {
            CLEAR_BIT(GPIO_PORTA_DIR_R, pin); // set the pin as input
        }
        if (Polarity == Pull_up)
        {
            SET_BIT(GPIO_PORTA_PUR_R, pin); // enable pull up resistor
        }
        else if (Polarity == Pull_down)
        {
            SET_BIT(GPIO_PORTA_PDR_R, pin); // enable pull down resistor
        }
        else
        {
            CLEAR_BIT(GPIO_PORTA_PUR_R, pin); // disable pull up resistor
            CLEAR_BIT(GPIO_PORTA_PDR_R, pin); // disable pull down resistor
        }
        SET_BIT(GPIO_PORTA_DEN_R, pin); // enable digital mode
        break;

    case GPIO_PORTB:
        if (direction == PIN_OUTPUT)
        {
            SET_BIT(GPIO_PORTB_DIR_R, pin); // set the pin as output
        }
        else
        {
            CLEAR_BIT(GPIO_PORTB_DIR_R, pin); // set the pin as input
        }
        if (Polarity == Pull_up)
        {
            SET_BIT(GPIO_PORTB_PUR_R, pin); // enable pull up resistor
        }
        else if (Polarity == Pull_down)
        {
            SET_BIT(GPIO_PORTB_PDR_R, pin); // enable pull down resistor
        }
        else
        {
            CLEAR_BIT(GPIO_PORTB_PUR_R, pin); // disable pull up resistor
            CLEAR_BIT(GPIO_PORTB_PDR_R, pin); // disable pull down resistor
        }
        SET_BIT(GPIO_PORTB_DEN_R, pin); // enable digital mode
        break;

    case GPIO_PORTC:

        if (direction == PIN_OUTPUT)
        {
            SET_BIT(GPIO_PORTC_DIR_R, pin); // set the pin as output
        }
        else
        {
            CLEAR_BIT(GPIO_PORTC_DIR_R, pin); // set the pin as input
        }
        if (Polarity == Pull_up)
        {
            SET_BIT(GPIO_PORTC_PUR_R, pin); // enable pull up resistor
        }
        else if (Polarity == Pull_down)
        {
            SET_BIT(GPIO_PORTC_PDR_R, pin); // enable pull down resistor
        }
        else
        {
            CLEAR_BIT(GPIO_PORTC_PUR_R, pin); // disable pull up resistor
            CLEAR_BIT(GPIO_PORTC_PDR_R, pin); // disable pull down resistor
        }
        SET_BIT(GPIO_PORTC_DEN_R, pin); // enable digital mode
        break;

    case GPIO_PORTD:
        if (direction == PIN_OUTPUT)
        {
            SET_BIT(GPIO_PORTD_DIR_R, pin); // set the pin as output
        }
        else
        {
            CLEAR_BIT(GPIO_PORTD_DIR_R, pin); // set the pin as input
        }
        if (Polarity == Pull_up)
        {
            SET_BIT(GPIO_PORTD_PUR_R, pin); // enable pull up resistor
        }
        else if (Polarity == Pull_down)
        {
            SET_BIT(GPIO_PORTD_PDR_R, pin); // enable pull down resistor
        }
        else
        {
            CLEAR_BIT(GPIO_PORTD_PUR_R, pin); // disable pull up resistor
            CLEAR_BIT(GPIO_PORTD_PDR_R, pin); // disable pull down resistor
        }
        SET_BIT(GPIO_PORTD_DEN_R, pin); // enable digital mode
        break;

    case GPIO_PORTE:
        if (direction == PIN_OUTPUT)
        {
            SET_BIT(GPIO_PORTE_DIR_R, pin); // set the pin as output
        }
        else
        {
            CLEAR_BIT(GPIO_PORTE_DIR_R, pin); // set the pin as input
        }
        if (Polarity == Pull_up)
        {
            SET_BIT(GPIO_PORTE_PUR_R, pin); // enable pull up resistor
        }
        else if (Polarity == Pull_down)
        {
            SET_BIT(GPIO_PORTE_PDR_R, pin); // enable pull down resistor
        }
        else
        {
            CLEAR_BIT(GPIO_PORTE_PUR_R, pin); // disable pull up resistor
            CLEAR_BIT(GPIO_PORTE_PDR_R, pin); // disable pull down resistor
        }
        SET_BIT(GPIO_PORTE_DEN_R, pin); // enable digital mode
        break;

    case GPIO_PORTF:
        if (direction == PIN_OUTPUT)
        {
            SET_BIT(GPIO_PORTF_DIR_R, pin); // set the pin as output
        }
        else
        {
            CLEAR_BIT(GPIO_PORTF_DIR_R, pin); // set the pin as input
        }
        if (Polarity == Pull_up)
        {
            SET_BIT(GPIO_PORTF_PUR_R, pin); // enable pull up resistor
        }
        else if (Polarity == Pull_down)
        {
            SET_BIT(GPIO_PORTF_PDR_R, pin); // enable pull down resistor
        }
        else
        {
            CLEAR_BIT(GPIO_PORTF_PUR_R, pin); // disable pull up resistor
            CLEAR_BIT(GPIO_PORTF_PDR_R, pin); // disable pull down resistor
        }
        SET_BIT(GPIO_PORTF_DEN_R, pin); // enable digital mode
        break;
    }
}

/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 */

void GPIO_writePin(GPIO_PortType port, uint8 pin, uint8 value)
{
    switch (port)
    {
    case GPIO_PORTA:
        if (value == LOGIC_HIGH)
        {
            SET_BIT(GPIO_PORTA_DATA_R, pin); // write logic high on the pin
        }
        else
        {
            CLEAR_BIT(GPIO_PORTA_DATA_R, pin); // write logic low on the pin
        }
        break;
    case GPIO_PORTB:
        if (value == LOGIC_HIGH)
        {
            SET_BIT(GPIO_PORTB_DATA_R, pin); // write logic high on the pin
        }
        else
        {
            CLEAR_BIT(GPIO_PORTB_DATA_R, pin); // write logic low on the pin
        }
        break;
    case GPIO_PORTC:
        if (value == LOGIC_HIGH)
        {
            SET_BIT(GPIO_PORTC_DATA_R, pin); // write logic high on the pin
        }
        else
        {
            CLEAR_BIT(GPIO_PORTC_DATA_R, pin); // write logic low on the pin
        }
        break;

    case GPIO_PORTD:
        if (value == LOGIC_HIGH)
        {
            SET_BIT(GPIO_PORTD_DATA_R, pin); // write logic high on the pin
        }
        else
        {
            CLEAR_BIT(GPIO_PORTD_DATA_R, pin); // write logic low on the pin
        }
        break;

    case GPIO_PORTE:
        if (value == LOGIC_HIGH)
        {
            SET_BIT(GPIO_PORTE_DATA_R, pin); // write logic high on the pin
        }
        else
        {
            CLEAR_BIT(GPIO_PORTE_DATA_R, pin); // write logic low on the pin
        }
        break;

    case GPIO_PORTF:
        if (value == LOGIC_HIGH)
        {
            SET_BIT(GPIO_PORTF_DATA_R, pin); // write logic high on the pin
        }
        else
        {
            CLEAR_BIT(GPIO_PORTF_DATA_R, pin); // write logic low on the pin
        }
        break;
    }
}

/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 */
uint8 GPIO_readPin(GPIO_PortType port, uint8 pin)
{
    switch (port)
    {
    case GPIO_PORTA:
        return GET_BIT(GPIO_PORTA_DATA_R, pin); // read the value of the pin
    case GPIO_PORTB:
        return GET_BIT(GPIO_PORTB_DATA_R, pin); // read the value of the pin
    case GPIO_PORTC:
        return GET_BIT(GPIO_PORTC_DATA_R, pin); // read the value of the pin
    case GPIO_PORTD:
        return GET_BIT(GPIO_PORTD_DATA_R, pin); // read the value of the pin
    case GPIO_PORTE:
        return GET_BIT(GPIO_PORTE_DATA_R, pin); // read the value of the pin
    case GPIO_PORTF:
        return GET_BIT(GPIO_PORTF_DATA_R, pin); // read the value of the pin
    default:
        return LOGIC_LOW; // Return low for invalid port
    }
}
