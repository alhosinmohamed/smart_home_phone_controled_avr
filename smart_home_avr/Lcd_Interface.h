/*****************************************************/
/* Author      : alhosin                             */
/* date        : 02/09/2023                          */
/*****************************************************/
#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

void Lcd_Init(void);
void Lcd_voidSendCommand(u8 Cpy_u8Command);
void Lcd_voidSendData(u8 Cpy_u8Data);
void Lcd_VoidWriteString(char Cpy_ChararrData[]);
void Lcd_VoidWriteNumber(s32 Cpy_Num);
void Lcd_GoToXY(u8 x,u8 y);
void Lcd_voidAddNewPattern(u8 Block_Num,u8 *arr);
void Lcd_voidShowNewPattern(u8 Block_Num,u8 x,u8 y);
#define clear 0b00000001

#endif
