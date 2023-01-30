#include "KEY_PAD.h"
#include "KEY_PAD_CFG.h"
#include "MCAL/DIO/DIO.h"
#define F_CPU 16000000UL
#include "util/delay.h"

u8 arr[4][4]={
        {'1', '2', '3', '+'},
        {'4', '5', '6', '-'},
        {'7', '8', '9', 'x'},
        {'.', '0', '=', '/'}
};

void KEY_PAD_INIT(void){
    PIN_MODE(KEY_PAD_X0,OUTPUT);
    PIN_MODE(KEY_PAD_X1,OUTPUT);
    PIN_MODE(KEY_PAD_X2,OUTPUT);
    PIN_MODE(KEY_PAD_X3,OUTPUT);
    
    PIN_MODE(KEY_PAD_Y0,INPUT);
    PIN_MODE(KEY_PAD_Y1,INPUT);
    PIN_MODE(KEY_PAD_Y2,INPUT);
    PIN_MODE(KEY_PAD_Y3,INPUT);
    
    PIN_WRITE(KEY_PAD_X0,HIGH);
    PIN_WRITE(KEY_PAD_X1,HIGH);
    PIN_WRITE(KEY_PAD_X2,HIGH);
    PIN_WRITE(KEY_PAD_X3,HIGH);
    
    PIN_PULL_UP_RES(KEY_PAD_Y0,ENABLE);
    PIN_PULL_UP_RES(KEY_PAD_Y1,ENABLE);
    PIN_PULL_UP_RES(KEY_PAD_Y2,ENABLE);
    PIN_PULL_UP_RES(KEY_PAD_Y3,ENABLE);
}

u8 KEY_PAD_READ(void){
    u8 r;
    u8 c;
    u8 temp, value = 0;
    for(r=KEY_PAD_X0;r<=KEY_PAD_X3;r++){
        PIN_WRITE(r,LOW);
        for (c=KEY_PAD_Y0;c<=KEY_PAD_Y3;c++){
            temp = PIN_READ(c);
            if(temp == PRESSED){
                value = arr[r - KEY_PAD_X0][C - KEY_PAD_Y0];  //must fill the array first according to the key pad
                while(!(temp = PIN_READ(c)));
                _delay_ms(10);
            }
        }
        PIN_WRITE(r,HIGH);
    }
    return value;
}