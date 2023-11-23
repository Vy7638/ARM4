/*
 * led_lcd.c
 *
 *  Created on: Nov 23, 2023
 *      Author: ADMIN
 */

#include "led_lcd.h"

void lcdRedGreen(){

}
void lcdRedAmber(){

}
void lcdGreenRed(){

}
void lcdAmberRed(){

}
void blinkyRed(){

}
void blinkyAmber(){

}
void blinkyGreen(){

}
void showMode(){
	lcd_ShowIntNum(70, 100, mode, 2, GREEN, BLACK, 24);
	lcd_ShowIntNum(110, 100, temp, 2, GREEN, BLACK, 24);
}
