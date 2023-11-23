/*
 * global.h
 *
 *  Created on: Nov 23, 2023
 *      Author: ADMIN
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define INIT 		0
#define RED_GREEN 	1
#define RED_AMBER 	2
#define GREEN_RED 	3
#define AMBER_RED 	4

#define RED_MANUAL 		11
#define AMBER_MANUAL 	12
#define GREEN_MANUAL	13

extern int status;

int timerRed;
int timerAmber;
int timerGreen;

int tempRed;
int tempAmber;
int tempGreen;

int mode;
int temp;

#endif /* INC_GLOBAL_H_ */
