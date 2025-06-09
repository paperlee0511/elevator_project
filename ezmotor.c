#include "ezmotor.h"

void ezmotor_on() //환풍기 모터 온
{
	TIM2->CCR1 = 70;
}


void ezmotor_off()//환풍기 모터 오프
{
	TIM2->CCR1 = 0;
}
