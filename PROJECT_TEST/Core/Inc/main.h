/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
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
#define d_Pin GPIO_PIN_0
#define d_GPIO_Port GPIOC
#define e_Pin GPIO_PIN_1
#define e_GPIO_Port GPIOC
#define YELLOW_WEST_Pin GPIO_PIN_1
#define YELLOW_WEST_GPIO_Port GPIOA
#define c_Pin GPIO_PIN_3
#define c_GPIO_Port GPIOA
#define f_Pin GPIO_PIN_4
#define f_GPIO_Port GPIOA
#define PA5_Pin GPIO_PIN_5
#define PA5_GPIO_Port GPIOA
#define PA6_Pin GPIO_PIN_6
#define PA6_GPIO_Port GPIOA
#define PA7_Pin GPIO_PIN_7
#define PA7_GPIO_Port GPIOA
#define GREEN_NORTH_Pin GPIO_PIN_5
#define GREEN_NORTH_GPIO_Port GPIOC
#define g_Pin GPIO_PIN_0
#define g_GPIO_Port GPIOB
#define YELLOW_NORTH_Pin GPIO_PIN_6
#define YELLOW_NORTH_GPIO_Port GPIOC
#define RED_NORTH_Pin GPIO_PIN_8
#define RED_NORTH_GPIO_Port GPIOC
#define b_Pin GPIO_PIN_10
#define b_GPIO_Port GPIOA
#define GREEN_WEST_Pin GPIO_PIN_15
#define GREEN_WEST_GPIO_Port GPIOA
#define a_Pin GPIO_PIN_3
#define a_GPIO_Port GPIOB
#define RED_WEST_Pin GPIO_PIN_5
#define RED_WEST_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
