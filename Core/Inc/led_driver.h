/*
 * led_driver.h
 *
 *  Created on: 12 Feb 2026
 *      Author: alexrandall
 */

#ifndef LED_DRIVER_H
#define LED_DRIVER_H

#include "stdint.h"

#define PORTD ((volatile uint32_t*)0x40020C14)

struct LEDstruct {
	volatile uint32_t * port; // the LED register
	uint32_t pin; // 0..15
};

typedef struct LEDstruct LED_t;

void led_init(LED_t*, volatile uint32_t*, uint32_t);

void led_on(LED_t*);
void led_on_all(LED_t*, LED_t*, LED_t*, LED_t*);

void led_off(LED_t*);
void led_off_all(LED_t*, LED_t*, LED_t*, LED_t*);

void delay_msec(uint32_t);

void blink(LED_t*);
void blink_all(LED_t*, LED_t*, LED_t* , LED_t*);
void blink_all_times(LED_t*, LED_t*, LED_t*, LED_t*, uint8_t);

#endif /* LED_DRIVER_H */
