/********************************************************************/
 /******************************************************************/
 /* 		Title : LCD Private File                               */
 /*		Author: Ahmed Mohamed Fathy (Ahmed Omda)				   */	
 /* 		Last Update: 17 Aug 2021						       */
 /******************************************************************/
/********************************************************************/

#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_

#define LCD_u8_FUNCTION_SET    0b00111000
#define LCD_u8_DISPLAY_CURSUR  0b00001100
#define LCD_u8_CLEAR_SCREEN    0b00000001
#define LCD_u8_CURSUR_DIR      0b00000110

static void LCD_void_WriteCommand(u8 Copy_u8_Command);
static void LCD_void_Execute(u8 Copy_u8_DataCMD);

#endif //LCD_PRIVATE_H_
