#include "motor.h"

extern TIM_HandleTypeDef htim1;

void carspeed(int leftspeed , int rightspeed)
{
    if (leftspeed > 0)
		{
		    HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0,GPIO_PIN_SET);
			  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,GPIO_PIN_RESET);
			  __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, leftspeed);
		}
		else if (leftspeed < 0)
		{
		    HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0,GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,GPIO_PIN_SET);
			  __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, -leftspeed);
		}
     else 
		 {
		    HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0,GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,GPIO_PIN_RESET);
			  __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 0);
		 }
	  if (rightspeed > 0)
		{
		    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_SET);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_RESET);
			 __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, rightspeed);
		}
		else if (rightspeed < 0)
		{
		    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_SET);
			 __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, -rightspeed);
		}
		else 
		{
		    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_RESET);
			  __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 0);
		}

}
