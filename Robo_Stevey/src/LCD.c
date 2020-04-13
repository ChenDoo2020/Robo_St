#include "LCD.h"

//static void lcd_driver_disp_clock(void);
static void lcd_driver_set_data(uint8_t data);

volatile bool LCD_backlight=false;

uint8_t temp;

static bool lcd_driver_reInit = false; //true;

#define LCD_NUMBER_REINIT_CMDS sizeof (LCD_ReInitCommandSequence )/sizeof(uint8_t)
#define LCD_NUMBER_INIT_CMDS sizeof (LCD_InitCommandSequence )/sizeof(uint8_t)

static const uint8_t LCD_InitCommandSequence[] =
{
	LCD_SET_FUNC_SET,
	LCD_SET_FUNC_SET,
	LCD_SET_FUNC_SET,
	LCD_SET_FUNC_SET,
	LCD_DISP_MODE_SET,
	LCD_CMD_CLEAR_DISPLAY,
	LCD_ENT_MODE_SET,
};

// Used for re initialisation
static const uint8_t LCD_ReInitCommandSequence[] = {
	LCD_SET_FUNC_SET,		//0x38
	LCD_SET_FUNC_SET,		//0x38
	LCD_ENT_MODE_SET,		//0x06
	LCD_DISP_MODE_SET,		//0x0c
	LCD_CMD_RETURN_HOME,	//0x02
};

void LCD_initial() {
	uint8_t i;
	_delay_ms(5);
	LCD_EN_set_level(false);
	_delay_us(1);
	LCD_RS_set_level(false);
	_delay_us(20);
	
	// clock out each of the commands in the init sequence.
	uint8_t number_cmds = (lcd_driver_reInit==true)?LCD_NUMBER_REINIT_CMDS:LCD_NUMBER_INIT_CMDS;

	for (i = 0; i < number_cmds; i++)
	{
		if (lcd_driver_reInit) lcd_driver_set_data(LCD_ReInitCommandSequence[i]);
		else lcd_driver_set_data(LCD_InitCommandSequence[i]);
	}
	
	lcd_driver_reInit = false;

	LCD_EN_set_level(false);
	_delay_us(20);
	
	lcd_driver_set_data(LCD_CMD_SET_CGRAM_ADDRESS); //Set CGRAM address to 0 // is this necessary?  we are not programming the LCD characters.

	LCD_EN_set_level(false);
	_delay_us(20);
	
	LCD_RS_set_level(true);
	
	LCD_EN_set_level(false);
	_delay_ms(100);
}

static void lcd_driver_set_data(uint8_t data)
{
	// 4 bit mode
	LCD_dataport = ((data & 0xF0) | (LCD_dataport_in & 0x0F));
	_delay_us(20);
	LCD_EN_set_level(true);
	_delay_us(40);
	LCD_EN_set_level(false);
	_delay_us(80);
		
	LCD_dataport = (((data & 0x0F) << 4) | (LCD_dataport_in & 0x0F));
	_delay_us(20);
	LCD_EN_set_level(true);
	_delay_us(40);
	LCD_EN_set_level(false);
	_delay_us(40);
	
/*	
	// 4 bit mode
	LCD7_set_level((data&0x80)?true:false);
	LCD6_set_level((data&0x40)?true:false);
	LCD5_set_level((data&0x20)?true:false);
	LCD4_set_level((data&0x10)?true:false);
	lcd_driver_disp_clock();
	LCD7_set_level((data&0x08)?true:false);
	LCD6_set_level((data&0x04)?true:false);
	LCD5_set_level((data&0x02)?true:false);
	LCD4_set_level((data&0x01)?true:false);
*/
/*
	// 8 bit mode
	LCD7_set_level((data&0x80)?true:false);
	LCD6_set_level((data&0x40)?true:false);
	LCD5_set_level((data&0x20)?true:false);
	LCD4_set_level((data&0x10)?true:false);
	LCD3_set_level((data&0x8)?true:false);
	LCD2_set_level((data&0x4)?true:false);
	LCD1_set_level((data&0x2)?true:false);
	LCD0_set_level((data&0x1)?true:false);
*/
//	lcd_driver_disp_clock();
}

/*
static void lcd_driver_disp_clock(void)
{
	LCD_EN_set_level(true);
	_delay_us(40);
	LCD_EN_set_level(false);
	_delay_us(120);
}
*/

void lcd_driver_clear_display(void) {
	LCD_RS_set_level(false);
    lcd_driver_set_data(LCD_CMD_CLEAR_DISPLAY);
  	_delay_us(5);
	LCD_RS_set_level(true);
}

void LCD_write(uint8_t data) {
	LCD_dataport = ((data & 0xF0) | (LCD_dataport_in & 0x0F));
	_delay_us(20);
	LCD_EN_set_level(true);
	_delay_us(40);
	LCD_EN_set_level(false);
	_delay_us(80);
   
	LCD_dataport = (((data & 0x0F) << 4) | (LCD_dataport_in & 0x0F));
	_delay_us(20);
	LCD_EN_set_level(true);
	_delay_us(40);
	LCD_EN_set_level(false);
	_delay_us(40);
}

void LCD_write_datamode (uint8_t data) {
	LCD_RS_set_level(true);
	_delay_us(100);
	LCD_write(data);	//send data
}

void LCD_address_set(uint8_t add) {
	LCD_RS_set_level(false);
	_delay_us(100);
	LCD_write(add);													// Send address
	LCD_RS_set_level(true);
	_delay_us(40);
}

void LCD_string_write(uint8_t addr, uint8_t length, const char *data) {
	if (addr != 0) {
		LCD_RS_set_level(false);
		_delay_us(100);
		
		LCD_dataport = ((addr & 0xF0) | (LCD_dataport_in & 0x0F));
		_delay_us(20);
		
		LCD_EN_set_level(true);
		_delay_us(40);
		LCD_EN_set_level(false);
		_delay_us(80);
				
		LCD_dataport = (((addr & 0x0F) << 4) | (LCD_dataport_in & 0x0F));
		_delay_us(20);
		
		LCD_EN_set_level(true);
		_delay_us(40);
		LCD_EN_set_level(false);
		_delay_us(40);

		LCD_RS_set_level(true);
		_delay_us(20);
	}
	
	for (int i=0; i<length; i++) {
		LCD_RS_set_level(true);
		_delay_us(40);
				
		LCD_dataport = ((pgm_read_byte(&data[i]) & 0xF0) | (LCD_dataport_in & 0x0F));
		_delay_us(20);
		
		LCD_EN_set_level(true);
		_delay_us(40);
		LCD_EN_set_level(false);
		_delay_us(80);
		
		LCD_dataport = (((pgm_read_byte(&data[i]) & 0x0F) << 4) | (LCD_dataport_in & 0x0F));
		_delay_us(20);
		
		LCD_EN_set_level(true);
		_delay_us(40);
		LCD_EN_set_level(false);
		_delay_us(40);
	}
}

void LCD_ascii_write(uint8_t addr, uint8_t length, const char *data) {
	if (addr != 0) {
		LCD_RS_set_level(false);
		_delay_us(40);
		
		LCD_dataport = ((addr & 0xF0) | (LCD_dataport_in & 0x0F));
		_delay_us(20);
		LCD_EN_set_level(true);
		_delay_us(40);
		LCD_EN_set_level(false);
		_delay_us(80);
		
		LCD_dataport = (((addr & 0x0F) << 4) | (LCD_dataport_in & 0x0F));
		_delay_us(20);
		LCD_EN_set_level(true);
		_delay_us(40);
		LCD_EN_set_level(false);
		_delay_us(40);
	}
	LCD_RS_set_level(true);	
	_delay_us(100);
	for (int i=0; i<length; i++) {
		LCD_dataport = ((data[i] & 0xF0) | (LCD_dataport_in & 0x0F));
		_delay_us(20);
		LCD_EN_set_level(true);
		_delay_us(40);
		LCD_EN_set_level(false);
		_delay_us(80);
		
		LCD_dataport = (((data[i] & 0x0F) << 4) | (LCD_dataport_in & 0x0F));
		_delay_us(20);
		LCD_EN_set_level(true);
		_delay_us(40);
		LCD_EN_set_level(false);
		_delay_us(120);
	}
}

void LCD_show_arrow(uint8_t arrow_position) {					// Arrow position bit 4,3,2,1
	LCD_address_set(LCD_ARROW_ADDRESS);
	LCD_write(arrow_position);
	LCD_address_set(LCD_ARROW_ICON);
	LCD_write(0x00);
}

void LCD_backlight_on(void) {
	LCD_BL_set_level(true);
}

void LCD_backlight_off(void) {
	LCD_BL_set_level(false);
}

void LCD_temperature(uint8_t addr, uint8_t temp) {
	char BCD_buff[3];
	uint8_t temp_float=abs(temp);
	
	LCD_address_set(addr);
	
	if (temp != 0) BINtoBCD3((temp/2), BCD_buff);
	LCD_write(BCD_buff[0]);
	LCD_write(BCD_buff[1]);
	LCD_write(BCD_buff[2]);
	if (temp_float&0x01){ LCD_write('.'); LCD_write('5'); }
	else { LCD_write('.'); LCD_write('0'); }
	LCD_write('?');
}

char* BINtoBCD3(char data, char *bcd) {
	bcd[0]=0;
	bcd[1]=0;
	bcd[2]=0;

	while (data > 99) {               // Count hundreds
		bcd[0]++;
		data -= 100;
	}

	while (data > 9) {                // Count tens
		bcd[1]++;
		data -= 10;
	}
	bcd[2]=data;
	if (bcd[0]==0)bcd[0]=' ';
	else bcd[0]+=0x30;
	if ((bcd[1]==0)&&(bcd[0]==0)) bcd[1]=' ';
	else bcd[1]+=0x30;
	bcd[2]+=0x30;
	return  bcd;						// Add ones and return answer
}


uint8_t programmable_chars[] =
{
	// 0=unused for indicator arrows
	0x00,				//
	0x00,				//
	0x00,				//
	0x00,				//
	0x00,				//
	0x00,				//
	0x00,				//
	0x00,				//

	// 1=down
	0x00,				//
	0x00,				//
	0x00,				//
	0x00,				//
	0x00,				//
	0x11,				//#   #
	0x0A,				// # #
	0x04,				//  #

	// 2=half degree
	0x06,				//  #
	0x09,				// # #
	0x06,				//  #
	0x00,				//
	0x00,				//
	0x00,				//
	0x00,				//
	0x00,				//

	// 3=full degree
	0x06,				//  #
	0x0F,				// ###
	0x06,				//  #
	0x00,				//
	0x00,				//
	0x00,				//
	0x00,				//
	0x00,				//

	// 4=wifi 1/3
	0x00,				//
	0x00,				//
	0x00,				//
	0x00,				//
	0x00,				//
	0x04,				//  #
	0x00,				//
	0x00,				//

	// 5=wifi 2/3
	0x00,				//
	0x00,				//
	0x04,				//  #
	0x0a,				// # #
	0x00,				//
	0x04,				//  #
	0x00,				//
	0x00,				//

	// 6=wifi 3/3
	0x0E,				// ###
	0x11,				//#   #
	0x4,				//  #
	0x0a,				// # #
	0,					//
	0x04,				//  #
	0,
	0,

	// 7=unused
	0x00,				//
	0x00,				//
	0x1F,				//#####
	0x1F,				//#####
	0x1F,				//#####
	0x1F,				//#####
	0x1F,				//#####
	0x00,				//
};

#define PROGRAMMABLE_CHARS_SIZE (sizeof(programmable_chars)/sizeof(uint8_t))

void lcd_program_custom_characters(void)
{
	uint8_t startPos;
	//Set the DDRAM address.
	_delay_ms(10);

    startPos = LCD_CMD_SET_CGRAM_ADDRESS;

	LCD_RS_set_level(false);

    //Set the cursor position.
    lcd_driver_set_data(startPos);

	LCD_RS_set_level(true);
    for (int i = 0; i < PROGRAMMABLE_CHARS_SIZE; i++)
    {
        //Put the data onto the LCD.
        lcd_driver_set_data(programmable_chars[i]);
		_delay_us(5);
    }
}