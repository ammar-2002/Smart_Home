#include "FLAME.h"
#include "FLAME_CFG.h"
#include "MCAL/DIO/DIO.h"

void FLAME_INIT(u8 sensor){
    switch(sensor){
        case FLAME_1:
            PIN_MODE(FLAME_1_PIN,INPUT);
            break;
        case FLAME_2:
            PIN_MODE(FLAME_2_PIN,INPUT);
            break;
        case FLAME_3:
            PIN_MODE(FLAME_3_PIN,INPUT);
            break;
        default:
            break;
    }
}

u8 FLAME_READ(u8 sensor){
    u8 reading;
    switch(sensor){
        case FLAME_1:
            reading = PIN_READ(FLAME_1_PIN);
            break;
        case FLAME_2:
            reading = PIN_READ(FLAME_2_PIN);
            break;
        case FLAME_3:
            reading = PIN_READ(FLAME_3_PIN);
            break;
        default:
            reading = NO_FIRE_DETECTED;
            break;
    }
    return reading;
}
