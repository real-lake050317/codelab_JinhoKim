#include <Servo.h>

const int firstServoPin = 9;
const int secondServoPin = 10;

Servo firstServo;
Servo secondServo;

int firstAngle = 0;
int secondAngle = 0;

void setup() {
  Serial.begin(9600);
  firstServo.attach(firstServoPin);
  secondServo.attach(secondServoPin);
}

void loop() {
  Serial.println("Enter coordinates in x y z format");
  Serial.println("Enter x value");
  double x = Serial.read();
  Serial.println("Enter y value");
  double y = Serial.read();
  Serial.println("Enter z value");
  double z = Serial.read();

  Serial.println("Input Values: " + x + " " + y + " " + x
  
  int phi = atan(y/z);
  int theta = acos(z/sqrt(sq(x) + sq(y)+ sq(z)));
  
  Serial.println("phi value / first servo angle :" + phi);
  Serial.println("theta value / second servo angle: " + theta);
  
}