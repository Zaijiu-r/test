#include"./BSP/EXTI/exti.h"
#include"./SYSTEM/delay/delay.h"


void exti_init(void)
{
     GPIO_InitTypeDef gpio_init_struct;
	   __HAL_RCC_GPIOA_CLK_ENABLE();
	   __HAL_RCC_AFIO_CLK_ENABLE();
	 __HAL_RCC_GPIOC_CLK_ENABLE();
    gpio_init_struct.Pin = GPIO_PIN_4;               
    gpio_init_struct.Mode = GPIO_MODE_IT_FALLING;         
    gpio_init_struct.Pull = GPIO_PULLUP;                                    
    HAL_GPIO_Init(GPIOA, &gpio_init_struct); 

	gpio_init_struct.Pin = GPIO_PIN_13;               
    gpio_init_struct.Mode = GPIO_MODE_OUTPUT_PP;         
    gpio_init_struct.Pull =GPIO_NOPULL; 
    gpio_init_struct.Speed = GPIO_SPEED_FREQ_LOW;	
    HAL_GPIO_Init(GPIOC, &gpio_init_struct);
      

     HAL_NVIC_SetPriority(EXTI4_IRQn,2,0);
	   HAL_NVIC_EnableIRQ(EXTI4_IRQn);

}
      void EXTI4_IRQHandler(void)
			{
			   HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_4);
			
			}


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
     //delay_ms(20);
	
	   
			 if(GPIO_Pin==GPIO_PIN_4)
			 {
			 HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_13);
			 }
		 
}