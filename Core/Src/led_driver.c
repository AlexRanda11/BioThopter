#include <led_driver.h>
#include "ess_helper.h"
#include "stdint.h"

uint32_t default_delay = 100;

void led_init(LED_t* led, volatile uint32_t* port, uint32_t pin) {
	led->port = port;
	led->pin = pin;

	led_off(led);
}

void led_on(LED_t* led) {
	*(led->port) = (1 << led->pin);
}

void led_on_all(LED_t* led1, LED_t* led2, LED_t* led3, LED_t* led4) {
	*(led1->port) |= (1 << led1->pin);
	*(led2->port) |= (1 << led2->pin);
	*(led3->port) |= (1 << led3->pin);
	*(led4->port) |= (1 << led4->pin);
}

void led_on_msec(LED_t* led, uint32_t on_time, uint32_t off_time) {
	*(led->port) = (1 << led->pin);

	delay_msec(on_time);
	led_off_msec(led, off_time);
}

void led_off(LED_t* led) {
	*(led->port) = (0 << led->pin);
}

void led_off_all(LED_t* led1, LED_t* led2, LED_t* led3, LED_t* led4) {
	*(led1->port) &= (0 << led1->pin);
	*(led2->port) &= (0 << led2->pin);
	*(led3->port) &= (0 << led3->pin);
	*(led4->port) &= (0 << led4->pin);
}

void led_off_msec(LED_t* led, uint32_t off_time) {
	*(led->port) = (0 << led->pin);

	delay_msec(off_time);
}

void blink(LED_t* led) {
	led_on(led);
	delay_msec(default_delay);

	led_off(led);
	delay_msec(default_delay);

}

void blink_all(LED_t* left, LED_t* front, LED_t* right, LED_t* back) {
	led_on_all(left, front, right, back);
	delay_msec(default_delay);

	led_off_all(left, front, right, back);
	delay_msec(default_delay);
}

void blink_all_times(LED_t* left, LED_t* front, LED_t* right, LED_t* back, uint8_t number_of_times) {
	for (uint8_t i = 0; i <= number_of_times; i++) {
		blink(left);
		blink(front);
		blink(right);
		blink(back);
	}
}

void delay_msec(uint32_t delay) {
	HAL_Delay(delay);
}


