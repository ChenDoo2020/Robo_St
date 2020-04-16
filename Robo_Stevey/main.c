/*
 * Robo_Stevey.c
 *
 * Created: 13/04/2020 6:56:37 AM
 * Author : Chen
 */ 

#include "PORT.h"
#include "LCD.h"
#include "PWM.h"
#include "Button.h"

button1_press = 0;

enum e_states
{
    start,
    find_start_ck,
    find_start_ack,
    init_ck,
    init_ack,
    init_done
}state;

int main(void)
{
    PORT_dir_init();
    
    LCD_initial();
    LCD_initial();
    
    LCD_backlight_on();
    LCD_ascii_write(0x80, 8, "Hello   ");
    _delay_ms(1000);
    LCD_ascii_write(0x80, 8, "this    ");
    _delay_ms(1000);
    LCD_ascii_write(0x80, 8, "is      ");
    _delay_ms(1000);
    LCD_ascii_write(0x80, 8, "RoboStev");
    _delay_ms(1000);
    LCD_backlight_off();
    
    state = start;
    _delay_ms(1000);
    PWM_init();
    LCD_backlight_on();
    while (1) 
    {
        switch (state)
        {
            case start:
            LCD_ascii_write(0x80, 8, "START   ");
            get_button1_state();
            if (button1_press)
            {
                button1_press = 0;
                
                state = find_start_ck;
            }
            _delay_ms(10);
            break;
            case find_start_ck:
            PWM_set_dir(true);
            PWM_gen();
            get_button1_state();
            if (button1_press)
            {
                button1_press = 0;
                
                state = start;
            }
            _delay_ms(10);
            break;
            case find_start_ack:
            case init_ck:
            break;
            case init_ack:
            break;
            case init_done:
            break;          
        } 
    }
}
