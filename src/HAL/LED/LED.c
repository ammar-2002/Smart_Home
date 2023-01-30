#include "LED.h"
#include "LED_CFG.h"
#include "MCAL/DIO/DIO.h"

void LED_INIT(u8 x){
	switch(x){
		case 0:
		PIN_MODE(LED_0_PIN,OUTPUT);
		break;
		case 1:
		PIN_MODE(LED_1_PIN,OUTPUT);
		break;
		case 2:
		PIN_MODE(LED_2_PIN,OUTPUT);
		break;
		default:
		break;
	}
}

void LED_ON(u8 x){
	switch(x){
		case 0:
		PIN_WRITE(LED_0_PIN,HIGH);
		break;
		case 1:
		PIN_WRITE(LED_1_PIN,HIGH);
		break;
		case 2:
		PIN_WRITE(LED_2_PIN,HIGH);
		break;
		default:
		break;
	}
}

void LED_OFF(u8 x){
	switch(x){
		case 0:
		PIN_WRITE(LED_0_PIN,LOW);
		break;
		case 1:
		PIN_WRITE(LED_1_PIN,LOW);
		break;
		case 2:
		PIN_WRITE(LED_2_PIN,LOW);
		break;
		default:
		break;
	}
}

void LED_TOG(u8 x){
	switch(x){
		case 0:
		PIN_TOG(LED_0_PIN);
		break;
		case 1:
		PIN_TOG(LED_1_PIN);
		break;
		case 2:
		PIN_TOG(LED_2_PIN);
		break;
		default:
		break;
	}
}
