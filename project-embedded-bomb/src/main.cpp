#include <Arduino.h> 
 
// Chamada das bibliotecas necessárias para utilizar o teclado e o display 
#include <Keypad.h> 
#include <LiquidCrystal.h> 
 
 
LiquidCrystal lcd(5, 4, 3, 2, A4, A5); 
const int Beep = 13; 
const byte ROWS = 4; // quantidade de linhas que utilizaremos no teclado 
const byte COLS = 4; // quantidade de colunas que utilizaremos no teclado 
 
char keys[ROWS][COLS] = // símbolos do teclado 
{ 
 
  {'1','2','3','A'}, 
 
  {'4','5','6','B'}, 
 
  {'7','8','9','C'}, 
 
  {'*','0','#','D'} 
 
}; 
 
byte rowPins[ROWS] = {A0, A1, 11, 10}; // informamos ao microcontrolador quais são os pinos das linhas 
 
byte colPins[COLS] = {9, 8, 7, 6}; // informamos ao microcontrolador quais são os pinos das colunas 
 
int LCDRow = 0; // indica em qual linha estamos no display 
 
int LCDPos = 0; // indica em qual posição estamos na linha do display 
 
 
 
 
 
#define passwordLength 8 // definimos o tamanho da senha 
 
char inputText[passwordLength]; // aqui ficam os números que iremos inserir 
 
char password[passwordLength] = "7553608"; // esta é a nossa senha 
 
 
 
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); // criamos o teclado 
 
 
 
bool isBombBoom = false; // variável condicional que indica se a bomba explodiu (ideia parcialmente abandonada) 
 
 
 
// Preparamos todos os dispositivos necessários para a bomba 
void setup() 
 
{ 
 
   pinMode(Beep, OUTPUT); 
 
   Serial.begin(9600); 
 
   lcd.begin(16, 2); 
 
   lcd.setCursor(LCDRow, 0); 
 
   lcd.setCursor(0, 0); 
 
   lcd.print("Enter password  "); 
 
   lcdRestPos(); 
 
} 
 
 
 
// Método para redefinir a posição no display 
void lcdRestPos() 
{ 
 
  LCDPos = 0; 
 
  lcd.setCursor(LCDPos, 1); 
 
} 
 
 
 
// Limpa a linha do display 
void lcdClearLine() { 
 
  lcdRestPos(); 
 
  lcd.print("                "); 
 
  lcdRestPos(); 
 
} 
 
 
 
void loop() 
 
{ 
 
 char key = keypad.getKey(); // botão que foi pressionado 
 
 if (!isBombBoom && key == '*') // Se o botão pressionado for *, apaga a senha digitada 
 
  { 
 
   	lcdClearLine(); 
 
  } 
 
  else if (!isBombBoom && key) 
 
  { 
 
    if (LCDPos == 0) // Se a posição estiver no início, limpamos a linha 
 
    { 
 
      	lcdClearLine(); 
 
    } 
 
    Serial.println(key); // Exibe os símbolos digitados no Serial Monitor para teste ou diagnóstico em caso de erros no funcionamento da bomba. 
 
    inputText[LCDPos] = key; // Armazena o símbolo digitado como parte da senha que estamos inserindo. 
 
    lcd.print(key); // Exibe no display o símbolo que foi digitado 
 
    lcd.setCursor(++LCDPos, 1); // Altera a posição, avançando uma posição 
 
    if (LCDPos == 7) // Quando a posição chega ao máximo de caracteres (7 caracteres), verifica se a senha está correta 
 
    { 
 
      lcdRestPos(); 
 
      if (!strcmp(inputText, password)) // Realiza a verificação da senha caso esteja correta 
 
      { 
 
        lcdClearLine(); // Limpa a linha para o temporizador da bomba 
 
        for(int i = 20; i >= 0; i--) // Ciclo do temporizador contendo o dispositivo sonoro (Piezo) e o LED (o LED está conectado no mesmo local com o Piezo para economizar espaço) 
 //antes tinha colocado 40 
        { 
 
        	tone(Beep, 600000); 
 
        	lcd.clear(); 
 
        	lcd.print(i); 
 
            delay(300); 
 
            noTone(Beep); 
 
            delay(700); 
 
        } 
        lcd.clear(); // Exibe a explosão 
 
        lcd.print("BOOOM!!!!!!"); 
 
        tone(Beep, 600000); 
 
        delay(5000); 
 
        noTone(Beep); 
 
      } 
 
      else  // Ação realizada quando a senha estiver incorreta 
 
      { 
 
        lcd.print("Password wrong  "); 
 
      } 
 
      lcdRestPos(); // Redefine a posição 
 
    } 
 
  } 
 
} 
