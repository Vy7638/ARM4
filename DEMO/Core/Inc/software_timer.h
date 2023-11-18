/*
 * software_timer.h
 *
 *  Created on: Nov 15, 2023
 *      Author: ADMIN
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "main.h"

extern uint16_t flag_timer2;

void setTimer2(uint16_t duration);
void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
