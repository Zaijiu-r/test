#include"./SYSTEM/sys/sys.h"
#include"./SYSTEM/usart/usart.h"
#include"./SYSTEM/delay/delay.h"
#include"./BSP/LED/led.h"
#include"./BSP/EXTI/exti.h"



int main(void)
{
    HAL_Init();
    sys_stm32_clock_init(RCC_PLL_MUL9);
    delay_init(72);
    led_init();
    exti_init();
		   while(1)
			 {
                 LED1(1);
                delay_ms(500);
                LED1(0);
                delay_ms(500);
			 }
}

