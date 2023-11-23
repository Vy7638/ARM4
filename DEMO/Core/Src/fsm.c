/*
 * fsm.c
 *
 *  Created on: Nov 23, 2023
 *      Author: ADMIN
 */

#include "fsm.h"

int counterRedGreen;
int counterRedAmber;
int counterGreenRed;
int counterAmberRed;

void fsm_auto_init(){
	counterRedGreen = timerGreen;
	counterRedAmber = timerAmber;
	counterGreenRed = timerGreen;
	counterAmberRed	= timerAmber;
}

void fsm_auto(){
  if (counter % 20 == 0){
	  counter = 0;
	switch (status) {
		case RED_GREEN:
			lcd_Clear(WHITE);
			lcdRedGreen();
			counterRedGreen--;
			if (counterRedGreen <= 0){
				counterRedGreen = timerGreen;
				status = RED_AMBER;
			}
			break;
		case RED_AMBER:
			lcd_Clear(WHITE);
			lcdRedAmber();
			counterRedAmber--;
			if (counterRedAmber <= 0){
				counterRedAmber = timerAmber;
				status = GREEN_RED;
			}
			break;
		case GREEN_RED:
			lcd_Clear(WHITE);
			lcdGreenRed();
			counterGreenRed--;
			if (counterGreenRed <= 0){
				counterGreenRed = timerGreen;
				status = AMBER_RED;
			}
			break;
		case AMBER_RED:
			lcd_Clear(WHITE);
			lcdAmberRed();
			counterAmberRed--;
			if (counterAmberRed <= 0){
				counterAmberRed = timerAmber;
				status = RED_GREEN;
			}
			break;
		case INIT:
			status = RED_GREEN;
			fsm_auto_init();
			break;
		default:
			break;
	}
  }
}

void fsm_manual(){
	switch (status) {
		case RED_MANUAL:
			mode = 2;
			temp = tempRed;
			blinkyRed();
			showMode();
			break;
		case AMBER_MANUAL:
			mode = 3;
			temp = tempAmber;
			blinkyAmber();
			showMode();
			break;
		case GREEN_MANUAL:
			mode = 4;
			temp = tempGreen;
			blinkyGreen();
			showMode();
			break;
		default:
			break;
	}
}
