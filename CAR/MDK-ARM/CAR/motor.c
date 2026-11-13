#include "motor.h"

extern TIM_HandleTypeDef htim3;

void Set_CAR_Speed(int LeftSpeed, int RightSpeed)
{
    if (LeftSpeed > 0)
		{
		    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_RESET);
			  __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,LeftSpeed);
		}
		else if (LeftSpeed < 0)
		{
		    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_SET);
			  __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,-LeftSpeed);
		}
		else 
		{
		    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_RESET);
			  __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,0);
		}
		
		if (RightSpeed > 0)
		{
		    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,GPIO_PIN_RESET);
			  __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,RightSpeed);
		}
		else if (RightSpeed < 0)
		{
		    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,GPIO_PIN_SET);
			  __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,-RightSpeed);
		}
		else
		{
		    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,GPIO_PIN_RESET);
			  __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,0);
		}
}
