/*****************************************************/
/* Author      : alhosin                             */
/* date        : 6/10/2023                           */
/*****************************************************/
#ifndef UART_REG_H_
#define UART_REG_H_

#define   UCSRA     (*((volatile u8 *) 0x2B))
#define   UCSRB     (*((volatile u8 *) 0x2A))
#define   UCSRC     (*((volatile u8 *) 0x40))
#define   UBRRL     (*((volatile u8 *) 0x29))
#define   UBRRH     (*((volatile u8 *) 0x40))
#define   UDR       (*((volatile u8 *) 0x2C))

#endif /* UART_REG_H_ */
