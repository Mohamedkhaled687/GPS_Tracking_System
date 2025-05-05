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


 #ifndef _SSI_H_
 #define _SSI_H_
 
 #include "..\..\LIB\std_types.h"
 #include "..\GPIO\GPIO.h"
 #include "..\SysticTimer\SYSTICK.c"
 
 /* SYSCTL REGS */
 #define SYSCTL_RCGCSSI *((volatile unsigned int *) 0x400FE61C)
 
 /* SSI REGISTER MAP */
 #define SSI0_BASE 0x40008000
 #define SSI1_BASE 0x40009000
 #define SSI2_BASE 0x4000A000
 #define SSI3_BASE 0x4000B000
 
 
 typedef struct {
     volatile uint32 SSICR0;     //SSI Control 0
     volatile uint32 SSICR1;     //SSI Control 1
     volatile uint32 SSIDR;      //SSI Data
     volatile uint32 SSISR;      //SSI Status
     volatile uint32 SSICPSR;    //SSI Clock Prescale
     volatile uint32 SSIIM;      //SSI Interrupt Mask
     volatile uint32 SSIRIS;     //SSI Raw Interrupt Status
     volatile uint32 SSIMIS;     //SSI Masked Interrupt Status
     volatile uint32 SSICR;      //SSI Interrupt Clear
     volatile uint32 SSIMACTL;   //SSI DMA Control
     uint32 RESERVED[1000];
     volatile uint32 SSICC;      //SSI Clock Configuration
 } SSI_Regs_t;
 
 typedef enum {
     SSI_MODULE_0,
     SSI_MODULE_1,
     SSI_MODULE_2,
     SSI_MODULE_3,
 }SSI_MODULE_t;
 
 typedef enum {
     SPI_MODE_0, //CPOL = 0, CPHA = 0
     SPI_MODE_1, //CPOL = , CPHA = 1
     SPI_MODE_2, //CPOL = 1, CPHA = 0
     SPI_MODE_3, //CPOL = 1, CPHA = 1
 }SPI_MODE_t;
 
 #define SSI0 ((SSI_Regs_t *) SSI0_BASE)
 #define SSI1 ((SSI_Regs_t *) SSI1_BASE)
 #define SSI2 ((SSI_Regs_t *) SSI2_BASE)
 #define SSI3 ((SSI_Regs_t *) SSI3_BASE)
 
 #define SSI0_TxFIFO_Full ~(config->SSISR & (1U << 1))
 
 /* PROTOTYPES */
 void SSI_Init(SSI_MODULE_t module, SSI_Regs_t *config);
 
 void SSI_Send(SSI_Regs_t *config,const uint8 *data);
 
 
 #endif