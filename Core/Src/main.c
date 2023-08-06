
#include "main.h"

I2C_HandleTypeDef i2c_handle;
UART_HandleTypeDef uart1_handle;
UART_HandleTypeDef uart2_handle;

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_USART1_UART_Init(void);


int main(void)
{

  HAL_Init();

  SystemClock_Config();

  MX_GPIO_Init();
  MX_I2C1_Init();
  MX_USART2_UART_Init();
  MX_USART1_UART_Init();

  while (1)
  {
  }
}


void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure. */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

static void MX_I2C1_Init(void)
{

  i2c_handle.Instance = I2C1;
  i2c_handle.Init.ClockSpeed = 100000;
  i2c_handle.Init.DutyCycle = I2C_DUTYCYCLE_2;
  i2c_handle.Init.OwnAddress1 = 0;
  i2c_handle.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  i2c_handle.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  i2c_handle.Init.OwnAddress2 = 0;
  i2c_handle.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  i2c_handle.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&i2c_handle) != HAL_OK)
  {
    Error_Handler();
  }

}

static void MX_USART1_UART_Init(void)
{
  uart1_handle.Instance = USART1;
  uart1_handle.Init.BaudRate = 115200;
  uart1_handle.Init.WordLength = UART_WORDLENGTH_8B;
  uart1_handle.Init.StopBits = UART_STOPBITS_1;
  uart1_handle.Init.Parity = UART_PARITY_NONE;
  uart1_handle.Init.Mode = UART_MODE_TX_RX;
  uart1_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  uart1_handle.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&uart1_handle) != HAL_OK)
  {
    Error_Handler();
  }

}

static void MX_USART2_UART_Init(void)
{
  uart2_handle.Instance = USART2;
  uart2_handle.Init.BaudRate = 115200;
  uart2_handle.Init.WordLength = UART_WORDLENGTH_8B;
  uart2_handle.Init.StopBits = UART_STOPBITS_1;
  uart2_handle.Init.Parity = UART_PARITY_NONE;
  uart2_handle.Init.Mode = UART_MODE_TX_RX;
  uart2_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  uart2_handle.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&uart2_handle) != HAL_OK)
  {
    Error_Handler();
  }

}

static void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

}

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
