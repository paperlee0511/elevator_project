#include "stepper.h"
#include "delay.h"
#include "ezmotor.h"
#include "buzzer.h"

//초기화 시켜줌
//인터럽트와 메인이 공유해야 하는 데이터기 때문에 volatile 타입 설정
//모터상태를 어디서든 접근하게 전역 선언
volatile uint16_t remainingSteps = 0;
volatile uint8_t motorDirection = DIR_CW;
volatile bool motorRunning = false;

void stepMotor (uint8_t step)
{
	HAL_GPIO_WritePin (IN1_GPIO_Port, IN1_pin, HALF_STEP_SEQ[step][0]);
	HAL_GPIO_WritePin (IN2_GPIO_Port, IN2_pin, HALF_STEP_SEQ[step][1]);
	HAL_GPIO_WritePin (IN3_GPIO_Port, IN3_pin, HALF_STEP_SEQ[step][2]);
	HAL_GPIO_WritePin (IN4_GPIO_Port, IN4_pin, HALF_STEP_SEQ[step][3]);
}

void rotateSteps (uint16_t steps, uint8_t direction) // 호출된 값 저장, 현재 모터 상태
{
	remainingSteps = steps; 			//남은 스텝
	motorDirection = direction;	//진행방향
	motorRunning = true; 			//이동 중 인지
	ezmotor_on ();
}

void startMotor () //호출하면 저장된 모터값에 따라 동작
{
	static uint16_t currentStep = 0;
	static uint32_t prevTime = 0;
	uint32_t currTime = HAL_GetTick ();

	if (motorRunning == false)
	{
		ezmotor_off ();
		return;
	}

	if ((currTime - prevTime) >= 1 && remainingSteps > 0)
	{
		prevTime = currTime;

		uint8_t step;
		if (motorDirection == DIR_CW)
		{
			step = currentStep % 8;
			lcd_arrow_up (0, 14);
		}
		else
		{
			step = 7 - (currentStep % 8);
			lcd_arrow_down (0, 14);
		}

		stepMotor (step);
		currentStep++;
		remainingSteps--;

		if (remainingSteps == 0)
		{
			motorRunning = false;

		}
	}
}

void rotateDegrees (uint16_t degrees, uint8_t direction) // 호출하면 rotateSteps 여기에 저장함
{
	//각도에 해당하는 스텝 수 계산
	uint16_t steps =
			(uint16_t) (((uint32_t) degrees * STEPS_PER_REVOLUTION) / 360);

	rotateSteps (steps, direction);
}

void stopMotor () // 모터 멈춤
{
	HAL_GPIO_WritePin (IN1_GPIO_Port, IN1_pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin (IN2_GPIO_Port, IN2_pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin (IN3_GPIO_Port, IN3_pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin (IN4_GPIO_Port, IN4_pin, GPIO_PIN_RESET);
	motorRunning = false;
	lcd_arrow_stop (0, 14);
	lcd_set_floors (rxData, targetData);
}














