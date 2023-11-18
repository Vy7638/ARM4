/*
 * software_timer.c
 *
 *  Created on: Nov 15, 2023
 *      Author: ADMIN
 */

#include "software_timer.h"

#define TIMER_CYCLE_2 1

uint16_t flag_timer2 = 0;
uint16_t timer2_counter = 0;
uint16_t timer2_MUL = 0;

void setTimer2(uint16_t duration){
	timer2_MUL = duration / TIMER_CYCLE_2;
	timer2_counter = timer2_MUL;
	flag_timer2 = 0;
}

void timerRun(){
	if (timer2_counter > 0){
		timer2_counter--;
		if (timer2_counter == 0){
			flag_timer2 = 1;
			timer2_counter = timer2_MUL;
		}
	}
}
