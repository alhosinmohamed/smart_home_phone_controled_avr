/*****************************************************/
/* Author      : alhosin                             */
/* date        : 6/10/2023                           */
/*****************************************************/

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_VoidInit(u8 U8parityMode,u8 U8StopBits,u8 U8DataBits);
void UART_voidSend(u8 Cpy_data);
u8 UART_U8Receive(void);
void UART_VoidSendString(u8 *StringPtr);
void UART_VoidRecString(u8 *str);

#define Disable 0
#define Odd 1
#define Even 2

#endif /* UART_INTERFACE_H_ */
