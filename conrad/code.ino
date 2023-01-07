#include <Servo.h>
#include <arduino.h>
#include <math.h>
#include "module.h"
#include "init.h"

struct coordinates {
  double x;
  double y;
  double z;
};

coordinates c = {0, 0, 0};

#define DEG_TO_RAD 0.0174532925199432
#define RAD_TO_DEG 57.2957795130823208

const int firstServoPin = 9;
const int secondServoPin = 10;

const int hallPin = A0;

Servo firstServo;
Servo secondServo;

int firstAngle = 0;
int secondAngle = 0;

bool isInputFinished = false;

coordinates input_coordinates() {
  coordinates temp;
  Serial.end();
  while (Serial.available() == 0)
  {
  }
  temp.x = Serial.parseFloat();
  temp.y = Serial.parseFloat();
  temp.z = Serial.parseFloat();

  return temp;
}

void setup() {
  Serial.begin(9600);
  firstServo.attach(firstServoPin);
  secondServo.attach(secondServoPin);
}

void loop() {
  Serial.println("Enter coordinates in x y z format");

  if (Serial.available()) {
    c = input_coordinates();
  } else {
    delay(100);
  }

  if (isInputFinished) {

    Serial.print("x value: ");
    Serial.println(x);
    Serial.print("y value: ");
    Serial.println(y);
    Serial.print("z value: ");
    Serial.println(z);

    double radX = x * DEG_TO_RAD;
    double radY = y * DEG_TO_RAD;
    double radZ = z * DEG_TO_RAD;

    Serial.print("x value in radian: ");
    Serial.println(radX);
    Serial.print("y value in radian: ");
    Serial.println(radY);
    Serial.print("z value in radian: ");
    Serial.println(radZ);

    int phi = atan(radY / radZ);
    int theta = acos(radZ / sqrt(sq(radX) + sq(radY) + sq(radZ)));

    firstAngle = phi;
    secondAngle = theta;

    Serial.print("phi value / first servo angle :");
    Serial.println(phi);
    Serial.print("theta value / second servo angle: ");
    Serial.println(theta);

    firstServo.write(phi);
    secondServo.write(theta);

    Serial.print("Execution Done");
  }
  /*
  Serial.println("Enter x value");
  double x = Serial.read();
  Serial.println("Enter y value");
  double y = Serial.read();
  Serial.println("Enter z value");
  double z = Serial.read();
  */

  return 0;
}