// i2c_lcd.c
#include "i2c_lcd.h"

extern uint16_t current_step;	// 테스트용
extern uint16_t target_step3;	// 테스트용

static char line1[20];	//LCD 1행, 배열선언
static char line2[20];	//LCD 2행, 배열선언

typedef enum
{
	LCD_IDLE,	// 0
	LCD_CLEAR,	// 1
	LCD_LINE1,	// 2
	LCD_LINE2,	// 3
	LCD_DONE	// 4
} LcdState;		// 데이터타입 이름 정의

static LcdState lcdState = LCD_DONE;	// LcdState 데이터타입의 lcdState 변수명 선언 0으로 초기화
static uint32_t last_lcd_update = 0;	// hal_gettick용 변수 선언 및 초기화

// 아래 화살표 패턴
uint8_t arrow_down1[8] =
	{ 0b00100, 0b00100, 0b10101, 0b01110, 0b00100, 0b00000, 0b00000, 0b00000 };

uint8_t arrow_down2[8] =
	{ 0b00000, 0b00000, 0b00100, 0b00100, 0b10101, 0b01110, 0b00100, 0b00000 };

uint8_t arrow_down3[8] =
	{ 0b00000, 0b00000, 0b00000, 0b00000, 0b00100, 0b00100, 0b10101, 0b01110 };
// 위 화살표 패턴
uint8_t arrow_up1[8] =
	{ 0b00000, 0b00000, 0b00000, 0b00100, 0b01110, 0b10101, 0b00100, 0b00100 };

uint8_t arrow_up2[8] =
	{ 0b00000, 0b00100, 0b01110, 0b10101, 0b00100, 0b00100, 0b00000, 0b00000 };

uint8_t arrow_up3[8] =
	{ 0b01110, 0b10101, 0b00100, 0b00100, 0b00000, 0b00000, 0b00000, 0b00000 };
// 멈춤 표시 패턴
uint8_t arrow_stop[8] =
	{ 0b00000, 0b00000, 0b01110, 0b01110, 0b01110, 0b01110, 0b00000, 0b00000 };

// 4비트용 lcd 커맨드
void lcd_command (uint8_t command)
{
	uint8_t high_nibble = command & 0xF0;			// 상위비트 추출
	uint8_t low_nibble = (command << 4) & 0xF0;		// 하위비트 추출
	uint8_t i2c_buffer[4];

	i2c_buffer[0] = high_nibble | 0x0C;
	i2c_buffer[1] = high_nibble | 0x08;
	i2c_buffer[2] = low_nibble | 0x0C;
	i2c_buffer[3] = low_nibble | 0x08;

	HAL_I2C_Master_Transmit (&hi2c1, I2C_LCD_ADDRESS, i2c_buffer, 4, 100);
}

void lcd_data (uint8_t data)
{
	uint8_t high_nibble = data & 0xF0;
	uint8_t low_nibble = (data << 4) & 0xF0;
	uint8_t i2c_buffer[4];

	i2c_buffer[0] = high_nibble | 0x0D;
	i2c_buffer[1] = high_nibble | 0x09;
	i2c_buffer[2] = low_nibble | 0x0D;
	i2c_buffer[3] = low_nibble | 0x09;

	HAL_I2C_Master_Transmit (&hi2c1, I2C_LCD_ADDRESS, i2c_buffer, 4, 100);
}

void i2c_lcd_init (void)	// inint 구간에 넣어야함
{
	HAL_Delay (50);
	lcd_command (0x33);
	HAL_Delay (5);
	lcd_command (0x32);
	HAL_Delay (5);
	lcd_command (0x28);
	HAL_Delay (5);
	lcd_command (DISPLAY_ON);
	HAL_Delay (5);
	lcd_command (0x06);
	HAL_Delay (5);
	lcd_command (CLEAR_DISPLAY);
	HAL_Delay (2);

	lcd_create_custom_chars ();	// 커스텀한 캐릭터 init할떄 같이 넣어 활성화
}

void lcd_string (char *str)
{
	while (*str)
		lcd_data (*str++);
}

void move_cursor (uint8_t row, uint8_t col)
{
	lcd_command (0x80 | (row << 6) | col);
}

// 커스텀 픽셀 등록 lcd init에 넣을것
void lcd_create_custom_chars (void)
{
	lcd_command (0x40); // CGRAM 시작 주소
	// CGRAM주소 이후 lcd_data를 통해 데이터를쓰면 순차적으로 저장됨.
	for (int i = 0; i < 8; i++)
		lcd_data (arrow_down1[i]);  // 0번슬롯
	// 0x04 ~ 0x47
	for (int i = 0; i < 8; i++)
		lcd_data (arrow_down2[i]);  // 1번슬롯
	// 0x48 ~ 0x4F
	for (int i = 0; i < 8; i++)
		lcd_data (arrow_down3[i]);  // 2번슬롯
	// 0x50 ~ 0x57
	for (int i = 0; i < 8; i++)
		lcd_data (arrow_up1[i]);  // 3번슬롯
	// 0x58 ~ 0x5F
	for (int i = 0; i < 8; i++)
		lcd_data (arrow_up2[i]);  // 4번슬롯
	// 0x60 ~ 0x67
	for (int i = 0; i < 8; i++)
		lcd_data (arrow_up3[i]);  // 5번슬롯
	// 0x68 ~ 0x6F
	for (int i = 0; i < 8; i++)
		lcd_data (arrow_stop[i]); // 6번슬롯
	// 0x70 ~ 0x77
}

// 출력할 층 정보를 설정하는 함수
void lcd_set_floors (uint16_t now, uint16_t target_floor)
{
	static uint16_t prev_now_floor = 0xffff;
	static uint16_t prev_target_floor = 0xffff;
	// 정수를 문자열로 변환 후 line1에 저장
	if (now != prev_now_floor || target_floor != prev_target_floor)
	{
		sprintf (line1, "Now: %dFloor", now);
		// 정수를 문자열로 변환 후 line2에 저장
		sprintf (line2, "Target: %dFloor", target_floor);
		lcdState = LCD_IDLE;

		prev_now_floor = now;
		prev_target_floor = target_floor;
	}

}

// 비블로킹으로 LCD 업데이트하는 상태 머신
void lcd_update (void)
{
	if (HAL_GetTick () - last_lcd_update < 30)
		return;
	last_lcd_update = HAL_GetTick ();

	switch (lcdState)
	{
		case LCD_IDLE:

			lcdState = LCD_CLEAR;	// case LCD_CLEAR 실행 준비
			break;

		case LCD_CLEAR:
			move_cursor (0, 0);
			lcd_string ("            ");		// clear 대신 덮어씌우기
			move_cursor (1, 0);
			lcd_string ("              ");	// clear 대신 덮어씌우기
//        lcd_command(CLEAR_DISPLAY);
			lcdState = LCD_LINE1;	// CASE LCD_LINE1 실행 준비
			break;

		case LCD_LINE1:
			move_cursor (0, 0);		// 1행 1열, 문자열 출력
			lcd_string (line1);
			lcdState = LCD_LINE2;	// CASE LCD_LINE2 실행 준비
			break;

		case LCD_LINE2:
			move_cursor (1, 0);		// 2행 1열 문자열 출력
			lcd_string (line2);
			lcdState = LCD_DONE;	// LCD_DONE 실행 준비
			break;

		case LCD_DONE:				// statick lcdState = 0 으로 초기화
			break;
	}
}
// 위 화살표 함수, 덮어씌우는 방식	// 모터 시계방향 때 넣을것
void lcd_arrow_up (uint8_t row, uint8_t col)
{
	static uint8_t anim_state = 0;		// 현재 화살표 애니메이션 상태 저장
	static uint32_t last_anim_time = 0;	// hal_gettick용 변수

	if (HAL_GetTick () - last_anim_time < 400)
		return;  // 0.4초 딜레이
	last_anim_time = HAL_GetTick ();

	move_cursor (row, col);		// 매개변수로 커서 위치 조정
	lcd_data (3 + anim_state);   // 3 -> 4 -> 5 -> 3...
	// lcd_data(3), (4), (5)의 저장된 데이터
	// 3번부터 불러오기 위해 + 3 추가

	anim_state = (anim_state + 1) % 3;	// 애니메이션이 3, 4, 5 순서로 불러와져야함
	// static anim_state로 인해 불러올떄마다 값이 저장된채로 불러와짐,
	// (0+1) % 3 = 1, (1+1) % 3 = 2, (2+1) % 3 = 0,
}

// 아래 화살표 함수, 덮어씌우는 방식	// 모터 반시계 방향 때 넣을것
void lcd_arrow_down (uint8_t row, uint8_t col)
{
	static uint8_t anim_state = 0;
	static uint32_t last_anim_time = 0;

	if (HAL_GetTick () - last_anim_time < 400)
		return;  // 400ms 간격
	last_anim_time = HAL_GetTick ();

	move_cursor (row, col);	// 매개변수로 커서 위치 조정
	lcd_data (anim_state); 	// 0 -> 1 -> 2 -> 1 ...
	// lcd_data(0), (1), (2)의 저장된 데이터

	anim_state = (anim_state + 1) % 3;	// 애니메이션이 0, 1, 2 순서로 불러와져야함
	// static anim_state로 인해 불러올떄마다 값이 저장된채로 불러와짐,
	//(0+1) % 3 = 1, (1+1) % 3 = 2, (2+1) % 3 = 0,

}

// 정지 표시, 덮어씌우는 방식
void lcd_arrow_stop (uint8_t row, uint8_t col)
{
	move_cursor (row, col);	// 매개변수로 커서 위치 조정
	lcd_data (6);			// lcd_data(6)의 데이터 저장됨.
}

