/*
 * led_lcd.c
 *
 *  Created on: Nov 23, 2023
 *      Author: ADMIN
 */

#include "led_lcd.h"

void lcdRedGreen(){
	lcd_DrawCircle(40, 180, RED, 20, 1);
	lcd_DrawCircle(160, 50, GREEN, 20, 1);
}
void lcdRedAmber(){
	lcd_DrawCircle(40, 180, RED, 20, 1);
	lcd_DrawCircle(120, 50, YELLOW, 20, 1);
}
void lcdGreenRed(){
	lcd_DrawCircle(40, 100, GREEN, 20, 1);
	lcd_DrawCircle(80, 50, RED, 20, 1);
}
void lcdAmberRed(){
	lcd_DrawCircle(40, 140, YELLOW, 20, 1);
	lcd_DrawCircle(80, 50, RED, 20, 1);
}

void blinkyRed(){
	if (counter > 10){
		lcd_Clear(WHITE);
	}
	else {
		lcd_DrawCircle(40, 180, RED, 20, 1);
		lcd_DrawCircle(80, 50, RED, 20, 1);
	}
}
void blinkyAmber(){
	if (counter > 10){
		lcd_Clear(WHITE);
	}
	else {
		lcd_DrawCircle(120, 50, YELLOW, 20, 1);
		lcd_DrawCircle(40, 140, YELLOW, 20, 1);
	}
}
void blinkyGreen(){
	if (counter > 10){
		lcd_Clear(WHITE);
	}
	else {
		lcd_DrawCircle(40, 100, GREEN, 20, 1);
		lcd_DrawCircle(160, 50, GREEN, 20, 1);
	}
}

void showMode(){
	lcd_ShowIntNum(70, 100, mode, 2, GREEN, BLACK, 24);
	lcd_ShowIntNum(110, 100, temp, 2, GREEN, BLACK, 24);
}
