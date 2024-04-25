/*****************************************************/
/* Author      : alhosin                             */
/* date        : 08/09/2023                          */
/*****************************************************/
/* 1 - include libraries */
#include "STD_TYPES.h"
#include "Bit_Math.h" 
#include<util/delay.h>

/* 2 - include module's files */
#include "Dio_Interface.h"
#include "Stpr_Interface.h"
#include "Stpr_Cfg.h"

void Stpr_voidInit(void)
{
	Dio_voidSetPinDirection(Stpr_Port,Blue_Pin,DIO_OUTPUT);
	Dio_voidSetPinDirection(Stpr_Port,Pink_Pin,DIO_OUTPUT);
	Dio_voidSetPinDirection(Stpr_Port,Yellow_Pin,DIO_OUTPUT);
	Dio_voidSetPinDirection(Stpr_Port,Orange_Pin,DIO_OUTPUT);
}


void Stpr_voidMove(u16 Cpy_u8Degree,u8 Cpy_u8Dirc)
{
	u16 step=((u32)Cpy_u8Degree*2057)/360;
	step =step/4;
	switch(Cpy_u8Dirc)
	{
	case CW:
		for(u16 i=0;i<step;i++)
		{
			Dio_voidSetPinValue(Stpr_Port,Blue_Pin,DIO_HIGH);
			Dio_voidSetPinValue(Stpr_Port,Pink_Pin,DIO_LOW);
			Dio_voidSetPinValue(Stpr_Port,Yellow_Pin,DIO_LOW);
			Dio_voidSetPinValue(Stpr_Port,Orange_Pin,DIO_LOW);
			_delay_ms(4);
			Dio_voidSetPinValue(Stpr_Port,Blue_Pin,DIO_LOW);
			Dio_voidSetPinValue(Stpr_Port,Pink_Pin,DIO_HIGH);
			Dio_voidSetPinValue(Stpr_Port,Yellow_Pin,DIO_LOW);
			Dio_voidSetPinValue(Stpr_Port,Orange_Pin,DIO_LOW);
			_delay_ms(4);
			Dio_voidSetPinValue(Stpr_Port,Blue_Pin,DIO_LOW);
			Dio_voidSetPinValue(Stpr_Port,Pink_Pin,DIO_LOW);
			Dio_voidSetPinValue(Stpr_Port,Yellow_Pin,DIO_HIGH);
			Dio_voidSetPinValue(Stpr_Port,Orange_Pin,DIO_LOW);
			_delay_ms(4);
			Dio_voidSetPinValue(Stpr_Port,Blue_Pin,DIO_LOW);
			Dio_voidSetPinValue(Stpr_Port,Pink_Pin,DIO_LOW);
			Dio_voidSetPinValue(Stpr_Port,Yellow_Pin,DIO_LOW);
			Dio_voidSetPinValue(Stpr_Port,Orange_Pin,DIO_HIGH);
			_delay_ms(4);
		}
		break;
	case CCW:
		for(u16 i=0;i<step;i++)
		{
			Dio_voidSetPinValue(Stpr_Port,Blue_Pin,DIO_LOW);
			Dio_voidSetPinValue(Stpr_Port,Pink_Pin,DIO_LOW);
			Dio_voidSetPinValue(Stpr_Port,Yellow_Pin,DIO_LOW);
			Dio_voidSetPinValue(Stpr_Port,Orange_Pin,DIO_HIGH);
			_delay_ms(5);
			Dio_voidSetPinValue(Stpr_Port,Blue_Pin,DIO_LOW);
			Dio_voidSetPinValue(Stpr_Port,Pink_Pin,DIO_LOW);
			Dio_voidSetPinValue(Stpr_Port,Yellow_Pin,DIO_HIGH);
			Dio_voidSetPinValue(Stpr_Port,Orange_Pin,DIO_LOW);
			_delay_ms(5);
			Dio_voidSetPinValue(Stpr_Port,Blue_Pin,DIO_LOW);
			Dio_voidSetPinValue(Stpr_Port,Pink_Pin,DIO_HIGH);
			Dio_voidSetPinValue(Stpr_Port,Yellow_Pin,DIO_LOW);
			Dio_voidSetPinValue(Stpr_Port,Orange_Pin,DIO_LOW);
			_delay_ms(5);
			Dio_voidSetPinValue(Stpr_Port,Blue_Pin,DIO_HIGH);
			Dio_voidSetPinValue(Stpr_Port,Pink_Pin,DIO_LOW);
			Dio_voidSetPinValue(Stpr_Port,Yellow_Pin,DIO_LOW);
			Dio_voidSetPinValue(Stpr_Port,Orange_Pin,DIO_LOW);
			_delay_ms(5);
		}
		break;
	}
}


