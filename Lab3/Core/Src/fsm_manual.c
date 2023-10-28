/*
 * fsm_manual.c
 *
 *  Created on: Oct 26, 2023
 *      Author: ASUS
 */

#include "fsm_manual.h"

void fsm_manual_run() {
	if (status == NORMAL_MODE)
		return;

	if (timer_flag[2] == 1) { 	// using timer3 to blink the led
		blink = 1 - blink;
		setTimer(2, 500); // toggle every 500ms, this would get f = 2Hz for blinking the led
	}

	if (timer_flag[1] == 1) {								// out of time, go back to normal mode
		reset_to_normal_mode();
	}

	switch (status) {
	case MANUAL_RED:
		setRedLight1(blink);
		setRedLight2(blink);

		if (isButtonPressed(1) == 1) {						// change mode
			status = MANUAL_YELLOW;
			counter_temp = YELLOW_LED_Delay / 1000;		// update temporary counter storing red led delay
			counter_light_1 = YELLOW_LED_Delay / 1000;	// counter light 1 show the value of current manual light
			counter_light_2 = status;										// counter light 2 show the mode
			setTimer(1, 5000);							// set timer 1 to 5 seconds for manual event
			setTimer(2, 500); 							// set timer 2 for led blinking
			setTimer(3, 250);							// timer 3 still counting 7-seg light
			counter_lights = 1;							// reset counter for switching 7-seg lights
		}

		if (isButtonPressed(2) == 1) {	// increasing 7-segment light counter
			counter_temp++;
			setTimer(1, 5000); 									// set 5 seconds for manual events
		}

		if (isButtonPressed(3) == 1) {// set the new value for 7-segment light counter
			RED_LED_Delay = counter_temp * 1000;
			setTimer(1, 5000); 									// set 5 seconds for manual events
			counter_light_1 = RED_LED_Delay / 1000;	// counter light 1 show the value of current manual light
			counter_lights = 1;							// reset counter for switching 7-seg lights
		}
		break;
	case MANUAL_YELLOW:
		setYellowLight1(blink);
		setYellowLight2(blink);

		if (isButtonPressed(1) == 1) {						// change mode
			status = MANUAL_GREEN;
			counter_temp = GREEN_LED_Delay / 1000;		// update temporary counter storing red led delay
			counter_light_1 = GREEN_LED_Delay / 1000;		// counter light 1 show the value of current manual light
			counter_light_2 = status;										// counter light 2 show the mode
			setTimer(1, 5000);							// set timer 1 to 5 seconds for manual event
			setTimer(2, 500); 							// set timer 2 for led blinking
			setTimer(3, 250);							// timer 3 still counting 7-seg light
			counter_lights = 1;							// reset counter for switching 7-seg lights
		}

		if (isButtonPressed(2) == 1) {						// increasing 7-segment light counter
			counter_temp++;
			setTimer(1, 5000); 									// set 5 seconds for manual events
		}

		if (isButtonPressed(3) == 1) {						// set the new value for 7-segment light counter
			YELLOW_LED_Delay = counter_temp * 1000;
			setTimer(1, 5000); 									// set 5 seconds for manual events
			counter_light_1 = YELLOW_LED_Delay / 1000;	// counter light 1 show the value of current manual light
			counter_lights = 1;							// reset counter for switching 7-seg lights
		}
		break;
	case MANUAL_GREEN:
		setGreenLight1(blink);
		setGreenLight2(blink);

		if (isButtonPressed(1) == 1) { 					// change back to normal mode [reset all required status]
			reset_to_normal_mode();
		}

		if (isButtonPressed(2) == 1) {						// increasing 7-segment light counter
			counter_temp++;
			setTimer(1, 5000); 									// set 5 seconds for manual events
		}

		if (isButtonPressed(3) == 1) {						// set the new value for 7-segment light counter
			GREEN_LED_Delay = counter_temp * 1000;
			setTimer(1, 5000); 									// set 5 seconds for manual events
			counter_light_1 = GREEN_LED_Delay / 1000;	// counter light 1 show the value of current manual light
			counter_lights = 1;							// reset counter for switching 7-seg lights

		}
		break;
	default:
		break;
	}

}
