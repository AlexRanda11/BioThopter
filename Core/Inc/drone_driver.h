/*
 * drone_driver.h
 *
 *  Created on: 11 Feb 2026
 *      Author: alexrandall
 */

#ifndef DRONE_DRIVER_H
#define DRONE_DRIVER_H

// System States (FSM)
typedef enum {
	INIT,
	FLIGHT,
	BIO_DETECTED
} SystemState;

// Flight Commands
typedef enum {
	HOVER,
	PITCH_FORWARD,
	PITCH_BACKWARD,
	ROLL_LEFT,
	ROLL_RIGHT,
	ROTATE_CLOCKWISE,
	ROTATE_COUNTER_CLOCKWISE,
} FlightCommands;

// Function Prototypes
void handle_hover(void);
void handle_pitch_forward(void);
void handle_pitch_backward(void);
void handle_roll_left(void);
void handle_roll_right(void);
void handle_rotate_clockwise(void);
void handle_rotate_counter_clockwise(void);

void Log_Event(SystemState);
void Process_Telemtry(void);

#endif /* DRONE_DRIVER_H */