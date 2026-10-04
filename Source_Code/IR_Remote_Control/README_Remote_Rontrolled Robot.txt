PROJECT TITLE: Arduino-Based Remote-Controlled Wheeled Robot

PROJECT OVERVIEW
This project presents the design and development of a two-wheel differential-drive mobile robot controlled wirelessly using an infrared (IR) remote control. An Arduino Uno is used as the main controller, while an L293D dual H-bridge motor driver interfaces the controller with two DC geared motors.

The project covers hardware design, embedded software development, Proteus simulation, circuit assembly, integration, and functional testing. The repository contains source code, simulation files, circuit designs, and supporting project evidence.

OBJECTIVES
- Design and develop a functional wheeled robot.
- Implement wireless control using an IR remote.
- Control two DC geared motors independently.
- Implement forward, backward, left, right, and stop operations.
- Interface the Arduino Uno with an L293D motor driver.
- Simulate and test the control circuit using Proteus.
- Develop and validate the hardware prototype.

HARDWARE COMPONENTS
- Arduino Uno
- L293D dual H-bridge motor driver
- Two DC geared motors
- IR remote control
- IR receiver
- Robot chassis and wheels
- Motor power supply
- Connecting wires and supporting components

SOFTWARE AND TOOLS
- Arduino IDE
- C/C++ embedded programming
- IRremote library v2.6.0
- Proteus Design Suite
- GitHub

REMOTE CONTROL FUNCTIONS
2  = Forward
8  = Backward
4  = Turn Left
6  = Turn Right
5  = Stop

The IR receiver is connected to Arduino digital pin D10.

MOTOR CONTROL CONNECTIONS
Left Motor:
D8 -> L293D 1A
D7 -> L293D 2A

Right Motor:
D5 -> L293D 3A
D4 -> L293D 4A

The L293D provides the required motor-driving and direction-control interface between the Arduino and the two DC geared motors.

DEVELOPMENT PROCESS
1. Identify system requirements.
2. Design the robot electrical and mechanical system.
3. Select the Arduino Uno and L293D motor driver.
4. Design the motor-control circuit.
5. Integrate the IR receiver and remote-control interface.
6. Develop the Arduino firmware.
7. Simulate and debug the circuit in Proteus.
8. Assemble the hardware.
9. Integrate the controller, motor driver, motors, and IR receiver.
10. Test and validate robot movement and remote-control functions.

REPOSITORY CONTENTS
Source_Code/
    Arduino robot control program

Proteus/
    Circuit schematic and simulation files

Hardware/
    Hardware design files and photographs

Images/
    Project and prototype photographs

Videos/
    Demonstration videos or links

Documentation/
    Supporting project documentation

README.txt
    Project description and technical information

PROJECT OUTCOME
The developed system demonstrates wireless control of a two-wheel mobile robot using an IR remote. The Arduino processes received IR commands and generates direction signals for the L293D motor driver, which controls the two DC geared motors.

The project demonstrates practical integration of embedded programming, digital electronics, motor control, IR communication, circuit simulation, and hardware prototyping.

ACADEMIC AND PROFESSIONAL USE
This repository is maintained as technical evidence of an engineering project and may be used for academic demonstration, learning, research reference, portfolio documentation, and professional evaluation.

AUTHOR
Hailemariam Muche
Electrical and Computer Engineering
Lecturer / Engineer

REPOSITORY NOTE
The files in this repository represent the available design, implementation, simulation, and supporting evidence of the project. The materials may be examined for educational and engineering purposes.
