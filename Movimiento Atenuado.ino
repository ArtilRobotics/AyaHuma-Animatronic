#include <Servo.h>
Servo legright;

int switch1 = 0;
float switch1Smoothed;
float switch1Prev=90;

void setup() {
  // put your setup code here, to run once:
  legright.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()){
  int dato = Serial.read();
  switch1Smoothed = (dato* 0.05) + (switch1Prev * 0.95);
  switch1Prev = switch1Smoothed;
  legright.write(switch1Smoothed);
  delay(20);
  }
    
}
