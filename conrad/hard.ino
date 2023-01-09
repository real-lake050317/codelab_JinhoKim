#include <Servo.h>
#include <arduino.h>
#include <math.h>
#include "I2Cdev.h"
#include "HMC5883L_Simple.h"
// #include "module.h"
// #include "init.h"

HMC5883L_Simple Compass;

struct coordinates {
  double x;
  double y;
  double z;
};

coordinates c = { 1, 2, 3 };

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
  while (Serial.available() == 0){}
  temp.x = Serial.parseFloat();
  temp.y = Serial.parseFloat();
  temp.z = Serial.parseFloat();

  return temp;
}

void setup() {
  Serial.begin(9600);
  Wire.begin();
  firstServo.attach(firstServoPin);
  secondServo.attach(secondServoPin);
}

void loop() {
  /*
  Serial.println("Enter coordinates in x y z format");
  Serial.println("Enter coordinate x");
  while (!Serial.available()) {
    delay(100);
  }
  Serial.println("Input Received. Processing...");

  c.x = Serial.read() - 48;
  Serial.println(c.x);

  isInputFinished = true;
  */

  // -----------------------------------------------
  Serial.println("Initializing I2C devices...");

  Compass.SetDeclination(23, 35, 'E');
  Compass.SetSamplingMode(COMPASS_SINGLE);
  Compass.SetScale(COMPASS_SCALE_130);
  Compass.SetOrientation(COMPASS_HORIZONTAL_X_NORTH);

  Serial.print("x value: ");
  Serial.println(c.x);
  Serial.print("y value: ");
  Serial.println(c.y);
  Serial.print("z value: ");
  Serial.println(c.z);

  double radX = c.x * DEG_TO_RAD;
  double radY = c.y * DEG_TO_RAD;
  double radZ = c.z * DEG_TO_RAD;

  Serial.print("x value in radian: ");
  Serial.println(radX);
  Serial.print("y value in radian: ");
  Serial.println(radY);
  Serial.print("z value in radian: ");
  Serial.println(radZ);

  double phi = atan(radY / radZ);
  double theta = acos(radZ / sqrt(sq(radX) + sq(radY) + sq(radZ)));

  firstAngle = phi;
  secondAngle = theta;

  Serial.print("phi value:");
  Serial.println(phi);
  Serial.print("theta value: ");
  Serial.println(theta);

  firstServo.write(phi);
  secondServo.write(theta);

  float heading = Compass.GetHeadingDegrees();
  Serial.print("Heading: \t");
  Serial.println(heading);

  Serial.print("Processing... Please Wait");

  delay(2500);

  Serial.print("Execution Done");

  /*
    Serial.println("Enter x value");
    double x = Serial.read();
    Serial.println("Enter y value");
    double y = Serial.read();
    Serial.println("Enter z value");
    double z = Serial.read();
  */
  exit(0);
}