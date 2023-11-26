/*
 * global.h
 *
 *  Created on: Nov 26, 2023
 *      Author: ADMIN
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define NORMAL 	1
#define MANUAL 	2
#define TIMER	3

#define YEAR_C	11
#define MONTH_C	12
#define DATE_C	13
#define DAY_C	14
#define HOUR_C	15
#define MIN_C	16
#define SEC_C	17

extern int status;
extern int subStatus;

int alarm_hours;
int alarm_min;
int alarm_sec;
int alarm_date;
int alarm_day;
int alarm_month;
int alarm_year;


#endif /* INC_GLOBAL_H_ */
