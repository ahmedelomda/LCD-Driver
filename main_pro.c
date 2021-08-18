#include "STD_types.h"
#include "BIT_math.h"
#include "DIO_int.h"
#include "LCD_int.h"
#include <avr/delay.h>

#define F_CPU 8000000   //define CPU 8Mega frequency Hertz

int main(void)
{
	DIO_void_Init();
	LCD_void_Init();

	while(1)
	{
		LCD_void_GoToRowCol(0,0);
		LCD_void_WriteString("   AHMED OMDA");
	}


	return 0;
}


