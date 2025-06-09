#include "buzzer.h"
#include "delay.h"


// 전역 변수
BuzzerState buzzer_state = BUZZER_IDLE;
uint32_t buzzer_timer = 0;
uint8_t song_index = 0;

uint16_t song[5] = {Do, Mi, Do1, mute,mute};

void buzzer_update () //song배열의 0,1,2 순서 500ms 출력 500ms off 1사이클
{
	switch (buzzer_state)
	{
		case BUZZER_IDLE:
			song_index = 0;
			TIM4->PSC = song[song_index];
			TIM4->CCR1 = 600;  // PWM 듀티비 설정
			buzzer_timer = HAL_GetTick ();
			buzzer_state = BUZZER_PLAYING;
			break;

		case BUZZER_PLAYING:
			// 500ms 지나면 소리 끔 → REST 상태로
			if (HAL_GetTick () - buzzer_timer >= 500)
			{
				TIM4->CCR1 = 0;  // PWM OFF
				TIM4->PSC = song[song_index];
				buzzer_timer = HAL_GetTick ();
				buzzer_state = BUZZER_REST;
			}
			break;

		case BUZZER_REST:
			// 500ms 쉬고 다음 음 실행
			if (HAL_GetTick () - buzzer_timer >= 500)
			{
				song_index++;
				if (song_index < 3)
				{
					// 다음 음 시작: 상태 바꾸고 소리 다시 켬
					TIM4->PSC = song[song_index];
					TIM4->CCR1 = 500;
					buzzer_timer = HAL_GetTick ();
					buzzer_state = BUZZER_PLAYING;
				}
				else
				{
					TIM4->CCR1 = 0;  // PWM OFF
					TIM4->PSC = song[song_index];
					break;
				}
			}
			break;
	}
}


void buzzer_off()
{
	TIM4->CCR1 = 0;
	TIM4->PSC = 0;
	buzzer_state = BUZZER_IDLE;
}



