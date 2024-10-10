/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "FreeRTOS.h"
#include "task.h"
#include "stdio.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define DWT_CTRL (*(volatile uint32_t *) 0xE0001000)
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */
TaskHandle_t task1_handle;
TaskHandle_t task2_handle;
TaskHandle_t task3_handle;
TaskHandle_t task_btn_handle;


TaskHandle_t task_btn_handle;
BaseType_t status;

TaskHandle_t volatile next_task_handle = NULL;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
/* USER CODE BEGIN PFP */
static void Task1_Handler(void*);
static void Task2_Handler(void*);
static void Task3_Handler(void*);
static void Task_btn_Handler(void*);
extern void SEGGER_UART_init(uint32_t);

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
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */

  //enable the cycle counter (CYCCNT register)
  DWT_CTRL |= (1<<0);
  SEGGER_SYSVIEW_DisableEvents(((U32)1u << 17)); //Disable Idle event
  SEGGER_UART_init(230400);

  SEGGER_SYSVIEW_Conf();
   //SEGGER_SYSVIEW_Start();

   status = xTaskCreate(Task1_Handler, "Task_1_o_5", 200, NULL, 3, &task1_handle);
   configASSERT(status == pdPASS);

   next_task_handle = task1_handle;

   status = xTaskCreate(Task2_Handler, "Task_2_g_5", 200,  NULL, 2, &task2_handle);
   configASSERT(status == pdPASS);

   status = xTaskCreate(Task3_Handler, "Task_3_r_5", 200, NULL, 1, &task3_handle);
   configASSERT(status == pdPASS);

   status = xTaskCreate(Task_btn_Handler, "Button_task_5", 200, NULL, 4, &task_btn_handle);
    configASSERT(status == pdPASS);

   vTaskStartScheduler(); //if the scheduler fails, this function will return.

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
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
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 84;
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

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

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
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LED3_Pin|LED4_Pin|LED5_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : PC14 */
  GPIO_InitStruct.Pin = GPIO_PIN_14;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : LED3_Pin LED4_Pin LED5_Pin */
  GPIO_InitStruct.Pin = LED3_Pin|LED4_Pin|LED5_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
static void Task1_Handler(void* parameters){

	BaseType_t status;
    char msg[30];

	while(1){
	  HAL_GPIO_TogglePin(GPIOB, LED3_Pin);
	  status = xTaskNotifyWait(0,0, NULL, pdMS_TO_TICKS(1000));
	  snprintf(msg,30,"%s\n", "Toggle LED3");
	  SEGGER_SYSVIEW_PrintfTarget(msg);
	  if(status == pdTRUE){
		  vTaskSuspendAll(); //modifying a global variable, when scheduler suspended preemption will not occur
		  next_task_handle = task2_handle;
		  xTaskResumeAll();
		  HAL_GPIO_WritePin(GPIOB, LED3_Pin, GPIO_PIN_SET);
			snprintf(msg,30,"%s\n", "Delete task1");
			SEGGER_SYSVIEW_PrintfTarget(msg);
		  vTaskDelete(NULL);
	  }
	}



}

static void Task2_Handler(void* parameters)
{
	BaseType_t status;
    char msg[30];


		while(1){
		  HAL_GPIO_TogglePin(GPIOB, LED4_Pin);
		  status = xTaskNotifyWait(0,0, NULL, pdMS_TO_TICKS(800));
		  snprintf(msg,30,"%s\n", "Toggle LED4");
		  SEGGER_SYSVIEW_PrintfTarget(msg);
		  if(status == pdTRUE){
			  vTaskSuspendAll();
			  next_task_handle = task3_handle;
			  xTaskResumeAll();
			  HAL_GPIO_WritePin(GPIOB, LED4_Pin, GPIO_PIN_SET);
				snprintf(msg,30,"%s\n", "Delete task2");
				SEGGER_SYSVIEW_PrintfTarget(msg);
			  vTaskDelete(NULL);
		  }
		}

}

static void Task3_Handler(void* parameters)
{
	BaseType_t status;
    char msg[30];

		while(1){
		  HAL_GPIO_TogglePin(GPIOB, LED5_Pin);
		  status = xTaskNotifyWait(0,0, NULL, pdMS_TO_TICKS(400));
		  snprintf(msg,30,"%s\n", "Toggle LED5");
		  SEGGER_SYSVIEW_PrintfTarget(msg);
		  if(status == pdTRUE){
			  vTaskSuspendAll();
			  next_task_handle = NULL;
			  xTaskResumeAll();
			  HAL_GPIO_WritePin(GPIOB, LED5_Pin, GPIO_PIN_SET);
			  snprintf(msg,30,"%s\n", "Delete task3");
			  SEGGER_SYSVIEW_PrintfTarget(msg);
			  vTaskDelete(task_btn_handle);
			  vTaskDelete(NULL);
		  }
		}


}

static void Task_btn_Handler(void* parameters)
{
	uint8_t btn_read = 0;
	uint8_t prev_read = 0;
	while(1){
		btn_read = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_14);
		if(btn_read){
			if(!prev_read){
				xTaskNotify(next_task_handle,0,eNoAction);
			}

		}
		prev_read = btn_read;
		vTaskDelay(pdMS_TO_TICKS(10));
	}

}

/* USER CODE END 4 */

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM5 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM5) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

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
