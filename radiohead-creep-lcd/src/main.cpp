#include <Arduino.h>

#include <LiquidCrystal.h>

// RS  E  D4 D5 D6 D7
LiquidCrystal lcd(6, 7, 8, 9, 10, 11);

void mostrar(const char *linha1, const char *linha2, int tempo)
{
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print(linha1);

  lcd.setCursor(0, 1);
  lcd.print(linha2);

  delay(tempo);
}

void setup()
{
  lcd.begin(16, 2);

  lcd.clear();
  delay(1900);

  mostrar("When you were", "here before", 2500);
  mostrar("Couldn't look", "you in the eye", 2500);
  mostrar("You're just like", "an angel", 2500);
  mostrar("Your skin makes", "me cry", 3000);

  mostrar("You float like", "a feather", 2500);
  mostrar("In a beautiful", "world", 2700);
  mostrar("I wish I was", "special", 2000);
  mostrar("You're so", "fuckin' special", 3000);

  mostrar("But I'm a creep", "", 2500);
  mostrar("I'm a weirdo", "", 3000);
  mostrar("What the hell", "am I doin' here?", 3200);
  mostrar("I don't belong", "here", 2200);
  mostrar("Oh-oh", "", 2200);
  mostrar("Oh-oh", "", 2200);

  mostrar("She's runnin'", "out the door", 2500);
  mostrar("She's runnin'", "out", 1800);
  mostrar("She run, run,", "run, run", 1800);
  mostrar("Ruuuuuuuuuuuuuun", "", 5000);

  lcd.clear();
}

void loop()
{
}
