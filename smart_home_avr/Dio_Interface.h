/*****************************************************/
/* Author      : alhosin                             */
/* date        : 01/09/2023                          */
/*****************************************************/
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H


/* Cpy_u8Port */
#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

/*Cpy_u8Pin */
#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7


/*Cpy_u8Dirc*/
#define DIO_INPUT  0
#define DIO_OUTPUT 1

/* Cpy_u8Value */
#define DIO_HIGH  1
#define DIO_LOW   0


/* For pins */
void Dio_voidSetPinDirection (u8 Cpy_u8Port , u8 Cpy_u8Pin , u8 Cpy_u8Dirc);
void Dio_voidSetPinValue (u8 Cpy_u8Port , u8 Cpy_u8Pin , u8 Cpy_u8Value);
u8 Dio_u8GetPinValue (u8 Cpy_u8Port , u8 Cpy_u8Pin);

/* For port */
void Dio_voidSetPortDirection (u8 Cpy_u8Port , u8 Cpy_u8Dirc);
void Dio_voidSetPortValue (u8 Cpy_u8Port , u8 Cpy_u8Value);
u8 Dio_u8GetPortValue (u8 Cpy_u8Port);

#endif
