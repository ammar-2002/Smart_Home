#ifndef LCD_H_
#define LCD_H_

#define _4_BIT_MODE 4
#define _8_BIT_MODE 8

#include "APP/LIB/STD_TYPES.h"

void LCD_INIT(void);
void LCD_SEND_CHR(u8);
void LCD_SEND_CMD(u8);
void LCD_SEND_STR(u8*);
void LCD_SEND_NUM(u32);
void LCD_CLR(void);

#endif /* LCD_H_ */