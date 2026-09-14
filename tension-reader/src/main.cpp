#include <Arduino.h>

#include <LiquidCrystal.h>

// RS  E  D4 D5 D6 D7
LiquidCrystal lcd(6, 7, 8, 9, 10, 11);

void setup()
{
  pinMode(A0, INPUT);

  lcd.begin(16,2);

  lcd.print("nao sei");

  delay(2000);

  lcd.clear();
}

void loop()
{
  int analog = analogRead(A0);

  float tensao = analog / 1023.0 * 5.0;

  lcd.clear();
  lcd.print(analog);
  lcd.setCursor(0,1);
  lcd.print(tensao);

  delay(1000);
}
