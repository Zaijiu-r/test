#include "bluetooth.h"
#include "motor.h"
#include "main.h"

extern UART_HandleTypeDef huart1;


		
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

