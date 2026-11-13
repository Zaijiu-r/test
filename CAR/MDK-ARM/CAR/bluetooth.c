#include "bluetooth.h"
#include "motor.h"
#include "main.h"

extern UART_HandleTypeDef huart1;

uint8_t command = 0;
uint8_t current_mode = 1;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance == USART1)
		{
		    HAL_UART_Receive_IT(&huart1,&command,1);
		}
}
void Bluetooth_Init(void)
{
   HAL_UART_Receive_IT(&huart1,&command,1);
}

void Bluetooth_Process(void)
{
    if(command == 'M')
		{
		   current_mode=1;
			 command = 'S';
		}
		else if (command == 'A')
		{
		   current_mode = 0;
       command = 0; 			
		}
		
		if(current_mode == 1)
		{
		   switch(command)
			 {  
				 case 'l':
					 Set_CAR_Speed(-3000,3000);
				 case 'r':
					 Set_CAR_Speed(3000,-3000);
				 case 'F':
					 Set_CAR_Speed(7000,7000);
				   break;
				 case 'M':
					 Set_CAR_Speed(5000,5000);
				   break;
				 case 'D':
					 Set_CAR_Speed(2500,2500);
				   break;
				 case 'B':
					 Set_CAR_Speed(-3000,-3000);
				   break;
				 case 'L':
					 Set_CAR_Speed(-4000,4000);
				   break;
				 case 'R':
					 Set_CAR_Speed(4000,-4000);
				   break;
				 case 'S':
				 default:
					 Set_CAR_Speed(0,0);
				   break;
			 }
			 
		}
}

