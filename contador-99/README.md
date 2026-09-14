# 🔢 Contador 99

Um contador digital desenvolvido com **PlatformIO**, capaz de realizar contagens de **0 a 99** utilizando um microcontrolador e display de dois dígitos.

## 📋 Sobre o projeto

O **Contador 99** é um projeto eletrônico desenvolvido para demonstrar conceitos básicos de programação embarcada, controle de displays e utilização de entradas e saídas digitais.

O contador permite incrementar os valores de **0 até 99**, podendo ser utilizado como base para projetos de contadores, temporizadores, placares e outros sistemas embarcados.

## ⚙️ Funcionalidades

* 🔢 Contagem de 0 a 99
* ⬆️ Incremento do contador
* 🔄 Retorno ao início após atingir 99
* 💡 Controle de display de dois dígitos
* ⚡ Desenvolvimento utilizando PlatformIO
* 🧩 Estrutura simples e fácil de modificar

## 🛠️ Tecnologias utilizadas

* **C/C++**
* **PlatformIO**
* **Microcontrolador**
* **Display de 7 segmentos**
* Componentes eletrônicos e GPIOs

## 📁 Estrutura do projeto

```text
contador-99/
├── include/
├── lib/
├── src/
│   └── main.cpp
├── test/
├── platformio.ini
└── README.md
```

## 🚀 Como executar

### 1. Clone o repositório

```bash
git clone https://github.com/luixzsantos/contador-99.git
```

### 2. Abra o projeto

Abra a pasta `contador-99` no **Visual Studio Code** com a extensão **PlatformIO** instalada.

### 3. Compile o projeto

No terminal do PlatformIO:

```bash
pio run
```

### 4. Envie para o microcontrolador

Conecte a placa ao computador e execute:

```bash
pio run --target upload
```

## 🔌 Funcionamento

O sistema mantém o valor atual do contador e atualiza o display conforme a contagem.

A sequência funciona da seguinte forma:

```text
00 → 01 → 02 → 03 → ... → 98 → 99 → 00
```

A lógica pode ser adaptada para utilizar botões, sensores ou outros dispositivos como entrada para controlar a contagem.

## 🎯 Objetivo

Este projeto tem como objetivo servir como exemplo de **programação para sistemas embarcados**, trabalhando conceitos como:

* Entradas e saídas digitais;
* Controle de displays;
* Variáveis e estruturas de repetição;
* Lógica de contagem;
* Desenvolvimento com PlatformIO.

## 📌 Possíveis melhorias

Algumas funcionalidades que podem ser adicionadas futuramente:

* ⬇️ Contagem regressiva;
* ⏸️ Botão de pausa;
* 🔄 Botão de reset;
* ⏱️ Contagem automática por tempo;
* 🔊 Buzzer;
* 💾 Armazenamento do último valor;
* 🎛️ Controle da velocidade da contagem.

## 👨‍💻 Autor

**Luiz Santos**

Projeto desenvolvido para estudos e experimentação com sistemas embarcados.

## 📄 Licença

Este projeto pode ser utilizado para fins educacionais e de estudo.
