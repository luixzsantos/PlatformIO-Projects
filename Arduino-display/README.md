# Display de 7 Segmentos com Arduino

## 📟 Sobre o projeto

Este projeto utiliza um **display de 7 segmentos** controlado por um **Arduino** para realizar a exibição de números de forma simples e visual.

O display de 7 segmentos é um componente eletrônico formado por **sete LEDs individuais**, identificados pelas letras **A, B, C, D, E, F e G**. Esses segmentos podem ser acionados em diferentes combinações para formar os números de **0 a 9** e alguns outros caracteres.

## 🔢 Como funciona

Cada segmento do display representa uma parte do número:

```text
       A
      ---
   F |   | B
      -G-
   E |   | C
      ---
       D
```

Ao acender diferentes segmentos, é possível formar os números. Por exemplo:

* **0:** A, B, C, D, E e F
* **1:** B e C
* **2:** A, B, G, E e D
* **3:** A, B, C, D e G
* **4:** F, G, B e C
* **5:** A, F, G, C e D
* **6:** A, F, G, E, C e D
* **7:** A, B e C
* **8:** Todos os segmentos
* **9:** A, B, C, D, F e G

## 🔌 Display e Arduino

Cada segmento pode ser conectado a uma porta digital do Arduino, normalmente utilizando **resistores** para limitar a corrente e proteger os LEDs.

O Arduino controla quais segmentos devem ser ligados ou desligados de acordo com o número que será exibido.

A lógica básica consiste em:

1. Definir as portas digitais utilizadas pelos segmentos.
2. Configurar essas portas como saídas.
3. Acender e apagar os segmentos de acordo com o número desejado.
4. Alterar a combinação dos segmentos para realizar a contagem ou exibição desejada.

## 💡 Aplicação neste projeto

Neste projeto, o display de 7 segmentos é utilizado para apresentar uma sequência numérica controlada pelo Arduino.

A atividade permite compreender conceitos importantes de eletrônica e programação, como:

* Controle de LEDs;
* Uso de portas digitais;
* Estruturas de repetição;
* Funções;
* Temporização com `delay()`;
* Lógica de acionamento de componentes eletrônicos.

## 🧰 Componentes

* Arduino;
* Display de 7 segmentos;
* Resistores;
* Protoboard;
* Cabos jumper;
* Cabo USB para programação.

## 🎯 Objetivo

O objetivo do projeto é demonstrar, de maneira prática, como um Arduino pode controlar um **display de 7 segmentos**, transformando comandos digitais em uma representação visual dos números.

Além de ser um projeto introdutório, esse princípio é utilizado em diversos equipamentos eletrônicos, como **relógios digitais, contadores, calculadoras, painéis e instrumentos de medição**.

https://www.tinkercad.com/things/9DyDaaFPAw4-contador-simples-com-arduino
