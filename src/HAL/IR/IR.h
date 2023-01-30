#ifndef TEST2_IR_H
#define TEST2_IR_H

#include "APP/LIB/STD_TYPES.h"

#define IR_1 0
#define IR_2 1
#define IR_3 2

#define OBJECT_DETECTED 1

#define Pressed 1
#define NotPressed 0

void IR_INIT(u8);
u8 IR_READ(u8);

#endif //TEST2_IR_H
