#include <Arduino.h>

#include <Keypad.h>
#include <LiquidCrystal.h>

// ==========================================
// LCD
// ==========================================

LiquidCrystal lcd(5, 4, 3, 2, A4, A5);

// ==========================================
// BUZZER E LED
// ==========================================

const int Beep = 13;
const int LED = 12;

// ==========================================
// KEYPAD 4x4
// ==========================================

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] =
    {
        {'1', '2', '3', 'A'},
        {'4', '5', '6', 'B'},
        {'7', '8', '9', 'C'},
        {'*', '0', '#', 'D'}};

byte rowPins[ROWS] = {A0, A1, 11, 10};
byte colPins[COLS] = {9, 8, 7, 6};

Keypad keypad = Keypad(
    makeKeymap(keys),
    rowPins,
    colPins,
    ROWS,
    COLS);

// ==========================================
// SENHA
// ==========================================

#define passwordLength 8

char inputText[passwordLength];
char password[passwordLength] = "7553608";

int LCDPos = 0;

// Guarda quando cada número foi digitado
unsigned long inputTime[7];

// Controla quais números já viraram *
bool inputMasked[7];

// ==========================================
// ESTADO DO SISTEMA
// ==========================================

bool isBombArmed = false;
bool isBombBoom = false;

// ==========================================
// CONTAGEM REGRESSIVA
// ==========================================

int countdown = 20;

unsigned long previousMillis = 0;

const unsigned long countdownInterval = 1000;

// ==========================================
// MENSAGEM DA BOMBA
// ==========================================

unsigned long previousMessageMillis = 0;

bool showBombHasBeen = true;

int messageCount = 0;

const unsigned long messageInterval = 1000;

// ==========================================
// CONTROLE DOS BIPS
// ==========================================

unsigned long previousBeepMillis = 0;

bool beepState = false;

// ==========================================
// PISCADA DO LCD
// ==========================================

unsigned long previousBlinkMillis = 0;

bool lcdVisible = true;

const unsigned long blinkInterval = 250;

// ==========================================
// PROTÓTIPOS
// ==========================================

void lcdPrintCentered(String text, int row);

void updateLCD();
void updatePasswordMask();
void updateBombMessage();
void updateCountdownBeep();

void keyBeep();

void startBomb();
void disarmBomb();
void explodeBomb();
void resetSystem();

void processNormalKey(char key);
void processCountdownKey(char key);

// ==========================================
// SETUP
// ==========================================

void setup()
{
  pinMode(Beep, OUTPUT);
  pinMode(LED, OUTPUT);

  digitalWrite(LED, LOW);

  Serial.begin(9600);

  lcd.begin(16, 2);

  lcdPrintCentered("ENTER PASSWORD", 0);

  lcd.setCursor(0, 1);
  lcd.print("                ");
}

// ==========================================
// TEXTO CENTRALIZADO
// ==========================================

void lcdPrintCentered(String text, int row)
{
  lcd.setCursor(0, row);

  lcd.print("                ");

  int position = (16 - text.length()) / 2;

  if (position < 0)
  {
    position = 0;
  }

  lcd.setCursor(position, row);

  lcd.print(text);
}

// ==========================================
// BIP DA TECLA
// ==========================================

void keyBeep()
{
  digitalWrite(LED, HIGH);

  tone(Beep, 1000);

  delay(50);

  noTone(Beep);

  digitalWrite(LED, LOW);
}

// ==========================================
// LOOP PRINCIPAL
// ==========================================

void loop()
{
  char key = keypad.getKey();

  // ======================================
  // SISTEMA AGUARDANDO SENHA
  // ======================================

  if (!isBombArmed && !isBombBoom)
  {
    if (key)
    {
      processNormalKey(key);
    }

    // Verifica se algum número precisa virar *
    updatePasswordMask();

    return;
  }

  // ======================================
  // SISTEMA ARMADO
  // ======================================

  if (isBombArmed && !isBombBoom)
  {
    if (key)
    {
      processCountdownKey(key);
    }

    // Verifica senha visual
    updatePasswordMask();

    // Atualiza mensagem
    updateBombMessage();

    // Atualiza bips
    updateCountdownBeep();

    // ==================================
    // CONTROLE DA CONTAGEM
    // ==================================

    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= countdownInterval)
    {
      previousMillis += countdownInterval;

      countdown--;

      Serial.print("Contagem: ");
      Serial.println(countdown);

      // Atualiza o LCD somente quando
      // o segundo realmente mudou
      if (countdown > 5)
      {
        updateLCD();
      }

      // Ativa o efeito de piscar
      // quando chegar em 5 segundos
      if (countdown <= 5)
      {
        previousBlinkMillis = millis();

        lcdVisible = true;

        lcd.clear();
      }

      // Chegou em zero
      if (countdown <= 0)
      {
        explodeBomb();

        return;
      }
    }

    // ==================================
    // PISCADA SOMENTE NOS 5 SEGUNDOS
    // ==================================

    if (countdown <= 5)
    {
      currentMillis = millis();

      if (currentMillis - previousBlinkMillis >= blinkInterval)
      {
        previousBlinkMillis += blinkInterval;

        lcdVisible = !lcdVisible;

        if (lcdVisible)
        {
          updateLCD();
        }
        else
        {
          lcd.clear();
        }
      }
    }
  }
}

// ==========================================
// CONTROLE DOS * DA SENHA
// ==========================================

void updatePasswordMask()
{
  if (LCDPos <= 0)
  {
    return;
  }

  unsigned long currentMillis = millis();

  bool changed = false;

  for (int i = 0; i < LCDPos; i++)
  {
    // Depois de 2 segundos,
    // transforma visualmente o número em *
    if (!inputMasked[i] &&
        currentMillis - inputTime[i] >= 2000)
    {
      inputMasked[i] = true;

      changed = true;
    }
  }

  // Só atualiza o LCD se algo realmente mudou
  if (changed)
  {
    updateLCD();
  }
}

// ==========================================
// MENSAGEM BOMB HAS BEEN / PLANTED
// ==========================================

void updateBombMessage()
{
  // Depois de 4 trocas,
  // a mensagem desaparece
  if (messageCount >= 4)
  {
    return;
  }

  unsigned long currentMillis = millis();

  if (currentMillis - previousMessageMillis >= messageInterval)
  {
    previousMessageMillis += messageInterval;

    messageCount++;

    showBombHasBeen = !showBombHasBeen;

    if (showBombHasBeen)
    {
      lcdPrintCentered("BOMB HAS BEEN", 0);
    }
    else
    {
      lcdPrintCentered("PLANTED", 0);
    }

    // Depois da quarta troca,
    // apaga a primeira linha
    if (messageCount >= 4)
    {
      lcdPrintCentered("", 0);
    }
  }
}

// ==========================================
// ATUALIZA LCD
// ==========================================

void updateLCD()
{
  // Se o LCD estiver apagado durante
  // o efeito de piscar, não escreve nada
  if (isBombArmed && countdown <= 5 && !lcdVisible)
  {
    return;
  }

  // ======================================
  // PRIMEIRA LINHA
  // ======================================

  if (isBombArmed)
  {
    if (messageCount < 4)
    {
      if (showBombHasBeen)
      {
        lcdPrintCentered("BOMB HAS BEEN", 0);
      }
      else
      {
        lcdPrintCentered("PLANTED", 0);
      }
    }
    else
    {
      lcdPrintCentered("", 0);
    }
  }

  // ======================================
  // SEGUNDA LINHA
  // ======================================

  lcd.setCursor(0, 1);

  lcd.print("                ");

  lcd.setCursor(0, 1);

  // ======================================
  // BOMBA ARMADA
  // ======================================

  if (isBombArmed)
  {
    // Contagem começa pela esquerda
    lcd.print(countdown);
    lcd.print("s");

    // Espaço entre contagem e senha
    if (LCDPos > 0)
    {
      lcd.print(" ");
    }

    // Mostra a senha
    for (int i = 0; i < LCDPos; i++)
    {
      if (inputMasked[i])
      {
        lcd.print("*");
      }
      else
      {
        lcd.print(inputText[i]);
      }
    }
  }

  // ======================================
  // SISTEMA AGUARDANDO SENHA
  // ======================================

  else
  {
    for (int i = 0; i < LCDPos; i++)
    {
      if (inputMasked[i])
      {
        lcd.print("*");
      }
      else
      {
        lcd.print(inputText[i]);
      }
    }
  }
}

// ==========================================
// PROCESSA SENHA PARA ARMAR
// ==========================================

void processNormalKey(char key)
{
  // Limpa senha
  if (key == '*')
  {
    keyBeep();

    LCDPos = 0;

    for (int i = 0; i < 7; i++)
    {
      inputMasked[i] = false;
    }

    lcd.setCursor(0, 1);
    lcd.print("                ");

    return;
  }

  keyBeep();

  // Adiciona número
  if (LCDPos < 7)
  {
    inputText[LCDPos] = key;

    inputTime[LCDPos] = millis();

    inputMasked[LCDPos] = false;

    LCDPos++;

    Serial.println(key);

    updateLCD();
  }

  // Verifica senha
  if (LCDPos == 7)
  {
    inputText[7] = '\0';

    if (!strcmp(inputText, password))
    {
      startBomb();
    }
    else
    {
      lcdPrintCentered("WRONG PASSWORD", 0);

      lcd.setCursor(0, 1);
      lcd.print("                ");

      delay(1500);

      resetSystem();
    }
  }
}

// ==========================================
// PROCESSA SENHA PARA DESARMAR
// ==========================================

void processCountdownKey(char key)
{
  // Limpa senha
  if (key == '*')
  {
    keyBeep();

    LCDPos = 0;

    for (int i = 0; i < 7; i++)
    {
      inputMasked[i] = false;
    }

    updateLCD();

    return;
  }

  keyBeep();

  // Adiciona número
  if (LCDPos < 7)
  {
    inputText[LCDPos] = key;

    inputTime[LCDPos] = millis();

    inputMasked[LCDPos] = false;

    LCDPos++;

    Serial.println(key);

    updateLCD();
  }

  // Verifica senha
  if (LCDPos == 7)
  {
    inputText[7] = '\0';

    if (!strcmp(inputText, password))
    {
      disarmBomb();
    }
    else
    {
      lcdPrintCentered("WRONG PASSWORD", 0);

      delay(500);

      LCDPos = 0;

      for (int i = 0; i < 7; i++)
      {
        inputMasked[i] = false;
      }

      updateLCD();
    }
  }
}

// ==========================================
// ARMA A BOMBA
// ==========================================

void startBomb()
{
  isBombArmed = true;

  countdown = 20;

  LCDPos = 0;

  previousMillis = millis();

  previousBeepMillis = millis();

  previousMessageMillis = millis();

  beepState = false;

  showBombHasBeen = true;

  messageCount = 0;

  lcdVisible = true;

  for (int i = 0; i < 7; i++)
  {
    inputMasked[i] = false;
    inputTime[i] = 0;
  }

  lcd.clear();

  // Primeira linha
  lcdPrintCentered("BOMB HAS BEEN", 0);

  // Segunda linha
  lcd.setCursor(0, 1);
  lcd.print("20s");

  // Bip de confirmação
  tone(Beep, 600);

  digitalWrite(LED, HIGH);

  delay(200);

  noTone(Beep);

  digitalWrite(LED, LOW);
}

// ==========================================
// DESARMA A BOMBA
// ==========================================

void disarmBomb()
{
  isBombArmed = false;

  LCDPos = 0;

  noTone(Beep);

  digitalWrite(LED, LOW);

  lcd.clear();

  // Primeira linha
  lcdPrintCentered("BOMB HAS BEEN", 0);

  // Segunda linha
  lcdPrintCentered("DEFUSED", 1);

  // Bip de confirmação
  tone(Beep, 1000);

  digitalWrite(LED, HIGH);

  delay(300);

  noTone(Beep);

  digitalWrite(LED, LOW);

  delay(2000);

  resetSystem();
}

// ==========================================
// VELOCIDADE DOS BIPS
// ==========================================

void updateCountdownBeep()
{
  unsigned long currentMillis = millis();

  int beepInterval;

  // 20 até 18 segundos
  if (countdown >= 18)
  {
    beepInterval = 700;
  }

  // 17 até 14 segundos
  else if (countdown >= 14)
  {
    beepInterval = 180;
  }

  // 13 até 10 segundos
  else if (countdown >= 10)
  {
    beepInterval = 120;
  }

  // 9 até 6 segundos
  else if (countdown >= 6)
  {
    beepInterval = 80;
  }

  // 5 até 3 segundos
  else if (countdown >= 3)
  {
    beepInterval = 50;
  }

  // 2 e 1 segundos
  else
  {
    beepInterval = 35;
  }

  // Controla buzzer e LED
  if (currentMillis - previousBeepMillis >= beepInterval)
  {
    previousBeepMillis += beepInterval;

    beepState = !beepState;

    if (beepState)
    {
      tone(Beep, 1000);

      digitalWrite(LED, HIGH);
    }
    else
    {
      noTone(Beep);

      digitalWrite(LED, LOW);
    }
  }
}

// ==========================================
// EXPLOSÃO
// ==========================================

void explodeBomb()
{
  isBombArmed = false;

  isBombBoom = true;

  noTone(Beep);

  digitalWrite(LED, LOW);

  lcd.clear();

  // Primeira linha
  lcdPrintCentered("BOOOM!!!!!!", 0);

  // Segunda linha
  lcdPrintCentered("", 1);

  // Buzzer e LED por 5 segundos
  tone(Beep, 600);

  digitalWrite(LED, HIGH);

  delay(5000);

  noTone(Beep);

  digitalWrite(LED, LOW);

  // Volta ao início
  resetSystem();
}

// ==========================================
// VOLTA AO INÍCIO
// ==========================================

void resetSystem()
{
  isBombArmed = false;

  isBombBoom = false;

  countdown = 20;

  LCDPos = 0;

  previousMillis = millis();

  previousBeepMillis = millis();

  previousMessageMillis = millis();

  previousBlinkMillis = millis();

  beepState = false;

  showBombHasBeen = true;

  messageCount = 0;

  lcdVisible = true;

  for (int i = 0; i < 7; i++)
  {
    inputMasked[i] = false;
    inputTime[i] = 0;
  }

  noTone(Beep);

  digitalWrite(LED, LOW);

  lcd.clear();

  // Primeira linha
  lcdPrintCentered("ENTER PASSWORD", 0);

  // Segunda linha
  lcd.setCursor(0, 1);
  lcd.print("                ");
}
