/*****************************************************/
/* Author      : alhosin                             */
/* date        : 14/3/2024                           */
/*****************************************************/

#ifndef PROJECT_INTERFACE_H_
#define PROJECT_INTERFACE_H_

/*LIB*/
#include"STD_TYPES.h"
#include"Bit_math.h"
#include<util/delay.h>
#include <string.h>
/*HAL*/
#include"Stpr_Interface.h"
#include "Lcd_Interface.h"
/*MCAL*/
#include"Dio_Interface.h"
#include "UART_Interface.h"
/*OWN*/
#include "project_cfg.h"

void buzzer (u8 state);
void GreenLed (u8 state);
void redLed (u8 state);
void Lights (u8 state);
void Fan (u8 state);
void AlarmThief (void);
void Gate (u8 state);
u8 password_check(u8 usernum);
u8 user_check(void);
u8 HomeOpen (void);

#define Right 1
#define Wrong 2
#define Open 1
#define Close 2
#define On DIO_HIGH
#define Off DIO_LOW
#define Number_Of_Users 10
#define USER_SIZE 8
#define PASS_SIZE 8
u8 loginUsers[Number_Of_Users][USER_SIZE] =
{
    {"Hosin"},
    {"Mohamed"},
    {"Hossam"},
    {"Shahd"},
    {"Khaled"},
    {"Ahmed"},
    {"Amr"},
    {"Rashad"},
    {"Shady"},
    {"Ganna"}
};

u8 loginPass[Number_Of_Users][PASS_SIZE] =
{
	{"000"},
    {"111"},
	{"222"},
    {"333"},
    {"444"},
    {"555"},
	{"666"},
	{"777"},
	{"888"},
    {"999"}
};

u8 Stpr_previous_state=Close;

#endif /* PROJECT_INTERFACE_H_ */
