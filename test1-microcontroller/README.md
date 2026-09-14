# 🔐 Simulação de Bomba com Arduino

Projeto acadêmico desenvolvido com **Arduino Uno** para demonstrar conceitos de **microcontroladores, entrada de dados, saída de sinais, temporização e controle de estados**.

> ⚠️ **Importante:** este projeto é exclusivamente uma simulação acadêmica. Não possui qualquer mecanismo relacionado a explosivos reais.

---

## 📌 Sobre o projeto

O sistema simula o funcionamento de um dispositivo que pode ser **armado, desarmado ou entrar em estado de explosão simulada**.

A interação é realizada através de um **teclado matricial 4x4**, enquanto um **LCD 16x2** apresenta as informações para o usuário.

O sistema utiliza:

* 🔢 Teclado matricial 4x4
* 🖥️ LCD 16x2
* 🔊 Buzzer
* 💡 LED
* 🧠 Arduino Uno
* 💻 PlatformIO
* ⏱️ Controle de tempo com `millis()`

---

## 🎯 Objetivos

O projeto foi desenvolvido para aplicar, na prática:

* Leitura de entradas digitais;
* Controle de dispositivos de saída;
* Utilização de display LCD;
* Utilização de teclado matricial;
* Controle de estados de um sistema;
* Manipulação de strings;
* Temporização sem depender exclusivamente de `delay()`;
* Controle de buzzer e LED;
* Implementação de uma contagem regressiva;
* Organização de um projeto Arduino utilizando PlatformIO.

---

## 🧩 Componentes utilizados

| Componente  | Função                         |
| ----------- | ------------------------------ |
| Arduino Uno | Controlador principal          |
| LCD 16x2    | Exibição das informações       |
| Keypad 4x4  | Entrada da senha               |
| Buzzer      | Sinal sonoro                   |
| LED         | Sinal visual                   |
| Resistores  | Proteção/adequação do circuito |

---

## 🔌 Ligações

### LCD 16x2

O LCD utiliza a biblioteca `LiquidCrystal`.

```cpp
LiquidCrystal lcd(5, 4, 3, 2, A4, A5);
```

| LCD | Arduino |
| --- | ------- |
| RS  | D5      |
| E   | D4      |
| D4  | D3      |
| D5  | D2      |
| D6  | A4      |
| D7  | A5      |

---

### 🔊 Buzzer e LED

| Componente | Pino |
| ---------- | ---- |
| Buzzer     | D13  |
| LED        | D12  |

O LED acompanha os sinais sonoros em diversas partes do sistema.

---

### 🔢 Keypad 4x4

```cpp
byte rowPins[ROWS] = {A0, A1, 11, 10};
byte colPins[COLS] = {9, 8, 7, 6};
```

| Keypad   | Arduino |
| -------- | ------- |
| Linha 1  | A0      |
| Linha 2  | A1      |
| Linha 3  | D11     |
| Linha 4  | D10     |
| Coluna 1 | D9      |
| Coluna 2 | D8      |
| Coluna 3 | D7      |
| Coluna 4 | D6      |

---

# 🔑 Funcionamento

Ao iniciar o sistema, o LCD apresenta:

```text
 ENTER PASSWORD
```

O usuário deve inserir uma senha de **7 caracteres**.

A senha definida no projeto é:

```text
7553608
```

### Teclas

* `0–9` → Digitação da senha
* `*` → Limpa a senha digitada
* `A–D` → Podem ser utilizadas como entradas do keypad, embora não façam parte da senha configurada

Cada tecla pressionada produz um pequeno **bip** e acende o LED momentaneamente.

---

# 👁️ Proteção visual da senha

Os números digitados permanecem visíveis inicialmente.

Após aproximadamente **2 segundos**, cada caractere é substituído visualmente por:

```text
*
```

Por exemplo:

```text
7
```

Depois:

```text
*
```

Isso é controlado individualmente para cada caractere através dos vetores:

```cpp
unsigned long inputTime[7];
bool inputMasked[7];
```

O programa registra o momento em que cada número foi digitado e verifica posteriormente se já passaram 2 segundos.

A senha real continua armazenada na memória. Apenas sua **representação no LCD** é alterada.

---

# 🚨 Armamento

Quando a senha correta é digitada:

```text
7553608
```

o sistema entra no estado **ARMADO**.

O LCD começa apresentando:

```text
BOMB HAS BEEN
20s
```

Um sinal sonoro e visual é emitido para indicar que o sistema foi armado.

A partir desse momento começa uma contagem regressiva de **20 segundos**.

---

# ⏱️ Contagem regressiva

A contagem é controlada utilizando:

```cpp
millis()
```

em vez de utilizar `delay(1000)` para cada segundo.

Isso permite que o programa continue verificando o teclado enquanto a contagem acontece.

A contagem segue:

```text
20s
19s
18s
17s
...
3s
2s
1s
0s
```

---

# 🔊 Aumento da frequência dos bips

Conforme o tempo diminui, os bips ficam mais rápidos.

| Tempo restante | Intervalo aproximado |
| -------------- | -------------------: |
| 20–18 s        |               700 ms |
| 17–14 s        |               180 ms |
| 13–10 s        |               120 ms |
| 9–6 s          |                80 ms |
| 5–3 s          |                50 ms |
| 2–1 s          |                35 ms |

O LED acompanha o funcionamento do buzzer, criando um alerta visual junto com o alerta sonoro.

---

# 💬 Mensagem durante o armamento

Nos primeiros segundos, o LCD alterna entre:

```text
BOMB HAS BEEN
```

e:

```text
PLANTED
```

A mensagem é centralizada na primeira linha do LCD.

Depois de algumas alternâncias, a primeira linha fica vazia e somente a contagem permanece sendo apresentada.

---

# 🔓 Desarmamento

Mesmo depois que o sistema é armado, o teclado continua funcionando.

O usuário pode digitar novamente a senha:

```text
7553608
```

Se a senha estiver correta, a simulação é interrompida.

O LCD apresenta:

```text
BOMB HAS BEEN
DEFUSED
```

O buzzer e o LED também fornecem um sinal de confirmação.

Depois de alguns segundos, o sistema retorna ao estado inicial.

---

# ❌ Senha incorreta

## Antes do armamento

Se uma senha incorreta for digitada, o LCD apresenta:

```text
WRONG PASSWORD
```

Após aproximadamente 1,5 segundo, o sistema retorna para:

```text
ENTER PASSWORD
```

---

## Durante a contagem

Se uma senha incorreta for utilizada para tentar desarmar o sistema:

```text
WRONG PASSWORD
```

é apresentado temporariamente.

A senha digitada é então limpa e a contagem regressiva continua normalmente.

---

# 💥 Explosão simulada

Se a contagem chegar a:

```text
0s
```

o sistema entra no estado de explosão simulada.

O LCD apresenta:

```text
BOOOM!!!!!!
```

O buzzer permanece ativo e o LED fica aceso durante aproximadamente **5 segundos**.

Após esse período, o sistema é reiniciado e volta para:

```text
ENTER PASSWORD
```

---

# 🧠 Estados do sistema

A lógica principal pode ser entendida através de três estados:

```text
┌──────────────────────┐
│  AGUARDANDO SENHA    │
└──────────┬───────────┘
           │
      senha correta
           │
           ▼
┌──────────────────────┐
│       ARMADO         │
│    contagem 20s      │
└───────┬────────┬─────┘
        │        │
 senha correta   │ 0 segundos
        │        │
        ▼        ▼
┌────────────┐ ┌─────────────────┐
│  DESARMADO │ │ EXPLOSÃO        │
│  DEFUSED   │ │   SIMULADA      │
└────────────┘ └─────────────────┘
```

No código, esses estados são representados pelas variáveis:

```cpp
bool isBombArmed = false;
bool isBombBoom = false;
```

---

# 🧱 Principais funções

O código foi dividido em funções para facilitar a compreensão e manutenção.

### `keyBeep()`

Responsável pelo feedback de cada tecla pressionada.

Ativa:

* Buzzer;
* LED.

---

### `processNormalKey()`

Processa as teclas quando o sistema está aguardando a senha.

É responsável por:

* Receber os caracteres;
* Armazenar a senha digitada;
* Limpar com `*`;
* Verificar a senha;
* Armar o sistema.

---

### `processCountdownKey()`

Processa as teclas durante a contagem regressiva.

Permite que o usuário tente desarmar o sistema através da senha correta.

---

### `startBomb()`

Inicializa o estado armado:

```cpp
isBombArmed = true;
countdown = 20;
```

Também reinicia os temporizadores e apresenta a mensagem de armamento.

---

### `disarmBomb()`

Finaliza a contagem quando a senha correta é inserida durante o estado armado.

Apresenta:

```text
BOMB HAS BEEN
DEFUSED
```

---

### `updateCountdownBeep()`

Controla a velocidade dos bips conforme o tempo restante.

Quanto menor o tempo, menor é o intervalo entre os bips.

---

### `updatePasswordMask()`

Verifica quanto tempo cada caractere foi digitado.

Após 2 segundos, altera sua exibição para `*`.

---

### `updateBombMessage()`

Controla a alternância entre:

```text
BOMB HAS BEEN
```

e:

```text
PLANTED
```

---

### `updateLCD()`

Centraliza a atualização das informações apresentadas no LCD.

---

### `explodeBomb()`

Executa a explosão **simulada** quando a contagem chega a zero.

---

### `resetSystem()`

Retorna todo o sistema para o estado inicial.

---

# 🛠️ Tecnologias e bibliotecas

O projeto foi desenvolvido em **C++ para Arduino**, utilizando PlatformIO.

Bibliotecas utilizadas:

```cpp
#include <Arduino.h>
#include <Keypad.h>
#include <LiquidCrystal.h>
```

### PlatformIO

Configuração utilizada:

```ini
[env:uno]
platform = atmelavr
board = uno
framework = arduino

lib_deps =
    Keypad
    LiquidCrystal
```

---

# 📁 Estrutura do projeto

```text
provamicrocontroladorbomba/
│
├── .gitignore
├── platformio.ini
│
└── src/
    └── main.cpp
```

### `platformio.ini`

Define:

* Placa utilizada;
* Plataforma;
* Framework;
* Bibliotecas.

### `src/main.cpp`

Contém toda a lógica do sistema.

### `.gitignore`

Evita que arquivos temporários e arquivos gerados pelo PlatformIO sejam enviados ao GitHub.

---

# ▶️ Como executar

### 1. Instalar o PlatformIO

Instale o PlatformIO no VS Code.

### 2. Abrir o projeto

Abra a pasta do projeto no VS Code.

### 3. Compilar

No PlatformIO, utilize:

```text
Build
```

ou execute:

```bash
pio run
```

### 4. Montar o circuito

Conecte os componentes seguindo a tabela de ligações apresentada neste README.

### 5. Fazer o upload

Com o Arduino conectado ao computador, utilize:

```text
Upload
```

ou:

```bash
pio run --target upload
```

---

# 📚 Conceitos aplicados

Este projeto permite estudar na prática:

* Microcontroladores;
* Programação em C++;
* GPIO;
* Entrada e saída digital;
* Teclado matricial;
* Displays LCD;
* Sinais sonoros;
* Sinais luminosos;
* Arrays;
* Strings;
* Funções;
* Variáveis booleanas;
* Controle de estados;
* Temporização;
* `millis()`;
* Bibliotecas Arduino;
* Organização de projetos com PlatformIO.

---

# 🎓 Objetivo acadêmico

O principal objetivo do projeto é demonstrar como um microcontrolador pode receber informações de um usuário, processar essas informações e controlar diferentes dispositivos de saída de acordo com as condições programadas.

Apesar da temática de "bomba", o projeto representa apenas uma **simulação lógica e visual**, sendo utilizado como recurso didático para demonstrar conceitos de programação e sistemas embarcados.

---

## 👨‍💻 Projeto

Desenvolvido por **Luiz Fernando Araujo Santos**.

Projeto acadêmico — **Engenharia Elétrica / Sistemas Embarcados**.
