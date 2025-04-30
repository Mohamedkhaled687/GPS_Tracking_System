#include "lcd.h"
#include "../../MCAL/GPIO/GPIO.c"

void LCD_pinsInit(void)
{
    GPIO_Init(GPIO_PORTA);

    /* Set pin directions */
    GPIO_PORTA_DIR_R |= (1 << LCD_RS_PIN_ID) | (1 << LCD_E_PIN_ID) | (1 << LCD_DB4_PIN_ID) | (1 << LCD_DB5_PIN_ID) | (1 << LCD_DB6_PIN_ID) | (1 << LCD_DB7_PIN_ID);

    /* Disable alternate functions */
    GPIO_PORTA_AFSEL_R &= ~((1 << LCD_RS_PIN_ID) | (1 << LCD_E_PIN_ID) | (1 << LCD_DB4_PIN_ID) | (1 << LCD_DB5_PIN_ID) | (1 << LCD_DB6_PIN_ID) | (1 << LCD_DB7_PIN_ID));

    /* Disable analog functionality */
    GPIO_PORTA_AMSEL_R &= ~((1 << LCD_RS_PIN_ID) | (1 << LCD_E_PIN_ID) | (1 << LCD_DB4_PIN_ID) | (1 << LCD_DB5_PIN_ID) | (1 << LCD_DB6_PIN_ID) | (1 << LCD_DB7_PIN_ID));

    /* Enable digital functionality */
    GPIO_PORTA_DEN_R |= (1 << LCD_RS_PIN_ID) | (1 << LCD_E_PIN_ID) | (1 << LCD_DB4_PIN_ID) | (1 << LCD_DB5_PIN_ID) | (1 << LCD_DB6_PIN_ID) | (1 << LCD_DB7_PIN_ID);
}
