/*
 * global.c
 *
 *  Created on: Oct 26, 2023
 *      Author: ASUS
 */

#include "global.h"

int blink = 0;
int status = NORMAL_MODE;
int status_light_1 = INIT;
int status_light_2 = INIT;
int counter_light_1 = 0;
int counter_light_2 =0;
int counter_lights = 1;
int counter_temp = 0;
int RED_LED_Delay = 5000;
int GREEN_LED_Delay = 3000;
int YELLOW_LED_Delay = 2000;

void reset_to_normal_mode() {
	status = NORMAL_MODE;
	status_light_1 = INIT;
	status_light_2 = INIT;
	blink = 0;
	counter_temp = 0;
}

