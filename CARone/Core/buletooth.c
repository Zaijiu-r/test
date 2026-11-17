#include "buletooth.h"
#include "motor.h"

uint8_t command = 0;
extern UART_HandleTypeDef *huart2;
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if (huart->Instance == USART2)
	{
	   HAL_UART_Receive_IT(huart2,&command,1);
	}
}

void Initbluetooth(void)
{
   HAL_UART_Receive_IT(huart2,&command,1);
}

void Usebluetooth(void)
{
    switch (command)
	  {
			case 'F' :
				carspeed(6500,6500);
			break;
			
			case 'M' :
				carspeed(4500,4500);
			break;
			
			case 'D' :
				carspeed(2500,2500);
			break;
			
			case 'l':
				carspeed(0,3500);
			break;
			
			case 'r':
				carspeed(3500,0);
			break;
			
			case 'S':
				carspeed(0,0);
			break;
			
			case 'L' :
				carspeed(1500,4500);
			break;
			
			case 'R' :
				carspeed(4500,1500);
			break;
			
			case 'B' :
				carspeed(-4500,-4500);
			break;
			
			case 'a':
				carspeed(1300,2300);
			break;
			
			case'b':
				carspeed(2300,1300);
			break;
		}
}

