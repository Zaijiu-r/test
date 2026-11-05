#include"./BSP/LED/gtim.h"


TIM_HandleTypeDef g_timx_cap_chy_handle;

void gtim_timx_cap_chy_init(uint16_t arr,uint16_t psc)
{
     TIM_IC_InitTypeDef timx_ic_cap_chy = {0};
		 
		 g_timx_cap_chy_handle.Instance = TIM3;
		  g_timx_cap_chy_handle.Init.Prescaler = psc;
		  g_timx_cap_chy_handle.Init.CounterMode = TIM_COUNTERMODE_UP;
		 g_timx_cap_chy_handle.Init.Period = arr;
		 HAL_TIM_IC_Init(&g_timx_cap_chy_handle);
		 
		 timx_ic_cap_chy.ICPolarity = TIM_ICPOLARITY_RISING;
		 timx_ic_cap_chy.ICSelection = TIM_ICSELECTION_DIRECTTI;
		 timx_ic_cap_chy.ICPrescaler = TIM_ICPSC_DIV1;
		 timx_ic_cap_chy.ICFilter = 0;
		 HAL_TIM_IC_ConfigChannel(&g_timx_cap_chy_handle,&timx_ic_cap_chy,TIM_CHANNEL_1);
		 
		  __HAL_TIM_ENABLE_IT(&g_timx_cap_chy_handle,TIM_IT_UPDATE);
		  HAL_TIM_IC_Start_IT(&g_timx_cap_chy_handle,TIM_CHANNEL_1);
}

void HAL_TIM_IC_MspInit(TIM_HandleTypeDef *htim)
{
      if (htim->Instance == TIM3)
			{
			     GPIO_InitTypeDef gpio_init_struct;
			     __HAL_RCC_TIM3_CLK_ENABLE();
				   __HAL_RCC_GPIOA_CLK_ENABLE();
			
			     gpio_init_struct.Pin = GPIO_PIN_6;
				   gpio_init_struct.Mode = GPIO_MODE_INPUT;
				   gpio_init_struct.Pull = GPIO_PULLDOWN;
				   gpio_init_struct.Speed = GPIO_SPEED_FREQ_HIGH;
				   HAL_GPIO_Init(GPIOA,&gpio_init_struct);
				
				   HAL_NVIC_SetPriority(TIM3_IRQn,1,3);
				   HAL_NVIC_EnableIRQ(TIM3_IRQn);
		    }
}

uint16_t g_timxchy_cap_sta = 0;
uint16_t g_timxchy_cap_val = 0;

void TIM3_IRQHandler(void)
{
     HAL_TIM_IRQHandler(&g_timx_cap_chy_handle);
}

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM3)
		{
		    if ((g_timxchy_cap_sta & 0X80) ==0)
				{
				    if (g_timxchy_cap_sta & 0X40)
				    {
						 g_timxchy_cap_sta |= 0X80;
						 g_timxchy_cap_val = HAL_TIM_ReadCapturedValue(&g_timx_cap_chy_handle,TIM_CHANNEL_1);
							TIM_RESET_CAPTUREPOLARITY(&g_timx_cap_chy_handle,TIM_CHANNEL_1);
							TIM_SET_CAPTUREPOLARITY(&g_timx_cap_chy_handle,TIM_CHANNEL_1,TIM_ICPOLARITY_RISING);
						}
						else
						{
						   g_timxchy_cap_sta = 0;
							g_timxchy_cap_val = 0;
							g_timxchy_cap_sta = 0X40;
							 __HAL_TIM_DISABLE(&g_timx_cap_chy_handle);
							__HAL_TIM_SET_COUNTER(&g_timx_cap_chy_handle,0);
							TIM_RESET_CAPTUREPOLARITY(&g_timx_cap_chy_handle,TIM_CHANNEL_1);
							TIM_SET_CAPTUREPOLARITY(&g_timx_cap_chy_handle,TIM_CHANNEL_1,TIM_ICPOLARITY_FALLING);
						  __HAL_TIM_ENABLE(&g_timx_cap_chy_handle);
						}
				
				}
		
		}

}
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM3)
		{
		   if ((g_timxchy_cap_sta & 0X80) == 0)
			 {
			     if (g_timxchy_cap_sta & 0X40)
					 {
					    if((g_timxchy_cap_sta & 0X3F) == 0X3F)
							{
							    TIM_RESET_CAPTUREPOLARITY(&g_timx_cap_chy_handle,TIM_CHANNEL_1);
								  __HAL_TIM_SET_CAPTUREPOLARITY(&g_timx_cap_chy_handle,TIM_CHANNEL_1,TIM_ICPOLARITY_RISING);
								 g_timxchy_cap_sta |=0X80;
								g_timxchy_cap_sta = 0XFFFF;
							}
					     else
							 {
							   g_timxchy_cap_sta++;
							 
							 }
					 }
			 }
		}


}

