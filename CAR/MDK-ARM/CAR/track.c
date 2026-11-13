#include "track.h"
#include "motor.h"

void Auto_Track(void)
{
    uint8_t N1 = HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0);
	  uint8_t N2 = HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_1);
	  uint8_t N3 = HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_2);
	  uint8_t N4 = HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_11);
	  uint8_t N5 = HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_12);

int BaseSpeed = 3500;
	
if ( N1 == 0||N2 == 0 )
 {
   Set_CAR_Speed(BaseSpeed-1000, BaseSpeed+1000);
 }
else if (N4 == 0||N5 == 0)
 {
   Set_CAR_Speed(BaseSpeed+1000, BaseSpeed-1000);
 }
else if (N3 == 0)
 {
   Set_CAR_Speed(BaseSpeed,BaseSpeed);
 }
else
 {
    Set_CAR_Speed(BaseSpeed-500, BaseSpeed-500);
 }
}
