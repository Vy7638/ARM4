/*
 * function.h
 *
 *  Created on: Nov 26, 2023
 *      Author: ADMIN
 */

#ifndef INC_FUNCTION_H_
#define INC_FUNCTION_H_

#include "global.h"
#include "lcd.h"
#include "ds3231.h"

void displayTime();
void updateTime();
void updateAlarm();
void show_mode();
void blinky_time();

#endif /* INC_FUNCTION_H_ */
