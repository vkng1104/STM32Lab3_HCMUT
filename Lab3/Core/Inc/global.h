/*
 * global.h
 *
 *  Created on: Oct 26, 2023
 *      Author: ASUS
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"

#define INIT 						1
#define AUTO_RED 			2
#define AUTO_GREEN 		3
#define AUTO_YELLOW 	4

#define MANUAL_RED 			18
#define MANUAL_GREEN 		19
#define MANUAL_YELLOW 	20

#define NO_7_SEGMENT_LIGHTS		4

extern int blink;					// blinking status
extern int status_light_1; 	// status for light 1
extern int status_light_2; 	// status for light 2
extern int counter_light_1; 	// counter for light 1
extern int counter_light_2; 	// counter for light 2
extern int counter_lights;
extern int RED_LED_Delay;
extern int GREEN_LED_Delay;
extern int YELLOW_LED_Delay;

#endif /* INC_GLOBAL_H_ */
