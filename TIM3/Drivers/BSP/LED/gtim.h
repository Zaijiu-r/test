#ifndef __GTIM_H
#define __GTIM_H

#include"stm32f1xx.h"
#include"stm32f1xx_hal_tim.h"

extern uint16_t g_timxchy_cap_sta;
void gtim_timx_cap_chy_init(uint16_t arr,uint16_t psc);
extern uint16_t g_timxchy_cap_val;

//void TIMX_CHY_Cap_Init(uint16_t arr,uint16_t psc);

#endif
