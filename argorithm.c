#include "argorithm.h"
#include "button.h"
#include "stepper.h"

void argorithm()
{
	// 내부 1 버튼(승강기 내부 1층버튼)
	if (btnSet == 0b00000001)
	{
		if (motorRunning == false)
		{
			rotateDegrees (5000, DIR_CCW);
			enableInterrupt (GPIO_PIN_1);
		}
	}
	buttonSet();

	// 내부 2 버튼(승강기 내부 2층버튼)
	if (btnSet == 0b00000010)
	{
		if(motorRunning == false && rxData == 1)
		{
			rotateDegrees (5000, DIR_CW);
			enableInterrupt (GPIO_PIN_2);
		}
		if(motorRunning == false && rxData == 2)
		{
			enableInterrupt (GPIO_PIN_2);
		}
		if(motorRunning == false && rxData == 3)
		{
			rotateDegrees (5000, DIR_CCW);
			enableInterrupt (GPIO_PIN_2);
		}
	}
	buttonSet();

	// 내부 3 버튼(승강기 내부 3층버튼)
	if (btnSet == 0b00000100)
	{
		if (motorRunning == false && rxData == 1)
		{
			rotateDegrees (5000, DIR_CW);
			enableInterrupt (GPIO_PIN_3);
		}
		if (motorRunning == false && rxData == 2)
		{
			rotateDegrees (5000, DIR_CW);
			enableInterrupt (GPIO_PIN_3);
		}
		if (motorRunning == false && rxData == 3)
		{
			enableInterrupt (GPIO_PIN_3);
		}
	}
	buttonSet();

	// 1층 업 버튼(1층에 있는 ↑버튼)
	if (btnSet == 0b00001000)
	{
		if (motorRunning == false)
		{
			rotateDegrees (5000, DIR_CCW);
			enableInterrupt (GPIO_PIN_1);
		}
	}
	buttonSet();

	// 2층 업 버튼(2층에 있는 ↑버튼)
	if (btnSet == 0b00010000)
	{
		if (motorRunning == false && rxData == 1)
		{
			rotateDegrees (5000, DIR_CW);
			enableInterrupt (GPIO_PIN_2);
		}
		if (motorRunning == false && rxData == 2)
		{
			enableInterrupt (GPIO_PIN_2);
		}
		if (motorRunning == false && rxData == 3)
		{
			rotateDegrees (5000, DIR_CCW);
			enableInterrupt (GPIO_PIN_2);
		}
	}
	buttonSet();

	// 2층 다운 버튼(2층에 있는 ↓버튼)
	if (btnSet == 0b00100000)
	{
		if (motorRunning == false && rxData == 1)
		{
			rotateDegrees (5000, DIR_CW);
			enableInterrupt (GPIO_PIN_2);
		}
		if (motorRunning == false && rxData == 2)
		{
			enableInterrupt (GPIO_PIN_2);
		}
		if (motorRunning == false && rxData == 3)
		{
			rotateDegrees (5000, DIR_CCW);
			enableInterrupt (GPIO_PIN_2);
		}
	}
	buttonSet();

	// 3층 다운 버튼(3층에 있는 ↓버튼)
	if (btnSet == 0b01000000)
	{
		if (motorRunning == false)
		{
			rotateDegrees (5000, DIR_CW);
			enableInterrupt (GPIO_PIN_3);
		}
	}
	buttonSet();








	// 2중첩 버튼 조합 (21개)

	// 내부 1 + 내부 2 버튼
	if (btnSet == 0b00000011)
	{
		if (rxData == 1 && motorRunning == false)
		{
			enableInterrupt (GPIO_PIN_1);
		}
		if(rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
		{
			enableInterrupt (GPIO_PIN_2);
		}
		if(rxData == 2 && motorRunning == false)
		{
			enableInterrupt (GPIO_PIN_2);
		}
		if(rxData == 2 && motorRunning == true && motorDirection == DIR_CCW)
		{
			enableInterrupt (GPIO_PIN_1);
		}
		if(rxData == 3 && motorRunning == false)
		{
			rotateDegrees (5000, DIR_CCW);
			enableInterrupt (GPIO_PIN_2);
		}
		if(rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
		{
			enableInterrupt (GPIO_PIN_2);
		}
	}
	buttonSet();

  // 내부 1 + 내부 3 버튼
  if (btnSet == 0b00000101)
  {
  	if(rxData == 1 && motorRunning == false)
  	{
  		enableInterrupt(GPIO_PIN_1);
  	}
  	if(rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
  	{
  		enableInterrupt(GPIO_PIN_3);
  	}
  	if(rxData == 2 && motorRunning == false)
  	{
  		rotateDegrees (5000, DIR_CCW);
  		enableInterrupt(GPIO_PIN_1);
  	}
  	if(rxData == 2 && motorRunning == true && motorDirection == DIR_CW)
  	{
  		enableInterrupt(GPIO_PIN_3);
  	}
		if(rxData == 2 && motorRunning == true && motorDirection == DIR_CCW)
		{
			enableInterrupt(GPIO_PIN_1);
		}
		if(rxData == 3 && motorRunning == false)
		{
			enableInterrupt(GPIO_PIN_3);
		}
		if(rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
		{
			enableInterrupt(GPIO_PIN_1);
		}
  }
  buttonSet();

	// 내부 1 + 1층 업 버튼
	if (btnSet == 0b00001001)
	{
		rotateDegrees(5000, DIR_CCW);
		enableInterrupt(GPIO_PIN_1);
	}
	buttonSet();

	// 내부 1 + 2층 업 버튼
	if (btnSet == 0b00010001)
	{
		if (rxData == 1 && motorRunning == false)
		{
			enableInterrupt(GPIO_PIN_1);
		}
		if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
		{
			enableInterrupt(GPIO_PIN_2);
		}
		if (rxData == 2 && motorRunning == false)
		{
			enableInterrupt(GPIO_PIN_2);
		}
		if (rxData == 2 && motorRunning == true && motorDirection == DIR_CCW)
		{
			enableInterrupt(GPIO_PIN_1);
		}
		if (rxData == 3 && motorRunning == false)
		{
			rotateDegrees (5000, DIR_CCW);
			enableInterrupt(GPIO_PIN_2);
		}
		if (rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
		{
			enableInterrupt(GPIO_PIN_2);
		}
	}
	buttonSet();

	// 내부 1 + 2층 다운 버튼
	if (btnSet == 0b00100001)
	{
		if (rxData == 1 && motorRunning == false)
		{
			enableInterrupt(GPIO_PIN_1);
		}
		if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
		{
			enableInterrupt(GPIO_PIN_2);
		}
		if (rxData == 2 && motorRunning == false)
		{
			enableInterrupt(GPIO_PIN_2);
		}
		if (rxData == 2 && motorRunning == true && motorDirection == DIR_CCW)
		{
			enableInterrupt(GPIO_PIN_1);
		}
		if (rxData == 3 && motorRunning == false)
		{
			rotateDegrees (5000, DIR_CCW);
			enableInterrupt(GPIO_PIN_2);
		}
		if (rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
		{
			enableInterrupt(GPIO_PIN_2);
		}
	}
	buttonSet();

	// 내부 1 + 3층 다운 버튼
	if (btnSet == 0b01000001)
	{
		if (rxData == 1 && motorRunning == false)
		{
			enableInterrupt(GPIO_PIN_1);
		}
		if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
		{
			enableInterrupt(GPIO_PIN_3);
		}
		if (rxData == 2 && motorRunning == false)
		{
			rotateDegrees (5000, DIR_CCW);
			enableInterrupt(GPIO_PIN_1);
		}
		if (rxData == 2 && motorRunning == true && motorDirection == DIR_CW)
		{
			enableInterrupt(GPIO_PIN_3);
		}
		if (rxData == 2 && motorRunning == true && motorDirection == DIR_CCW)
		{
			enableInterrupt(GPIO_PIN_1);
		}
		if (rxData == 3 && motorRunning == false)
		{
			enableInterrupt(GPIO_PIN_3);
		}
		if (rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
		{
			enableInterrupt(GPIO_PIN_1);
		}
	}
	buttonSet();

	// 내부 2 + 내부 3 버튼
	if (btnSet == 0b00000110)
	{
		if (rxData == 1 && motorRunning == false)
		{
			rotateDegrees (5000, DIR_CW);
			enableInterrupt(GPIO_PIN_2);
		}
		if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
		{
			enableInterrupt(GPIO_PIN_2);
		}
		if (rxData == 2 && motorRunning == false)
		{
			enableInterrupt(GPIO_PIN_2);
		}
		if (rxData == 2 && motorRunning == true && motorDirection == DIR_CW)
		{
			enableInterrupt(GPIO_PIN_3);
		}
		if (rxData == 3 && motorRunning == false)
		{
			enableInterrupt(GPIO_PIN_3);
		}
		if (rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
		{
			enableInterrupt(GPIO_PIN_2);
		}
	}
	buttonSet();

	// 내부 2 + 1층 업 버튼
	if (btnSet == 0b00001010)
	{
		if (rxData == 1 && motorRunning == false)
		{
			enableInterrupt(GPIO_PIN_1);
		}
		if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
		{
			enableInterrupt(GPIO_PIN_2);
		}
		if (rxData == 2 && motorRunning == false)
		{
			enableInterrupt(GPIO_PIN_2);
		}
		if (rxData == 2 && motorRunning == true && motorDirection == DIR_CCW)
		{
			enableInterrupt(GPIO_PIN_1);
		}
		if (rxData == 3 && motorRunning == false)
		{
			rotateDegrees (5000, DIR_CCW);
			enableInterrupt(GPIO_PIN_2);
		}
		if (rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
		{
			enableInterrupt(GPIO_PIN_2);
		}
	}
	buttonSet();

	// 내부 2 + 2층 업 버튼
	if (btnSet == 0b00010010)
	{
		if (rxData == 1 && motorRunning == false)
		{
			rotateDegrees (5000, DIR_CW);
			enableInterrupt(GPIO_PIN_2);
		}
		if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
		{
			enableInterrupt(GPIO_PIN_2);
		}
		if (rxData == 2 && motorRunning == false)
		{
			enableInterrupt(GPIO_PIN_2);
		}
		if (rxData == 3 && motorRunning == false)
		{
			rotateDegrees (5000, DIR_CCW);
			enableInterrupt(GPIO_PIN_2);
		}
		if (rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
		{
			enableInterrupt(GPIO_PIN_2);
		}
	}
	buttonSet();

	// 내부 2 + 2층 다운 버튼
	if (btnSet == 0b00100010)
	{
		if (rxData == 1 && motorRunning == false)
		{
			rotateDegrees (5000, DIR_CW);
			enableInterrupt (GPIO_PIN_2);
		}
		if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
		{
			enableInterrupt (GPIO_PIN_2);
		}
		if (rxData == 2 && motorRunning == false)
		{
			enableInterrupt (GPIO_PIN_2);
		}
		if (rxData == 3 && motorRunning == false)
		{
			rotateDegrees (5000, DIR_CCW);
			enableInterrupt (GPIO_PIN_2);
		}
		if (rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
		{
			enableInterrupt (GPIO_PIN_2);
		}
	}
	buttonSet();

	// 내부 2 + 3층 다운 버튼
	if (btnSet == 0b01000010)
	{
		if (rxData == 1 && motorRunning == false)
		{
			rotateDegrees (5000, DIR_CW);
			enableInterrupt (GPIO_PIN_2);
		}
		if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
		{
			enableInterrupt (GPIO_PIN_2);
		}
		if (rxData == 2 && motorRunning == false)
		{
			enableInterrupt (GPIO_PIN_2);
		}
		if (rxData == 2 && motorRunning == true && motorDirection == DIR_CW)
		{
			enableInterrupt (GPIO_PIN_3);
		}
		if (rxData == 3 && motorRunning == false)
		{
			enableInterrupt (GPIO_PIN_3);
		}
		if (rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
		{
			enableInterrupt (GPIO_PIN_2);
		}
	}

	// 내부 3 + 1층 업 버튼
	if (btnSet == 0b00001100)
	{
		if (rxData == 1 && motorRunning == false)
		{
			enableInterrupt (GPIO_PIN_1);
		}
		if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
		{
			enableInterrupt (GPIO_PIN_3);
		}
		if (rxData == 2 && motorRunning == false)
		{
			rotateDegrees (5000, DIR_CW);
			enableInterrupt (GPIO_PIN_3);
		}
		if (rxData == 2 && motorRunning == true && motorDirection == DIR_CW)
		{
			enableInterrupt (GPIO_PIN_3);
		}
		if (rxData == 2 && motorRunning == true && motorDirection == DIR_CCW)
		{
			enableInterrupt (GPIO_PIN_1);
		}
		if (rxData == 3 && motorRunning == false)
		{
			enableInterrupt (GPIO_PIN_3);
		}
		if (rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
		{
			enableInterrupt (GPIO_PIN_1);
		}
	}
	buttonSet();

	// 내부 3 + 2층 업 버튼
	if (btnSet == 0b00010100)
	{
		if (rxData == 1 && motorRunning == false)
		{
			rotateDegrees (5000, DIR_CW);
			enableInterrupt (GPIO_PIN_2);
		}
		if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
		{
			enableInterrupt (GPIO_PIN_2);
		}
		if (rxData == 2 && motorRunning == false)
		{
			enableInterrupt (GPIO_PIN_2);
		}
		if (rxData == 2 && motorRunning == true && motorDirection == DIR_CW)
		{
			enableInterrupt (GPIO_PIN_3);
		}
		if (rxData == 3 && motorRunning == false)
		{
			enableInterrupt (GPIO_PIN_3);
		}
		if (rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
		{
			enableInterrupt (GPIO_PIN_2);
		}
	}
	buttonSet();

	// 내부 3 + 2층 다운 버튼
	if (btnSet == 0b00100100)
	{
		if (rxData == 1 && motorRunning == false)
		{
			rotateDegrees (5000, DIR_CW);
			enableInterrupt (GPIO_PIN_2);
		}
		if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
		{
			enableInterrupt (GPIO_PIN_2);
		}
		if (rxData == 2 && motorRunning == false)
		{
			enableInterrupt (GPIO_PIN_2);
		}
		if (rxData == 2 && motorRunning == true && motorDirection == DIR_CW)
		{
			enableInterrupt (GPIO_PIN_3);
		}
		if (rxData == 3 && motorRunning == false)
		{
			enableInterrupt (GPIO_PIN_3);
		}
		if (rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
		{
			enableInterrupt (GPIO_PIN_2);
		}
	}
	buttonSet();

	// 내부 3 + 3층 다운 버튼
	if (btnSet == 0b01000100)
	{
		if (rxData == 1 && motorRunning == false)
		{
			rotateDegrees (5000, DIR_CW);
			enableInterrupt (GPIO_PIN_3);
		}
		if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
		{
			enableInterrupt (GPIO_PIN_3);
		}
		if (rxData == 2 && motorRunning == false)
		{
			rotateDegrees (5000, DIR_CW);
			enableInterrupt (GPIO_PIN_3);
		}
		if (rxData == 2 && motorRunning == true && motorDirection == DIR_CW)
		{
			enableInterrupt (GPIO_PIN_3);
		}
		if (rxData == 3 && motorRunning == false)
		{
			enableInterrupt (GPIO_PIN_3);
		}
	}
	buttonSet();

	// 1층 업 + 2층 업 버튼
	if (btnSet == 0b00011000)
	{
		if (rxData == 1 && motorRunning == false)
		{
			enableInterrupt (GPIO_PIN_1);
		}
		if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
		{
			enableInterrupt (GPIO_PIN_2);
		}
		if (rxData == 2 && motorRunning == false)
		{
			enableInterrupt (GPIO_PIN_2);
		}
		if (rxData == 2 && motorRunning == true && motorDirection == DIR_CCW)
		{
			enableInterrupt (GPIO_PIN_1);
		}
		if (rxData == 3 && motorRunning == false)
		{
			rotateDegrees (5000, DIR_CCW);
			enableInterrupt (GPIO_PIN_2);
		}
		if (rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
		{
			enableInterrupt (GPIO_PIN_2);
		}
	}
	buttonSet();

	// 1층 업 + 2층 다운 버튼
	if (btnSet == 0b00101000)
	{
		if (rxData == 1 && motorRunning == false)
		{
			enableInterrupt (GPIO_PIN_1);
		}
		if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
		{
			enableInterrupt (GPIO_PIN_2);
		}
		if (rxData == 2 && motorRunning == false)
		{
			enableInterrupt (GPIO_PIN_2);
		}
		if (rxData == 2 && motorRunning == true && motorDirection == DIR_CCW)
		{
			enableInterrupt (GPIO_PIN_1);
		}
		if (rxData == 3 && motorRunning == false)
		{
			rotateDegrees (5000, DIR_CCW);
			enableInterrupt (GPIO_PIN_2);
		}
		if (rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
		{
			enableInterrupt (GPIO_PIN_2);
		}
	}
	buttonSet();

	// 2층 업 + 3층 다운 버튼
	if (btnSet == 0b01010000)
	{
		if (rxData == 1 && motorRunning == false)
		{
			rotateDegrees (5000, DIR_CW);
			enableInterrupt (GPIO_PIN_2);
		}
		if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
		{
			enableInterrupt (GPIO_PIN_2);
		}
		if (rxData == 2 && motorRunning == false)
		{
			enableInterrupt (GPIO_PIN_2);
		}
		if (rxData == 2 && motorRunning == true && motorDirection == DIR_CW)
		{
			enableInterrupt (GPIO_PIN_3);
		}
		if (rxData == 3 && motorRunning == false)
		{
			enableInterrupt (GPIO_PIN_3);
		}
		if (rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
		{
			enableInterrupt (GPIO_PIN_2);
		}
	}
	buttonSet();

	// 2층 다운 + 3층 다운 버튼
	if (btnSet == 0b01100000)
	{
		if (rxData == 1 && motorRunning == false)
		{
			rotateDegrees (5000, DIR_CW);
			enableInterrupt (GPIO_PIN_2);
		}
		if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
		{
			enableInterrupt (GPIO_PIN_2);
		}
		if (rxData == 2 && motorRunning == false)
		{
			enableInterrupt (GPIO_PIN_2);
		}
		if (rxData == 2 && motorRunning == true && motorDirection == DIR_CW)
		{
			enableInterrupt (GPIO_PIN_3);
		}
		if (rxData == 3 && motorRunning == false)
		{
			enableInterrupt (GPIO_PIN_3);
		}
		if (rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
		{
			enableInterrupt (GPIO_PIN_2);
		}
	}
	buttonSet();

	// 1층 업 + 3층 다운 버튼
	if (btnSet == 0b01001000)
	{
		if (rxData == 1 && motorRunning == false)
		{
			enableInterrupt (GPIO_PIN_1);
		}
		if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
		{
			enableInterrupt (GPIO_PIN_3);
		}
		if (rxData == 2 && motorRunning == false)
		{
			rotateDegrees (5000, DIR_CW);
			enableInterrupt (GPIO_PIN_3);
		}
		if (rxData == 2 && motorRunning == true && motorDirection == DIR_CW)
		{
			enableInterrupt (GPIO_PIN_3);
		}
		if (rxData == 2 && motorRunning == true && motorDirection == DIR_CCW)
		{
			enableInterrupt (GPIO_PIN_1);
		}
		if (rxData == 3 && motorRunning == false)
		{
			enableInterrupt (GPIO_PIN_3);
		}
		if (rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
		{
			enableInterrupt (GPIO_PIN_1);
		}
	}
	buttonSet();

	// 2층 업 + 2층 다운 버튼
	if (btnSet == 0b00110000)
	{
		if (rxData == 1 && motorRunning == false)
		{
			rotateDegrees (5000, DIR_CW);
			enableInterrupt (GPIO_PIN_2);
		}
		if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
		{
			enableInterrupt (GPIO_PIN_2);
		}
		if (rxData == 2 && motorRunning == false)
		{
			enableInterrupt (GPIO_PIN_2);
		}
		if (rxData == 3 && motorRunning == false)
		{
			rotateDegrees (5000, DIR_CCW);
			enableInterrupt (GPIO_PIN_2);
		}
		if (rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
		{
			enableInterrupt (GPIO_PIN_2);
		}
	}
	buttonSet();




	//		// 3중첩 버튼 조합 (35개)
	//		// 내부 1 + 내부 2 + 내부 3 버튼
	//		if (btnSet == 0b00000111)
	//		{
	//			if (rxData == 1 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//		}
	//
	//		// 내부 1 + 내부 2 + 1층 업 버튼
	//		if (btnSet == 0b00001011)
	//		{
	//			if (rxData == 1 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//		}
	//
	//		// 내부 1 + 내부 2 + 2층 업 버튼
	//		if (btnSet == 0b00010011)
	//		{
	//			if (rxData == 1 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//		}
	//
	//		// 내부 1 + 내부 2 + 2층 다운 버튼
	//		if (btnSet == 0b00100011)
	//		{
	//			if (rxData == 1 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//		}
	//
	//		// 내부 1 + 내부 2 + 3층 다운 버튼
	//		if (btnSet == 0b01000011)
	//		{
	//			if (rxData == 1 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//		}
	//
	//		// 내부 1 + 내부 3 + 1층 업 버튼
	//		if (btnSet == 0b00001101)
	//		{
	//			if (rxData == 1 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//		}
	//
	//		// 내부 1 + 내부 3 + 2층 업 버튼
	//		if (btnSet == 0b00010101)
	//		{
	//			if (rxData == 1 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//		}
	//
	//		// 내부 1 + 내부 3 + 2층 다운 버튼
	//		if (btnSet == 0b00100101)
	//		{
	//			if (rxData == 1 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//		}
	//
	//		// 내부 1 + 내부 3 + 3층 다운 버튼
	//		if (btnSet == 0b01000101)
	//		{
	//			if (rxData == 1 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//		}
	//
	//		// 내부 1 + 1층 업 + 2층 업 버튼
	//		if (btnSet == 0b00011001)
	//		{
	//			if (rxData == 1 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//		}
	//
	//		// 내부 1 + 1층 업 + 2층 다운 버튼
	//		if (btnSet == 0b00101001)
	//		{
	//			if (rxData == 1 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//		}
	//
	//		// 내부 1 + 1층 업 + 3층 다운 버튼
	//		if (btnSet == 0b01001001)
	//		{
	//			if (rxData == 1 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//		}
	//
	//		// 내부 1 + 2층 업 + 2층 다운 버튼
	//		if (btnSet == 0b00110001)
	//		{
	//			if (rxData == 1 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//		}
	//
	//		// 내부 1 + 2층 업 + 3층 다운 버튼
	//		if (btnSet == 0b01010001)
	//		{
	//			if (rxData == 1 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//		}
	//
	//		// 내부 1 + 2층 다운 + 3층 다운 버튼
	//		if (btnSet == 0b01100001)
	//		{
	//			if (rxData == 1 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//		}
	//
	//		// 내부 2 + 내부 3 + 1층 업 버튼
	//		if (btnSet == 0b00001110)
	//		{
	//			if (rxData == 1 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//		}
	//
	//		// 내부 2 + 내부 3 + 2층 업 버튼
	//		if (btnSet == 0b00010110)
	//		{
	//			if (rxData == 1 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//		}
	//
	//		// 내부 2 + 내부 3 + 2층 다운 버튼
	//		if (btnSet == 0b00100110)
	//		{
	//			if (rxData == 1 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//		}
	//
	//		// 내부 2 + 내부 3 + 3층 다운 버튼
	//		if (btnSet == 0b01000110)
	//		{
	//			if (rxData == 1 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//		}
	//
	//		// 내부 2 + 1층 업 + 2층 업 버튼
	//		if (btnSet == 0b00011010)
	//		{
	//			if (rxData == 1 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//		}
	//
	//		// 내부 2 + 1층 업 + 2층 다운 버튼
	//		if (btnSet == 0b00101010)
	//		{
	//			if (rxData == 1 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//		}
	//
	//		// 내부 2 + 1층 업 + 3층 다운 버튼
	//		if (btnSet == 0b01001010)
	//		{
	//			if (rxData == 1 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//		}
	//
	//		// 내부 2 + 2층 업 + 3층 다운 버튼
	//		if (btnSet == 0b01010010)
	//		{
	//			if (rxData == 1 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//		}
	//
	//		// 내부 2 + 2층 업 + 2층 다운 버튼
	//		if (btnSet == 0b00110010)
	//		{
	//			if (rxData == 1 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//		}
	//
	//		// 내부 3 + 2층 업 + 2층 다운 버튼
	//		if (btnSet == 0b00110100)
	//		{
	//			if (rxData == 1 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//		}
	//
	//		// 내부 3 + 1층 업 + 2층 업 버튼
	//		if (btnSet == 0b00011100)
	//		{
	//			if (rxData == 1 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//		}
	//
	//		// 내부 3 + 1층 업 + 2층 다운 버튼
	//		if (btnSet == 0b00101100)
	//		{
	//			if (rxData == 1 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//		}
	//
	//		// 내부 3 + 1층 업 + 3층 다운 버튼
	//		if (btnSet == 0b01001100)
	//		{
	//			if (rxData == 1 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//		}
	//
	//		// 내부 3 + 2층 업 + 3층 다운 버튼
	//		if (btnSet == 0b01010100)
	//		{
	//			if (rxData == 1 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//		}
	//
	//		// 1층 업 + 2층 업 + 3층 다운 버튼
	//		if (btnSet == 0b01011000)
	//		{
	//			if (rxData == 1 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//		}
	//
	//		// 1층 업 + 2층 다운 + 3층 다운 버튼
	//		if (btnSet == 0b01101000)
	//		{
	//			if (rxData == 1 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//		}
	//
	//		// 2층 업 + 2층 다운 + 3층 다운 버튼
	//		if (btnSet == 0b01110000)
	//		{
	//			if (rxData == 1 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//		}
	//
	//		// 내부 2 + 2층 다운 + 3층 다운 버튼
	//		if (btnSet == 0b01100010)
	//		{
	//			if (rxData == 1 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//		}
	//
	//		// 내부 3 + 2층 다운 + 3층 다운 버튼
	//		if (btnSet == 0b01100100)
	//		{
	//			if (rxData == 1 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//		}
	//
	//		// 1층 업 + 2층 업 + 2층 다운 버튼
	//		if (btnSet == 0b00111000)
	//		{
	//			if (rxData == 1 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 1 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CW)
	//			{
	//
	//			}
	//			if (rxData == 2 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == false)
	//			{
	//
	//			}
	//			if (rxData == 3 && motorRunning == true && motorDirection == DIR_CCW)
	//			{
	//
	//			}
	//		}
}
