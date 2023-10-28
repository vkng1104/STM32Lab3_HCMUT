/*
 * fsm_manual.c
 *
 *  Created on: Oct 26, 2023
 *      Author: ASUS
 */

#include "fsm_manual.h"

void fsm_manual_run() {
	if (timer_flag[3] == 1) { 	// using timer3 to blink the led
		blink = 1 - blink;
		setTimer(3, 500); // toggle every 500ms, this would get f = 2Hz for blinking the led
	}
//	switch (status) {
//	case MANUAL_RED:
//		resetLights();
//		status = AUTO_RED;
//		setTimer(1, RED_LED_Delay);
//		break;
//	case MANUAL_GREEN:
//		setRedLight();
//		if (timer_flag[1] == 1) {
//			status = AUTO_GREEN;
//			setTimer(1, GREEN_LED_Delay);
//		}
//		break;
//	case MANUAL_YELLOW:
//		setGreenLight();
//		if (timer_flag[1] == 1) {
//			status = AUTO_YELLOW;
//			setTimer(1, YELLOW_LED_Delay);
//		}
//		break;
//	default:
//		break;
//	}
}
