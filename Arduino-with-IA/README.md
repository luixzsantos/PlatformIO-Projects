#  Jogo de Reflexo com Arduino 

## Desenvolvimento de um sistema eletrônico de medição de tempo de reação utilizando Arduino Uno

**Desenvolvido por: Luiz Fernando**

---

#  Sobre o Projeto

O **Jogo de Reflexo com Arduino Uno** é um projeto eletrônico interativo desenvolvido com o objetivo de medir a velocidade de reação de um usuário diante de um estímulo visual.

O sistema funciona através do acionamento aleatório de LEDs controlados pelo Arduino Uno. Quando um LED é aceso, o jogador deve identificar rapidamente a cor correspondente e pressionar o botão associado. Após a resposta, o microcontrolador calcula o tempo entre o acionamento do LED e o comando realizado pelo usuário, apresentando o desempenho obtido.

Este projeto combina conceitos de **eletrônica digital, programação embarcada e sistemas microcontrolados**, demonstrando na prática como um dispositivo eletrônico pode receber informações, processar dados e executar ações automaticamente.

Desenvolvido com finalidade educacional, o projeto busca aplicar conhecimentos de hardware e software em uma solução simples, funcional e interativa.

---

#  Objetivos do Projeto

O principal objetivo deste projeto é desenvolver um dispositivo capaz de medir o tempo de reação humano utilizando um Arduino Uno conectado a LEDs e botões.

Durante sua construção e programação, são explorados conceitos fundamentais da área de sistemas embarcados, como:

* Configuração de entradas e saídas digitais;
* Controle de componentes eletrônicos;
* Programação em Arduino C/C++;
* Uso de variáveis e estruturas condicionais;
* Criação de lógica de funcionamento;
* Geração de valores aleatórios;
* Medição de tempo utilizando a função `millis()`.

Além do aprendizado técnico, o projeto também estimula o desenvolvimento do raciocínio lógico, criatividade e capacidade de resolver problemas utilizando tecnologia.

---

#  Funcionamento do Sistema

O funcionamento do jogo acontece em etapas:

1. O Arduino inicia o sistema e prepara os componentes eletrônicos.
2. O programa aguarda um intervalo de tempo aleatório.
3. Um LED é acionado indicando o estímulo visual.
4. O Arduino registra o instante em que o LED foi ligado.
5. O jogador identifica a cor correspondente.
6. O botão associado é pressionado.
7. O sistema calcula o tempo de reação.
8. O resultado pode ser utilizado para avaliação do desempenho.

Exemplo de cálculo:

```
Momento em que o LED acendeu:
5000 ms

Momento em que o botão foi pressionado:
5300 ms

Tempo de reação:
5300 - 5000 = 300 ms
```

Quanto menor for o tempo obtido, maior será a velocidade de resposta do jogador.

---

#  Como Jogar

Para iniciar uma rodada, o jogador deve posicionar os dedos próximos aos botões de controle.

Após o início do sistema, é necessário aguardar o acionamento de um LED. Assim que o sinal luminoso aparecer, o jogador deve identificar sua cor e pressionar rapidamente o botão correspondente.

O Arduino realiza automaticamente o cálculo do tempo de resposta e permite iniciar novas rodadas para comparação dos resultados.

O projeto também pode ser adaptado para um modo competitivo, permitindo comparar o desempenho de diferentes jogadores.

---

#  Componentes Utilizados

## Componentes principais

* Arduino Uno;
* 3 LEDs de cores diferentes;
* 3 botões de pressão;
* Resistores de 220 Ω;
* Protoboard;
* Cabos jumper;
* Cabo USB para programação.

## Possíveis expansões

O projeto pode receber novos componentes para aumentar sua funcionalidade:

* Display LCD 16x2 ou OLED;
* Buzzer para efeitos sonoros;
* Sistema de pontuação;
* Memória para armazenar recordes;
* Caixa de proteção personalizada.

---

# 🔧 Montagem do Circuito

## Conexão dos LEDs

Os LEDs representam as saídas visuais do sistema e são controlados diretamente pelo Arduino Uno.

| Componente   | Pino Arduino |
| ------------ | ------------ |
| LED vermelho | Digital 2    |
| LED verde    | Digital 3    |
| LED azul     | Digital 4    |

Cada LED utiliza um resistor de proteção para controlar a corrente elétrica e evitar danos ao componente.

---

## Conexão dos Botões

Os botões funcionam como entradas digitais responsáveis por enviar comandos ao microcontrolador.

| Componente     | Pino Arduino |
| -------------- | ------------ |
| Botão vermelho | Digital 8    |
| Botão verde    | Digital 9    |
| Botão azul     | Digital 10   |

A configuração utilizada é:

```cpp
INPUT_PULLUP
```

Essa função utiliza os resistores internos do Arduino para facilitar a leitura dos botões e reduzir a quantidade de componentes externos necessários.

---

#  Desenvolvimento do Software

O código do projeto foi desenvolvido utilizando:

* **Arduino IDE 2**
* **Linguagem Arduino C/C++**

O software é responsável por controlar toda a lógica do jogo, incluindo:

* Inicialização dos componentes;
* Controle dos LEDs;
* Leitura dos botões;
* Geração de atrasos aleatórios;
* Cálculo do tempo de reação;
* Controle das rodadas.

As principais funções utilizadas são:

### Configuração dos pinos

```cpp
pinMode()
```

Define se um pino será utilizado como entrada ou saída.

### Controle dos LEDs

```cpp
digitalWrite()
```

Permite ligar ou desligar os LEDs.

### Leitura dos botões

```cpp
digitalRead()
```

Permite verificar se o jogador pressionou determinado botão.

### Medição de tempo

```cpp
millis()
```

Utilizada para registrar o tempo decorrido e calcular a velocidade de resposta do jogador.

O cálculo principal realizado pelo programa é:

```
Tempo de reação =
tempo do botão pressionado -
tempo em que o LED foi ativado
```

---

#  Conceitos Aplicados

Durante o desenvolvimento foram aplicados diversos conceitos importantes de programação e eletrônica:

* Microcontroladores;
* Entradas e saídas digitais;
* Comunicação entre hardware e software;
* Estruturas condicionais;
* Laços de repetição;
* Variáveis;
* Funções;
* Temporização;
* Geração de valores aleatórios;
* Sistemas embarcados.

---

#  Metodologia de Desenvolvimento

O projeto foi desenvolvido seguindo algumas etapas principais.

## 1. Planejamento

Inicialmente foi definida a proposta do jogo, os componentes necessários e a lógica de funcionamento.

## 2. Montagem Eletrônica

Os componentes foram conectados em uma protoboard, realizando a integração entre LEDs, botões e Arduino Uno.

## 3. Programação

O código foi desenvolvido utilizando a Arduino IDE 2, implementando o controle dos componentes e a lógica do jogo.

## 4. Testes

Foram realizados testes para verificar:

* Funcionamento dos LEDs;
* Leitura correta dos botões;
* Precisão da medição de tempo;
* Resposta do sistema.

## 5. Melhorias

Após os testes iniciais, foram identificadas possibilidades de evolução para tornar o projeto mais completo e interativo.

---

#  Melhorias Futuras

Algumas melhorias que podem ser implementadas:

* Sistema de ranking e recordes;
* Modo multiplayer;
* Display para apresentação dos resultados;
* Sons de confirmação e alerta;
* Comunicação com aplicativo;
* Armazenamento de pontuações;
* Construção de uma estrutura física semelhante a um produto comercial.

Essas melhorias podem transformar o projeto em um equipamento mais avançado, mantendo a mesma base de aprendizado em Arduino e sistemas embarcados.

---

#  Conclusão

O **Jogo de Reflexo com Arduino Uno** é um projeto que demonstra a aplicação prática da eletrônica e da programação na criação de um sistema interativo.

Através dele é possível compreender o funcionamento de um microcontrolador, desde a leitura de informações externas até o processamento de dados e controle de componentes eletrônicos.

Além de ser uma ferramenta educativa para aprendizado de Arduino, o projeto representa uma introdução aos conceitos utilizados em áreas como automação, robótica e desenvolvimento de sistemas embarcados.

---

#  Créditos

**Desenvolvimento do projeto:** Luiz Fernando

Projeto desenvolvido para fins educacionais, envolvendo programação Arduino, eletrônica digital e sistemas embarcados.
