/*
 * graphics.c
 *
 *  Created on: Oct 26, 2023
 *      Author: ASUS
 */

#include "graphics.h"

void initLights()
{
	counter_temp = 0;
	status_light_1 = INIT;
	status_light_2 = INIT;

	HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, GPIO_PIN_SET);

	HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, GPIO_PIN_SET);

	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
}

void setRedLight1(int blink)
{
	HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, blink);
	HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, GPIO_PIN_SET);
}
void setGreenLight1(int blink)
{
	HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, blink);
	HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, GPIO_PIN_SET);
}
void setYellowLight1(int blink)
{
	HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, blink);
}

void setRedLight2(int blink)
{
	HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, blink);
	HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, GPIO_PIN_SET);
}
void setGreenLight2(int blink)
{
	HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, blink);
	HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, GPIO_PIN_SET);
}
void setYellowLight2(int blink)
{
	HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, blink);
}

void display7SegmentLED(int number, GPIO_TypeDef *GPIOx, uint16_t GPIO_Pins[])
{
	int num[10][7] = {
		// a  b  c  d  e  f  g
		{0, 0, 0, 0, 0, 0, 1}, // 0
		{1, 0, 0, 1, 1, 1, 1}, // 1
		{0, 0, 1, 0, 0, 1, 0}, // 2
		{0, 0, 0, 0, 1, 1, 0}, // 3
		{1, 0, 0, 1, 1, 0, 0}, // 4
		{0, 1, 0, 0, 1, 0, 0}, // 5
		{0, 1, 0, 0, 0, 0, 0}, // 6
		{0, 0, 0, 1, 1, 1, 1}, // 7
		{0, 0, 0, 0, 0, 0, 0}, // 8
		{0, 0, 0, 0, 1, 0, 0}  // 9
	};

	for (int i = 0; i < 7; i++)
	{
		HAL_GPIO_WritePin(GPIOx, GPIO_Pins[i], num[number][i]);
	}
}

void display7SegmentLight()
{
	uint16_t GPIO_Pins[] = {SEG0_Pin, SEG1_Pin, SEG2_Pin, SEG3_Pin,
							SEG4_Pin, SEG5_Pin, SEG6_Pin};
	switch (counter_lights)
	{
	case 1:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
		display7SegmentLED(counter_light_1 / 10, GPIOB, GPIO_Pins); // first digit of light 1
		if (timer_flag[3] == 1)
		{
			counter_lights = 2;
			setTimer(3, 250);
		}
		break;
	case 2:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
		display7SegmentLED(counter_light_1 % 10, GPIOB, GPIO_Pins); // second digit of light 1
		if (timer_flag[3] == 1)
		{
			counter_lights = 3;
			setTimer(3, 250);
		}
		break;
	case 3:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
		display7SegmentLED(counter_light_2 / 10, GPIOB, GPIO_Pins); // first digit of light 2
		if (timer_flag[3] == 1)
		{
			counter_lights = 4;
			setTimer(3, 250);
		}
		break;
	case 4:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
		display7SegmentLED(counter_light_2 % 10, GPIOB, GPIO_Pins); // second digit of light 2
		if (timer_flag[3] == 1)
		{
			counter_lights = 1;
			if (status == NORMAL_MODE)
			{
				counter_light_1--;
				counter_light_2--;
			}
			setTimer(3, 250);
		}
		break;
	default:
		counter_lights = 1;
		break;
	}
}
