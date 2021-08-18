/********************************************************************/
 /******************************************************************/
 /* 		Title : LCD Program File                               */
 /*		Author: Ahmed Mohamed Fathy (Ahmed Omda)				   */	
 /* 		Last Update: 17 Aug 2021						       */
 /******************************************************************/
/********************************************************************/

#include "STD_types.h"
#include "BIT_math.h"
#include "LCD_int.h"
#include "LCD_config.h"
#include "LCD_private.h"
#include "DIO_int.h"
#include "DIO_config.h"
#include "DIO_private.h"

#include <avr/delay.h>  //for delay
/*
u8 a[8] = {6, 14, 4, 4, 4, 0, 0, 0}; // أ
u8 m[8] = {0, 0, 2, 5, 29, 2, 0, 0}; // م
u8 h[8] = {0, 0, 6, 1, 30, 0, 0, 0}; // ح
u8 d[8] = {0, 0, 6, 1, 6, 0, 0, 0};  // د
*/

static void LCD_void_WriteCommand(u8 Copy_u8_Command)
{
	DIO_void_SetPinValue(LCD_us_PIN_RS, DIO_u8LOW); //write command
	LCD_void_Execute(Copy_u8_Command);
}

static void LCD_void_Execute(u8 Copy_u8_DataCMD)
{
	DIO_void_SetPinValue(LCD_us_PIN_RW, DIO_u8LOW);
	_delay_ms(1);
	DIO_void_SetPinValue(LCD_us_PIN_E, DIO_u8HIGH);
	_delay_ms(1);
	
	// write data
	if(GET_BIT(Copy_u8_DataCMD, 0))
	{
		DIO_void_SetPinValue(LCD_u8D0, DIO_u8HIGH);
	}
	else
	{
		DIO_void_SetPinValue(LCD_u8D0, DIO_u8LOW);
	}
	
	if(GET_BIT(Copy_u8_DataCMD, 1))
	{
		DIO_void_SetPinValue(LCD_u8D1, DIO_u8HIGH);
	}
	else
	{
		DIO_void_SetPinValue(LCD_u8D1, DIO_u8LOW);
	}
		
	if(GET_BIT(Copy_u8_DataCMD, 2))
	{
		DIO_void_SetPinValue(LCD_u8D2, DIO_u8HIGH);
	}
	else
	{
		DIO_void_SetPinValue(LCD_u8D2, DIO_u8LOW);
	}
	
	if(GET_BIT(Copy_u8_DataCMD, 3))
	{
		DIO_void_SetPinValue(LCD_u8D3, DIO_u8HIGH);
	}
	else
	{
		DIO_void_SetPinValue(LCD_u8D3, DIO_u8LOW);
	}
	
	if(GET_BIT(Copy_u8_DataCMD, 4))
	{
		DIO_void_SetPinValue(LCD_u8D4, DIO_u8HIGH);
	}
	else
	{
		DIO_void_SetPinValue(LCD_u8D4, DIO_u8LOW);
	}
	
	if(GET_BIT(Copy_u8_DataCMD, 5))
	{
		DIO_void_SetPinValue(LCD_u8D5, DIO_u8HIGH);
	}
	else
	{
		DIO_void_SetPinValue(LCD_u8D5, DIO_u8LOW);
	}
	
	if(GET_BIT(Copy_u8_DataCMD, 6))
	{
		DIO_void_SetPinValue(LCD_u8D6, DIO_u8HIGH);
	}
	else
	{
		DIO_void_SetPinValue(LCD_u8D6, DIO_u8LOW);
	}
	
	if(GET_BIT(Copy_u8_DataCMD, 7))
	{
		DIO_void_SetPinValue(LCD_u8D7, DIO_u8HIGH);
	}
	else
	{
		DIO_void_SetPinValue(LCD_u8D7, DIO_u8LOW);
	}
	
	
	DIO_void_SetPinValue(LCD_us_PIN_E, DIO_u8LOW);
}

void LCD_void_WriteCharacter(u8 Copy_u8_Data)
{
	DIO_void_SetPinValue(LCD_us_PIN_RS, DIO_u8HIGH);  //write character
	LCD_void_Execute(Copy_u8_Data);
}

void LCD_void_ClearScrean(void)
{
	LCD_void_WriteCommand(LCD_u8_CLEAR_SCREEN);
}

void LCD_void_Init(void)
{
	_delay_ms(35);
	LCD_void_WriteCommand(LCD_u8_FUNCTION_SET);
	_delay_ms(1);
	LCD_void_WriteCommand(LCD_u8_DISPLAY_CURSUR);
	_delay_ms(1);
	LCD_void_WriteCommand(LCD_u8_CLEAR_SCREEN);
	_delay_ms(2);
	LCD_void_WriteCommand(LCD_u8_CURSUR_DIR);
}

void LCD_void_WriteString(u8* Copy_PString)
{
	u8 Local_u8Counter = 0;
	
	while(Copy_PString[Local_u8Counter] != '\0' )
	{
		LCD_void_WriteCharacter(Copy_PString[Local_u8Counter]);
		Local_u8Counter++;
	}
}

void LCD_void_GoToRowCol(u8 Copy_u8_Row, u8 Copy_u8_Col)
{
	//adress DDRAM -> 0x80
	//line 0 -> 0x80 | (0x00 + 0:15)
	//line 1 -> 0x80 | (0x40 + 0:15)
	u8 Local_u8Address;
	
	switch(Copy_u8_Row)
	{
		case 0:
		Local_u8Address = (0x00 + Copy_u8_Col) | 0x80;
		break;
		
		case 1:
		Local_u8Address = (0x40 + Copy_u8_Col) | 0x80;
		break;
	}
	
	LCD_void_WriteCommand(Local_u8Address);

}










