#include "drone_driver.h"
#include "pwm_driver.h"
#include <string.h>
#include <stdio.h>

void handle_hover(){
	for(uint8_t i = 0; i < 4; i++){
		pwm_driver_set(i, 50);
		pwm_driver_update();
	}
}

void handle_pitch_forward() {
	pwm_driver_set(0, 50);
	pwm_driver_update();

	pwm_driver_set(1, 20);
	pwm_driver_update();

	pwm_driver_set(2, 50);
	pwm_driver_update();

	pwm_driver_set(3, 80);
	pwm_driver_update();
}

void handle_pitch_backward() {
	pwm_driver_set(0, 50);
	pwm_driver_update();

	pwm_driver_set(1, 80);
	pwm_driver_update();

	pwm_driver_set(2, 50);
	pwm_driver_update();

	pwm_driver_set(3, 20);
	pwm_driver_update();
}

void handle_roll_left() {
	pwm_driver_set(0, 20);
	pwm_driver_update();

	pwm_driver_set(1, 50);
	pwm_driver_update();

	pwm_driver_set(2, 80);
	pwm_driver_update();

	pwm_driver_set(3, 50);
	pwm_driver_update();
}

void handle_roll_right() {
	pwm_driver_set(0, 80);
	pwm_driver_update();

	pwm_driver_set(1, 50);
	pwm_driver_update();

	pwm_driver_set(2, 20);
	pwm_driver_update();

	pwm_driver_set(3, 50);
	pwm_driver_update();
}

void handle_rotate_clockwise() {
	pwm_driver_set(0, 20);
	pwm_driver_update();

	pwm_driver_set(1, 80);
	pwm_driver_update();

	pwm_driver_set(2, 20);
	pwm_driver_update();

	pwm_driver_set(3, 80);
	pwm_driver_update();
}

void handle_rotate_counter_clockwise() {
	pwm_driver_set(0, 80);
	pwm_driver_update();

	pwm_driver_set(1, 20);
	pwm_driver_update();

	pwm_driver_set(2, 80);
	pwm_driver_update();

	pwm_driver_set(3, 20);
	pwm_driver_update();
}

void Log_Event(SystemState currentState){
	const char* SystemStateStrings[] = {
			"INIT",
			"FLIGHT",
			"BIO_DETECTED"
	};

	printf("[BioThopter Event Log] Current State: %s\r\n", SystemStateStrings[currentState]);
}

void Process_Telemetry(void) {
	printf("[BioThopter Telemetry Log] Biosignature detected! Transmitting details to Ground Control System...");
}
