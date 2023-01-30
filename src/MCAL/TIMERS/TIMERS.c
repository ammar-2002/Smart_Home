#include "TIMERS.h"
#include "TIMERS_CFG.h"
#include "MCAL/REG.h"
#include "APP/LIB/BIT_MATH.h"
#include "MCAL/DIO/DIO.h"
u32 num_of_ov;
u32 initial_value;

void TIMER_0_INIT(void)
{
#if TIMER_0_MODE   ==  NORMAL
    CLR_BIT(TCCR0,3);
    CLR_BIT(TCCR0,6);
#elif TIMER_0_MODE  == CTC
    SET_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);
#endif
    SET_BIT(SREG,7);    // to enable global int
    SET_BIT(TIMSK,0);   // to enable timer0 int
}
void TIMER_0_SET_TIME(u32 desired_time)
{
    u32 tick_time   = 1024 / 16;   // result in micro second
    u32 total_ticks = ( desired_time * 1000 ) / tick_time;
    num_of_ov       = total_ticks / 256;
    initial_value   = 255 - ( total_ticks % 256 );
    if( (total_ticks % 256) != 0 )
    {
        TCNT0       = initial_value;
        num_of_ov++;
    }
}

void TIMER_0_START(void)
{
#if TIMER_0_PRESCALER     ==   _64
    SET_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);
#elif TIMER_0_PRESCALER   ==   _256
    CLR_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
    SET_BIT(TCCR0,2);
#elif TIMER_0_PRESCALER   ==   _1024
    SET_BIT(TCCR0,0);
    CLR_BIT(TCCR0,1);
    SET_BIT(TCCR0,2);
#endif
}

void TIMER_0_STOP(void)
{
    CLR_BIT(TCCR0,0);
    CLR_BIT(TCCR0,1);
    CLR_BIT(TCCR0,2);
}

void TIMER_1_INIT(void)
{
    /*to select ctc mode in timer 1*/
    CLR_BIT(TCCR1A,0);
    CLR_BIT(TCCR1A,1);
    SET_BIT(TCCR1B,3);
    CLR_BIT(TCCR1B,4);

    /*_to enable global int and timer 1 int*/
    SET_BIT(SREG,7);
    SET_BIT(TIMSK,4);
}
void TIMER_1_SET_TIME(u32 desired_time)
{
    if (desired_time <= 8000)
    {
        u8  tick_time  = 1024 / 16;      // result will be in micro second
        u32 total_ticks = desired_time*1000 / tick_time;
        OCR1A = total_ticks - 1;

    }
}
void TIMER_1_START(void)
{
    SET_BIT(TCCR1B,0);
    CLR_BIT(TCCR1B,1);
    SET_BIT(TCCR1B,2);
}
void TIMER_1_STOP(void)
{
    CLR_BIT(TCCR1B,0);
    CLR_BIT(TCCR1B,1);
    CLR_BIT(TCCR1B,2);
}
void PWM_0_INIT(void)
{
    SET_BIT(DDRB,3);
    /* to select fast pwm mode*/
    SET_BIT(TCCR0,3);
    SET_BIT(TCCR0,6);
    /*to select non inverted mode*/
    CLR_BIT(TCCR0,4);
    SET_BIT(TCCR0,5);
}

void PWM_0_SET_DUTY_CYCLE(u8 duty_cycle)
{
    if(duty_cycle <= 100)
    {
        OCR0 = (( duty_cycle * 256 ) / 100 ) - 1;
    }
}

void PWM_0_START(void)
{
    CLR_BIT(TCCR0,0);
    CLR_BIT(TCCR0,1);
    SET_BIT(TCCR0,2);
}

void PWM_0_STOP(void)
{
    CLR_BIT(TCCR0,0);
    CLR_BIT(TCCR0,1);
    CLR_BIT(TCCR0,2);
}

void PWM_1_INIT(void)
{

    /*to select mode 14 -> fast pwm mode with icr1 in top in timer 1*/
    CLR_BIT(TCCR1A,0);
    SET_BIT(TCCR1A,1);
    SET_BIT(TCCR1B,3);
    SET_BIT(TCCR1B,4);

    /*to select non inverted mode*/
    SET_BIT(TCCR1A,7);
    ICR1 = 1250;
}
void PWM_1_SET_DUTY_CYCLE(u8 duty_cycle)
{
    OCR1B = (( duty_cycle * 1250 ) / 100 ) - 1;
}
void PWM_1_START(void)
{
    CLR_BIT(TCCR1B,0);
    CLR_BIT(TCCR1B,1);
    SET_BIT(TCCR1B,2);
}
void PWM_1_STOP(void)
{
    CLR_BIT(TCCR1B,0);
    CLR_BIT(TCCR1B,1);
    CLR_BIT(TCCR1B,2);
}

void PWM_2_INIT(void)
{
    SET_BIT(DDRD,7);
    SET_BIT(TCCR2,3);
    SET_BIT(TCCR2,6);
    SET_BIT(TCCR2,5);
}
void PWM_2_SET_DUTY_CYCLE(u8 duty_cycle)
{
    OCR2 = (( duty_cycle * 256 ) / 100 ) - 1;
}
void PWM_2_START(void)
{
    SET_BIT(TCCR2,0);
    SET_BIT(TCCR2,1);
    SET_BIT(TCCR2,2);
}
void PWM_2_STOP(void)
{

}