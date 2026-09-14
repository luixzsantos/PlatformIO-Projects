# 🔘 Uso de Botões no Arduino

## 📌 O que é?

Os **botões** são componentes utilizados para enviar comandos ao Arduino. Quando o botão é pressionado, o Arduino consegue identificar essa ação e executar uma determinada função no programa.

Eles podem ser utilizados para **ligar e desligar LEDs, iniciar sequências, alterar estados do projeto ou enviar comandos**.

## 🧰 Materiais utilizados

* Arduino Uno
* 1 botão (push button)
* 1 LED
* 1 resistor de 220 Ω
* Jumpers
* Protoboard

## ⚙️ Como funciona?

O botão é conectado a uma porta digital do Arduino. O programa verifica continuamente se o botão está pressionado.

Neste exemplo, utilizamos o **pino 7** para o botão e o **pino 8** para o LED.

Quando o botão é pressionado, o LED acende. Quando o botão é solto, o LED apaga.

## 💻 Código

```cpp
const int botao = 7;
const int led = 8;

void setup() {
  pinMode(botao, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() {
  if (digitalRead(botao) == LOW) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
}
```

## 🔌 `INPUT_PULLUP`

Neste projeto utilizamos:

```cpp
pinMode(botao, INPUT_PULLUP);
```

Essa configuração utiliza o **resistor de pull-up interno do Arduino**, evitando a necessidade de colocar um resistor externo para o botão.

Com `INPUT_PULLUP`:

* **Botão solto:** `HIGH`
* **Botão pressionado:** `LOW`

Por isso, no código verificamos:

```cpp
if (digitalRead(botao) == LOW)
```

## 🎯 Aplicação na Sinaleira

O botão também pode ser utilizado no projeto da **sinaleira com LED vermelho e branco**. Por exemplo, ao pressionar o botão, podemos fazer a sinaleira mudar do LED vermelho para o LED branco.

Isso permite tornar o projeto **interativo**, fazendo com que o usuário controle parte do funcionamento do Arduino através do botão.

## ✅ Conclusão

O uso de botões é uma das formas mais simples de criar **interação entre o usuário e o Arduino**. Através da leitura de uma entrada digital, o Arduino consegue identificar quando o botão foi pressionado e executar uma ação programada.


https://www.tinkercad.com/things/3tMwrbzOEhi-arduino-bottom2
