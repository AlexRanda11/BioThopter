/* * BioThopter
 * Target: STM32 (Bare Metal)
 * */
#include "main.h"
#include "drone_driver.h"
#include "ess_helper.h"
#include "led_driver.h"
#include "pwm_driver.h"
#include "stdio.h"

int main(void) {
	uint8_t is_pressed;

	// Initialize PWM for 4 LEDs
	LED_t front;
	led_init(&front, PORTD, 13);

	LED_t left;
	led_init(&left, PORTD, 12);

	LED_t right;
	led_init (&right, PORTD, 14);

	LED_t back;
	led_init(&back, PORTD, 15);

	pwm_driver_init(&left, &front, &right, &back);
	HAL_Init();
	ess_helper_init();

	SystemState currentState = INIT;
	FlightCommands currentCommand = HOVER;

	while(1) {
		is_pressed = GPIOA->IDR & 0x01;

		switch(currentState) {
			case INIT:
				Log_Event(INIT);

				blink_all_times(&left, &front, &right, &back, 5);

				currentState = FLIGHT;

				break;

			case FLIGHT:
				Log_Event(FLIGHT);

				is_pressed = GPIOA->IDR & 0x01;

				if (is_pressed) {
					currentState = BIO_DETECTED;
					break;
				}

				switch(currentCommand) {
					case HOVER:
						handle_hover();
						break;
					case PITCH_FORWARD:
						handle_pitch_forward();
						break;
					case PITCH_BACKWARD:
						handle_pitch_backward();
						break;
					case ROLL_LEFT:
						handle_roll_left();
						break;
					case ROLL_RIGHT:
						handle_roll_right();
						break;
					case ROTATE_CLOCKWISE:
						handle_rotate_clockwise();
						break;
					case ROTATE_COUNTER_CLOCKWISE:
						handle_rotate_counter_clockwise();
						break;
				}

				break;


			case BIO_DETECTED:
				Log_Event(BIO_DETECTED);


				if (is_pressed) {
					blink_all(&left, &front, &right, &back);
				} else {
					currentState = FLIGHT;
				}

				break;
		}
	}
}
