/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */
void led1(GPIO_PinState state);
void led2(GPIO_PinState state);
void led3(GPIO_PinState state);
void led4(GPIO_PinState state);
void led5(GPIO_PinState state);
void wheel_cw(uint32_t delay);
void half_wheel_cw(uint32_t delay);
void wheel_ccw(uint32_t delay);
void half_wheel_ccw(uint32_t delay);
void onoff(uint32_t delay);
void delay_onoff(uint32_t delay);

void go_to_sleep();
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
  /* USER CODE BEGIN 2 */
  __HAL_RCC_PWR_CLK_ENABLE();
  /* USER CODE END 2 */
 
 

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  	uint32_t delay1=50, delay2=600;
  	wheel_cw(delay1);
  	wheel_cw(delay1);
  	wheel_cw(delay1);
  	wheel_cw(delay1);
  	half_wheel_cw(delay1);
		delay_onoff(delay2);
		onoff(delay2);
		onoff(delay2);
		HAL_Delay(delay2);
		wheel_ccw(delay1);
		wheel_ccw(delay1);
		wheel_ccw(delay1);
		wheel_ccw(delay1);
		half_wheel_ccw(delay1);
		delay_onoff(delay2);
		onoff(delay2);
		onoff(delay2);
		HAL_Delay(delay2);

		go_to_sleep();

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
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLLMUL_4;
  RCC_OscInitStruct.PLL.PLLDIV = RCC_PLLDIV_4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV64;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
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

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED4_Pin|LED3_Pin|LED2_Pin|LED1_Pin 
                          |LED5_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : PC14 PC15 */
  GPIO_InitStruct.Pin = GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : LED4_Pin LED3_Pin LED2_Pin LED1_Pin 
                           LED5_Pin */
  GPIO_InitStruct.Pin = LED4_Pin|LED3_Pin|LED2_Pin|LED1_Pin 
                          |LED5_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PA5 PA6 PA7 PA10 */
  GPIO_InitStruct.Pin = GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_10;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PB1 */
  GPIO_InitStruct.Pin = GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void led1(GPIO_PinState state){
	HAL_GPIO_WritePin(LED1_GPIO_Port,LED1_Pin,state);
}

void led2(GPIO_PinState state){
	HAL_GPIO_WritePin(LED2_GPIO_Port,LED2_Pin,state);
}

void led3(GPIO_PinState state){
	HAL_GPIO_WritePin(LED3_GPIO_Port,LED3_Pin,state);
}

void led4(GPIO_PinState state){
	HAL_GPIO_WritePin(LED4_GPIO_Port,LED4_Pin,state);
}

void led5(GPIO_PinState state){
	HAL_GPIO_WritePin(LED5_GPIO_Port,LED5_Pin,state);
}

void wheel_cw(uint32_t delay){
	led1(1);
	HAL_Delay(delay);
	led2(1);
	HAL_Delay(delay);
	led3(1);
	HAL_Delay(delay);
	led4(1);
	HAL_Delay(delay);
	led5(1);
	HAL_Delay(delay);
	led1(0);
	HAL_Delay(delay);
	led2(0);
	HAL_Delay(delay);
	led3(0);
	HAL_Delay(delay);
	led4(0);
	HAL_Delay(delay);
	led5(0);
	HAL_Delay(delay);
}

void half_wheel_cw(uint32_t delay){
	led1(1);
	HAL_Delay(delay);
	led2(1);
	HAL_Delay(delay);
	led3(1);
	HAL_Delay(delay);
	led4(1);
	HAL_Delay(delay);
	led5(1);
	HAL_Delay(delay);
}

void wheel_ccw(uint32_t delay){
	led5(1);
	HAL_Delay(delay);
	led4(1);
	HAL_Delay(delay);
	led3(1);
	HAL_Delay(delay);
	led2(1);
	HAL_Delay(delay);
	led1(1);
	HAL_Delay(delay);
	led5(0);
	HAL_Delay(delay);
	led4(0);
	HAL_Delay(delay);
	led3(0);
	HAL_Delay(delay);
	led2(0);
	HAL_Delay(delay);
	led1(0);
	HAL_Delay(delay);
}

void half_wheel_ccw(uint32_t delay){
	led5(1);
	HAL_Delay(delay);
	led4(1);
	HAL_Delay(delay);
	led3(1);
	HAL_Delay(delay);
	led2(1);
	HAL_Delay(delay);
	led1(1);
	HAL_Delay(delay);
}

void onoff(uint32_t delay) {
	HAL_Delay(delay);
	led1(1);
	led2(1);
	led3(1);
	led4(1);
	led5(1);
	HAL_Delay(delay);
	led1(0);
	led2(0);
	led3(0);
	led4(0);
	led5(0);
}

void delay_onoff(uint32_t delay){
	HAL_Delay(delay);
	led1(0);
	led2(0);
	led3(0);
	led4(0);
	led5(0);
}

void go_to_sleep(){
	HAL_PWREx_EnableUltraLowPower();
	HAL_PWREx_EnableFastWakeUp();
	__HAL_PWR_CLEAR_FLAG(PWR_FLAG_SB);
	HAL_PWR_DisableWakeUpPin(PWR_WAKEUP_PIN1);
	__HAL_PWR_CLEAR_FLAG(PWR_FLAG_WU);
	HAL_PWR_EnableWakeUpPin(PWR_WAKEUP_PIN1);
	HAL_PWR_EnterSTANDBYMode();
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

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
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
