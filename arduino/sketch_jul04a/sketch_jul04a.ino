#include <Servo.h>

Servo myservo;

int pos = 0;

void setup() {
  Serial.begin(9600);
  myservo.attach(9);
}

void loop() {
  int temp = 204 - analogRead(A0)/5;
  Serial.println(temp);
  if (pos != temp) {
    if (pos > temp){
      for (int i = pos; i >= temp; i--){
        myservo.write(i);
        delay(5);
      }
    }
    else {
      for (int i = pos; i <= temp; i++){
        myservo.write(i);
        delay(5);
      }
    }
    pos = temp;
  }
  
  delay(10);
  
}
