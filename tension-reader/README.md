# Tension Reader

Projeto desenvolvido com **Arduino Uno** para realizar a leitura de uma tensão analógica através da entrada **A0** e exibir os valores em um **LCD 16x2**.

O projeto utiliza a leitura analógica do Arduino para calcular uma tensão aproximada entre **0 V e 5 V**.

## 🛠️ Tecnologias

* Arduino Uno
* LCD 16x2
* C/C++
* PlatformIO
* Arduino Framework
* Biblioteca `LiquidCrystal`

## 📖 Sobre o projeto

O Arduino realiza uma leitura analógica utilizando o pino `A0`.

O conversor analógico-digital do Arduino Uno possui **10 bits**, portanto a função `analogRead()` retorna valores entre:

```text
0 - 1023
```

A tensão é calculada utilizando:

```text
tensão = leitura / 1023 × 5
```

O valor da leitura e a tensão calculada são exibidos no LCD.

## 🔌 Conexão do LCD

O LCD 16x2 utiliza os seguintes pinos:

| LCD | Arduino Uno |
| --- | ----------: |
| RS  |           6 |
| E   |           7 |
| D4  |           8 |
| D5  |           9 |
| D6  |          10 |
| D7  |          11 |

A entrada analógica utilizada para a medição é:

```text
A0
```

## 💻 Código

```cpp
#include <Arduino.h>
#include <LiquidCrystal.h>

// RS  E  D4 D5 D6 D7
LiquidCrystal lcd(6, 7, 8, 9, 10, 11);

void setup()
{
  pinMode(A0, INPUT);

  lcd.begin(16, 2);

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

  lcd.setCursor(0, 1);
  lcd.print(tensao);

  delay(1000);
}
```

## 📊 Exemplo de funcionamento

Se a entrada `A0` receber aproximadamente metade da tensão de referência, o Arduino poderá realizar uma leitura próxima de:

```text
512
```

E calcular aproximadamente:

```text
2.50 V
```

No LCD:

```text
512
2.50
```

## ⚙️ Configuração do PlatformIO

O projeto pode utilizar:

```ini
[env:uno]
platform = atmelavr
board = uno
framework = arduino
```

## 🚀 Como executar

1. Conecte o LCD 16x2 ao Arduino Uno conforme a tabela acima.
2. Conecte o sinal que deseja medir à entrada `A0`.
3. Abra o projeto no **Visual Studio Code + PlatformIO**.
4. Compile o projeto.
5. Faça o upload para o Arduino Uno.
6. Observe a leitura e a tensão no LCD.

## ⚠️ Atenção

A entrada analógica do Arduino Uno não deve receber uma tensão superior à tensão máxima permitida pela placa, normalmente **5 V** quando a referência padrão é utilizada.

Não conecte diretamente tensões desconhecidas ou superiores ao limite da entrada `A0`, pois isso pode danificar o Arduino.

Além disso, o cálculo assume uma referência de **5 V**. Na prática, a tensão real de referência pode variar, então a medição é uma **estimativa**.

## 📌 Objetivo

Este projeto foi desenvolvido para praticar:

* Leitura analógica com `analogRead()`
* Conversão de uma leitura ADC para tensão
* Utilização de LCD 16x2
* Controle de cursor no LCD
* Desenvolvimento de projetos Arduino com PlatformIO

## 👤 Autor

**Luiz Fernando Araujo Santos**

https://www.tinkercad.com/things/aEN2V6VphPx-tensao-valor/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard%2Fdesigns%2Fcircuits
