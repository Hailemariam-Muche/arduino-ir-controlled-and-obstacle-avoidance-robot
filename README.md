# Arduino IR Controlled and Obstacle Avoidance Robot

An advanced, dual-mode autonomous and remote-controlled mobile robot built using the Arduino ecosystem. This repository contains complete code implementations demonstrating alternative locomotion architectures and control methodologies on a single robotic platform: an autonomous vehicle driven directly by continuous rotation servos alongside a manually operated system using standard DC motors managed via an H-Bridge driver over infrared (IR) protocols.

## 🚀 Key Features
* **Dual Operational Modes:** Switch configurations seamlessly between autonomous ultrasonic obstacle avoidance and manual wireless IR remote control.
* **Intelligent Obstacle Avoidance:** Uses time-of-flight acoustic depth tracking to dynamically map boundaries, trigger safety thresholds, and execute reverse/escape path routing patterns.
* **Wireless Demodulation:** Decodes real-time 38kHz infrared transmission packets to execute instant manual driving and steering commands over an H-bridge driver.
* **Precision Motor & Servo Control:** Shows direct PWM servo navigation for lightweight operations, alongside hardware logic gating to govern high-torque dual DC motor chassis.

---

## 🛠️ Hardware Components Required
To build this multi-mode robotics project, the following electronic components are utilized:
* **Microcontroller:** Arduino Uno R3 (or compatible ATmega328P based development board)
* **Distance Sensor:** HC-SR04 Ultrasonic Distance Sensor Module
* **Wireless Sensor:** TSOP382 / VS1838B Infrared Demodulator Module
* **Motor Driver:** L298N Dual H-Bridge Motor Driver Module
* **Actuators:** 
  * 2x 360-Degree Continuous Rotation Servo Motors (For Part 1 layout)
  * 2x Geared DC Smart Car Chassis Motors (For Part 2 layout)
* **Input Device:** Handheld Infrared Remote Control Transmitter Handset
* **Power Source:** 2x 18650 Li-ion Batteries (7.4V pack) or stable 9V battery framework

---

## 📌 Pin Configuration & Circuit Schematic

The project supports two distinct hardware wiring maps depending on which specific firmware script you choose to compile and flash onto the microcontroller:

### Configuration 1: Continuous Servo & Ultrasonic Tracking Assembly (Autonomous Code)

| Component / Wire Trace | Arduino Pin | Logic Signal Type | Functional Responsibility |
| :--- | :--- | :--- | :--- |
| **HC-SR04 Trigger** | Pin 7 | Digital Output | Sends high-frequency acoustic ping bursts |
| **HC-SR04 Echo** | Pin 8 | Digital Input | Listens for sound wave reflection bounds |
| **Right Wheel Servo** | Pin 9 | PWM Output | Drives right-side drivetrain velocity |
| **Left Wheel Servo** | Pin 10 | PWM Output | Drives left-side drivetrain velocity |

### Configuration 2: H-Bridge Driver & IR Receiver Assembly (Manual Control Code)

| Component / Wire Trace | Arduino Pin | Logic Signal Type | Target System Allocation |
| :--- | :--- | :--- | :--- |
| **Motor 2 (Right) IN4** | Pin 4 | Digital Output | Right Motor Rotation Phase B |
| **Motor 2 (Right) IN3** | Pin 5 | Digital Output | Right Motor Rotation Phase A |
| **Motor 1 (Left) IN2** | Pin 7 | Digital Output | Left Motor Rotation Phase B |
| **Motor 1 (Left) IN1** | Pin 8 | Digital Output | Left Motor Rotation Phase A |
| **IR Receiver OUT** | Pin 10 | Digital Input | Raw decoded sensor stream data packet |
| **Status Indicator LED** | Pin 13 | Output Toggle | Visual telemetry blink confirmation link |

---

## 💻 Software & Algorithms
The repository source code balances real-time sensor polling and state-machine conditional logic:

1. **IR Decoding (`IR_Remote_Control.ino`):** Captures incoming wave streams, filters out environmental background noise, and converts parsed data frames directly into direction parameters based on this remote code matching system:
   * `0xFF02FD` &rarr; **Forward Sequence** (Engages H-bridge inputs forward)
   * `0xFF9867` &rarr; **Backward Sequence** (Inverts channel polarities to reverse)
   * `0xFFE01F` &rarr; **Turn Left Sequence** (Spins right motor forward, left motor backward for 600ms)
   * `0xFF906F` &rarr; **Turn Right Sequence** (Spins left motor forward, right motor backward for 600ms)
   * `0xFFA857` &rarr; **Emergency Stop Sequence** (Grounds all control lines to brake instantly)
2. **Distance Processing (`Obstacle_Avoidance_Servo.ino`):** Generates a clean 10-microsecond trigger pulse and uses the standard acoustic math equation inside a `pulseIn()` timing wrapper to calculate boundary distances:
   \[\text{Distance in Inches} = \frac{\text{Echo Pulse Duration}}{74} \div 2\]
3. **Decision Tree Matrix:** Operates a proactive defense mechanism. If path constraints fall into a collision zone (Distance < 5 inches), the robot safely flags an escape pattern: commands a total halt (`goStop()`) for 2000ms, engages full reversal (`goReverse()`) via reverse PWM rotation values (`180`) for 2000ms, and resets tracking to locate an open pathway.

### Libraries Used
* `Servo.h` - Integrated native abstraction library for managing micro-servo timing configurations.
* `IRremote.h` - Used to demodulate, process, and decode incoming remote transmission data streams.

---

## ⚙️ Installation & Usage Guide

1. **Clone the Repository:**
   ```bash
   git clone https://github.com
   ```
2. **Setup IDE:** Launch your desktop **Arduino IDE** and open the specific `.ino` file you want to deploy from the project directory.
3. **Install Dependencies:** Navigate to *Sketch -> Include Library -> Manage Libraries...*, look up **IRremote** inside the library manager tool, and ensure the dependency is updated and installed.
4. **Upload:** Connect your Arduino Uno board via a standard USB cable, select your target board configuration and its associated communication COM port under *Tools*, and click the **Upload** arrow to flash the code.

---

## 🤝 Contributing
Contributions, layout expansions, schematic updates, and control algorithm optimizations are welcome! Feel free to fork this repository, make updates to the control pathing structures, and submit a pull request.
