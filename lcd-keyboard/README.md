# LCD Keyboard

Projeto desenvolvido com **Arduino Uno**, **LCD 16x2** e teclado matricial, utilizando **PlatformIO**.

## 🛠️ Tecnologias

* Arduino Uno
* LCD 16x2
* Teclado matricial
* C/C++
* PlatformIO

## 📁 Estrutura do projeto

```text
lcd-keyboard/
├── include/
├── lib/
├── src/
│   └── main.cpp
├── test/
├── platformio.ini
└── README.md
```

## ⚙️ Configuração

O projeto utiliza o ambiente `uno` do PlatformIO:

```ini
[env:uno]
platform = atmelavr
board = uno
framework = arduino
```

## 🚀 Como executar

1. Clone o repositório:

```bash
git clone https://github.com/luixzsantos/lcd-keyboard.git
```

2. Abra a pasta do projeto no **Visual Studio Code** com o **PlatformIO** instalado.

3. Conecte o Arduino Uno ao computador.

4. Compile o projeto usando **Build**.

5. Envie o programa para o Arduino usando **Upload**.

## 📟 LCD

O LCD é controlado pela biblioteca `LiquidCrystal`.

Exemplo de inicialização:

```cpp
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
    lcd.begin(16, 2);
}

void loop() {
}
```

## 🔌 Hardware

O projeto foi desenvolvido para **Arduino Uno**. Os pinos utilizados pelo LCD podem ser alterados diretamente no código conforme a montagem do circuito.

## 📌 Status

🚧 Projeto em desenvolvimento.

## 👤 Autor

**Luiz Santos**

---

Se este projeto foi útil para você, fique à vontade para dar uma ⭐ no repositório.
