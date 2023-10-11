//https://ttssh2.osdn.jp/index.html.en 

#include<Servo.h> // include server library
Servo servo_9; // create servo object to control a servo
int poser = 0; // initial position of server
int val; // initial value of input

void setup() {
  Serial.begin(9600); // Serial comm begin at 9600bps
  servo_9.attach(9);// server is connected at pin 9
}

void loop() {
  if (Serial.available()) // if serial value is available 
  {
    val = Serial.read();// then read the serial value
    if (val == 'q') //if value input is equals to d
    {
      servo_9.write(100);
     }
    if (val == 'e') //if value input is equals to a
    {
     servo_9.write(0);
    }
  }
}
