#include <Arduino.h>

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int analog = analogRead(A0);
  Serial.println(analog);
  delay(1000);
}
