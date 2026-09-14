# 🚦 Sinaleira LED com Arduino — LED Vermelho e Branco

## 📌 Sobre o projeto

Este projeto apresenta a montagem de uma **sinaleira utilizando Arduino e dois LEDs**, sendo um **LED vermelho** e um **LED branco**.

O objetivo é demonstrar, de forma simples, como o Arduino pode controlar diferentes LEDs em uma sequência programada, utilizando portas digitais.

## 🧰 Materiais utilizados

* 1x Arduino Uno
* 1x LED vermelho
* 1x LED branco
* 2x resistores de 220 Ω
* Jumpers
* Protoboard
* Cabo USB

## 🔌 Funcionamento

O Arduino controla os dois LEDs por meio de suas portas digitais.

A sequência do teste é:

1. O **LED vermelho** acende.
2. Após alguns segundos, o LED vermelho apaga.
3. O **LED branco** acende.
4. Após alguns segundos, o LED branco apaga.
5. O ciclo é repetido continuamente.

Esse projeto pode ser utilizado como uma atividade introdutória para aprender **saídas digitais, LEDs, resistores e programação básica em Arduino**.

## 💻 Código

```cpp
const int ledVermelho = 8;
const int ledBranco = 9;

void setup() {
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledBranco, OUTPUT);
}

void loop() {
  // Acende o LED vermelho
  digitalWrite(ledVermelho, HIGH);
  digitalWrite(ledBranco, LOW);
  delay(3000);

  // Apaga o vermelho e acende o branco
  digitalWrite(ledVermelho, LOW);
  digitalWrite(ledBranco, HIGH);
  delay(3000);
}
```

## 🔧 Montagem

O LED vermelho deve ser conectado à **porta digital 8** do Arduino, utilizando um resistor de 220 Ω.

O LED branco deve ser conectado à **porta digital 9**, também utilizando um resistor de 220 Ω.

Os terminais negativos dos LEDs devem ser conectados ao **GND (terra)** do Arduino.

### Esquema simplificado

```text
Arduino                LED

Pino 8  ──[220 Ω]──► LED Vermelho ──► GND
Pino 9  ──[220 Ω]──► LED Branco   ──► GND
```

## 🧪 Teste

Ao conectar o Arduino ao computador e enviar o código, o sistema deverá iniciar automaticamente.

O **LED vermelho permanecerá aceso por 3 segundos** e depois será substituído pelo **LED branco por mais 3 segundos**. Esse processo continuará se repetindo enquanto o Arduino estiver ligado.

## 🎯 Objetivo

O projeto tem como finalidade demonstrar o controle de LEDs por meio de um Arduino, servindo como exemplo básico para projetos de **sinaleiras, indicadores luminosos e sistemas de sinalização eletrônica**.

## 📚 Tecnologias

* Arduino
* C/C++
* Eletrônica básica
* LEDs
* Protoboard

## 👨‍💻 Autor

Projeto desenvolvido para fins de estudo e aprendizado com Arduino.

https://www.tinkercad.com/things/d5DATEEzk7R-sinaleira-com-led
