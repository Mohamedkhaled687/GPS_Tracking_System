/******************************************************************************
 *
 * Module: LCD
 *
 * File Name: lcd.h
 *
 * Description: Header file for the LCD driver
 *
 * Author: Mosa Abdulaziz
 *
 ******************************************************************************/

#ifndef LCD_H_
#define LCD_H_

#include "../../LIB/std_types.h"
#include "../../MCAL/GPIO/GPIO.c"
#include "../../MCAL/SysticTimer/SYSTICK.c"

/*******************************************************************************
 *                                Definitions                                  *
 ******************************************************************************/
/* LCD Data bits mode configuration: choose either 4 or 8 */
#define LCD_DATA_BITS_MODE 4

#if ((LCD_DATA_BITS_MODE != 4) && (LCD_DATA_BITS_MODE != 8))
#error "Number of Data bits should be equal to 4 or 8"
#endif

/* LCD HW Ports and Pins IDs */

#define LCD_DATA_R GPIO_PORTB_DATA_R

#define LCD_CTRL_PORT_ID GPIO_PORTE

#define LCD_RS_PIN_ID PIN_1
#define LCD_RW_PIN_ID PIN_2
#define LCD_E_PIN_ID PIN_3

#define LCD_DATA_PORT_ID GPIO_PORTB

#if (LCD_DATA_BITS_MODE == 4)
#define LCD_DB4_PIN_ID PIN_4
#define LCD_DB5_PIN_ID PIN_5
#define LCD_DB6_PIN_ID PIN_6
#define LCD_DB7_PIN_ID PIN_7
#endif

/**********LCD 16x2 Commands************/
#define Clear_Disp_CMD 0x01
#define Disp_On_CMD 0x0C
#define Cursor_Set_CMD 0x80
#define Eight_Bit_Mode_CMD 0x38
#define Stabilize_4_Bit_CMD 0x33
#define Four_Bits_Data_Mode 0x32
#define Two_Line_Four_Bit_Mode 0x28

/*******************************************************************************
 *                      Functions Prototypes                                   *
 ******************************************************************************/

/*
 * Description :
 * Initialize the GPIO pins for the LCD.
 */

void LCD_GPIO_init(void);

/*
 * Description :
 * Initialize the LCD:
 * 1. Setup the LCD pins directions using GPIO driver.
 * 2. Setup the LCD Data Mode (4-bit or 8-bit).
 */
void LCD_init(void);

/*
 * Description :
 * Send the required command to the screen.
 */
void LCD_sendCommand(uint8 command);

/*
 * Description :
 * Display the required character on the screen.
 */
void LCD_displayCharacter(uint8 data);

/*
 * Description :
 * Display the required string on the screen.
 */
void LCD_displayString(const char *Str);

/*
 * Description :
 * Move the cursor to a specified row and column index on the screen.
 */
void LCD_moveCursor(uint8 row, uint8 col);

/*
 * Description :
 * Display the required string in a specified row and column index.
 */
void LCD_displayStringRowColumn(uint8 row, uint8 col, const char *Str);

/*
 * Description :
 * Display the required decimal value on the screen.
 */
void LCD_intgerToString(double data);

/*
 * Description :
 * Send the clear screen command.
 */
void LCD_clearScreen(void);

#endif /* LCD_H_ */
