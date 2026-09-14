#include <Arduino.h>

#define LED_VD 8
#define LED_VM 7

#define SW_D 3
#define SW_E 2

int ledselecionado;

void setup()
{
  pinMode(SW_D, OUTPUT);
  pinMode(LED_VD, OUTPUT);
  pinMode(SW_D, INPUT);
  pinMode(SW_E, INPUT);
}

void loop()
{
  if (digitalRead(SW_D) == 1)
  {
    ledselecionado = LED_VD;
  }
  if (digitalRead(SW_E) == 1)
  {
    ledselecionado = LED_VM;
  }
  digitalWrite(ledselecionado, HIGH);
  delay(500);
  digitalWrite(ledselecionado, LOW);
  delay(500);
}
