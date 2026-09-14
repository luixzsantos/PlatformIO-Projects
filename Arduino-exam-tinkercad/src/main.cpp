#include <Arduino.h>

int ledverde = 13;
int ledamarelo = 12;
int ledvermelho = 11;

#define a 5000
#define b 2000
#define c 5000

void setup()
{
  pinMode(ledverde, OUTPUT);
  pinMode(ledamarelo, OUTPUT);
  pinMode(ledvermelho, OUTPUT);
}
void loop()
{
  digitalWrite(ledverde, HIGH);
  digitalWrite(ledamarelo, LOW);
  digitalWrite(ledvermelho, LOW);
  delay(a);
  digitalWrite(ledverde, LOW);
  digitalWrite(ledamarelo, HIGH);
  digitalWrite(ledvermelho, LOW);
  delay(b);
  digitalWrite(ledverde, LOW);
  digitalWrite(ledamarelo, LOW);
  digitalWrite(ledvermelho, HIGH);
  delay(c);
}
