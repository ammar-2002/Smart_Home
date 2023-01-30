#include "SERVO.h"
#include "SERVO_CFG.h"
#include "MCAL/DIO/DIO.h"
#include "MCAL/TIMERS/TIMERS.h"

void SERVO_INIT(void)
{
    PWM_2_INIT();
    PWM_2_START();
}
void SERVO_ROTATE(u8 duty_cycle)
{
    PWM_2_SET_DUTY_CYCLE(duty_cycle);
}