#include "button.h"

volatile uint8_t btnSet;

//버튼 7개 설정
BUTTON_CONTROL button[7] =
	{
		{ GPIOC, GPIO_PIN_8, 0 },
		{ GPIOC, GPIO_PIN_6, 0 },
		{ GPIOC, GPIO_PIN_5, 0 },
		{ GPIOA, GPIO_PIN_12, 0 },
		{ GPIOA, GPIO_PIN_11, 0 },
		{ GPIOB, GPIO_PIN_12, 0 },
		{ GPIOB, GPIO_PIN_2, 0 } };

bool buttonGetPressed (uint8_t num) //버튼입력확인
{
	bool ret = false;
	static uint32_t prevTime = 0;
	uint32_t currTime = HAL_GetTick ();

	if (HAL_GPIO_ReadPin (button[num].port, button[num].pinNumber)
			== button[num].onState)
	{
		if (currTime - prevTime > 50)
		{
			if (HAL_GPIO_ReadPin (button[num].port, button[num].pinNumber)
					== button[num].onState)
			{
				ret = true;
			}
			prevTime = currTime;
		}
	}
	return ret;
}

bool buttonState[7] =
	{ false, false, false, false, false, false, false }; //버튼 입력 저장할 배열

void scanButtons () //버튼입력시 배열에 저장
{
	if (buttonGetPressed (0))
		buttonState[0] = true;
	if (buttonGetPressed (1))
		buttonState[1] = true;
	if (buttonGetPressed (2))
		buttonState[2] = true;
	if (buttonGetPressed (3))
		buttonState[3] = true;
	if (buttonGetPressed (4))
		buttonState[4] = true;
	if (buttonGetPressed (5))
		buttonState[5] = true;
	if (buttonGetPressed (6))
		buttonState[6] = true;
	buttonSet ();
}

void buttonSet () 	//배열을 비트연산자로 변환
{
	btnSet = (buttonState[6] << 6) | (buttonState[5] << 5) | (buttonState[4] << 4)
			| (buttonState[3] << 3) | (buttonState[2] << 2) | (buttonState[1] << 1)
			| buttonState[0];
}



