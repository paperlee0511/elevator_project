
#ifndef INC_I2C_LCD_H_
#define INC_I2C_LCD_H_

#include "main.h"
#include "i2c.h"
#include "stdio.h"
#include "string.h"
#include "int.h"

#define TOTAL_STEPS 	12288

#define I2C_LCD_ADDRESS	(0x27 <<1 )
#define BACKLIGHT_ON	0x08


#define DISPLAY_ON		0x0C
#define DISPLAY_OFF		0x08
#define	CLEAR_DISPLAY	0x01	// 2ms delay 필요
#define RETURN_HOME		0x02

void lcd_command(uint8_t command);
void lcd_data(uint8_t data);
void i2c_lcd_init(void);
void lcd_string(char *str);
void move_cursor(uint8_t row, uint8_t col);
void lcd_set_floors(uint16_t now, uint16_t target);
void lcd_update();								// LCD정보 업데이트 함수 원형 선언
void lcd_create_custom_chars(void);				// 캐릭터 커스텀 함수 원형선언
void lcd_arrow_up(uint8_t row, uint8_t col);	//위 화살표 함수 원형선언
void lcd_arrow_down(uint8_t row, uint8_t col);	//아래 화살표 함수 원형선언
void lcd_arrow_stop(uint8_t row, uint8_t col);	// 네모 모먕 함수 원형선언



#endif /* INC_I2C_LCD_H_ */
