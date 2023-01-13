#include <Servo.h>

const int firstServoPin = 9;
const int secondServoPin = 10;

Servo firstServo;
Servo secondServo;

int firstAngle = 0;
int secondAngle = 0;

int phi = 0;
int theta = 0;

void setup() {
    Serial.begin(9600);
    firstServo.attach(firstServoPin);
    secondServo.attach(secondServoPin);
}

void loop() {
    firstServo.write(firstAngle);
    secondServo.write(secondAngle);
    delay(1000);
    
    Serial.println("Configuration finished.");

    firstServo.write(phi);
    secondServo.write(theta);

    delay(1000);

    Serial.println("Execution Finished");

    exit(0);
}