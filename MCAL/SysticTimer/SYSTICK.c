
#include "systick.h"
#include "../../LIB/std_types.h"
//*****************************************************************************
// Initializes the SysTick timer with system clock, no interrupts.
//*****************************************************************************
void SysTick_Init(void)
{
    // Disable SysTick during setup
    SYSTICK_CTRL = 0;

    // Configure: system clock source, no interrupt, do not start yet
    SYSTICK_CTRL = SYSTICK_CLK_SRC_SYS | SYSTICK_INT_DISABLE;
}

//*****************************************************************************
// Delays the program for a given number of milliseconds (blocking).
//*****************************************************************************
void SysTick_DelayMs(uint32 ms)
{
    uint32 ticksPerMs = SysCtlClockGet() / 1000;

    while (ms--)
    {
        // Set reload value for 1ms delay
        SYSTICK_RELOAD = ticksPerMs - 1;

        // Clear current counter value (writing any value clears it)
        SYSTICK_CURRENT = 0;

        // Start the timer
        SYSTICK_CTRL |= SYSTICK_ENABLE;

        // Wait for COUNT flag (bit 16) to be set
        while ((SYSTICK_CTRL & (1 << 16)) == 0)
            ;

        // Stop the timer (optional for single-shot)
        SYSTICK_CTRL &= ~SYSTICK_ENABLE;
    }
}

void SysTick_DelayUs(uint32 us)
{
    uint32 ticksPerUs = SysCtlClockGet() / 1000000;

    for(uint32 i = 0; i < us; i++)
    {
        SYSTICK_RELOAD = ticksPerUs - 1;
        SYSTICK_CURRENT = 0;
        SYSTICK_CTRL |= SYSTICK_ENABLE;
        while ((SYSTICK_CTRL & (1 << 16)) == 0);
        SYSTICK_CTRL &= ~SYSTICK_ENABLE;
    }
}
