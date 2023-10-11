//TO RESERVE FORMATTING 
// STILL MAKING CHANGES
#include <Servo.h>
#define trigPin 3
#define echoPin 2
Servo servo_9;
int sound = 250;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  servo_9.attach(9, 500, 2500);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  digitalWrite(trigPin, HIGH);
  delay(50);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

  if (distance <= 30) {
    Serial.println("the distance is less than 10");
    servo_9.write(100);
    delay(1500);
  }
  else {
    servo_9.write(0);
  }
  if (distance > 60 || distance < 0) {
    Serial.println("The distance is more than 60");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(500);
}
