#include "IR.h"
#include "IR_CFG.h"
#include "MCAL/DIO/DIO.h"

void IR_INIT(u8 sensor){
    switch(sensor){
        case IR_1:
            PIN_MODE(IR_1_PIN,INPUT);
            break;
        case IR_2:
            PIN_MODE(IR_2_PIN,INPUT);
            break;
        case IR_3:
            PIN_MODE(IR_3_PIN,INPUT);
            break;
        default:
            break;
    }
}

u8 IR_READ(u8 sensor){
    u8 reading;
    switch(sensor){
        case IR_1:
            reading = PIN_READ(IR_1_PIN);
            break;
        case IR_2:
            reading = PIN_READ(IR_2_PIN);
            break;
        case IR_3:
            reading = PIN_READ(IR_3_PIN);
            break;
        default:
            reading = 0;
            break;
    }
    return reading;
}