#ifndef SSI_TIVAC_H_
#define SSI_TIVAC_H_

/*-----------------------------------------------------------
 * SSI (SPI) Driver for Tiva C Series TM4C123x
 * Description:
 *    Provides basic initialization, send, receive,
 *    and transmit/receive for SPI communication.
 *-----------------------------------------------------------*/

#include "../../LIB/std_types.h"
/*-----------------------------------------------------------
 *  Addresses for enabling/disabling clock gating to the SSI modules
 *-----------------------------------------------------------*/
#define SYSCTL_PERIPH_SSI0    0x00001010  // SSI0 Peripheral
#define SYSCTL_PERIPH_SSI1    0x00001020  // SSI1 Peripheral 
#define SYSCTL_PERIPH_SSI2    0x00001040  // SSI2 Peripheral
#define SYSCTL_PERIPH_SSI3    0x00002000  // SSI3 Peripheral

/*-----------------------------------------------------------
 * Peripheral Base Addresses
 *-----------------------------------------------------------*/
#define SSI0_BASE   0x40008000UL
#define SSI1_BASE   0x40009000UL
#define SSI2_BASE   0x4000A000UL
#define SSI3_BASE   0x4000B000UL

/*-----------------------------------------------------------
 * SSI Register Structure
 *-----------------------------------------------------------*/
typedef struct
{
    volatile uint32 SSICR0;    // Control Register 0
    volatile uint32 SSICR1;    // Control Register 1
    volatile uint32 SSIDR;     // Data Register
    volatile uint32 SSISR;     // Status Register
    volatile uint32 SSICPSR;   // Clock Prescale Register
    volatile uint32 SSIIM;     // Interrupt Mask
    volatile uint32 SSIRIS;    // Raw Interrupt Status
    volatile uint32 SSIMIS;    // Masked Interrupt Status
    volatile uint32 SSIICR;    // Interrupt Clear
    volatile uint32 SSIDMACTL; // DMA Control
} SSI_RegDef_t;

/* Create easy access pointers */
#define SSI0    ((SSI_RegDef_t *)SSI0_BASE)
#define SSI1    ((SSI_RegDef_t *)SSI1_BASE)
#define SSI2    ((SSI_RegDef_t *)SSI2_BASE)
#define SSI3    ((SSI_RegDef_t *)SSI3_BASE)

/*-----------------------------------------------------------
 * SSI Register Bit Definitions
 *-----------------------------------------------------------*/
/* SSICR0 bits */
#define SSI_CR0_SCR_M       0x0000FF00  // Serial Clock Rate Mask
#define SSI_CR0_SPH         (1U << 7)   // Clock Phase
#define SSI_CR0_SPO         (1U << 6)   // Clock Polarity
#define SSI_CR0_FRF_M       0x00000030  // Frame Format Mask
#define SSI_CR0_DSS_M       0x0000000F  // Data Size Select Mask

/* SSICR1 bits */
#define SSI_CR1_SSE         (1U << 1)   // SSI Enable
#define SSI_CR1_MS          (1U << 2)   // Master/Slave Select

/* SSISR bits */
#define SSI_SR_BSY          (1U << 4)   // Busy Flag
#define SSI_SR_TNF          (1U << 1)   // Transmit FIFO Not Full
#define SSI_SR_RNE          (1U << 2)   // Receive FIFO Not Empty

/*-----------------------------------------------------------
 * User Configuration Types
 *-----------------------------------------------------------*/
/* SSI Module */
typedef enum {
    SSI_Module_0,
    SSI_Module_1,
    SSI_Module_2,
    SSI_Module_3
} SSI_Module_t;

/* Master or Slave */
typedef enum {
    SSI_Mode_Master,
    SSI_Mode_Slave
} SSI_Mode_t;

/* SPI Protocol Mode */
typedef enum {
    SSI_Protocol_Mode0, // SPO=0, SPH=0
    SSI_Protocol_Mode1, // SPO=0, SPH=1
    SSI_Protocol_Mode2, // SPO=1, SPH=0
    SSI_Protocol_Mode3  // SPO=1, SPH=1
} SSI_Protocol_t;

/* Data Size Options */
typedef enum {
    SSI_DataSize_4  = 3,
    SSI_DataSize_5,
    SSI_DataSize_6,
    SSI_DataSize_7,
    SSI_DataSize_8,
    SSI_DataSize_9,
    SSI_DataSize_10,
    SSI_DataSize_11,
    SSI_DataSize_12,
    SSI_DataSize_13,
    SSI_DataSize_14,
    SSI_DataSize_15,
    SSI_DataSize_16 = 15
} SSI_DataSize_t;

/* Full SSI Configuration */
typedef struct {
    SSI_Module_t module;       // SSI0, SSI1, etc.
    SSI_Mode_t mode;           // Master or Slave
    SSI_Protocol_t protocol;   // SPI Protocol Mode
    SSI_DataSize_t dataSize;   // Data Size (bits)
    uint32 clockRate;        // SCK Clock in Hz
} SSI_Config_t;

/*-----------------------------------------------------------
 * Function Prototypes
 *-----------------------------------------------------------*/

/**
 * @brief Initialize the selected SSI (SPI) module.
 * @param config Pointer to SSI_Config_t structure.
 * @return true if successful, false if failed.
 */
uint8 SSI_Init(const SSI_Config_t *config);

/**
 * @brief Send a block of data (polling mode).
 * @param module SSI Module (SSI0, SSI1, etc.)
 * @param txBuffer Pointer to transmit buffer.
 * @param len Number of bytes to send.
 * @return true if successful, false if error.
 */
uint8 SSI_Send(SSI_Module_t module, const uint8 *txBuffer, uint32 len);

/**
 * @brief Receive a block of data (polling mode).
 * @param module SSI Module (SSI0, SSI1, etc.)
 * @param rxBuffer Pointer to receive buffer.
 * @param len Number of bytes to receive.
 * @return true if successful, false if error.
 */
uint8 SSI_Receive(SSI_Module_t module, uint8 *rxBuffer, uint32 len);

/**
 * @brief Simultaneous send and receive a frame.
 * @param module SSI Module.
 * @param txData Data to send.
 * @return Received data.
 */
uint16 SSI_TransmitReceive(SSI_Module_t module, uint16 txData);

/**
 * @brief Deinitialize the selected SSI module.
 * @param module SSI Module to deinit.
 */
void SSI_DeInit(SSI_Module_t module);

#endif /* SSI_TIVAC_H_ */
