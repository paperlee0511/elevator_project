
#include "fnd.h"

//FND숫자 패턴 0 ~ 9
uint8_t fnd_number[10] =
{
		0xC0, // 0
		0xF9, // 1
		0xA4, // 2
		0xB0, // 3
		0x99, // 4
		0x92, // 5
		0x82, // 6
		0xF8, // 7
		0x80, // 8
		0x90  // 9
};

void FND_DisplayNumber(uint8_t num) //8-BIT SHIFT REGISTERS 연결 num값에 층수값(rxData)넣어 현재 층수 표현
{
	//HAL_GPIO_WritePin(GPIOx, GPIO_Pin, PinState)
	if(num>9) return ;	//	9이상의 값이 나오면 return

	HAL_GPIO_WritePin(FND_RCLK_PORT, FND_RCLK_PIN, GPIO_PIN_RESET);  // 래치 비활성화
	shiftOut(fnd_number[num]);  // 숫자 패턴 시프트레지스터에 출력	// 0~9까지의 정수만 들어갈수있음.
	HAL_GPIO_WritePin(FND_RCLK_PORT, FND_RCLK_PIN, GPIO_PIN_SET);    // 래치 활성화, FND에 출력
	// low -> data핀 설정 -> high

}
// 8-BIT SHIFT REGISTERS(SN74HC595)사용,
// SER데이터선, SRCLR -> Vcc에 연결
void shiftOut(uint8_t data) //3개의 핀 활용 FND값 시프트
{
	for (int i = 7; i >= 0; i--)	// MSB부터 가기때문에 7 에서 시작
	{
		HAL_GPIO_WritePin(FND_SRCLK_PORT, FND_SRCLK_PIN, GPIO_PIN_RESET);
		//시프트 클럭 LOW

		uint8_t bit = (data >> i) & 0x01; // 상위비트부터 추출
		HAL_GPIO_WritePin(FND_DATA_PORT, FND_DATA_PIN, bit ? GPIO_PIN_SET : GPIO_PIN_RESET);
		// 데이터 설정

		HAL_GPIO_WritePin(FND_SRCLK_PORT, FND_SRCLK_PIN, GPIO_PIN_SET);
		// 시프트 클럭 HIGH
	}
	// LSB부터 1비트씩 시프트 레지스터 전송, 각 비트마다, SRCLK LOW, DATA, SRCLK HIGH
	// 하위비부터 보내면 FND의 값이 깨져서 나옴 하위비트부터 보내려면 시프트레지스터의 Q7 -> FND의A 연결...
}

