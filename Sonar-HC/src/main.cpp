#define TRIGGER_PIN 2
#define ECHO_PIN 3
#define LED_PIN 5

void setup()
{
  Serial.begin(9600);

  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{

  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  long duracao = pulseIn(ECHO_PIN, HIGH);

  int cm = duracao * 0.034 / 2;

  cm = constrain(cm, 2, 350);

  int luz = map(cm, 4, 350, 255, 0);

  analogWrite(LED_PIN, luz);

  Serial.print("Distancia: ");
  Serial.print(cm);
  Serial.println(" cm");

  Serial.print("Brilho: ");
  Serial.println(luz);

  delay(100);
}
