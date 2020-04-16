/*
 * PWM.c
 *
 * Created: 2/04/2020 10:25:46 AM
 *  Author: chen
 */ 
#include "PWM.h"


void PWM_init()
{
	// Waveform generation mode 14
	// WGM13:0 to 1:1:1:0
	TCCR1B |= (1<<WGM13) | (1<<WGM12);
	TCCR1A |= (1<<WGM11);
	// No Pre-scaling
	// CS12:0 to 0:0:1
	TCCR1B |= (1<<CS10);
}

void PWM_gen()
{
    switch (step)
    {
        case step0:
        step = step1;
        break;
        case step1:
        ICR1 = F_CPU/500;
        OCR1A = F_CPU/1500;
        TCCR1A |= (1<<COM1A1) | (1<<COM1A0);
        _delay_ms(20);
        step = step2;
    	break;
        case step2:
        ICR1 = F_CPU/1500;
        OCR1A = F_CPU/4500;
        _delay_ms(20);
        step = step3;
        break;
        case step3:
        ICR1 = F_CPU/3000;
        OCR1A = F_CPU/9000;
        _delay_ms(20);
        step = step4;
        break; 
        case step4:
        ICR1 = F_CPU/6000;
        OCR1A = F_CPU/18000;
        break;                       
    }
}

void PWM_halt()
{
	// Disable FAST PWM
	TCCR1A &= ~(1<<COM1A1) & ~(1<<COM1A0);
    step = step0;
}

void PWM_set_dir(const bool dir)
{
    if (dir)
    {
        PORTB |= (1<<PORTB0);
    }
    else
    {
        PORTB &= ~(1<<PORTB0);
    }
}
