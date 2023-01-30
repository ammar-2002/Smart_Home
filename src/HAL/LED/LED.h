#ifndef LED_H_
#define LED_H_

#include "APP/LIB/STD_TYPES.h"

#define LED_0 0
#define LED_1 1
#define LED_2 2

void LED_INIT(u8);
void LED_ON(u8);
void LED_OFF(u8);
void LED_TOG(u8);

#endif /* LED_H_ */