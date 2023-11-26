/*
 * function.c
 *
 *  Created on: Nov 26, 2023
 *      Author: ADMIN
 */

#include "function.h"

void displayTime(){
	lcd_ShowIntNum(70, 100, ds3231_hours, 2, GREEN, BLACK, 24);
	lcd_ShowIntNum(110, 100, ds3231_min, 2, GREEN, BLACK, 24);
	lcd_ShowIntNum(150, 100, ds3231_sec, 2, GREEN, BLACK, 24);
	lcd_ShowIntNum(20, 130, ds3231_day, 2, YELLOW, BLACK, 24);
	lcd_ShowIntNum(70, 130, ds3231_date, 2, YELLOW, BLACK, 24);
	lcd_ShowIntNum(110, 130, ds3231_month, 2, YELLOW, BLACK, 24);
	lcd_ShowIntNum(150, 130, ds3231_year, 2, YELLOW, BLACK, 24);
}

void updateTime(){
	ds3231_Write(ADDRESS_YEAR, ds3231_year);
	ds3231_Write(ADDRESS_MONTH, ds3231_month);
	ds3231_Write(ADDRESS_DATE, ds3231_date);
	ds3231_Write(ADDRESS_DAY, ds3231_day);
	ds3231_Write(ADDRESS_HOUR, ds3231_hours);
	ds3231_Write(ADDRESS_MIN, ds3231_min);
	ds3231_Write(ADDRESS_SEC, ds3231_sec);
}
void updateAlarm(){
	alarm_hours = ds3231_hours;
	alarm_min = ds3231_min;
	alarm_sec = ds3231_sec;
	alarm_date = ds3231_date;
	alarm_day = ds3231_day;
	alarm_month = ds3231_month;
	alarm_year = ds3231_year;
}
void show_mode(){
	switch (status) {
		case NORMAL:
			lcd_StrCenter(0, 2, "MODE 1: NORMAL", RED, BLUE, 16, 1);
			break;
		case MANUAL:
			lcd_StrCenter(0, 2, "MODE 2: MANUAL", RED, BLUE, 16, 1);
			break;
		case TIMER:
			lcd_StrCenter(0, 2, "MODE 3: TIMER", RED, BLUE, 16, 1);
			break;
		default:
			break;
	}
}
void blinky_time(){
	switch (subStatus) {
		case YEAR_C:
			lcd_ShowIntNum(150, 130, ds3231_year, 2, BLACK, BLACK, 24);
			break;
		case MONTH_C:
			lcd_ShowIntNum(110, 130, ds3231_month, 2, BLACK, BLACK, 24);
			break;
		case DATE_C:
			lcd_ShowIntNum(70, 130, ds3231_date, 2, BLACK, BLACK, 24);
			break;
		case DAY_C:
			lcd_ShowIntNum(20, 130, ds3231_day, 2, BLACK, BLACK, 24);
			break;
		case HOUR_C:
			lcd_ShowIntNum(70, 100, ds3231_hours, 2, BLACK, BLACK, 24);
			break;
		case MIN_C:
			lcd_ShowIntNum(110, 100, ds3231_min, 2, BLACK, BLACK, 24);
			break;
		case SEC_C:
			lcd_ShowIntNum(150, 100, ds3231_sec, 2, BLACK, BLACK, 24);
			break;
		default:
			break;
	}
}
