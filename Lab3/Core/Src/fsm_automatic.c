/*
 * fsm_automatic.c
 *
 *  Created on: Oct 26, 2023
 *      Author: ASUS
 */

#include "fsm_automatic.h"

void fsm_automatic_run() {
	switch (status_light_1) {
	case INIT:
		initLights();
		status_light_1 = AUTO_RED;
		setTimer(1, RED_LED_Delay);
		counter_light_1 = RED_LED_Delay / 1000;
		setTimer(3, 1000); 	// timer for decreasing light counting
		setTimer(4, 250); 		// timer for counting light
		break;
	case AUTO_RED:
		setRedLight1(blink);
		if (timer_flag[1] == 1) {
			status_light_1 = AUTO_GREEN;
			setTimer(1, GREEN_LED_Delay);
			counter_light_1 = GREEN_LED_Delay / 1000;
		}
		break;
	case AUTO_GREEN:
		setGreenLight1(blink);
		if (timer_flag[1] == 1) {
			status_light_1 = AUTO_YELLOW;
			setTimer(1, YELLOW_LED_Delay);
			counter_light_1 = YELLOW_LED_Delay / 1000;
		}
		break;
	case AUTO_YELLOW:
		setYellowLight1(blink);
		if (timer_flag[1] == 1) {
			status_light_1 = AUTO_RED;
			setTimer(1, RED_LED_Delay);
			counter_light_1 = RED_LED_Delay / 1000;
		}
		break;
	default:
		break;
	}

	switch (status_light_2) {
	case INIT:
		initLights();
		status_light_2 = AUTO_GREEN;
		setTimer(2, GREEN_LED_Delay);
		counter_light_2 = GREEN_LED_Delay / 1000;
		break;
	case AUTO_RED:
		setRedLight2(blink);
		if (timer_flag[2] == 1) {
			status_light_2 = AUTO_GREEN;
			setTimer(2, GREEN_LED_Delay);
			counter_light_2 = GREEN_LED_Delay / 1000;
		}
		break;
	case AUTO_GREEN:
		setGreenLight2(blink);
		if (timer_flag[2] == 1) {
			status_light_2 = AUTO_YELLOW;
			setTimer(2, YELLOW_LED_Delay);
			counter_light_2 = YELLOW_LED_Delay / 1000;
		}
		break;
	case AUTO_YELLOW:
		setYellowLight2(blink);
		if (timer_flag[2] == 1) {
			status_light_2 = AUTO_RED;
			setTimer(2, RED_LED_Delay);
			counter_light_2 = RED_LED_Delay / 1000;
		}
		break;
	default:
		break;
	}
}
