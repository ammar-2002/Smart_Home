#include "LCD_CFG.h"
#include "LCD.h"
#include "MCAL/DIO/DIO.h"
#define F_CPU 16000000UL
#include "util/delay.h"

void LCD_INIT(void){
	PIN_MODE(LCD_RS_PIN,OUTPUT);
	PIN_MODE(LCD_EN_PIN,OUTPUT);
	PIN_MODE(LCD_RW_PIN,OUTPUT);
	PIN_WRITE(LCD_RW_PIN,LOW);
	#if LCD_MODE == _8_BIT_MODE
	PORT_MODE(LCD_DATA_PORT,OUTPUT);
	LCD_SEND_CMD(0x38);  /* THIS COMMAND ACTIVATE 4 BIT MODE ********************/
	#elif LCD_MODE == _4_BIT_MODE
	PIN_MODE(LCD_DATA_PIN_4,OUTPUT);
	PIN_MODE(LCD_DATA_PIN_5,OUTPUT);
	PIN_MODE(LCD_DATA_PIN_6,OUTPUT);
	PIN_MODE(LCD_DATA_PIN_7,OUTPUT);
	LCD_SEND_CMD(0x33);  /* THIS COMMAND ACTIVATE 4 BIT MODE ********************/
	LCD_SEND_CMD(0x32);  /* THIS COMMAND ACTIVATE 4 BIT MODE ********************/  /* ALL THREE COMANDS FOR 4 BIT MODE */
	LCD_SEND_CMD(0x28);  /* THIS COMMAND ACTIVATE 4 BIT MODE ********************/
	#endif
	LCD_SEND_CMD(0x0C);  /* THIS COMMAND TO TURN ON DISPLAY AND TURN OFF CURSOR */
	LCD_SEND_CMD(0x01);  /* THIS COMMAND TO CLEAR LCD ***************************/
	LCD_SEND_CMD(0x06);  /* THIS COMMAND TO MOVE CURSOR FROM LEFT TO WRITE ******/
	LCD_SEND_CMD(0x02);  /* THIS COMMAND TO RETURN HOME *************************/
}

void LCD_SEND_CMD(u8 command){
	#if LCD_MODE == _8_BIT_MODE
	PIN_WRITE(LCD_RS_PIN,LOW);
	PORT_WRITE(LCD_DATA_PORT,command);
	PIN_WRITE(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	PIN_WRITE(LCD_EN_PIN,LOW);
	_delay_ms(10);
	#elif LCD_MODE == _4_BIT_MODE
	PIN_WRITE(LCD_RS_PIN,LOW);
	PORT_WRITE(LCD_DATA_PORT,(command & 0xF0) | (PORT_READ(LCD_DATA_PORT) & 0x0F));
	PIN_WRITE(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	PIN_WRITE(LCD_EN_PIN,LOW);
	_delay_ms(10);
	PORT_WRITE(LCD_DATA_PORT,(command << 4) | (PORT_READ(LCD_DATA_PORT) & 0x0F));
	PIN_WRITE(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	PIN_WRITE(LCD_EN_PIN,LOW);
	_delay_ms(10);
	#endif
}

void LCD_SEND_CHR(u8 character){
	#if LCD_MODE == _8_BIT_MODE
	PIN_WRITE(LCD_RS_PIN,HIGH);
	PORT_WRITE(LCD_DATA_PORT,character);
	PIN_WRITE(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	PIN_WRITE(LCD_EN_PIN,LOW);
	_delay_ms(10);
	#elif LCD_MODE == _4_BIT_MODE
	PIN_WRITE(LCD_RS_PIN,HIGH);
	PORT_WRITE(LCD_DATA_PORT, (character & 0xF0) | (PORT_READ(LCD_DATA_PORT) & 0x0F));
	PIN_WRITE(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	PIN_WRITE(LCD_EN_PIN,LOW);
	_delay_ms(10);
	PIN_WRITE(LCD_RS_PIN,HIGH);
	PORT_WRITE(LCD_DATA_PORT, (character << 4) | (PORT_READ(LCD_DATA_PORT) & 0x0F));
	PIN_WRITE(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	PIN_WRITE(LCD_EN_PIN,LOW);
	_delay_ms(10);
	#endif
}

void LCD_SEND_STR(u8* string){
	u8 i=0;
	while(*(string+i) != '\0'){
		LCD_SEND_CHR(*(string+i));
		i++;
	}
}

void LCD_SEND_NUM(u32 num){
    u32 rem = 0;
    u8 arr [16];
    s8 i = 0;
    while(num){
        rem = num % 10;
        arr[i] = rem + 48;
        i++;
        num = num / 10;
    }
    i--;
    while(i > -1)
    {
        LCD_SEND_CHR(arr[i]);
        i--;
    }
}

void LCD_CLR(void){
    LCD_SEND_CMD(0x01);
}
