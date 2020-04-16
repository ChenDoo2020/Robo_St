/*
 * PORT.c
 *
 * Created: 13/04/2020 7:26:20 AM
 *  Author: Chen
 */ 
#include <util/delay.h>
#include "PORT.h"


void PORT_dir_init()
{
	/* PORTD config
	** PD0 and PD1 as inputs for the optocoupler */
	DDRD &= ~(1<<DDD0) & ~(1<<DDD1);
	DDRD |= (1<<DDD2) | (1<<DDD3) | (1<<DDD4) | (1<<DDD5) | (1<<DDD6) | (1<<DDD7); // Rest as output
	PIND |= (1<<PIND0) | (1<<PIND1); //Enable internal pull up for PD0 and PD1
	/* PORTC config
	** PC0:3 as inputs for the proximity sensors */
	DDRC &= ~(1<<DDC0) & ~(1<<DDC1) & ~(1<<DDC2) & ~(1<<DDC3);
	DDRC |= (1<<DDC4) | (1<<DDC5); // Rest as output
	PINC |= (1<<PINC0) | (1<<PINC1) | (1<<PINC2) | (1<<PINC3); //Enable internal pull up for PC0:3
	/* PORTB config
	** PB0:2 as outputs for U/D and PWM */
	DDRB |= (1<<DDB0) | (1<<DDB1) | (1<<DDB2);
	DDRB &= ~(1<<DDB3) & ~(1<<DDB4) & ~(1<<DDB5);
} 

void PORTB_set_pin_level(const uint8_t pin, const bool level)
{
	if(level){
		PORTB |= (1<<pin);
	}
	else{
		PORTB &= ~(1<<pin);
	}
}

void LCD_EN_set_level(const bool level)
{
	if(level){
		PORTC |= (1<<4);
	}
	else{
		PORTC &= ~(1<<4);
	}
}

void LCD_BL_set_level(const bool level)
{
	if(level){
		PORTD |= (1<<3);
	}
	else{
		PORTD &= ~(1<<3);
	}
}
// Get level of optocouplers
bool OPTO1_get_level()
{
    if (PIND & (1<<PIND0)){
        return true;
    }
    else{
        return false;
    }
}

bool OPTO2_get_level()
{
    if (PIND & (1<<PIND1)){
        return true;
    }
    else{
        return false;
    }
}

// Get level of proximity sensors
bool PROXY1_get_level()
{
    if (PINC & (1<<PINC0)){
        return true;
    }
    else{
        return false;
    }
}
bool PROXY2_get_level()
{
    if (PINC & (1<<PINC0)){
        return true;
    }
    else{
        return false;
    }
}
bool PROXY3_get_level()
{
    if (PINC & (1<<PINC0)){
        return true;
    }
    else{
        return false;
    }
}
bool PROXY4_get_level()
{
    if (PINC & (1<<PINC0)){
        return true;
    }
    else{
        return false;
    }
}

