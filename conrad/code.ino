#include <Servo.h>
#define DEG_TO_RAD 0.017453292519943295769236907684886
#define RAD_TO_DEG 57.295779513082320876798154814105

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

  // Serial.println("Input Values: " + x + " " + y + " " + z);

  double radX = x * DEG_TO_RAD;
  double radY = y * DEG_TO_RAD;
  double radZ = z * DEG_TO_RAD;
  
  int phi = atan(y/z);
  int theta = acos(z/sqrt(sq(x) + sq(y)+ sq(z)));

  
  
  // Serial.println("phi value / first servo angle :" + phi);
  // Serial.println("theta value / second servo angle: " + theta);
  
}