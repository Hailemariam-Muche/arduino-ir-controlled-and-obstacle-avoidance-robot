README.txt

ARDUINO-BASED OBSTACLE AVOIDANCE ROBOT
Proteus Simulation Version – DC Motors + L293D

1. PROJECT OVERVIEW
-------------------
This Proteus simulation represents an Arduino-based autonomous
obstacle avoidance wheeled robot.

The robot continuously measures distance using an HC-SR04-compatible
UltrasonicTEP sensor. When the distance is 5 inches or greater,
the robot moves forward.

When an obstacle is detected below 5 inches, the robot:
1. Stops briefly.
2. Reverses for approximately 1 second.
3. Stops briefly.
4. Spins right for approximately 0.7 seconds.
5. Measures distance again.
6. Moves forward if the path is clear.
7. If still blocked, spins left for approximately 1.4 seconds.
8. Moves forward.

2. PURPOSE OF THE PROTEUS VERSION
---------------------------------
The physical robot uses two continuous-rotation servo motors.
The standard MOTOR-PWMSERVO model in Proteus is a positional
hobby servo, so it does not accurately represent continuous
wheel-drive servos.

Therefore, this Proteus version uses:
    Arduino UNO + L293D + Two DC Motors

This provides a practical bidirectional wheel-drive simulation.

3. COMPONENTS
-------------
- Arduino UNO
- UltrasonicTEP / HC-SR04-compatible ultrasonic sensor
- Potentiometer for adjustable simulated distance
- L293D dual H-bridge motor driver
- Two DC motors
- +5V supply
- Motor supply
- Ground terminals

4. PIN CONFIGURATION
--------------------
Ultrasonic sensor:
    TRIG -> Arduino D7
    ECHO -> Arduino D8
    VCC  -> +5V
    GND  -> GND
    SimPin -> Potentiometer wiper

L293D:
    Pin 1  EN1  -> Arduino D6
    Pin 2  1A   -> Arduino D2
    Pin 3  1Y   -> Left motor
    Pin 4       -> GND
    Pin 5       -> GND
    Pin 6  2Y   -> Left motor
    Pin 7  2A   -> Arduino D3
    Pin 8  VCC2 -> Motor supply

    Pin 9  EN2  -> Arduino D9
    Pin 10 3A   -> Arduino D4
    Pin 11 3Y   -> Right motor
    Pin 12      -> GND
    Pin 13      -> GND
    Pin 14 4Y   -> Right motor
    Pin 15 4A   -> Arduino D5
    Pin 16 VCC1 -> +5V

Potentiometer:
    Terminal 1 -> +5V
    Wiper      -> UltrasonicTEP SimPin
    Terminal 3 -> GND

5. MOTOR CONTROL
----------------
Left motor:
    IN1 = D2
    IN2 = D3
    EN1 = D6

Right motor:
    IN1 = D4
    IN2 = D5
    EN2 = D9

Forward:
    Left  = IN1 HIGH, IN2 LOW
    Right = IN1 HIGH, IN2 LOW

Reverse:
    Left  = IN1 LOW, IN2 HIGH
    Right = IN1 LOW, IN2 HIGH

Spin right:
    Left = Forward
    Right = Reverse

Spin left:
    Left = Reverse
    Right = Forward

Stop:
    Both motor enable signals are disabled.

6. OBSTACLE THRESHOLD
---------------------
Threshold:
    5 inches

If distance >= 5 inches:
    Move forward.

If distance < 5 inches:
    Execute the obstacle-avoidance sequence.

7. DISTANCE MEASUREMENT
-----------------------
The Arduino generates a 10-microsecond ultrasonic trigger pulse
and measures the returning echo pulse using pulseIn().

Approximate calculation:
    distance = duration / 74 / 2

The potentiometer connected to the UltrasonicTEP SimPin is used
to adjust the simulated obstacle distance in Proteus.

8. OBSTACLE-AVOIDANCE ALGORITHM
-------------------------------
START
  |
  v
Measure distance
  |
  +-- distance >= 5 in --> Move Forward
  |
  +-- distance < 5 in
          |
          v
        STOP
          |
          v
      REVERSE 1 s
          |
          v
        STOP
          |
          v
    SPIN RIGHT 0.7 s
          |
          v
    Measure distance
       /            Clear      Blocked
      |           |
      v           v
   Forward    SPIN LEFT
                 1.4 s
                   |
                   v
                Forward

9. TESTING
-----------
Test 1:
Set simulated distance below 5 inches.
Expected: obstacle avoidance is activated.

Test 2:
Set distance to 5 inches or more.
Expected: robot moves forward.

Test 3:
After a right turn, make the simulated path clear.
Expected: robot moves forward.

Test 4:
Keep the path blocked.
Expected: robot turns right, detects the blockage,
turns left, and then continues forward.

10. PHYSICAL ROBOT VS PROTEUS
-----------------------------
Physical robot:
    Two continuous-rotation servo motors
    Servo.h control
    Typical commands:
        0   = one direction
        90  = stop
        180 = opposite direction

Proteus:
    Two DC motors
    L293D H-bridge driver
    Arduino digital signals control motor direction

The obstacle-detection and avoidance concept is the same in both
versions; only the wheel-drive implementation differs.

11. DEVELOPMENT PROCESS
-----------------------
1. Define obstacle-avoidance requirements.
2. Select Arduino UNO.
3. Interface the ultrasonic sensor.
4. Set the 5-inch obstacle threshold.
5. Develop forward, reverse, turn and stop functions.
6. Develop the avoidance algorithm.
7. Build the Proteus circuit.
8. Replace continuous-servo representation with L293D/DC motors.
9. Add adjustable UltrasonicTEP simulation.
10. Compile the Arduino program and load the HEX file.
11. Test different simulated distances.
12. Compare simulation behavior with the physical prototype.

12. LIMITATIONS
---------------
- Only one forward-facing ultrasonic sensor is used.
- A single sensor cannot independently measure left and right.
- The right turn is followed by a new forward measurement.
- If still blocked, the robot performs a left turn.
- Turning time and motor speed are approximate.
- DC motors/L293D represent the physical continuous-rotation
  servo wheel drives in the Proteus simulation.

13. FUTURE IMPROVEMENTS
-----------------------
- Add left and right ultrasonic sensors.
- Use a servo-mounted scanning ultrasonic sensor.
- Implement PWM motor-speed control.
- Improve turn calibration.
- Add PID-based steering.
- Add battery monitoring.
- Add wireless/Bluetooth control.
- Implement more advanced path planning.

14. EXPECTED RESULT
-------------------
The simulation demonstrates an autonomous two-wheel robot that:
- Measures obstacle distance.
- Moves forward when clear.
- Detects obstacles below 5 inches.
- Reverses when an obstacle is detected.
- Attempts a right turn.
- Rechecks the path.
- Turns left if the path remains blocked.
- Continues forward after avoidance.

15. SUGGESTED REPOSITORY STRUCTURE
----------------------------------
Obstacle-Avoidance-Robot/
|
+-- README.txt
+-- Arduino/
|   +-- Obstacle_Avoidance_Robot.ino
+-- Proteus/
|   +-- Obstacle_Avoidance_Robot.pdsprj
|   +-- Schematic/
+-- Images/
|   +-- Proteus_Schematic.png
|   +-- Simulation_Test.png
+-- Videos/
|   +-- Proteus_Simulation.mp4
+-- Documentation/
    +-- Project_Description.pdf

16. ACADEMIC / ENGINEERING RELEVANCE
------------------------------------
This project demonstrates practical integration of:
- Embedded systems
- Arduino programming
- Ultrasonic sensing
- Motor control
- H-bridge motor driving
- Autonomous robotics
- Proteus simulation
- Hardware/software integration
- Algorithm development and testing

17. AUTHOR
----------
Author: Hailemariam Muche
Project: Arduino-Based Obstacle Avoidance Robot
Simulation: Proteus Design Suite
Controller: Arduino UNO

END OF README
