/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "i2c.h"
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "button.h"
#include "stepper.h"
#include "delay.h"
#include "int.h"
#include "stdio.h"
#include "string.h"
#include "i2c_lcd.h"
#include "fnd.h"
#include "servo.h"
#include "ezmotor.h"
#include "buzzer.h"
#include "argorithm.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
//  volatile uint8_t rxDataaa = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM11_Init();
  MX_TIM3_Init();
  MX_I2C1_Init();
  MX_TIM2_Init();
  MX_TIM4_Init();
  /* USER CODE BEGIN 2 */

	disableInterrupt (GPIO_PIN_1);
	disableInterrupt (GPIO_PIN_2);
	disableInterrupt (GPIO_PIN_3);

	i2c_lcd_init();	// lcd inint -> init 함수 안에 커스텀 캐릭터 들어가야함
	HAL_TIM_Base_Start (&htim3);  						// 타이머3 시작
	HAL_TIM_Base_Start (&htim11);							// 타이머11 시작
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1); // pwm 출력 시작
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1); // pwm 출력 시작
	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1); // pwm 출력 시작

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	while (1)
	{
		while (stopDelay) // 인터럽트 플래그 루틴(포토인터럽터 콜백함수 내 플래그)
			{
				stopMotor (); //모터 스탑
				buzzer_update();
				servo_update (); //서브모터 문열림
				static uint32_t prevTime = 0;
				uint32_t currTime = HAL_GetTick ();
				lcd_set_floors (rxData, targetData);
				lcd_update ();
				if (prevTime == 0) //prevTime을 시스템 시간으로 초기화
				{
					prevTime = currTime;
				}
				if ((currTime - prevTime) >= 3000) // 3000ms 동안 while문 실행
				{
					prevTime = 0; 	//prevTime으로 초기화
					stopDelay = false; //인터럽트 플래그 오프
					buzzer_off (); //부저 오프
				}
				scanButtons (); //모터 스탑 중에도 버튼입력 확인
			}
		scanButtons (); //버튼입력 확인해서 state배열에 집어넣기
		floorCheck (); 	//해당층 포토인터럽터에 걸리면 rxData = 해당층
		lcd_update (); // lcd 현상태 업데이트
		lcd_set_floors (rxData, targetData); //현재층(rxData)와 목표층(포토인터럽터 활성화 핀) LCD에 정보입력
		FND_DisplayNumber (rxData); //FND에 현재층 표시(승강기 내부 층표시) 	//인터럽트 콜백함수 내 플래그 루틴(5초간 모터 스탑)
		scanButtons (); //버튼입력 확인해서 state배열에 집어넣기
		buttonSet (); 	//버튼입력 확인한 배열을 비트연산자(0b00000000) 형태로 변환
		argorithm (); 	//비트연산자 형태별 승강기 우선순위 구현
		startMotor (); 	//현재 남은스텝수, 진행방향, 모터구동 상태 확인하여 실행

		/* USER CODE END WHILE */

		/* USER CODE BEGIN 3 */
	}
	/* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 100;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
