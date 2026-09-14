#include <Arduino.h>

#define ESPERA 500

int ledvermelho = 8;
int ledbranco = 7;

void setup()
{
  pinMode(ledvermelho, OUTPUT);
  pinMode(ledbranco, OUTPUT);
}

void loop()
{
  digitalWrite(ledvermelho, HIGH);
  digitalWrite(ledbranco, LOW);
  delay(ESPERA);

  digitalWrite(ledvermelho, LOW);
  digitalWrite(ledbranco, HIGH);
  delay(ESPERA);
}
