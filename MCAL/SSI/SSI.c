/******************************************************************************
 *
 * Module: SSI
 *
 * File Name: SSI.h
 *
 * Description: Source file for the Tiva C SSI driver
 *
 * Author: Ahmed Mustafa
 *
 *******************************************************************************/
#include "SSI.h"

void SSI_Init(SSI_MODULE_t module, SSI_Regs_t *config) {
    switch(module) {
        case SSI_MODULE_0:
            SYSCTL_RCGCSSI |= 0x01;

            GPIO_Init(GPIO_PORTA);
            GPIO_Pin_Init(GPIO_PORTA, PIN_2);
            GPIO_Pin_Init(GPIO_PORTA, PIN_4);
            GPIO_Pin_Init(GPIO_PORTA, PIN_5);

            GPIO_PORTA_PCTL_R &= ~(0xF << 8);
            GPIO_PORTA_PCTL_R |= (0x2 << 8);
            GPIO_PORTA_PCTL_R &= ~(0xF << 16);
            GPIO_PORTA_PCTL_R |= (0x2 << 16);
            GPIO_PORTA_PCTL_R &= ~(0xF << 20);
            GPIO_PORTA_PCTL_R |= (0x2 << 20);

            GPIO_setupPinMode(GPIO_PORTA, PIN_2, Pull_up, PIN_OUTPUT);
            GPIO_setupPinMode(GPIO_PORTA, PIN_4, Pull_up, PIN_OUTPUT);
            GPIO_setupPinMode(GPIO_PORTA, PIN_5, Pull_up, PIN_OUTPUT);

            config->SSICR1  &= ~(0x17);  //Clear SSICR1
            config->SSICR1  &= ~(0x1);   //Set to Master
            config->SSICC   &= ~(0xF);   //Use System Clock
            config->SSICPSR |= (0x2);    //Set CPSDVSR
            config->SSICR0  &= ~(0xFF << 8); //Set SCR to 0
            config->SSICR0  &= ~(0xC << 4); //CPOL = 0, SPO = 0
            config->SSICR0  &= ~(0x3 << 4); //FRF = 0 Freescale SPI Frame Format
            config->SSICR0 |= (0x7);        //8-bit data size
            config->SSIMACTL |= (0x2);      //TxFIFO Enabled
            
            break;
        case(SSI_MODULE_1):
        break;
        case(SSI_MODULE_2):
        break;
        case(SSI_MODULE_3):
        break;
    }
}

void SSI_Send(SSI_Regs_t *config, const uint8 *data) {
    while(((config->SSIDR) & SSI0_FIFO_Empty) == SSI0_FIFO_Empty);
    config->SSIDR = *data;
    return;
}