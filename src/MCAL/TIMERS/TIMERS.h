#ifndef TIMERS_H_
#define TIMERS_H_

#define NON_INVERTED  0
#define INVERTED  1

#include "APP/LIB/STD_TYPES.h"

#define NORMAL     0
#define CTC        1

#define _64        0
#define _256       1
#define _1024      2

void TIMER_0_INIT     (void);
void TIMER_0_SET_TIME (u32);
void TIMER_0_START    (void);
void TIMER_0_STOP     (void);

void TIMER_1_INIT     (void);
void TIMER_1_SET_TIME (u32);
void TIMER_1_START    (void);
void TIMER_1_STOP     (void);

void PWM_0_INIT(void);
void PWM_0_SET_DUTY_CYCLE(u8);
void PWM_0_START(void);
void PWM_0_STOP(void);

void PWM_1_INIT(void);
void PWM_1_SET_DUTY_CYCLE(u8);
void PWM_1_START(void);
void PWM_1_STOP(void);

void PWM_2_INIT(void);
void PWM_2_SET_DUTY_CYCLE(u8);
void PWM_2_START(void);
void PWM_2_STOP(void);

#endif /* TIMERS_H_ */