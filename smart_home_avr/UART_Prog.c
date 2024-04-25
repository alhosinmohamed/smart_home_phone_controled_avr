/*****************************************************/
/* Author      : alhosin                             */
/* date        : 6/10/2023                           */
/*****************************************************/
#include "STD_TYPES.h"
#include "Bit_Math.h"

#include "UART_Interface.h"
#include "UART_Private.h"
#include "UART_Reg.h"

void (*CallbackFunc)(void);
u8 *callBackPtr=NULL;

void UART_VoidInit(u8 U8parityMode,u8 U8StopBits,u8 U8DataBits)
{
	u8 Cpy_UCSRC=0b10000000;

	switch(U8parityMode)
	{
	case Disable:
		Cpy_UCSRC|=0b00000000;
		break;
	case Odd:
		Cpy_UCSRC|=0b00110000;
		break;
	case Even:
		Cpy_UCSRC|=0b00100000;
		break;
	}
	switch(U8StopBits)
	{
	case 1:
		Cpy_UCSRC|=0b00000000;
		break;
	case 2:
		Cpy_UCSRC|=0b00001000;
		break;
	}
	switch(U8DataBits)
	{
	case 5:
		clear_Bit(UCSRB,UCSZ2);
		Cpy_UCSRC|=0b00000000;
		break;
	case 6:
		clear_Bit(UCSRB,UCSZ2);
		Cpy_UCSRC|=0b00000010;
		break;
	case 7:
		clear_Bit(UCSRB,UCSZ2);
		Cpy_UCSRC|=0b00000100;
		break;
	case 8:
		clear_Bit(UCSRB,UCSZ2);
		Cpy_UCSRC|=0b00000110;
		break;
	case 9:
		set_Bit(UCSRB,UCSZ2);
		Cpy_UCSRC|=0b00001110;
		break;
	}

	set_Bit(UCSRB,RXEN);
	set_Bit(UCSRB,TXEN);
	UCSRC=Cpy_UCSRC;
	UBRRL=51;

	/* Set to 8 bit mode
		 * No parity
	 	 * One stop bit
	 	 * UCSRC=0b10000110 */

}



void UART_voidSend(u8 Cpy_data)
{
	while (get_Bit(UCSRA , UDRE) == 0);
	UDR = Cpy_data ;
}



u8 UART_U8Receive(void)
{
	while(get_Bit(UCSRA,RXC)==0);
	return UDR;
}



void UART_VoidSendString(u8 *StringPtr)
{
	u8 i=0;
	do
	{
		UART_voidSend(StringPtr[i]);
		i++;
	}
	while(StringPtr[i]!=NULL);
}

void UART_VoidRecString(u8 *str)
{
	u8 i = 0;
	str[i] = UART_U8Receive();
	//will continue to receive until you send .
	while(str[i] != '\r' && str[i] != NULL)
	{
		i++;
		str[i] = UART_U8Receive();
	}
	str[i] = '\0';
}


void UART_voidReceiveAsynch(u8 *Cpy_u8DataPtr,void (* Cpy_func)(void))
{
	set_Bit(UCSRB,RXCIE);//to enable interrupt
	callBackPtr=Cpy_u8DataPtr;
	CallbackFunc=Cpy_func;
}


void __vector_13(void) __attribute__((signal)) ;
void __vector_13(void)
{
	if((callBackPtr != NULL)&&(CallbackFunc != NULL))
	{
		*callBackPtr=UDR;
		CallbackFunc();
	}
}
