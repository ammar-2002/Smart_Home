#ifndef TIMERS_CFG_H_
#define TIMERS_CFG_H_

#define CRYSTAL_FREQUENCY 16

/********_SELECT_TIMER_0_MODE_********/
/*_OPTIONS_1_-> [ NORMAL ] ***********/
/*_OPTIONS_2_-> [ CTC ] **************/
#define TIMER_0_MODE         NORMAL
/*************************************/

/******_SELECT_TIMER_0_PRESCALER_******/
/*_OPTIONS_1_-> [ _64 ] ***************/
/*_OPTIONS_2_-> [ _256 ] **************/
/*_OPTIONS_3_-> [ _1024 ] *************/
#define TIMER_0_PRESCALER       _1024
/*************************************/

#define FAST_PWM_MODE NON_INVERTED

#endif /* TIMERS_CFG_H_ */