#ifndef __LCD_H
#define __LCD_H

#include <stdint.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <stdlib.h>
#include <stdbool.h>

#include "PORT.h"
#ifdef __cplusplus
extern "C" {
#endif

#ifndef F_CPU
/* prevent compiler error by supplying a default */
# warning "F_CPU not defined for <util/delay.h>"
#define F_CPU 8000000UL
#endif

#define     LCD_dataport  PORTD
#define     LCD_dataport_in  PIND
static inline void LCD_RS_set_level(const bool level)
{
	PORTB_set_pin_level(2, level);
}

// 4 bit mode
//#define LCD_SET_FUNC_SET		LCD_CMD_FUNCTION_SET|LCD_FUNC_SET_F					//The common Function Set used on our display.	FUNC_SET: 4 bit display line, 1 Line, 5*8 Dots
#define LCD_SET_FUNC_SET		LCD_CMD_FUNCTION_SET								//The common Function Set used on our display.	FUNC_SET: 4 bit display line, 1 Line, 5*8 Dots

// 8 bit mode
//#define LCD_CMD_FUNC_SET		LCD_CMD_FUNCTION_SET|LCD_FUNC_SET_DL|LCD_FUNC_SET_N			//The common Function Set used on our display.	FUNC_SET: 8 bit display line, 2 Line, 5*8 Dots

//	The Entry Mode Set Used on our DIsplay at startup
//	ENTRY_MODE: Cursor Move Right , Do not shift Display
#define LCD_ENT_MODE_SET		LCD_CMD_ENTRY_MODE_SET|LCD_ENTRY_MODE_SET_CURSOR_DIR

//	The Display Mode Setting Used on our DIsplay at startup
//	Display on , CUrsor Off, Cursor Blink off.
#define LCD_DISP_MODE_SET		LCD_CMD_DISPLAY_ON_OFF|LCD_DISPLAY_DISP_ON

//	The command to set the cursor position and turn the cursor on.
#define LCD_SET_CURSOR_POS		LCD_CMD_DISPLAY_ON_OFF|LCD_DISPLAY_DISP_ON|LCD_DISPLAY_CURSOR_BLINK

/* LCD module constants */
#define NEW_LINE 				0xc0

//
//	The offset to put the cursor on line 2 of the display.
//
#define LCD_LINE_2_OFFSET		0x040

typedef enum lcd_driver_cmds
{
	LCD_CMD_CLEAR_DISPLAY	=		0x01,				//!<The LCD Clear Display Command
	LCD_CMD_RETURN_HOME		=		0x02,				//!<The LCD Return Home Command
	LCD_CMD_ENTRY_MODE_SET 	=		0x04,				//!<The LCD Entry Mode Set bit with no options
	LCD_CMD_DISPLAY_ON_OFF	=		0x08,				//!<The LCD display on off for Display, CUrsor and Blinking of CUrsor
	LCD_CMD_CURSOR_DISPLAY_SHIFT =	0x10,				//!<Set cursor moving and display shift control bit, and the direction, without changing of DDRAM data.
	LCD_CMD_FUNCTION_SET 		=	0x20,				//!<The LCD Function Set bit with no options
	LCD_CMD_SET_CGRAM_ADDRESS	=	0x40,				//!<Move the address pointing to in CGRAM to the address in the lower 6 bits.
	LCD_CMD_SET_DDRAM_ADDRESS	=	0x80,				//!<Move the address pointed to in DDRAM to the address in the lower 7 bits.	
	
	LCD_ENTRY_MODE_SHIFT_DISPLAY  =	0x01,				//!< Enables shifting of entire display.
	LCD_DISPLAY_CURSOR_BLINK	=	0x01,				//!<THe Blinking of the Cursor.
	LCD_ENTRY_MODE_SET_CURSOR_DIR =	0x02,				//!< The Cursor moving direction
	LCD_DISPLAY_CURSOR_ON	=		0x02,				//!<The Cursor On/Off
	LCD_CURSOR_DISPLAY_LEFT_RIGHT=	0x02,				//!<1 selects Left moving 0 selects right moving
	LCD_DISPLAY_DISP_ON		=		0x04,				//!<THe DIsplay on/off
	LCD_CURSOR_DISPLAY_CURSOR	=	0x04,				//!<1 selects display 0 selects cursor
	LCD_FUNC_SET_F			=		0x04,				//!<(F:5x11 dots/5x8 dots)
	LCD_FUNC_SET_N				=	0x08,				//!<(N:2-line/1-line)and, display font type
	LCD_FUNC_SET_DL	 			=	0x10,				//!<(DL:8-bit/4-bit), numbers of display line
	LCD_ARROW_ADDRESS			=	0x40,				//!< the address of the arrows in LCD memory
	LCD_ARROW_ICON				=	0xC0,				//!< the address of the arrow icon

}lcd_driver_cmds;

#define		LCD_WIDTH	8	    // LCD IS 16 CHARACTERS LONG
#define		BL_TIMEOUT  240	    // LCD BACKLIGHT TIMEOUT DEFAULT | 0 = ALWAYS ON, 60-240 SECONDS


extern uint8_t flow_state;
extern volatile bool LCD_backlight;

void LCD_splash();
void LCD_write(uint8_t data);
void LCD_write_datamode(uint8_t data);
void LCD_line_write(char *data, uint8_t length); //length has to <= LCD_WIDTH
void LCD_enable_toggle(void);
void LCD_homing(void);
void LCD_initial(void);
void LCD_address_set(uint8_t add);
void LCD_topline_write(char *data, uint8_t length);
void LCD_bottomline_write(char *data, uint8_t length);
void LCD_topline_clear(void);
void LCD_bottomline_clear(void);
void LCD_rotateleft(void);
void LCD_rotateright(void);
void LCD_cursor_shift_right(void);
void LCD_cursor_shift_left(void);
void LCD_show_arrow(uint8_t arrow_position);
void LCD_scroll(const char *data, uint8_t length);
void LCD_RTC_time_display(unsigned char data);
void LCD_floattemp_display(uint8_t sign,int8_t temp);
void LCD_realtime_temp_display(uint8_t sign,int8_t temp);
void LCD_show_halfdegree_symbol(void);
void LCD_show_up_arrow(void);
void LCD_show_down_arrow(void);
void LCD_line_write_P(const char *data, uint8_t length);
void LCD_topline_write_P(const char *data, uint8_t length);
void LCD_bottomline_write_P(const char *data, uint8_t length);
void LCD_ascii_write(uint8_t addr, uint8_t length, const char *data);
void display_date_time();

void LCD_backlight_on(void);
void LCD_backlight_off(void);



//unsigned char* BINtoBCD3(unsigned char data, unsigned char *bcd);
char* BINtoBCD3(char data, char *bcd);
unsigned char BINtoBCD2(unsigned char data);

#ifdef __cplusplus
}
#endif


#endif