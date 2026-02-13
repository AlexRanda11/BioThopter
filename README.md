# BioThopter: Autonomous Martian Life-Detecting Drone

## Project Overview

**BioThopter** is an embedded systems project developed for the **STM32F411E-DISCO** platform. It simulates the flight dynamics and scientific mission of an autonomous drone deployed in a Martian environment to detect biosignatures. By utilizing a **diamond-pattern LED array**, the system emulates quadcopter maneuvers such as pitch, roll, and yaw through software-defined **Pulse Width Modulation (PWM)**.

The project demonstrates a **Reactive Embedded System** that transitions between autonomous flight states and an alert state upon the detection of environmental triggers (simulated via an onboard button/analog proxy).

---

## File Structure and Functionality

The software is designed with a modular architecture, separating low-level hardware abstraction from high-level mission logic.

1. **Mission Logic Layer**
    - `main.c`: The "Executive" of the system. It contains the primary Finite State Machine (FSM) which cycles through `INIT`, `FLIGHT`, and `BIO_DETECTED` states. It handles the reactive logic, such as switching to an alert mode when a "biosignature" is detected via a button press.

    - `drone_driver.c / .h`: Defines the flight behavior. It contains high-level "handlers" (e.g., `handle_pitch_forward()`) that translate flight commands into specific duty cycles for the four PWM channels. It also manages the **Event Log** and **Telemetry** output to simulate communication with a Ground Control System.

2. **Hardware Abstraction Layer (HAL)**
    - `pwm_driver.c / .h`: A custom software PWM implementation. It tracks a global counter and compares it against individual channel values to toggle GPIO pins, allowing for 0-100% brightness control across the LED array.

    - `led_driver.c / .h`: Provides the low-level bitwise manipulation of the STM32 GPIO registers. It includes functions for initializing LEDs, toggling them individually, or performing synchronized actions like blink_all().

    - `ess_helper.h`: A utility header provided for compatibility with the project environment.

    - `main.h`: Contains the standard STM32 HAL includes and system-wide definitions required for the hardware to function.

---

# Technical Features

- **Reactive State Machine**: The system responds in real-time to physical inputs, fulfilling the "interplay between hardware and software" requirement.

- **Diamond Configuration Flight Rules**:

    - **Pitch Forward**: Dims the Front LED and brightens the Back LED to simulate forward tilt.

    - **Roll Right**: Brightens the Left LED and dims the Right LED.

    - **Yaw (Rotate)**: Adjusts diagonal pairs to simulate rotational torque.

- **Telemetry Emulation**: Outputs system status and "Science Data" via a simulated wireless link (printf to console).
