#ifndef __BLUETOOTH_H
#define __BLUETOOTH_H

#include "main.h"

extern uint8_t command;
extern uint8_t current_mode;

void Bluetooth_Init(void);
void Bluetooth_Process(void);

#endif
