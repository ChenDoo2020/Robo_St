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
#include "PORT.h"

enum pwm_step{step0,step1,step2,step3,step4}step;
void PWM_init();
void PWM_gen();
void PWM_halt();
void PWM_set_dir(const bool dir);
#endif /* PWM_H_ */