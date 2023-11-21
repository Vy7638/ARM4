/*
 * software_timer.h
 *
 *  Created on: Nov 15, 2023
 *      Author: ADMIN
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "led_7seg.h"
#include "tim.h"

//extern uint16_t flag_timer1;
extern uint16_t flag_timer2;

void timer_init();
//void setTimer1(uint16_t duration);
void setTimer2(uint16_t duration);

#endif /* INC_SOFTWARE_TIMER_H_ */
