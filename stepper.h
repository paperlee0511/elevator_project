#ifndef INC_STEPPER_H_
#define INC_STEPPER_H_

#include "main.h"
#include "i2c_lcd.h"
#include <stdbool.h> // 이거 버튼에도 있음 합치셈

extern volatile uint16_t remainingSteps;
extern volatile uint8_t motorDirection;
extern volatile bool motorRunning;
extern volatile uint8_t rxData;

#define STEPS_PER_REVOLUTION 		4096
#define DIR_CW 									0 			// 시계 방향
#define DIR_CCW 								1 			// 반시계 방향


#define IN1_pin 								GPIO_PIN_1
#define IN1_GPIO_Port 					GPIOB
#define IN2_pin 								GPIO_PIN_15
#define IN2_GPIO_Port 					GPIOB
#define IN3_pin 								GPIO_PIN_14
#define IN3_GPIO_Port 					GPIOB
#define IN4_pin 								GPIO_PIN_13
#define IN4_GPIO_Port 					GPIOB


static const uint8_t HALF_STEP_SEQ[8][4]=
		{
				{1, 0, 0, 0},
				{1, 1, 0, 0},
				{0, 1, 0, 0},
				{0, 1, 1, 0},
				{0, 0, 1, 0},
				{0, 0, 1, 1},
				{0, 0, 0, 1},
				{1, 0, 0, 1}
		};


void stepMotor(uint8_t step);
void rotateSteps(uint16_t steps, uint8_t direction);
void startMotor();
void rotateDegrees(uint16_t degrees, uint8_t direction);
void stopMotor();


#endif /* INC_STEPPER_H_ */
