
#ifndef INC_FND_H_
#define INC_FND_H_

#include "main.h"


#define FND_DATA_PIN	GPIO_PIN_3		// 데이터를 보낼 선
#define FND_DATA_PORT	GPIOB			// PB3
#define FND_SRCLK_PIN	GPIO_PIN_4		// 데이터 이동
#define FND_SRCLK_PORT  GPIOB			// PB4
#define FND_RCLK_PIN	GPIO_PIN_5		// 출력
#define FND_RCLK_PORT	GPIOB			// PB5


void FND_DisplayNumber(uint8_t num);	// FND에 출력될 함수
void shiftOut(uint8_t data);			// 데이터 시프트 함수






#endif /* INC_FND_H_ */
