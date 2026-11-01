#include"./BSPa/KEY/key.h"
#include "./SYSTEM/delay/delay.h"

void key_init(void)
{
	GPIO_InitTypeDef gpio_init_struct;
	
	__HAL_RCC_GPIOA_CLK_ENABLE();
	
	gpio_init_struct.Pin=GPIO_PIN_0;
	gpio_init_struct.Mode=GPIO_MODE_INPUT;
	gpio_init_struct.Pull=GPIO_PULLUP;
	HAL_GPIO_Init(GPIOA,&gpio_init_struct);
}

uint8_t key_scan(void)
{
	if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0)==0)
	{
	   delay_ms(10);
	   if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0)==0)
		 {
			  while(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0)==0);
		    return 1; 
		 }
	}
	return 0;
	
}