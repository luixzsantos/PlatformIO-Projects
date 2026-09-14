# Analog Reader

Projeto simples desenvolvido com **Arduino Uno** e **PlatformIO** para realizar a leitura de um sinal analógico através da entrada **A0** e exibir o valor no **Monitor Serial**.

## 🛠️ Tecnologias

* Arduino Uno
* C/C++
* PlatformIO
* Arduino Framework

## 📖 Sobre o projeto

O projeto utiliza a função `analogRead()` para ler o valor recebido pela entrada analógica `A0`.

No Arduino Uno, a leitura possui resolução de **10 bits**, produzindo valores entre:

```text
0 - 1023
```

O valor é enviado pela comunicação serial a cada **1 segundo**.

## 💻 Código

```cpp
#include <Arduino.h>

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int analog = analogRead(A0);
  Serial.println(analog);
  delay(1000);
}
```

## 🔌 Funcionamento

O programa realiza as seguintes etapas:

1. Configura o pino `A0` como entrada.
2. Inicia a comunicação Serial em **9600 baud**.
3. Lê o valor analógico de `A0`.
4. Envia o valor para o Monitor Serial.
5. Aguarda 1 segundo.
6. Repete o processo.

## 📊 Exemplo

Se um potenciômetro ou sensor estiver conectado ao `A0`, o Monitor Serial poderá apresentar valores como:

```text
0
128
356
512
789
1023
```

O valor varia de acordo com a tensão aplicada à entrada analógica.

## 🚀 Como usar

1. Conecte o Arduino Uno ao computador.
2. Abra o projeto no **Visual Studio Code + PlatformIO**.
3. Faça o upload do código para o Arduino.
4. Abra o **Serial Monitor**.
5. Configure a velocidade para **9600 baud**.
6. Observe os valores enviados pelo Arduino.

## 🔧 Exemplo com potenciômetro

Um potenciômetro pode ser conectado da seguinte forma:

```text
Potenciômetro
├── VCC → 5V
├── GND → GND
└── Pino central → A0
```

Ao girar o potenciômetro, o valor exibido no Monitor Serial deverá variar entre aproximadamente **0 e 1023**.

## 📌 Objetivo

Este projeto serve como uma introdução à leitura de **entradas analógicas** no Arduino e pode ser utilizado como base para projetos com sensores, potenciômetros e outros dispositivos analógicos.

## 👤 Autor

**Luiz Santos**
