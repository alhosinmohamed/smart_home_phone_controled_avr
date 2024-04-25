/*****************************************************/
/* Author      : alhosin                             */
/* date        : 02/09/2023                          */
/*****************************************************/
#include"STD_TYPES.h"
#include"Bit_math.h"
#include<util/delay.h>
#include <stdlib.h>

#include"Dio_Interface.h"

#include "Lcd_Interface.h"
#include "Lcd_Cfg.h"


void Lcd_voidSendCommand(u8 Cpy_u8Command)
{
	//RS low
	Dio_voidSetPinValue(LCD_RS_PORT,LCD_RS_PIN,DIO_LOW);
	//RW low
	Dio_voidSetPinValue(LCD_RW_PORT,LCD_RW_PIN,DIO_LOW);
	//Send the command
	Dio_voidSetPortValue(LCD_DATA_PORT,Cpy_u8Command);
	//the enable pulse
	Dio_voidSetPinValue(LCD_E_PORT,LCD_E_PIN,DIO_HIGH);
	_delay_ms(1);
	Dio_voidSetPinValue(LCD_E_PORT,LCD_E_PIN,DIO_LOW);
	_delay_ms(1);
}

void Lcd_voidSendData(u8 Cpy_u8Data)
{
	//RS high
	Dio_voidSetPinValue(LCD_RS_PORT,LCD_RS_PIN,DIO_HIGH);
	//RW low
	Dio_voidSetPinValue(LCD_RW_PORT,LCD_RW_PIN,DIO_LOW);
	//Send the data
	Dio_voidSetPortValue(LCD_DATA_PORT,Cpy_u8Data);
	//the enable pulse
	Dio_voidSetPinValue(LCD_E_PORT,LCD_E_PIN,DIO_HIGH);
	_delay_ms(1);
	Dio_voidSetPinValue(LCD_E_PORT,LCD_E_PIN,DIO_LOW);
	_delay_ms(1);
}

void Lcd_Init(void)
{
	// Initialize pins as out
	Dio_voidSetPortDirection(LCD_DATA_PORT,DIO_OUTPUT);
	Dio_voidSetPinDirection(LCD_RS_PORT,LCD_RS_PIN,DIO_OUTPUT);
	Dio_voidSetPinDirection(LCD_RW_PORT,LCD_RW_PIN,DIO_OUTPUT);
	Dio_voidSetPinDirection(LCD_E_PORT,LCD_E_PIN,DIO_OUTPUT);

	_delay_ms(40);
	Lcd_voidSendCommand(0b00111000);
	_delay_ms(1);
	Lcd_voidSendCommand(0b00001100);
	_delay_ms(1);
	Lcd_voidSendCommand(0b00000001);
	_delay_ms(2);
	Lcd_voidSendCommand(0b00000110);
}

void Lcd_GoToXY(u8 x,u8 y)
{
	u8 Lcd_u8Adress=64*x+y+128;
	Lcd_voidSendCommand(Lcd_u8Adress);
}

void Lcd_VoidWriteString(char Cpy_ChararrData[])
{
	u8 counter=0;
	while(Cpy_ChararrData[counter]!='\0')
	{

		Lcd_voidSendData(Cpy_ChararrData[counter]);
		counter++;
	}

}

void Lcd_voidAddNewPattern(u8 Block_Num,u8 *arr)
{
	u8 address = 64+Block_Num*8;
	Lcd_voidSendCommand(address);

	for(u8 i=0;i<8;i++)
	{
		Lcd_voidSendData(arr[i]);
	}
}
void Lcd_voidShowNewPattern(u8 Block_Num,u8 x,u8 y)
{
	Lcd_GoToXY(x,y);
	Lcd_voidSendData(Block_Num);
}

void Lcd_VoidWriteNumber(s32 Cpy_Num)
{
	u8 store[14],i=0; // store to hold the converted number as a string
	if (Cpy_Num<0)
    {
    	Cpy_Num=(-Cpy_Num);
    	while(Cpy_Num!=0)
       {
   		   store[i]=(Cpy_Num%10)+'0';
   		   Cpy_Num=(Cpy_Num-(Cpy_Num%10))/10;
   		   i++;
   	   }
       store[i]='-';
    }
    else if(Cpy_Num==0)
    {
    	store[i]='0';
    }
    else if (Cpy_Num>0)
    {
    	while(Cpy_Num!=0)
        {
   	   	   store[i]=(Cpy_Num%10)+'0';
   	 	   Cpy_Num=(Cpy_Num-(Cpy_Num%10))/10;
   		   i++;
   	    }
    	i--;
    }

   for(s8 y=i;y>=0;y--)
   {
	   Lcd_voidSendData(store[y]);
   }
}


