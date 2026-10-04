// Arduino Based Servo Motor Driven Obstacle Avoidance Robot
// Using Ultrasonic Sensor

#include <Servo.h>

#define Trigger 7
#define Echo 8

Servo servoRight;
Servo servoLeft;

void setup() {

servoRight.attach(9);
servoLeft.attach(10);

pinMode(Echo, INPUT);
pinMode(Trigger, OUTPUT);

goStop();
}

void goForward() {

servoRight.write(0);
servoLeft.write(0);
}

void goReverse() {

servoRight.write(180);
servoLeft.write(180);
}

void goSpinRight() {

servoRight.write(0);
servoLeft.write(180);
}

void goSpinLeft() {

servoRight.write(180);
servoLeft.write(0);
}

void goStop() {

servoRight.write(90);
servoLeft.write(90);
}

void loop() {

// -----------------------------
// Measure distance
// -----------------------------

digitalWrite(Trigger, LOW);
delayMicroseconds(2);

digitalWrite(Trigger, HIGH);
delayMicroseconds(10);

digitalWrite(Trigger, LOW);

long duration = pulseIn(Echo, HIGH);

int distance = duration / 74 / 2;

// -----------------------------
// Obstacle avoidance logic
// -----------------------------

if (distance >= 5) {

// No obstacle
goForward();

}

else {

// Obstacle detected
goStop();
delay(300);

// Move backward
goReverse();
delay(1000);

// Stop
goStop();
delay(300);

// Try turning right
goSpinRight();
delay(700);

// Stop after turning
goStop();
delay(300);

// Measure distance again
digitalWrite(Trigger, LOW);
delayMicroseconds(2);

digitalWrite(Trigger, HIGH);
delayMicroseconds(10);

digitalWrite(Trigger, LOW);

duration = pulseIn(Echo, HIGH);

distance = duration / 74 / 2;

// -----------------------------
// Check right direction
// -----------------------------

if (distance >= 5) {

// Right direction is clear
goForward();

}

else {

// Right direction is blocked
// Turn left
goSpinLeft();
delay(1400);

// Stop after turning
goStop();
delay(300);

// Continue forward
goForward();
}
}

delay(100);
}
