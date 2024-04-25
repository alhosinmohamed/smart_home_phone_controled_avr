/*****************************************************/
/* Author      : alhosin                             */
/* date        : 01/09/2023                          */
/*****************************************************/
/* 1 - include libraries */
#include "STD_TYPES.h"
#include "Bit_Math.h" 

/* 2 - include module's files */
#include "Dio_Interface.h"
#include "Dio_Private.h"
#include "Dio_Cfg.h"
#include "Dio_Reg.h"


void Dio_voidSetPinDirection (u8 Cpy_u8Port , u8 Cpy_u8Pin , u8 Cpy_u8Dirc){
	if (Cpy_u8Dirc == DIO_INPUT)
	{
		switch (Cpy_u8Port){
		 case DIO_PORTA : clear_Bit(DDRA , Cpy_u8Pin) ; break;
		 case DIO_PORTB : clear_Bit(DDRB , Cpy_u8Pin); break;
		 case DIO_PORTC : clear_Bit(DDRC , Cpy_u8Pin); break;
		 case DIO_PORTD : clear_Bit(DDRD , Cpy_u8Pin); break;
		}
	}
	else if (Cpy_u8Dirc == DIO_OUTPUT){
		switch (Cpy_u8Port){
		 case DIO_PORTA : set_Bit(DDRA , Cpy_u8Pin) ; break;
		 case DIO_PORTB : set_Bit(DDRB , Cpy_u8Pin); break;
		 case DIO_PORTC : set_Bit(DDRC , Cpy_u8Pin); break;
		 case DIO_PORTD : set_Bit(DDRD , Cpy_u8Pin); break;
		}
	}
}
void Dio_voidSetPinValue (u8 Cpy_u8Port , u8 Cpy_u8Pin , u8 Cpy_u8Value){
	if (Cpy_u8Value == DIO_LOW)
	{
		switch (Cpy_u8Port){
		 case DIO_PORTA : clear_Bit(PORTA , Cpy_u8Pin) ; break;
		 case DIO_PORTB : clear_Bit(PORTB , Cpy_u8Pin); break;
		 case DIO_PORTC : clear_Bit(PORTC , Cpy_u8Pin); break;
		 case DIO_PORTD : clear_Bit(PORTD , Cpy_u8Pin); break;
		}
	}
	else if (Cpy_u8Value == DIO_HIGH){
		switch (Cpy_u8Port){
		 case DIO_PORTA : set_Bit(PORTA , Cpy_u8Pin) ; break;
		 case DIO_PORTB : set_Bit(PORTB , Cpy_u8Pin); break;
		 case DIO_PORTC : set_Bit(PORTC , Cpy_u8Pin); break;
		 case DIO_PORTD : set_Bit(PORTD , Cpy_u8Pin); break;
		}
	}
}
u8 Dio_u8GetPinValue (u8 Cpy_u8Port , u8 Cpy_u8Pin){
	u8 local_u8InValue = 0 ;
	switch (Cpy_u8Port){
	 case DIO_PORTA : local_u8InValue = get_Bit(PINA , Cpy_u8Pin) ; break;
	 case DIO_PORTB : local_u8InValue = get_Bit(PINB , Cpy_u8Pin); break;
	 case DIO_PORTC : local_u8InValue = get_Bit(PINC , Cpy_u8Pin); break;
	 case DIO_PORTD : local_u8InValue = get_Bit(PIND , Cpy_u8Pin); break;
	}

	return local_u8InValue ;
}


void Dio_voidSetPortDirection (u8 Cpy_u8Port , u8 Cpy_u8Dirc)
{
	if (Cpy_u8Dirc == DIO_INPUT)
	{
		switch (Cpy_u8Port)
		{
		 case DIO_PORTA : DDRA = 0x00 ; break;
		 case DIO_PORTB : DDRB = 0x00 ; break;
		 case DIO_PORTC : DDRC = 0x00 ; break;
		 case DIO_PORTD : DDRD = 0x00 ; break;
		}
	}
	else if (Cpy_u8Dirc == DIO_OUTPUT)
	{
		switch (Cpy_u8Port)
		{
		 case DIO_PORTA : DDRA = 0XFF ; break;
		 case DIO_PORTB : DDRB = 0XFF ; break;
		 case DIO_PORTC : DDRC = 0XFF ; break;
		 case DIO_PORTD : DDRD = 0XFF ; break;
		}
	}
}
void Dio_voidSetPortValue (u8 Cpy_u8Port , u8 Cpy_u8Value){
	switch (Cpy_u8Port)
	{
	 case DIO_PORTA : PORTA =  Cpy_u8Value; break;
	 case DIO_PORTB : PORTB =  Cpy_u8Value; break;
	 case DIO_PORTC : PORTC =  Cpy_u8Value; break;
	 case DIO_PORTD : PORTD =  Cpy_u8Value; break;
	}

}
u8 Dio_u8GetPortValue (u8 Cpy_u8Port){
	u8 local_u8InValue = 0 ;
	switch (Cpy_u8Port){
	 case DIO_PORTA : local_u8InValue = PINA ; break;
	 case DIO_PORTB : local_u8InValue = PINB ; break;
	 case DIO_PORTC : local_u8InValue = PINC ; break;
	 case DIO_PORTD : local_u8InValue = PIND ; break;
	}

	return local_u8InValue ;
}
