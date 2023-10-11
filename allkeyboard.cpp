#include <Servo.h> // include server library
Servo servo_9; // create servo object to control a servo
int poser = 0; // initial position of server
int val; // initial value of input
const int motorPin1 = 4; 
const int motorPin2 = 5; 
const int motorPin3 = 6; 
const int motorPin4 = 7; 
const int enablePinA = 8; 
const int enablePinB = 9; 

// Stop motor
void stopMotor() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
}

void setup() {
  Serial.begin(9600); // Serial comm begin at 9600bps
  servo_9.attach(9);// server is connected at pin 9

  // Start serial communication
    // Start serial communication
  Serial.println("Press 'W' to move chassis forward, 'S' to move chassis backward, 'A' to turn left, 'D' to turn right, and 'X' to stop.");

  // Set pins as outputs
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(enablePinA, OUTPUT);
  pinMode(enablePinB, OUTPUT);

  // Enable motor driver A and B
  digitalWrite(enablePinA, HIGH);
  digitalWrite(enablePinB, HIGH);
}



void loop() {
  if (Serial.available()) // if serial value is available 
  {
    val = Serial.read();// then read the serial value
    if (val == 'r') //if value input is equals to d
    {
      poser += 1; //than position of servo motor increases by 1 ( anti clockwise)
      servo_9.write(poser);// the servo will move according to position 
      delay(15);//delay for the servo to get to the position
     }
    if (val == 't') //if value input is equals to a
    {
      poser -= 1; //than position of servo motor decreases by 1 (clockwise)
      servo_9.write(poser);// the servo will move according to position 
      delay(15);//delay for the servo to get to the position
    }
  }
   if (Serial.available()) {
    char command = Serial.read();

    switch (command) {
      case 'A':
      case 'a':
        // Move robot forward
        digitalWrite(motorPin1, HIGH);
        digitalWrite(motorPin2, LOW);
        digitalWrite(motorPin3, HIGH);
        digitalWrite(motorPin4, LOW);
        break;

      case 'D':
      case 'd':
        // Move robot backward
        digitalWrite(motorPin1, LOW);
        digitalWrite(motorPin2, HIGH);
        digitalWrite(motorPin3, LOW);
        digitalWrite(motorPin4, HIGH);
        break;

      case 'W':
      case 'w':
        // Turn left 
        digitalWrite(motorPin1, LOW);
        digitalWrite(motorPin2, HIGH);
        digitalWrite(motorPin3, HIGH);
        digitalWrite(motorPin4, LOW);
        break;

      case 'S':
      case 's':
        // Turn right
        digitalWrite(motorPin1, HIGH);
        digitalWrite(motorPin2, LOW);
        digitalWrite(motorPin3, LOW);
        digitalWrite(motorPin4, HIGH);
        break;

      case 'X':
      case 'x':
        stopMotor();
        break;

      default:
        break;
    }
  }
}