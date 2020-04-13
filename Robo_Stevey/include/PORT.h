/*
 * PORT.h
 *
 * Created: 13/04/2020 7:26:10 AM
 *  Author: Chen
 */ 


#ifndef PORT_H_
#define PORT_H_

#include <avr/io.h>
#include <stdbool.h>
void PORT_dir_init();
void PORTB_set_pin_level(const uint8_t pin, const bool level);
void LCD_EN_set_level(const bool level);
void LCD_BL_set_level(const bool level);
#endif /* PORT_H_ */