#include <Servo.h>
#define Trigger 7
#define Echo 8
Servo servoRight;
Servo servoLeft;

void setup() {
 servoRight.attach(9);// put your setup code here, to run once:
 servoLeft.attach(10);
// Serial.begin(9600);
 pinMode(Echo, INPUT);
 pinMode(Trigger, OUTPUT);
}
void goForward(){
  servoRight.write(0);
  servoLeft.write(0);
}
void goReverse(){
  servoRight.write(180);
  servoLeft.write(180);
}
void goSpinRight(){
  servoRight.write(0);
  //servoLeft.write(0);
}
void goSpinLeft(){
 // servoRight.write(0);
  servoLeft.write(0);
}
void goStop(){
  servoRight.write(90);
  servoLeft.write(90);
}
void loop() {

  digitalWrite(Trigger, LOW);
  delayMicroseconds(2);

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);

  digitalWrite(Trigger, LOW);

  int distance = pulseIn(Echo, HIGH);
   distance = distance/74/2;
   //Serial.println(distance);
   delay(100);
   if(distance>=5){
           goForward();
   }
   else {
    goStop();
    delay(2000);
    goReverse();
    delay(2000);
    goStop();
   }
   }
