#include "LCD.h"
#include "../../MCAL/GPIO/GPIO.h"


void LCD_pinsInit(void)
{
    /* Enable clock for PORTA */
    RCGCGPIO |= (1 << 0);  // 0 for PORTA
    while ((PRGPIO & (1 << 0)) == 0); // Wait until PORTA is ready

    /* Unlock PORTA if required (only PF0 usually needs this, not PA) */
    // GPIO_PORTA_LOCK_R = GPIO_LOCK_KEY;
    // GPIO_PORTA_CR_R |= ALL_USED_PINS;

    /* Set pin directions */
    GPIO_PORTA_DIR_R |= (1 << LCD_RS_PIN_ID) | (1 << LCD_E_PIN_ID)
                      | (1 << LCD_DB4_PIN_ID) | (1 << LCD_DB5_PIN_ID)
                      | (1 << LCD_DB6_PIN_ID) | (1 << LCD_DB7_PIN_ID);

    /* Disable alternate functions */
    GPIO_PORTA_AFSEL_R &= ~((1 << LCD_RS_PIN_ID) | (1 << LCD_E_PIN_ID)
                          | (1 << LCD_DB4_PIN_ID) | (1 << LCD_DB5_PIN_ID)
                          | (1 << LCD_DB6_PIN_ID) | (1 << LCD_DB7_PIN_ID));

    /* Disable analog functionality */
    GPIO_PORTA_AMSEL_R &= ~((1 << LCD_RS_PIN_ID) | (1 << LCD_E_PIN_ID)
                          | (1 << LCD_DB4_PIN_ID) | (1 << LCD_DB5_PIN_ID)
                          | (1 << LCD_DB6_PIN_ID) | (1 << LCD_DB7_PIN_ID));

    /* Enable digital functionality */
    GPIO_PORTA_DEN_R |= (1 << LCD_RS_PIN_ID) | (1 << LCD_E_PIN_ID)
                      | (1 << LCD_DB4_PIN_ID) | (1 << LCD_DB5_PIN_ID)
                      | (1 << LCD_DB6_PIN_ID) | (1 << LCD_DB7_PIN_ID);
}
