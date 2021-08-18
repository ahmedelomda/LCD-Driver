/********************************************************************/
 /******************************************************************/
 /* 		Title : LCD Interface File                             */
 /*		Author: Ahmed Mohamed Fathy (Ahmed Omda)				   */	
 /* 		Last Update: 17 Aug 2021						       */
 /******************************************************************/
/********************************************************************/

/*
 send command 
 driver inializaion
 show data
 set cursur
*/

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

/*********************************************************************/
/*************************Public Defination***************************/
/*********************************************************************/



/*********************************************************************/
/*************************Public Functions****************************/
/*********************************************************************/
void LCD_void_Init(void);
void LCD_void_WriteCharacter(u8 Copy_u8_Data);
void LCD_void_ClearScrean(void);
void LCD_void_WriteString(u8* Copy_PString);
void LCD_void_GoToRowCol(u8 Copy_u8_Row, u8 Copy_u8_Col);


#endif  //LCD_INTERFACE_H_
