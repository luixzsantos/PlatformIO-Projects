# 🖥️ Monitor Serial

## 📌 O que é?

O **Monitor Serial** é uma ferramenta da Arduino IDE que permite visualizar as informações enviadas pelo Arduino para o computador.

Ele funciona como uma **tela de comunicação**, mostrando mensagens e valores durante a execução do programa.

## 🎯 Para que serve?

O Monitor Serial pode ser utilizado para:

* 🔎 Acompanhar o funcionamento do projeto;
* 🧪 Realizar testes;
* 🐛 Identificar erros no código;
* 💡 Verificar o estado dos LEDs;
* 📊 Visualizar valores enviados por sensores;
* 💬 Mostrar mensagens durante a execução do programa.

## ⚙️ Como funciona?

Para utilizar o Monitor Serial, é necessário iniciar a comunicação serial no código:

```cpp
Serial.begin(9600);
```

Depois, podemos enviar uma mensagem para o Monitor Serial utilizando:

```cpp
Serial.println("LED vermelho ligado");
```

## 🚦 Exemplo no projeto

Na sinaleira com **LED vermelho e LED branco**, o Arduino pode informar qual LED está ligado:

```cpp
Serial.println("LED vermelho ligado");
```

E depois:

```cpp
Serial.println("LED branco ligado");
```

No Monitor Serial, será possível visualizar:

```text
LED vermelho ligado
LED branco ligado
LED vermelho ligado
LED branco ligado
```

## 💻 Velocidade da comunicação

Neste projeto, utilizamos:

```cpp
Serial.begin(9600);
```

Por isso, o Monitor Serial deve estar configurado para **9600 baud**.

## ✅ Conclusão

O Monitor Serial é uma ferramenta importante para **testar e acompanhar projetos com Arduino**. Ele permite observar o que está acontecendo no programa em tempo real, facilitando a identificação de problemas e a compreensão do funcionamento do circuito.

https://www.tinkercad.com/things/kOlWoaPi0WE-monitor-serial
