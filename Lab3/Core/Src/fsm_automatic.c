/*
 * fsm_automatic.c
 *
 *  Created on: Oct 26, 2023
 *      Author: ASUS
 */

#include "fsm_automatic.h"

void fsm_automatic_run() {
	if (status != NORMAL_MODE)
		return;
	if (isButtonPressed(1) == 1) {
		status = MANUAL_RED;
		counter_temp = RED_LED_Delay / 1000;	// update temporary counter storing red led delay
		counter_light_1 = RED_LED_Delay / 1000;	// counter light 1 show the value of current manual light
		counter_light_2 = status;								// counter light 2 show the mode
		setTimer(1, 5000);							// set timer 1 to 5 seconds for manual event
		setTimer(2, 500); 							// set timer 2 for led blinking
		setTimer(3, 250);							// timer 3 still counting 7-seg light
		counter_lights = 1;							// reset counter for switching 7-seg lights
		return;
	}
	switch (status_light_1) {
	case INIT:
		initLights();
		status_light_1 = AUTO_RED;
		setTimer(1, RED_LED_Delay);
		counter_light_1 = RED_LED_Delay / 1000;
		setTimer(3, 250); 		// timer 3 for counting light
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
