/*
 * PWM.c
 *
 * Created: 2/04/2020 10:25:46 AM
 *  Author: chen
 */ 
#include "PWM.h"


static inline void PWM_init()
{
	// Waveform generation mode 14
	// WGM13:0 to 1:1:1:0
	TCCR1B |= (1<<WGM13) | (1<<WGM12);
	TCCR1A |= (1<<WGM11) | (1<<WGM10);
	// No Pre-scaling
	// CS12:0 to 0:0:1
	TCCR1B |= (1<<CS10);
}

static inline void PWM_gen()
{
	// Enable FAST PWM inverting mode
	TCCR1A |= (1<<COM1A1) | (1<<COM1A0);
	_delay_ms(1);
	// Set initial frequency to 500Hz, duty cycle = 30%
	ICR1 = 15999;
	OCR1A = 4800;
	_delay_ms(10);
	// Set frequency to 1500Hz
	ICR1 = 5333;
	OCR1A = 1600;
	_delay_ms(10);
	// Set final frequency to 5000Hz
	ICR1 = 1500;
	OCR1A = 480;
}

static inline void PWM_halt()
{
	// Disable FAST PWM
	TCCR1A &= ~(1<<COM1A1) & ~(1<<COM1A0);
}