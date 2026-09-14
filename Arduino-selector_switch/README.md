# Chave Seletora com Arduino UNO

Uma **chave seletora** é um dispositivo utilizado para selecionar entre diferentes opções de funcionamento de um circuito. Neste projeto, o **Arduino UNO** é responsável por identificar a posição selecionada pela chave e executar uma ação correspondente.

A chave pode possuir várias posições, sendo que cada posição representa uma opção diferente. O Arduino lê os sinais elétricos gerados pela chave através de suas entradas digitais ou analógicas e, de acordo com a posição identificada, pode controlar LEDs, relés, displays, motores ou outros dispositivos.

## Como funciona

De forma simplificada, o funcionamento ocorre da seguinte maneira:

1. A chave seletora é conectada às entradas do Arduino UNO.
2. O usuário seleciona uma posição da chave.
3. O Arduino identifica qual posição foi selecionada.
4. O programa interpreta essa informação.
5. O Arduino executa a função correspondente à posição escolhida.

Por exemplo, uma chave com quatro posições pode ser utilizada para selecionar quatro modos diferentes:

| Posição | Função |
| ------: | ------ |
|       1 | Modo 1 |
|       2 | Modo 2 |
|       3 | Modo 3 |
|       4 | Modo 4 |

Dessa forma, a chave seletora funciona como uma **interface física de seleção**, permitindo que o usuário escolha diferentes funções do sistema sem precisar alterar o código do Arduino.

## Arduino UNO

O **Arduino UNO** é responsável pelo processamento das informações recebidas pela chave. Seu microcontrolador executa o programa desenvolvido no Arduino/PlatformIO e determina qual ação deve ser realizada para cada posição da chave.

Este tipo de projeto é bastante útil em sistemas de automação, painéis de controle, seleção de modos de operação e projetos eletrônicos que necessitam de uma seleção física entre diferentes funções.
