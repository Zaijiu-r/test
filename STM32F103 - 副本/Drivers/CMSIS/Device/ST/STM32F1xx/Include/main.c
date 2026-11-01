#include"stm32f1xx_hal.h"
#include"./SYSTEM/sys/sys.h"
#include"./SYSTEM/usart/usart.h"
#include"./SYSTEM/delay/delay.h"
#include"./BSPa/LEDa/led.h"
#include"./BSPa/KEY/key.h"

int main(void)
{
    HAL_Init();
	  __HAL_RCC_GPIOC_CLK_ENABLE();
    sys_stm32_clock_init(RCC_PLL_MUL9);
    delay_init(72);
    led_init();
	  key_init();
		while(1)
		{   
			if(key_scan()==1)
			{
				
				HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_13);
				/*HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13,GPIO_PIN_RESET);
				delay_ms(1000);
         HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13,GPIO_PIN_SET);
			   delay_ms(1000);*/

		  } 
		}
}
