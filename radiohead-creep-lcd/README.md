# Creep LCD

Projeto desenvolvido com **Arduino Uno**, **PlatformIO** e um display **LCD 16x2**.

O projeto utiliza o LCD para exibir uma sequência de mensagens com diferentes intervalos de tempo. As mensagens são apresentadas automaticamente, criando uma sequência visual no display.

## 🛠️ Tecnologias utilizadas

* Arduino Uno
* PlatformIO
* C/C++
* LCD 16x2
* Biblioteca LiquidCrystal

## 📟 Funcionamento

Ao iniciar o Arduino, o LCD é inicializado e começa a apresentar as mensagens automaticamente.

Cada mensagem possui duas linhas e permanece no display durante um determinado período antes de ser substituída pela próxima.

O funcionamento segue uma sequência programada no código:

```text
Mensagem 1
     ↓
Mensagem 2
     ↓
Mensagem 3
     ↓
Mensagem 4
     ↓
...
     ↓
Mensagem final
```

Após a última mensagem, o LCD é limpo e o programa permanece parado.

## 🔌 Ligações do LCD

O LCD 16x2 está conectado ao Arduino da seguinte forma:

| LCD | Arduino |
| --- | ------: |
| RS  |       6 |
| E   |       7 |
| D4  |       8 |
| D5  |       9 |
| D6  |      10 |
| D7  |      11 |

Além disso:

| LCD | Conexão               |
| --- | --------------------- |
| VSS | GND                   |
| VDD | 5V                    |
| RW  | GND                   |
| V0  | Controle de contraste |
| A   | 5V                    |
| K   | GND                   |

## 📁 Estrutura do projeto

```text
creep/
├── include/
├── lib/
├── src/
│   └── main.cpp
├── test/
└── platformio.ini
```

## ⚙️ Configuração do PlatformIO

O projeto utiliza Arduino Uno e a biblioteca `LiquidCrystal`.

O arquivo `platformio.ini` contém:

```ini
[env:uno]
platform = atmelavr
board = uno
framework = arduino
lib_deps =
    arduino-libraries/LiquidCrystal
```

## 🚀 Como executar

1. Abra o projeto no **Visual Studio Code**.
2. Instale a extensão **PlatformIO IDE**.
3. Conecte o Arduino Uno ao computador.
4. Abra o projeto.
5. Acesse **PlatformIO → Project Tasks → uno**.
6. Clique em **Build** para compilar.
7. Clique em **Upload** para enviar o programa ao Arduino.

## 🎯 Objetivo

O objetivo do projeto é praticar:

* Programação em C++;
* Utilização de Arduino;
* Controle de displays LCD;
* Uso da biblioteca `LiquidCrystal`;
* Desenvolvimento de projetos com PlatformIO;
* Controle de tempo utilizando `delay()`.

## 👨‍💻 Autor

**Luiz Fernando Araujo Santos**

Projeto desenvolvido para fins de estudo e aprendizado com Arduino e PlatformIO.

https://www.tinkercad.com/things/0zEitVGAzZ6-lcd-display-basic-creep
