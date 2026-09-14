#include <Arduino.h>

void setup()
{
  Serial.begin(9600);

  Serial.println("INICIO DO PROGRAMA");

  pinMode(13, OUTPUT);
}

void loop()
{
  digitalWrite(13, HIGH);
  Serial.println("LED ESTA ACESO");
  delay(1000);
  digitalWrite(13, LOW);
  Serial.println("LED ESTA APAGADO");
  delay(1000);
}
