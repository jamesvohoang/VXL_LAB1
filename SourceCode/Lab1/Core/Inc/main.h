/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "software_timer.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LedRed_Pin GPIO_PIN_5
#define LedRed_GPIO_Port GPIOA
#define LedYellow_Pin GPIO_PIN_6
#define LedYellow_GPIO_Port GPIOA
#define LedGreen_Pin GPIO_PIN_7
#define LedGreen_GPIO_Port GPIOA
#define Seg1_Pin GPIO_PIN_0
#define Seg1_GPIO_Port GPIOB
#define Seg2_Pin GPIO_PIN_1
#define Seg2_GPIO_Port GPIOB
#define Seg3_Pin GPIO_PIN_2
#define Seg3_GPIO_Port GPIOB
#define Seg4_Pin GPIO_PIN_3
#define Seg4_GPIO_Port GPIOB
#define Seg5_Pin GPIO_PIN_4
#define Seg5_GPIO_Port GPIOB
#define Seg6_Pin GPIO_PIN_5
#define Seg6_GPIO_Port GPIOB
#define Seg7_Pin GPIO_PIN_6
#define Seg7_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
