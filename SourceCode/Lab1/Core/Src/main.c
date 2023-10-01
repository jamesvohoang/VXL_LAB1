/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
typedef enum
{
  Red1_Green2,
  Red1_Yellow2,
  Green1_Red2,
  Yellow1_Red2
}TrafficLightColor;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
uint8_t state;
uint8_t count;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void SwitchLed(uint32_t time)
{
  state = 1 - state;

  HAL_GPIO_WritePin(LedRed_GPIO_Port, LedRed_Pin, state);
  HAL_GPIO_WritePin(LedYellow_GPIO_Port, LedYellow_Pin, 1 - state);
  HAL_Delay(time);
}

void TurnOffLight()
{
  state = 1;
  HAL_GPIO_WritePin(LedRed_GPIO_Port, LedRed_Pin, state);
  HAL_GPIO_WritePin(LedYellow_GPIO_Port, LedYellow_Pin, state);
  HAL_GPIO_WritePin(LedGreen_GPIO_Port, LedGreen_Pin, state);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, state);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, state);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, state);
}

void DisplayNum(uint8_t a, uint8_t b, uint8_t c, uint8_t d, uint8_t e, uint8_t f, uint8_t g )
{
    HAL_GPIO_WritePin(Seg1_GPIO_Port, Seg1_Pin, a);
    HAL_GPIO_WritePin(Seg2_GPIO_Port, Seg2_Pin, b);
    HAL_GPIO_WritePin(Seg3_GPIO_Port, Seg3_Pin, c);
    HAL_GPIO_WritePin(Seg4_GPIO_Port, Seg4_Pin, d);
    HAL_GPIO_WritePin(Seg5_GPIO_Port, Seg5_Pin, e);
    HAL_GPIO_WritePin(Seg6_GPIO_Port, Seg6_Pin, f);
    HAL_GPIO_WritePin(Seg7_GPIO_Port, Seg7_Pin, g);
}

void display7SEG(int num)
{
  switch (num)
  {
  case 0:
    DisplayNum(0, 0, 0, 0, 0, 0, 1);
    break;
  case 1:
    DisplayNum(1, 0, 0, 1, 1, 1, 1);
    break;
  case 2:
    DisplayNum(0, 0, 1, 0, 0, 1, 0);
    break;
  case 3:
    DisplayNum(0, 0, 0, 0, 1, 1, 0);
    break;
  case 4:
    DisplayNum(1, 0, 0, 1, 1, 0, 0);
    break;
  case 5:
    DisplayNum(0, 1, 0, 0, 1, 0, 0);
    break;
  case 6:
    DisplayNum(0, 1, 0, 0, 0, 0, 0);
    break;
  case 7:
    DisplayNum(0, 0, 0, 1, 1, 1, 1);
    break;
  case 8:
    DisplayNum(0, 0, 0, 0, 0, 0, 0);
    break;
  case 9:
    DisplayNum(0, 0, 0, 0, 1, 0, 0);
    break;
  
  default:
    break;
  }
}

void SimulateTrafficLight()
{
  TurnOffLight();
  HAL_GPIO_WritePin(LedRed_GPIO_Port, LedRed_Pin, 0);
  HAL_Delay(5000);


  TurnOffLight();
  HAL_GPIO_WritePin(LedYellow_GPIO_Port, LedYellow_Pin, 0);
  HAL_Delay(2000);

  TurnOffLight();
  HAL_GPIO_WritePin(LedGreen_GPIO_Port, LedGreen_Pin, 0);
  HAL_Delay(3000);
}

void ChangeLight(uint8_t light)
{

  switch (light)
  {
  case Red1_Green2:
    TurnOffLight();
    HAL_GPIO_WritePin(LedRed_GPIO_Port, LedRed_Pin, 0);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, 0);
    break;
  case Red1_Yellow2:
    TurnOffLight();
    HAL_GPIO_WritePin(LedRed_GPIO_Port, LedRed_Pin, 0);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);
    break;
  case Green1_Red2:
    TurnOffLight();
    HAL_GPIO_WritePin(LedGreen_GPIO_Port, LedGreen_Pin, 0);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 0);
    break;
  case Yellow1_Red2:
    TurnOffLight();
    HAL_GPIO_WritePin(LedYellow_GPIO_Port, LedYellow_Pin, 0);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 0);
    break;

  default:
    break;
  }
}


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
  /* USER CODE BEGIN 2 */
  uint8_t counter = 0;
  TrafficLightColor lightColor = 0;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

    if(lightColor >= 4) lightColor = 0;

    if(!counter)
    {
      switch (lightColor)
      {
      case Red1_Green2:
        counter = 5;
        break;
      case Red1_Yellow2:
        counter = 2;
        break;
      case Green1_Red2:
        counter = 6;
        break;

      case Yellow1_Red2:
        counter = 2;
        break;
      
      default:
        break;
      }
      ChangeLight(lightColor++);
    }

    display7SEG(counter--);

    HAL_Delay(100);
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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
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

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LedRed_Pin|LedYellow_Pin|LedGreen_Pin|GPIO_PIN_8
                          |GPIO_PIN_9|GPIO_PIN_10, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, Seg1_Pin|Seg2_Pin|Seg3_Pin|GPIO_PIN_10
                          |GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14
                          |GPIO_PIN_15|Seg4_Pin|Seg5_Pin|Seg6_Pin
                          |Seg7_Pin|GPIO_PIN_9, GPIO_PIN_RESET);

  /*Configure GPIO pins : LedRed_Pin LedYellow_Pin LedGreen_Pin PA8
                           PA9 PA10 */
  GPIO_InitStruct.Pin = LedRed_Pin|LedYellow_Pin|LedGreen_Pin|GPIO_PIN_8
                          |GPIO_PIN_9|GPIO_PIN_10;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : Seg1_Pin Seg2_Pin Seg3_Pin PB10
                           PB11 PB12 PB13 PB14
                           PB15 Seg4_Pin Seg5_Pin Seg6_Pin
                           Seg7_Pin PB9 */
  GPIO_InitStruct.Pin = Seg1_Pin|Seg2_Pin|Seg3_Pin|GPIO_PIN_10
                          |GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14
                          |GPIO_PIN_15|Seg4_Pin|Seg5_Pin|Seg6_Pin
                          |Seg7_Pin|GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
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
