/******************************************************************************
 *
 * Module: LCD
 *
 * File Name: lcd.h
 *
 * Description: Header file for the LCD driver
 *
 * Author: [Your Name]
 *
 ******************************************************************************/

 #ifndef LCD_H_
 #define LCD_H_
 
 #include "../../LIB/std_types.h"
 #include "gpio.h"
 
 /*******************************************************************************
  *                                Definitions                                  *
  ******************************************************************************/
/* LCD Data bits mode configuration: choose either 4 or 8 */
#define LCD_DATA_BITS_MODE 4

#if ((LCD_DATA_BITS_MODE != 4) && (LCD_DATA_BITS_MODE != 8))
#error "Number of Data bits should be equal to 4 or 8"
#endif

/* LCD HW Ports and Pins IDs */
#define LCD_RS_PORT_ID      GPIO_PORTA
#define LCD_RS_PIN_ID       PIN_1

#define LCD_E_PORT_ID       GPIO_PORTA
#define LCD_E_PIN_ID        PIN_2

#define LCD_DATA_PORT_ID    GPIO_PORTA

#if (LCD_DATA_BITS_MODE == 4)
#define LCD_DB4_PIN_ID      PIN_3
#define LCD_DB5_PIN_ID      PIN_4
#define LCD_DB6_PIN_ID      PIN_5
#define LCD_DB7_PIN_ID      PIN_6
#endif

 /* LCD Commands */
 #define LCD_CLEAR_COMMAND             0x01
 #define LCD_GO_TO_HOME                0x02
 #define LCD_TWO_LINES_EIGHT_BITS_MODE 0x38
 #define LCD_TWO_LINES_FOUR_BITS_MODE  0x28
 #define LCD_CURSOR_OFF                0x0C
 #define LCD_CURSOR_ON                 0x0E
 #define LCD_SET_CURSOR_LOCATION       0x80

 /*External register macros (make sure these are defined properly in your headers) */
#define RCGCGPIO        (*((volatile uint32 *)0x400FE608))
#define PRGPIO          (*((volatile uint32 *)0x400FEA08))
#define GPIO_LOCK_KEY   0x4C4F434B  // Unlock key

 /*******************************************************************************
  *                      Functions Prototypes                                   *
  ******************************************************************************/
 
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
 void LCD_intgerToString(int data);
 
 /*
  * Description :
  * Send the clear screen command.
  */
 void LCD_clearScreen(void);
 
 #endif /* LCD_H_ */
 