/*
 * graphics.h
 *
 *  Created on: Oct 26, 2023
 *      Author: ASUS
 */

#ifndef INC_GRAPHICS_H_
#define INC_GRAPHICS_H_

#include "main.h"
#include "global.h"

void initLights();
void setRedLight1(int);
void setGreenLight1(int);
void setYellowLight1(int);
void setRedLight2(int);
void setGreenLight2(int);
void setYellowLight2(int);

void display7SegmentLED(int number, GPIO_TypeDef *GPIOx, uint16_t GPIO_Pins[]);
void display7SegmentLight();
#endif /* INC_GRAPHICS_H_ */
