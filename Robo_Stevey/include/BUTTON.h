/*
 * BUTTON.h
 *
 * Created: 16/04/2020 1:57:56 PM
 *  Author: chen
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/atomic.h>

uint8_t button1_press;
uint8_t button2_press;
uint8_t button3_press;
uint8_t button4_press;

void get_button1_state();
#endif /* BUTTON_H_ */