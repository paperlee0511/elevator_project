#include "int.h"
#include "stepper.h"
#include  "button.h"
#include "servo.h"
#include "buzzer.h"

volatile uint8_t rxData = 1;
volatile bool stopDelay = false;
volatile uint8_t targetData = 1;

void floorCheck ()
{
	uint32_t currTime = HAL_GetTick ();
	static uint32_t prevTime = 0;

	if (HAL_GPIO_ReadPin (GPIOC, GPIO_PIN_1) == GPIO_PIN_SET)
	{
		if (prevTime == 0)
		{
			prevTime = currTime;
		}

		if ((currTime - prevTime) >= 50)
		{
			rxData = 1;
			prevTime = 0;
		}
	}

	if (HAL_GPIO_ReadPin (GPIOC, GPIO_PIN_2) == GPIO_PIN_SET)
	{
		if (prevTime == 0)
		{
			prevTime = currTime;
		}

		if ((currTime - prevTime) >= 50)
		{
			rxData = 2;
			prevTime = 0;
		}
	}

	if (HAL_GPIO_ReadPin (GPIOC, GPIO_PIN_3) == GPIO_PIN_SET)
	{
		if (prevTime == 0)
		{
			prevTime = currTime;
		}

		if ((currTime - prevTime) >= 50)
		{
			rxData = 3;
			prevTime = 0;
		}
	}
}

void intInit ()  //인터럽트 초기화(비활성화 상태)
{
	HAL_NVIC_DisableIRQ (EXTI1_IRQn);
	HAL_NVIC_DisableIRQ (EXTI2_IRQn);
	HAL_NVIC_DisableIRQ (EXTI3_IRQn);
}

void intOn () 		//인터럽트 모두 활성화
{
	HAL_NVIC_EnableIRQ (EXTI1_IRQn);
	HAL_NVIC_EnableIRQ (EXTI2_IRQn);
	HAL_NVIC_EnableIRQ (EXTI3_IRQn);
}

void enableInterrupt (uint16_t GPIO_PIN) //특정핀 켜기
{
	if (GPIO_PIN == GPIO_PIN_1)
	{
		HAL_NVIC_EnableIRQ (EXTI1_IRQn);
		targetData = 1;
	}
	else if (GPIO_PIN == GPIO_PIN_2)
	{
		HAL_NVIC_EnableIRQ (EXTI2_IRQn);
		targetData = 2;
	}
	else if (GPIO_PIN == GPIO_PIN_3)
	{
		HAL_NVIC_EnableIRQ (EXTI3_IRQn);
		targetData = 3;
	}
}

void disableInterrupt (uint16_t GPIO_PIN) //특정핀 끄기
{
	if (GPIO_PIN == GPIO_PIN_1)
	{
		HAL_NVIC_DisableIRQ (EXTI1_IRQn);
	}
	else if (GPIO_PIN == GPIO_PIN_2)
	{
		HAL_NVIC_DisableIRQ (EXTI2_IRQn);
	}
	else if (GPIO_PIN == GPIO_PIN_3)
	{
		HAL_NVIC_DisableIRQ (EXTI3_IRQn);
	}
}

void HAL_GPIO_EXTI_Callback (uint16_t GPIO_Pin) // 인터럽트 발생 시 동작
{
	if (GPIO_Pin == GPIO_PIN_1)
	{
		// PC1 인터럽트 처리
		stopMotor ();
		rxData = 1;
		stopDelay = true;
		buttonState[0] = false;
		buttonState[3] = false;
		disableInterrupt (GPIO_PIN_1);

	}
	else if (GPIO_Pin == GPIO_PIN_2)
	{
		// PC2 인터럽트 처리
		stopMotor ();
		rxData = 2;
		stopDelay = true;
		buttonState[1] = false;
		buttonState[4] = false;
		buttonState[5] = false;
		disableInterrupt (GPIO_PIN_2);

	}
	else if (GPIO_Pin == GPIO_PIN_3)
	{
		// PC3 인터럽트 처리
		stopMotor ();
		rxData = 3;
		stopDelay = true;
		buttonState[2] = false;
		buttonState[6] = false;
		disableInterrupt (GPIO_PIN_3);

	}
	// 인터럽트 플래그 클리어
	__HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_1);
}


