#include <Servo.h>
Servo bloom;
int prox;
int duration, distance;


void setup()
{
  Serial.begin(9600);
  bloom.writeMicroseconds(1500);
  bloom.attach(11);
  bloom.write(40);
  prox = 10;
  
}

void loop()
{
  pinMode(prox, OUTPUT);
  digitalWrite(prox, HIGH);
  delay(500);
  digitalWrite(prox, LOW);
  
  pinMode(prox, INPUT);
  duration = pulseIn(prox, HIGH);
  distance = (duration / 2) / 29.1;
  
  if(distance < 30)
    bloom.write(100);
  else
    bloom.write(88);
//  else if(distance < 60)
//    bloom.write(45);
//  else
//    bloom.write(40);
}
