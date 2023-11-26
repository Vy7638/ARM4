/*
 * fsm_timer.c
 *
 *  Created on: Nov 26, 2023
 *      Author: ADMIN
 */

#include "fsm_timer.h"

int counter = 0;

void sw_fsm(){
	switch (subStatus) {
		case YEAR_C:
			subStatus = MONTH_C;
			break;
		case MONTH_C:
			subStatus = DATE_C;
			break;
		case DATE_C:
			subStatus = DAY_C;
			break;
		case DAY_C:
			subStatus = HOUR_C;
			break;
		case HOUR_C:
			subStatus = MIN_C;
			break;
		case MIN_C:
			subStatus = SEC_C;
			break;
		case SEC_C:
			subStatus = YEAR_C;
			lcd_Clear(WHITE);
			if (status == MANUAL){
				status = TIMER;
			}
			else status = NORMAL;
			break;
		default:
			break;
	}
}
void sub_fsm(){
	switch (subStatus) {
		case YEAR_C:
			ds3231_year++;
			if (ds3231_year >= 100)
				ds3231_year = 0;
			break;
		case MONTH_C:
			ds3231_month++;
			if (ds3231_month > 12)
				ds3231_month= 1;
			break;
		case DATE_C:
			ds3231_date++;
			if (ds3231_month == 2){
				if (ds3231_date > 29){
					ds3231_date = 1;
				}
			}
			else if (ds3231_month == 4 || ds3231_month == 6 || ds3231_month == 9 || ds3231_month == 11){
				if (ds3231_date > 30){
					ds3231_date = 1;
				}
			}
			else {
				if (ds3231_date > 31){
					ds3231_date = 1;
				}
			}
			break;
		case DAY_C:
			ds3231_day++;
			if (ds3231_day > 7)
				ds3231_day = 1;
			break;
		case HOUR_C:
			ds3231_hours++;
			if (ds3231_hours >= 24)
				ds3231_hours = 0;
			break;
		case MIN_C:
			ds3231_min++;
			if (ds3231_min >= 60)
				ds3231_min = 0;
			break;
		case SEC_C:
			ds3231_sec++;
			if (ds3231_sec >= 60)
				ds3231_sec = 0;
			break;
		default:
			break;
	}
}
void input_process(){
	switch (status) {
		case NORMAL:
			if (button_count[13] == 1){
				status = MANUAL;
				subStatus = YEAR_C;
				lcd_Clear(WHITE);
			}
			break;
		case MANUAL:
			if (button_count[13] == 1){
				updateTime();
				status = TIMER;
				lcd_Clear(WHITE);
			}
			if (button_count[12] == 1){
				sw_fsm();
			}
			if (button_count[3] == 1 || (button_count[3] / 40 > 0 && button_count[3] % 4 == 0)){
				sub_fsm();
			}
			break;
		case TIMER:
			if (button_count[13] == 1){
				updateAlarm();
				status = NORMAL;
				lcd_Clear(WHITE);
			}
			if (button_count[12] == 1){
				sw_fsm();
			}
			if (button_count[3] == 1|| (button_count[3] / 40 > 0 && button_count[3] % 4 == 0)){
				sub_fsm();
			}
			break;
		default:
			break;
	}
}
void fsm(){
	show_mode();
	switch (status) {
		case NORMAL:
			ds3231_ReadTime();
			displayTime();
			break;
		case MANUAL:
			counter++;
			if (counter > 5){
				blinky_time();
			}
			else {
				displayTime();
			}
			if (counter >= 10){
				counter  = 0;
			}
			break;
		case TIMER:
			counter++;
			if (counter > 5){
				blinky_time();
			}
			else {
				displayTime();
			}
			if (counter >= 10){
				counter  = 0;
			}
			break;
		default:
			break;
	}
}


