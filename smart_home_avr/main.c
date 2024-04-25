/*****************************************************/
/* Author      : alhosin                             */
/* date        : 14/3/2024                           */
/*****************************************************/

#include "project_interface.h"

int main ()
{
	//to initialize the LEDs the buzzer
	Dio_voidSetPortDirection(PRO_PORT,DIO_OUTPUT);
	//to initialize the stepper that will open the door
	Stpr_voidInit();
	//to initialize the UART that will communicate with the PC
	UART_VoidInit(Disable,1,8);
	//to initialize the LCD
	Lcd_Init();

    while (1)
    {
    	// the default home locked
		GreenLed(Off);
		redLed(On);

    	u8 PersonCheck=user_check();

    	if (PersonCheck==Right)
    	{
    		u8 nouse =HomeOpen();
		}
    	else
    	{
    		Lcd_voidSendCommand(clear);
    		Lcd_VoidWriteString("Call the service");
    		AlarmThief();
    		while(1);
    	}
    }
}


void buzzer (u8 state)
{
	if (state==Right)
	{
		Dio_voidSetPinValue(PRO_PORT,BuzzerPin,DIO_HIGH);
		_delay_ms(100);
		Dio_voidSetPinValue(PRO_PORT,BuzzerPin,DIO_LOW);
		_delay_ms(200);
		Dio_voidSetPinValue(PRO_PORT,BuzzerPin,DIO_HIGH);
		_delay_ms(100);
		Dio_voidSetPinValue(PRO_PORT,BuzzerPin,DIO_LOW);
	}
	else if (state==Wrong)
	{
		Dio_voidSetPinValue(PRO_PORT,BuzzerPin,DIO_HIGH);
		_delay_ms(100);
		Dio_voidSetPinValue(PRO_PORT,BuzzerPin,DIO_LOW);
		_delay_ms(200);
		Dio_voidSetPinValue(PRO_PORT,BuzzerPin,DIO_HIGH);
		_delay_ms(1000);
		Dio_voidSetPinValue(PRO_PORT,BuzzerPin,DIO_LOW);
	}
}


void GreenLed (u8 state)
{
	Dio_voidSetPinValue(PRO_PORT,GreenLedPin,state);
}


void redLed (u8 state)
{
	Dio_voidSetPinValue(PRO_PORT,RedLedPin,state);
}


void Lights (u8 state)
{
	Dio_voidSetPinValue(PRO_PORT,LightPin,state);
}


void Fan (u8 state)
{
	Dio_voidSetPinValue(PRO_PORT,FanPin,state);
}


void AlarmThief (void)
{
	for (int i = 0; i < 10; ++i)
	{
		Dio_voidSetPinValue(PRO_PORT,BuzzerPin,DIO_HIGH);
		_delay_ms(800);
		Dio_voidSetPinValue(PRO_PORT,BuzzerPin,DIO_LOW);
		_delay_ms(200);
	}
}


void Gate (u8 state)
{

	if(state==Open)
	{
		if (Stpr_previous_state==Close)
		{
			Stpr_voidMove(120,CW);
			Stpr_previous_state=Open;
		}
	}
	else if(state==Close)
	{
		if (Stpr_previous_state==Open)
		{
			Stpr_voidMove(120,CCW);
			Stpr_previous_state=Close;
		}
	}
}


u8 password_check(u8 y)
{
	u8 usernum=y;
	Lcd_voidSendCommand(clear);
	Lcd_VoidWriteString("Locked ");
	Lcd_GoToXY(1,0);
	Lcd_VoidWriteString("Type Password ");
	for (u8 i=0;i<3;i++)
	{
		u8 Password [PASS_SIZE];
		UART_VoidRecString(Password);
		if(strcmp(Password, loginPass[usernum]) == 0)
		{
			Lcd_voidSendCommand(clear);
			Lcd_VoidWriteString("welcome");
			GreenLed(On);
			redLed(Off);
			buzzer(Right);
			Gate(Open);
			return Right;
		}
		if (i<2)
		{
			Lcd_voidSendCommand(clear);
			Lcd_VoidWriteString("Try again ");
			buzzer(Wrong);
		}
	}
	return Wrong;
}


u8 user_check(void)
{
	Lcd_voidSendCommand(clear);
	Lcd_VoidWriteString("Locked ");
	Lcd_GoToXY(1,0);
	Lcd_VoidWriteString("Type username ");
	for (u8 i=0;i<3;i++)
	{
		u8 user [USER_SIZE];
		UART_VoidRecString(user);
		for(u8 y=0;y<10;y++)
		{
			if(strcmp(user, loginUsers[y]) == 0)
			{
				buzzer(Right);
				u8 State= password_check(y);
				return State;
			}
		}
		if (i<2)
		{
			Lcd_voidSendCommand(clear);
			Lcd_VoidWriteString("Try again ");
			buzzer(Wrong);
		}
	}
	return Wrong;
}


u8 HomeOpen (void)
{
	u8 command[14];
	Lcd_voidSendCommand(clear);
	Lcd_VoidWriteString("opened ");
	while(1)
	{
		UART_VoidRecString(command);

		if(strcmp(command, "Light_on")==0)
			Lights(On);
		else if(strcmp(command, "Light_off")==0)
			Lights(Off);
		else if(strcmp(command, "Fan_on")==0)
			Fan(On);
		else if(strcmp(command, "Fan_off")==0)
			Fan(Off);
		else if(strcmp(command, "Gate_open")==0)
		    Gate(Open);
		else if(strcmp(command, "Gate_close")==0)
			Gate(Close);
		else if(strcmp(command, "Home_lock")==0)
		{
			GreenLed(Off);
			redLed(On);
			Lights(Off);
			Fan(Off);
			buzzer(Right);
			Lcd_voidSendCommand(clear);
			Lcd_VoidWriteString("Locked ");
			Lcd_GoToXY(1,0);
			Lcd_VoidWriteString("Type username ");
			Gate(Close);
			return 0;
		}
		else
		{
			Lcd_voidSendCommand(clear);
			Lcd_VoidWriteString("Wrong choice ");
			_delay_ms(3000);
			Lcd_voidSendCommand(clear);
			Lcd_VoidWriteString("opened ");

		}
	}
}
