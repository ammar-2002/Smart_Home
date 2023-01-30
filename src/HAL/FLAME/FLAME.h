#ifndef TEST2_FLAME_H
#define TEST2_FLAME_H

#include "APP/LIB/STD_TYPES.h"

#define FLAME_1 0
#define FLAME_2 1
#define FLAME_3 2

#define FIRE_DETECTED 1
#define NO_FIRE_DETECTED 0

void FLAME_INIT(u8);
u8 FLAME_READ(u8);

#endif //TEST2_FLAME_H
