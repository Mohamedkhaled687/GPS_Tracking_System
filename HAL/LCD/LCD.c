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

 #include "LCD.h"
 #include "../../MCAL/SysticTimer/SYSTICK.h"
 
 /*
  * Description :
  * Initialize the LCD:
  * 1. Setup the LCD pins directions using GPIO driver.
  * 2. Setup the LCD Data Mode (4-bit or 8-bit).
  */
 
 void LCD_GPIO_init(void)
 {
     GPIO_init(LCD_CTRL_PORT_ID); // give clock to the GPIO PORTE
     GPIO_init(LCD_DATA_PORT_ID); // give clock to the GPIO PORTB
 
     GPIO_Pin_Init(GPIO_PORTE, LCD_RS_PIN_ID); // initialize the RS pin
     GPIO_Pin_Init(GPIO_PORTE, LCD_RW_PIN_ID); // initialize the RW pin
     GPIO_Pin_Init(GPIO_PORTE, LCD_E_PIN_ID);  // initialize the E pin
 
     GPIO_setupPinMode(GPIO_PORTE, LCD_RS_PIN_ID, Pull_down, PIN_OUTPUT); // set the RS pin as output
     GPIO_setupPinMode(GPIO_PORTE, LCD_RW_PIN_ID, Pull_down, PIN_OUTPUT); // set the RW pin as output
     GPIO_setupPinMode(GPIO_PORTE, LCD_E_PIN_ID, Pull_down, PIN_OUTPUT);  // set the E pin as output
 
     GPIO_setupPinMode(GPIO_PORTB, LCD_DB4_PIN_ID, Pull_down, PIN_OUTPUT); // set the DB4 pin as output
     GPIO_setupPinMode(GPIO_PORTB, LCD_DB5_PIN_ID, Pull_down, PIN_OUTPUT); // set the DB5 pin as output
     GPIO_setupPinMode(GPIO_PORTB, LCD_DB6_PIN_ID, Pull_down, PIN_OUTPUT); // set the DB6 pin as output
     GPIO_setupPinMode(GPIO_PORTB, LCD_DB7_PIN_ID, Pull_down, PIN_OUTPUT); // set the DB7 pin as output
 }
 
 /*
  * Description :
  * Initialize the LCD:
  * 1. Setup the LCD pins directions using GPIO driver.
  * 2. Setup the LCD Data Mode (4-bit or 8-bit).
  */
 void LCD_init(void)
 {
     LCD_GPIO_init();
 
     LCD_sendCommand(Stabilize_4_Bit_CMD);    // send the stabilize command to the LCD
     LCD_sendCommand(Four_Bits_Data_Mode);    // send the four bits data mode command to the LCD
     LCD_sendCommand(Two_Line_Four_Bit_Mode); // send the two line four bit mode command to the LCD
 
     LCD_sendCommand(Clear_Disp_CMD); // send the clear display command to the LCD
     LCD_sendCommand(Disp_On_CMD);    // send the display on command to the LCD
 }
 
 /*
  * Description :
  * Send the required command to the screen.
  */
 void LCD_sendCommand(uint8 command)
 {
     GPIO_writePin(LCD_CTRL_PORT_ID, LCD_RS_PIN_ID, LOGIC_LOW); // set the RS pin as low
     GPIO_writePin(LCD_CTRL_PORT_ID, LCD_RW_PIN_ID, LOGIC_LOW); // set the RW pin as low
     GPIO_writePin(LCD_CTRL_PORT_ID, LCD_E_PIN_ID, LOGIC_HIGH); // set the E pin as high
     SysTick_DelayMs(1);                                        // delay for 1ms
 
     LCD_DATA_R = (LCD_DATA_R & 0x0F) | (command & 0xF0); // write the command to the data port
     SysTick_DelayMs(1);                                  // delay for 1ms
 
     GPIO_writePin(LCD_CTRL_PORT_ID, LCD_E_PIN_ID, LOGIC_LOW); // set the E pin as low
     SysTick_DelayMs(1);                                       // delay for 1ms
 
     GPIO_writePin(LCD_CTRL_PORT_ID, LCD_E_PIN_ID, LOGIC_HIGH); // set the E pin as high
     SysTick_DelayMs(1);                                        // delay for 1ms
 
     LCD_DATA_R = (LCD_DATA_R & 0x0F) | ((command & 0xF0) << 4); // write the command to the data port
     SysTick_DelayMs(1);                                         // delay for 1ms
 
     GPIO_writePin(LCD_CTRL_PORT_ID, LCD_E_PIN_ID, LOGIC_LOW); // set the E pin as low
     SysTick_DelayMs(1);                                       // delay for 1ms
 }
 
 /*
  * Description :
  * Send the required character to the screen.
  */
 void LCD_displayCharacter(uint8 data)
 {
     GPIO_writePin(LCD_CTRL_PORT_ID, LCD_RS_PIN_ID, LOGIC_HIGH); // set the RS pin as high
     GPIO_writePin(LCD_CTRL_PORT_ID, LCD_RW_PIN_ID, LOGIC_LOW);  // set the RW pin as low
     GPIO_writePin(LCD_CTRL_PORT_ID, LCD_E_PIN_ID, LOGIC_HIGH);  // set the E pin as high
     SysTick_DelayMs(1);                                         // delay for 1ms
 
     LCD_DATA_R = (LCD_DATA_R & 0x0F) | (data & 0xF0); // write the data to the data port
     SysTick_DelayMs(1);                               // delay for 1ms
 
     GPIO_writePin(LCD_CTRL_PORT_ID, LCD_E_PIN_ID, LOGIC_LOW); // set the E pin as low
     SysTick_DelayMs(1);                                       // delay for 1ms
 
     GPIO_writePin(LCD_CTRL_PORT_ID, LCD_E_PIN_ID, LOGIC_HIGH); // set the E pin as high
     SysTick_DelayMs(1);                                        // delay for 1ms
 
     LCD_DATA_R = (LCD_DATA_R & 0x0F) | ((data & 0xF0) << 4); // write the data to the data port
     SysTick_DelayMs(1);                                      // delay for 1ms
 
     GPIO_writePin(LCD_CTRL_PORT_ID, LCD_E_PIN_ID, LOGIC_LOW); // set the E pin as low
     SysTick_DelayMs(1);                                       // delay for 1ms
 }
 
 /*
  * Description :
  * Send the required string to the screen.
  */
 void LCD_displayString(const char *Str)
 {
     uint8 counter = 0;
     while (Str[counter] != '\0')
     {
         LCD_displayCharacter(Str[counter]);
         counter++;
     }
 }
 
 /*
  * Description :
  * Move the cursor to a specific position on the screen.
  */
 void LCD_moveCursor(uint8 row, uint8 col)
 {
     uint8 cursor_position;
 
     switch (row)
     {
     case 0:
         cursor_position = col;
         break;
     case 1:
         cursor_position = col + 0x40;
         break;
     }
 
     LCD_sendCommand(cursor_position | Cursor_Set_CMD); // send the cursor set command to the LCD
 }
 
 /*
  * Description :
  * Display the required string in a specific row and column index.
  */
 void LCD_displayStringRowColumn(uint8 row, uint8 col, const char *Str)
 {
     LCD_moveCursor(row, col);
     LCD_displayString(Str);
 }
 
 /*
  * Description :
  * Display the required decimal value on the screen.
  */
 void LCD_intgerToString(double data)
 {
     char str[5] = {0};
     sprintf(str, "%.2f", data);
     LCD_displayString(str);
 }
 
 /*
  * Description :
  * Send the clear screen command to the screen.
  */
 void LCD_clearScreen(void)
 {
     LCD_sendCommand(Clear_Disp_CMD); // send the clear display command to the LCD
 }