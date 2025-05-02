/**
 ******************************************************************************
 * @file    SSI_TivaC.c
 * @author  Houssam Magdy
 * @brief   Tiva C SSI (SPI) Driver Implementation
 ******************************************************************************
 *
 *
 * This file implements the functions for the Tiva C SSI peripheral,
 * which is used for SPI and other synchronous serial communication.
 *
 * IMPORTANT NOTES:
 * 1. GPIO Configuration: You MUST add code to configure the specific
 * GPIO pins used by your chosen SSI module (CLK, FSS, RX, TX).
 * 2. Clock Calculation: You MUST add code to calculate the correct
 * SSICPSR and SSICR0[SCR] values based on your desired clock rate
 * and the system clock frequency.
 * 3. Error Handling: This is a basic polling driver. More robust
 * applications may require interrupt-driven or DMA-based transfers,
 * as well as more comprehensive error handling and timeouts.
 * 4. Data Size: Transfer functions use uint16_t for compatibility up
 * to 16-bit data, but you might need to adapt for strict 8-bit
 * transfers or if using other data sizes.
 *
 ******************************************************************************
 */

// Include the SSI Driver header file
#include "SPI.h" // Assuming your header is named SSI_TivaC.h

// Include necessary system/library headers
#include <stddef.h> // For NULL
#include "../../LIB/std_types.h"
#include "../../MCAL/SysticTimer/SYSTICK.h"
// #include "../../MCAL/SYSCTL/SYSCTL.h" // Assumes System Control functions are defined here
//  Assuming uint8, uint16, uint32 are defined in std_types.h,
//  but explicitly including stdint.h for standard types is good practice.

// Array of pointers to the base addresses of the SSI modules
// Allows accessing the correct module registers using the SSI_Module_t enum
// These pointers (SSI0, SSI1, etc.) are defined in SSI_TivaC.h
static SSI_RegDef_t *const SSI_Modules[] = {SSI0, SSI1, SSI2, SSI3};

// // Define a simple delay function (if not available elsewhere)
// // A more precise wait might involve checking the SYSCTL Peripheral Ready register
// static void SSI_DelayUs(uint32_t us)
// {
//     // Simple busy-wait loop - replace with a timer-based delay if needed
//     volatile uint32 i;
//     // Approximate loop count per microsecond - needs tuning based on CPU frequency
//     // Adjust this value based on your microcontroller's clock speed
//     uint32 cycles_per_us = 10; // Example value; adjust based on your system clock
//     for (i = 0; i < (us * cycles_per_us); ++i);
// }

/**
 * @brief:: Initializes the specified SSI module based on configuration.
 * @param ::config Pointer to the configuration structure (cannot be NULL).
 * @return ::true if initialization is successful, false otherwise.
 */
uint8 SSI_Init(const SSI_Config_t *config)
{
    // Validate configuration pointer and module index
    if (config == NULL || config->module > SSI_Module_3)
    {
        return FALSE; // Invalid configuration
    }

    // Get the base azddress pointer for the selected SSI module
    SSI_RegDef_t *ssi = SSI_Modules[config->module];

    // --- STEP 1: Enable and Configure GPIO Pins ---
    // This is a critical step not fully implemented here.
    // You MUST:
    // 1. Enable the clock for the GPIO port(s) used by the SSI module
    //    (e.g., SYSCTL_EnablePeripheral(SYSCTL_PERIPH_GPIOA); for SSI0)
    // 2. Unlock and commit GPIO registers if needed (for certain pins like PF0)
    // 3. Configure the specific pins (CLK, FSS, RX, TX) for their alternative
    //    functionality as SSI pins using the GPIO_PCTL register.
    // 4. Configure pin direction (e.g., TX as output, RX as input).
    // 5. Configure pull-up/down resistors or drive strength if required.
    //
    // Example placeholder (replace with your actual GPIO setup code):
    /*
    switch(config->module)
    {
        case SSI_Module_0:
            // Configure GPIO Port A pins PA2-PA5 for SSI0
            // You need to include your GPIO driver header here, e.g., #include "../../MCAL/GPIO/GPIO.h"
            // And use your GPIO driver functions to configure the pins.
            // Example (using hypothetical GPIO driver functions):
            // GPIO_EnableClock(GPIO_PORTA);
            // GPIO_SetPinAlternateFunction(GPIO_PORTA, GPIO_PIN_2, GPIO_ALT_FUNC_SSI0); // CLK
            // GPIO_SetPinAlternateFunction(GPIO_PORTA, GPIO_PIN_3, GPIO_ALT_FUNC_SSI0); // FSS
            // GPIO_SetPinAlternateFunction(GPIO_PORTA, GPIO_PIN_4, GPIO_ALT_FUNC_SSI0); // RX
            // GPIO_SetPinAlternateFunction(GPIO_PORTA, GPIO_PIN_5, GPIO_ALT_FUNC_SSI0); // TX
            // GPIO_SetPinDigitalEnable(GPIO_PORTA, GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5);
            // For Master mode, configure TX as output, RX as input. For Slave, TX as input, RX as output.
            break;
        case SSI_Module_1:
            // Configure GPIO Port F pins PF0-PF3 for SSI1 (requires unlock/commit for PF0)
            // ... your GPIO configuration code ...
            break;
        // Add cases for SSI_Module_2 (Port B), SSI_Module_3 (Port D) as needed
    }
    */

    // --- STEP 2: Enable SSI Module Clock ---
    // Enable the clock for the selected SSI peripheral in SYSCTL
    // SYSCTL_PERIPH_SSI0 is assumed to be the base for SSI peripheral enums
    SYSCTL_EnablePeripheral(SYSCTL_PERIPH_SSI0 + config->module);

    // Wait for the SSI peripheral to be ready (check SYSCTL_PRSSI register)
    // You need to access the SYSCTL_PRSSI register (Peripheral Ready for SSI)
    // while (! (SYSCTL->PRSSI & (1 << config->module)) ); // Example check (adjust register access if needed)
    SysTick_DelayUs(10); // Simple delay as a placeholder if PRSSI check is not implemented

    // --- STEP 3: Configure SSI Module ---

    // Disable the SSI module before configuration changes (clear SSE bit in SSICR1)
    // Using the macro from your header: SSI_CR1_SSE
    CLR_BIT(ssi->SSICR1, SSI_CR1_SSE);

    // Configure Master/Slave Mode (MS bit in SSICR1)
    // Using the macro from your header: SSI_CR1_MS
    if (config->mode == SSI_Mode_Slave)
    {
        SET_BIT(ssi->SSICR1, SSI_CR1_MS); // Set MS bit for Slave mode
        // Note: Slave mode might require additional SOD (Slave Mode Output Disable) configuration
    }
    else
    {                                     // SSI_Mode_Master
        CLR_BIT(ssi->SSICR1, SSI_CR1_MS); // Clear MS bit for Master mode
    }

    // --- STEP 4: Set Clock Prescale and Serial Clock Rate ---
    // This is a critical step not fully implemented here.
    // You MUST calculate the SSICPSR and the SCR field in SSICR0 based on:
    // - Your system clock frequency (SysClk)
    // - Your desired SSI clock rate (config->clockRate)
    // The formula is complex: ClockRate = SysClk / (SSICPSR * (1 + SSICR0[SCR]))
    // You need to find the smallest valid SSICPSR (an even number between 2 and 254)
    // and the corresponding SCR (between 0 and 255) to get as close as possible
    // to the desired clockRate.
    //
    // Example placeholder (replace with your actual calculation):
    /*
    uint32_t sysClk = SYSCTL_GetSystemClockFreq(); // Assumes SYSCTL driver provides this
    uint32_t ssiClk = config->clockRate;
    uint32_t ssicpsd = 2; // SSICPSR value (start with minimum even value)
    uint32_t scr = 0;     // SSICR0[SCR] value

    // Calculation logic here... find ssicpsd (even, 2-254) and scr (0-255)
    // to satisfy ClockRate = SysClk / (ssicpsd * (1 + scr))
    // You might iterate through possible ssicpsd values and calculate the required scr.
    // Ensure scr is within 0-255.

    ssi->SSICPSR = ssicpsd;
    // Clear existing SCR bits and set the new value
    // Using the mask from your header: SSI_CR0_SCR_M
    ssi->SSICR0 &= ~SSI_CR0_SCR_M;
    ssi->SSICR0 |= (scr << 8);       // Shift SCR value into position
    */

    // --- Current hardcoded clock setup (replace with calculation above) ---
    ssi->SSICPSR = 2;              // Example: setting prescale to 2
    ssi->SSICR0 &= ~SSI_CR0_SCR_M; // Clear SCR field using mask from header
    ssi->SSICR0 |= (0 << 8);       // Example: setting SCR to 0
    // This hardcoded setup results in SSI_Clk = SysClk / (2 * (1 + 0)) = SysClk / 2

    // --- STEP 5: Set SSICR0 Register (SPO, SPH, FRF, DSS) ---
    // Configure Clock Polarity (SPO), Clock Phase (SPH), Frame Format (FRF), Data Size Select (DSS)
    // SCR bits were handled above.
    // Using masks and bits from your header: SSI_CR0_SPH, SSI_CR0_SPO, SSI_CR0_FRF_M, SSI_CR0_DSS_M
    ssi->SSICR0 &= ~(SSI_CR0_SPH | SSI_CR0_SPO | SSI_CR0_FRF_M | SSI_CR0_DSS_M); // Clear relevant bits

    // Configure Frame Format (usually SPI)
    // Assuming SSI_CR0_FRF_SPI is defined in your header (it wasn't in the provided snippet,
    // but 0x00 is the value for SPI format according to datasheet).
    // If not defined, you can use the raw value: ssi->SSICR0 |= (0x0 << 4);
    // Let's assume you add SSI_CR0_FRF_SPI to your header: #define SSI_CR0_FRF_SPI (0x0 << 4)
    // ssi->SSICR0 |= SSI_CR0_FRF_SPI; // Use SPI Frame Format

    // Using the raw value for SPI Frame Format (0x0) as it wasn't in your provided header snippet
    ssi->SSICR0 |= (0x0 << 4); // Set Frame Format to SPI

    // Configure SPI Protocol Mode (SPO and SPH bits)
    // Using macro names from your header: SSI_CR0_SPH, SSI_CR0_SPO
    // For the <--TFT--> we will be using mode3 according to the TFT's datasheet
    // The differnt spi modes is to choose which type of clock polarity(CPOL) && Clock Phase (CPHA)
    // The clock polarity and the clock phase determine how is the data are sampled and clocked in the spi communication
    switch (config->protocol)
    {
    case SSI_Protocol_Mode0: // SPO=0, SPH=0 -->Clock idle low, data sampled on rising edge
        // No bits to set for Mode 0
        break;
    case SSI_Protocol_Mode1:               // SPO=0, SPH=1 -->Clock idle low, data sampled on falling edge
        SET_BIT(ssi->SSICR0, SSI_CR0_SPH); // Set SPH bit
        break;
    case SSI_Protocol_Mode2:               // SPO=1, SPH=0-->Clock idle high, data sampled on falling edge
        SET_BIT(ssi->SSICR0, SSI_CR0_SPO); // Set SPO bit
        break;
    case SSI_Protocol_Mode3:               // SPO=1, SPH=1 -->Clock idle high, data sampled on rising edge
        SET_BIT(ssi->SSICR0, SSI_CR0_SPO); // Set SPO bit
        SET_BIT(ssi->SSICR0, SSI_CR0_SPH); // Set SPH bit
        break;
    }

    // configuring the Data Size Select field in the SSI Control Register 0 (SSICR0) to set how many bits are transferred in each SPI frame.
    /*
    SSI_CR0_DSS_M:
    This is a bit mask that covers the DSS field bits (typically bits 3:0 in SSICR0)
    On Tiva C microcontrollers, the DSS field is 4 bits wide (values 0x3 to 0xF for 4-16 bit transfers)

    config->dataSize:
    This comes from your configuration structure
    It should be an enum value that corresponds to the desired data size (4-16 bits)
    */
    ssi->SSICR0 |= (config->dataSize & SSI_CR0_DSS_M); // Mask ensures only the lower 4 bits of enum are used

    // --- STEP 6: Enable SSI Module ---
    // Enable the SSI module (set SSE bit in SSICR1)
    // Using the macro from your header: SSI_CR1_SSE
    SET_BIT(ssi->SSICR1, SSI_CR1_SSE);

    return TRUE; // Initialization complete
}

/**
 * @brief:: Sends a block of data over the specified SSI module using polling.
 * @module:: The SSI module to use.
 * @param txBuffer:: Pointer to transmit buffer.
 * @param len:: Number of data frames to send.
 * @return:: true if data transfer initiates successfully, false if error.
 * @note:: This is a blocking (polling) send function.
 */
uint8 SSI_Send(SSI_Module_t module, const uint8 *txBuffer, uint32 len)
{
    // Validate module index(from zero to 3) and buffer/length
    // if pointer == null would casue hard fault
    // if len==0 --> Transmitting zero bytes is either a programming error or wasted CPU cycles
    if (module > SSI_Module_3 || txBuffer == NULL || len == 0)
    {
        return FALSE; // Invalid input
    }

    SSI_RegDef_t *ssi = SSI_Modules[module];

    // Determine the data size in bytes/half-words for buffer access
    // This is a simplification; a more robust driver would check config->dataSize
    // and cast txBuffer accordingly. Assuming uint8_t* for simplicity here,
    // but be aware of potential issues if dataSize > 8.
    const uint8 *txBuf8 = (const uint8 *)txBuffer; // in most cases of tft it is 8-bit SPI configured

    // Loop through each data frame to send
    for (uint32 i = 0; i < len; ++i)
    {
        // Wait while the Transmit FIFO is full (TNF bit in SSISR is 0) ; TNF--> Transmit FIFO isnot Full
        // Using macro from the header: SSI_SR_TNF -->line _59
        while (!(ssi->SSISR & SSI_SR_TNF))
            ;

        // Write the data frame to the Data Register (SSIDR)
        // The hardware will use the configured DSS(Data Size Select) setting. if(8)--> 8-bits are used ;else all 16 are used
        // Writing a larger type than DSS is safe; higher bits are ignored.
        // Reading a larger type than DSS will have undefined higher bits.
        ssi->SSIDR = txBuf8[i]; // Writing uint8_t here; adjust if dataSize > 8
    }

    // Optional: Wait for the transmit to complete (Busy bit in SSISR clears)
    // Using macro from your header: SSI_SR_BSY
    // while(ssi->SSISR & SSI_SR_BSY);

    return TRUE; // Send operation initiated (data is in FIFO or being sent)
}

/**
 * @brief:: Receives a block of data over the specified SSI module using polling.
 * @param module:: The SSI module to use.
 * @param rxBuffer:: Pointer to receive buffer. Type should match dataSize.
 * @param len:: Number of data frames to receive.
 * @return:: true if data reception initiates successfully, false if error.
 * @note:: This is a blocking (polling) receive function.
 * @note:: The type of rxBuffer and len should correspond to the configured dataSize.
 * For dataSize <= 8, use uint8_t*. For dataSize > 8 and <= 16, use uint16_t*.
 * @note:: In Master mode, transmission (dummy data) is required to clock
 * in receive data. Consider using SSI_TransmitReceive in a loop.
 */
uint8 SSI_Receive(SSI_Module_t module, uint8 *rxBuffer, uint32 len)
{
    // Validate module index and buffer/length
    if (module > SSI_Module_3 || rxBuffer == NULL || len == 0)
    {
        return FALSE; // Invalid input
    }

    SSI_RegDef_t *ssi = SSI_Modules[module];

    // --- CAUTION ---
    // In Master mode, the SSI only generates clock cycles when you write data
    // to the SSIDR (Transmit). To receive data, you must transmit something,
    // often dummy data (e.g., 0x0000 or 0xFFFF).
    // This basic receive function as implemented here will only work correctly
    // in Slave mode, or if data is being transmitted simultaneously by a master.
    // For Master receive, you typically call SSI_TransmitReceive in a loop
    // or implement a send-then-receive logic.

    // Determine the data size in bytes/half-words for buffer access
    // This is a simplification; a more robust driver would check config->dataSize
    // and cast rxBuffer accordingly. Assuming uint8_t* for simplicity here,
    // but be aware of potential issues if dataSize > 8.
    uint8 *rxBuf8 = (uint8 *)rxBuffer;

    // Loop for each data frame to receive
    for (uint32 i = 0; i < len; ++i)
    {
        // Wait while the Receive FIFO is empty (RNE bit in SSISR is 0)
        // Using macro from your header: SSI_SR_RNE
        while (!(ssi->SSISR & SSI_SR_RNE))
            ; // Wait for RNE bit (Receive FIFO Not Empty)

        // Read the received data frame from the Data Register (SSIDR)
        // The hardware will provide data based on the configured DSS setting.
        // Reading into a uint8_t here; adjust if dataSize > 8.
        rxBuf8[i] = (uint8)(ssi->SSIDR); // Read from SSIDR, cast to uint8_t
    }

    return TRUE; // Receive operation complete
}

/**
 * @brief:: Simultaneous send and receive a frame using polling.
 * @param module:: The SSI module to use.
 * @param txData:: Data to send (uint16_t).
 * @return Received:: data (uint16_t). Returns 0xFFFF on invalid module for error indication.
 * @note:: This is a blocking (polling) send/receive function.
 * @note:: This function is suitable for sending and receiving one frame at a time
 * and is often used in Master mode to clock in received data.
 * @note:: Handles data as uint16_t frame. Adapt data type if using dataSize <= 8 bits.
 */
uint16 SSI_TransmitReceive(SSI_Module_t module, uint16 txData)
{
    // Validate module index
    if (module > SSI_Module_3)
    {
        // Return an error indicator - 0xFFFF is common for SPI errors
        return 0xFFFF;
    }

    SSI_RegDef_t *ssi = SSI_Modules[module];

    // Wait while the Transmit FIFO is full
    // Using macro from your header: SSI_SR_TNF
    while (!(ssi->SSISR & SSI_SR_TNF))
        ;

    // Write the data frame to be transmitted
    // This action also starts the clock generation in Master mode
    ssi->SSIDR = txData;

    // Wait while the Receive FIFO is empty (data received)
    // Using macro from your header: SSI_SR_RNE
    while (!(ssi->SSISR & SSI_SR_RNE))
        ;

    // Read the received data frame from SSIDR
    // The hardware provides data based on DSS. Reading into uint16_t is safe if DSS <= 16.
    return (uint16)(ssi->SSIDR);
}

/**
 * @brief Deinitializes the selected SSI module.
 * @param module The SSI module to deinitialize.
 */
void SSI_DeInit(SSI_Module_t module)
{
    // Validate module index
    if (module > SSI_Module_3)
    {
        return; // Invalid input
    }

    SSI_RegDef_t *ssi = SSI_Modules[module];

    // Disable the SSI module (clear SSE bit in SSICR1)
    // Using the macro from your header: SSI_CR1_SSE
    CLR_BIT(ssi->SSICR1, SSI_CR1_SSE);

    // Optional: Disable the peripheral clock to save power
    // Assumes SYSCTL_DisablePeripheral exists and enum aligns
    // SYSCTL_DisablePeripheral(SYSCTL_PERIPH_SSI0 + module);

    // Optional: Reset GPIO pins to a default state (e.g., inputs or GPIO)
    // This depends on your GPIO configuration philosophy.
}