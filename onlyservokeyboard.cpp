#include<Servo.h> // include server library
Servo servo_10; // create servo object to control a servo
int poser = 0; // initial position of server
int val; // initial value of input

void setup() {
  Serial.begin(9600); // Serial comm begin at 9600bps
  servo_10.attach(10);// server is connected at pin 10
}

void loop() {
  if (Serial.available()) // if serial value is available 
  {
    val = Serial.read();// then read the serial value
    if (val == 'q') //if value input is equals to q
    {
      poser += 1; //than position of servo motor increases by 1 ( anti clockwise)
      servo_10.write(poser);// the servo will move according to position 
      delay(15);//delay for the servo to get to the position
     }
    if (val == 'e') //if value input is equals to e
    {
      poser -= 1; //than position of servo motor decreases by 1 (clockwise)
      servo_10.write(poser);// the servo will move according to position 
      delay(15);//delay for the servo to get to the position
    }
  }
}