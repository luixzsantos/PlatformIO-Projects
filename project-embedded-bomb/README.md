<h1>💣 Embedded Bomb — Arduino Uno</h1>

<h2>📌 Sobre o projeto</h2>

<p>
Este projeto consiste em uma <strong>simulação de um sistema de bomba utilizando Arduino Uno</strong>,
desenvolvida com o objetivo de demonstrar conceitos de sistemas embarcados, programação em C++,
entrada e processamento de dados e comunicação entre diferentes componentes eletrônicos.
</p>

<p>
A ideia do projeto foi inspirada no funcionamento da bomba presente no jogo
<strong>Counter-Strike: Global Offensive (CS:GO)</strong>. A escolha desse exemplo foi feita
porque o conceito é facilmente compreendido: existe uma entrada através de um teclado,
uma condição de ativação, uma contagem regressiva e um sinal sonoro e visual indicando
o estado do sistema.
</p>

<p>
No projeto desenvolvido, esses elementos foram adaptados para um ambiente de
<strong>eletrônica e sistemas embarcados</strong>, utilizando componentes físicos controlados
por um Arduino Uno.
</p>

<h2>🎮 Inspiração no CS:GO</h2>

<p>
No CS:GO, a bomba possui um sistema visual e sonoro bastante característico. Depois de
armada, existe uma contagem regressiva acompanhada por sinais sonoros, aumentando a
sensação de urgência para os jogadores.
</p>

<p>
A ideia utilizada neste projeto foi transformar esse conceito em uma demonstração
de sistemas embarcados. Em vez de reproduzir o funcionamento real de um dispositivo,
o Arduino apenas <strong>simula os estados do sistema</strong>.
</p>

<p>
A relação pode ser representada da seguinte maneira:
</p>

<table>
    <thead>
        <tr>
            <th>Conceito</th>
            <th>CS:GO</th>
            <th>Projeto Arduino</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>Entrada</td>
            <td>Interação do jogador</td>
            <td>Teclado matricial 4x4</td>
        </tr>
        <tr>
            <td>Ativação</td>
            <td>Bomba armada</td>
            <td>Senha correta</td>
        </tr>
        <tr>
            <td>Temporização</td>
            <td>Contagem regressiva</td>
            <td>Contador de 20 segundos</td>
        </tr>
        <tr>
            <td>Sinal sonoro</td>
            <td>Beep da bomba</td>
            <td>Buzzer/Piezo</td>
        </tr>
        <tr>
            <td>Informação visual</td>
            <td>Interface do jogo</td>
            <td>Display LCD 16x2</td>
        </tr>
        <tr>
            <td>Finalização</td>
            <td>Explosão no jogo</td>
            <td>Mensagem "BOOOM!!!!!!"</td>
        </tr>
    </tbody>
</table>

<h2>⚙️ Lógica do sistema</h2>

<p>
A lógica do projeto pode ser dividida em quatro etapas principais:
<strong>entrada, validação, temporização e finalização</strong>.
</p>

<h3>1️⃣ Entrada</h3>

<p>
Ao iniciar, o Arduino configura todos os componentes e apresenta no LCD:
</p>

<pre>Enter password</pre>

<p>
O teclado matricial é utilizado como dispositivo de entrada. Cada tecla pressionada
é identificada pelo Arduino através da biblioteca <code>Keypad</code>.
</p>

<p>
Os caracteres digitados são armazenados no vetor <code>inputText</code>.
A tecla <code>*</code> pode ser utilizada para limpar a entrada.
</p>

<h3>2️⃣ Validação da senha</h3>

<p>
Depois que sete caracteres são digitados, o programa compara a entrada do usuário
com a senha armazenada no código.
</p>

<pre>
char password[passwordLength] = "7553608";
</pre>

<p>
A comparação é realizada utilizando a função:
</p>

<pre>
strcmp(inputText, password)
</pre>

<p>
Se os valores forem iguais, o sistema considera a senha correta e passa para
a próxima etapa. Caso contrário, o LCD apresenta:
</p>

<pre>Password wrong</pre>

<h3>3️⃣ Contagem regressiva</h3>

<p>
Quando a senha está correta, o sistema inicia um contador de 20 segundos.
Essa etapa é controlada por um laço <code>for</code>:
</p>

<pre>
for(int i = 20; i &gt;= 0; i--)
</pre>

<p>
A cada repetição, o valor atual do contador é enviado para o LCD.
Ao mesmo tempo, o buzzer é acionado utilizando a função <code>tone()</code>,
criando o efeito sonoro da contagem regressiva.
</p>

<p>
Depois de um pequeno intervalo, o buzzer é desligado utilizando
<code>noTone()</code> e o contador continua para o próximo valor.
</p>

<h3>4️⃣ Finalização da simulação</h3>

<p>
Quando o contador chega a zero, o programa limpa o LCD e apresenta:
</p>

<pre>BOOOM!!!!!!</pre>

<p>
O buzzer é então acionado novamente durante alguns segundos para representar
o encerramento da simulação.
</p>

<h2>🧠 Fluxo lógico</h2>

<pre>
        INÍCIO
           │
           ▼
   Inicialização do Arduino
           │
           ▼
    "Enter password"
           │
           ▼
     Digitar senha
           │
           ▼
    7 caracteres?
       │       │
      NÃO     SIM
       │       │
       │       ▼
       │   Verificar senha
       │       │
       │    ┌──┴──┐
       │    │     │
       │  ERRADA  CORRETA
       │    │     │
       │    ▼     ▼
       │ "Password"  Contagem
       │  "wrong"   regressiva
       │              │
       │              ▼
       │          20 → 0
       │              │
       │              ▼
       │         "BOOOM!!!!!!"
       │              │
       └──────────────┘
</pre>

<h2>🔧 Componentes</h2>

<ul>
    <li>Arduino Uno</li>
    <li>Teclado matricial 4x4</li>
    <li>Display LCD 16x2</li>
    <li>Buzzer/Piezo</li>
    <li>Protoboard</li>
    <li>Jumpers</li>
</ul>

<h2>🤔 Por que Arduino Uno?</h2>

<p>
O <strong>Arduino Uno</strong> foi escolhido por ser uma plataforma simples,
acessível e adequada para projetos acadêmicos de sistemas embarcados.
Ele possui quantidade suficiente de entradas e saídas para conectar todos
os componentes utilizados no projeto.
</p>

<p>
Além disso, o Arduino possui uma grande quantidade de bibliotecas e uma
comunidade ampla, facilitando o desenvolvimento e permitindo que o foco
do projeto fique na lógica do sistema e na integração entre hardware e software.
</p>

<h2>🎛️ Teclado matricial</h2>

<p>
O teclado 4x4 possui quatro linhas e quatro colunas. O Arduino identifica
qual tecla foi pressionada através da biblioteca <code>Keypad</code>.
</p>

<table>
    <tr>
        <th>Teclado</th>
        <th>Arduino Uno</th>
    </tr>
    <tr><td>Linha 1</td><td>A0</td></tr>
    <tr><td>Linha 2</td><td>A1</td></tr>
    <tr><td>Linha 3</td><td>D11</td></tr>
    <tr><td>Linha 4</td><td>D10</td></tr>
    <tr><td>Coluna 1</td><td>D9</td></tr>
    <tr><td>Coluna 2</td><td>D8</td></tr>
    <tr><td>Coluna 3</td><td>D7</td></tr>
    <tr><td>Coluna 4</td><td>D6</td></tr>
</table>

<h2>🖥️ Display LCD</h2>

<p>
O display LCD 16x2 funciona como a principal interface visual do projeto.
Ele apresenta as mensagens do sistema, a senha digitada, a contagem regressiva
e o resultado final da simulação.
</p>

<table>
    <tr>
        <th>LCD</th>
        <th>Arduino Uno</th>
    </tr>
    <tr><td>RS</td><td>D5</td></tr>
    <tr><td>E</td><td>D4</td></tr>
    <tr><td>D4</td><td>D3</td></tr>
    <tr><td>D5</td><td>D2</td></tr>
    <tr><td>D6</td><td>A4</td></tr>
    <tr><td>D7</td><td>A5</td></tr>
</table>

<h2>🔊 Buzzer</h2>

<p>
O buzzer está conectado ao pino <strong>D13</strong> e é utilizado para
produzir os sinais sonoros durante a contagem regressiva e na finalização
da simulação.
</p>

<h2>💻 Tecnologias utilizadas</h2>

<ul>
    <li>C++</li>
    <li>Arduino Framework</li>
    <li>PlatformIO</li>
    <li>Keypad Library</li>
    <li>LiquidCrystal Library</li>
</ul>

<h2>🚀 Como executar</h2>

<ol>
    <li>Instale o Visual Studio Code.</li>
    <li>Instale a extensão PlatformIO.</li>
    <li>Clone o repositório.</li>
    <li>Abra o projeto no PlatformIO.</li>
    <li>Conecte o Arduino Uno ao computador.</li>
    <li>Monte o circuito de acordo com os pinos definidos no projeto.</li>
    <li>Compile o código.</li>
    <li>Faça o upload para o Arduino.</li>
    <li>Ligue o sistema.</li>
    <li>Digite a senha <code>7553608</code>.</li>
    <li>Acompanhe a contagem regressiva no LCD.</li>
</ol>

<h2>📁 Estrutura do projeto</h2>

<pre>
project-embedded-bomb/
├── platformio.ini
├── README.md
└── src/
    └── main.cpp
</pre>
<h2>🔬 Simulação no Tinkercad</h2>

<p>
O projeto também foi desenvolvido e testado virtualmente no
<strong>Tinkercad</strong>, permitindo verificar o funcionamento do
circuito antes da montagem física.
</p>

<p>
A simulação permite testar o Arduino Uno, teclado matricial, display LCD
e buzzer, além de validar a lógica do programa e as conexões entre os
componentes.
</p>

<p>
<a href="https://www.tinkercad.com/things/l9l6sf3Crzf-embedded-bomb-usc">
🔗 Acessar a simulação no Tinkercad
</a>
</p>

<h2>⚠️ Aviso</h2>

<p>
Este projeto é <strong>exclusivamente educacional</strong> e consiste em
uma simulação eletrônica inspirada em elementos visuais e sonoros de
um jogo. Não utiliza explosivos, materiais pirotécnicos ou mecanismos
destinados a causar danos.
</p>

<h2>👨‍💻 Autor</h2>

<p>
<strong>Luiz Fernando Araujo Santos</strong>
</p>
