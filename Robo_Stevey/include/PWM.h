/*
 * PWM.h
 *
 * Created: 2/04/2020 10:04:33 AM
 *  Author: chen
 */ 


#ifndef PWM_H_
#define PWM_H_
#include <avr/io.h>
#include <util/delay.h>

static inline void PWM_init();
static inline void PWM_gen();
static inline void PWM_halt();
#endif /* PWM_H_ */