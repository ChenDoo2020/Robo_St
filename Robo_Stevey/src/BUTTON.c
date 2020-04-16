/*
 * BUTTON.c
 *
 * Created: 16/04/2020 1:58:20 PM
 *  Author: chen
 */ 
#include "BUTTON.h"

void get_button1_state()
{
    uint8_t count = 0;
    
    bool button_state = 0;
    
    bool current_state = (!(PINB&(1<<3)) & !(PINB(1<<5)));
    
    if(current_state != button_state)
    {
        count++;
        if (count>5)
        {
            button_state = current_state;
            
            if (button_state !=0)
            {
                button1_press = 1;
            }
            count = 0;
        }
    } 
    else 
    {
        count = 0;
    }
}

