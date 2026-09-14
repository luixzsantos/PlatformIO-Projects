/*
  JOGO DE REFLEXO COM ARDUINO UNO
  --------------------------------
  Um LED (dentre 3) acende em um momento aleatório.
  O jogador deve pressionar o botão correspondente o mais rápido possível.
  O tempo de reação é calculado com millis() e mostrado no Monitor Serial.
*/

// ---------- Configuração dos pinos ----------
const int NUM_JOGADORES = 3;

const int pinosLED[NUM_JOGADORES]   = {2, 3, 4};   // vermelho, verde, azul
const int pinosBotao[NUM_JOGADORES] = {8, 9, 10};  // vermelho, verde, azul

const char* nomesCores[NUM_JOGADORES] = {"VERMELHO", "VERDE", "AZUL"};

// ---------- Variáveis do jogo ----------
unsigned long tempoLedAceso = 0;
unsigned long tempoBotaoPressionado = 0;
int ledEscolhido = -1;

// ---------- Configuração inicial ----------
void setup() {
  Serial.begin(9600);

  for (int i = 0; i < NUM_JOGADORES; i++) {
    pinMode(pinosLED[i], OUTPUT);
    digitalWrite(pinosLED[i], LOW);
    pinMode(pinosBotao[i], INPUT_PULLUP);
  }

  randomSeed(analogRead(A0)); // gera sementes diferentes a cada execução
  // OBS: o pino A0 precisa estar livre (sem nada conectado) para essa linha funcionar bem.
  // Se você já estiver usando A0 para outro componente, troque para outro pino analógico livre (ex: A1, A2...).

  Serial.println("===================");
  Serial.println("   REFLEX GAME  ");
  Serial.println("===================");
  Serial.println("Prepare-se...");
}

// ---------- Loop principal ----------
void loop() {
  iniciarRodada();
  aguardarResposta();
  delay(2000); // pequena pausa antes da próxima rodada
}

// ---------- Funções do jogo ----------

void iniciarRodada() {
  // Garante que todos os LEDs estão apagados
  for (int i = 0; i < NUM_JOGADORES; i++) {
    digitalWrite(pinosLED[i], LOW);
  }

  // Espera um tempo aleatório entre 1 e 5 segundos
  long espera = random(1000, 5000);
  delay(espera);

  // Escolhe aleatoriamente qual LED será aceso
  ledEscolhido = random(0, NUM_JOGADORES);

  // Acende o LED e registra o tempo
  digitalWrite(pinosLED[ledEscolhido], HIGH);
  tempoLedAceso = millis();

  Serial.println();
  Serial.print("LED ");
  Serial.print(nomesCores[ledEscolhido]);
  Serial.println(" aceso! Aperte o botão correspondente!");
}

void aguardarResposta() {
  bool respondeu = false;

  while (!respondeu) {
    for (int i = 0; i < NUM_JOGADORES; i++) {
      // Botão pressionado = LOW, por causa do INPUT_PULLUP
      if (digitalRead(pinosBotao[i]) == LOW) {

        // --- Debounce simples ---
        // Espera 20ms e confirma se o botão continua pressionado.
        // Isso evita leituras falsas causadas pelo "chacoalhar" mecânico do botão.
        delay(20);
        if (digitalRead(pinosBotao[i]) == LOW) {
          tempoBotaoPressionado = millis();
          processarResposta(i);
          respondeu = true;
          break;
        }
      }
    }
  }
}

void processarResposta(int botaoPressionado) {
  digitalWrite(pinosLED[ledEscolhido], LOW);

  unsigned long tempoReacao = tempoBotaoPressionado - tempoLedAceso;

  if (botaoPressionado == ledEscolhido) {
    Serial.print("Correto! Tempo de reação: ");
    Serial.print(tempoReacao);
    Serial.println(" ms");
  } else {
    Serial.print("Errado! Você apertou o botão ");
    Serial.print(nomesCores[botaoPressionado]);
    Serial.print(" mas o LED era ");
    Serial.println(nomesCores[ledEscolhido]);
  }

  Serial.println("Nova rodada em instantes...");
}