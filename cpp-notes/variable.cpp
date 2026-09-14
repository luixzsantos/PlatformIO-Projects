#include <iostream>
#include <tchar.h>
int main()
{
  //Função que configura o console windows para mostrar acentos
  _tsetlocale(LC_ALL, _T("portuguese"));

  //Declaração de Variáveis
  //Primeiro colocamos qual o tipo de variavel que desejamos
  //o computador crie ao executar nosso programa
  //neste caso escolhemos ambas como int (integer)
  //ou seja o local da memoria que estamos solicitando ao computador
  //deve ser capaz de armazenar apenas numeros inteiros(-3,-2,-1,0,1,2)
  //então int NumVidas pode ser lido da seguinte forma:
  // Crie um local na memoria RAM que seja capaz de armazenar apenas numeros inteiros e coloue o nome deste local como NumVidas
  //eu sei que você só entende endereço de memoria mas vai facilitar muito para mim se voce nomear este endereço de memoria com um nome. desta forma esta abstração vai me permitir manipular melhor entre endereço de memoria pois seria complicado ter que ficar digitando
  //melhor usar um nome ao inves de um endereço de memoria
  int NumVidas = 5;
  //ACIMA O COMPUTADOR IRA ALOCAR UM ESPAÇO DO TIPO INTEIRO
  //DEPOIS VAI ATE ESTE LOCAL NA RAM E VAI COLOCAR O VALOR 5 DENTRO DESTE LOCAL NA RAM
  int Score = 1350;
   //ACIMA O COMPUTADOR IRA ALOCAR UM ESPAÇO DO TIPO INTEIRO
  //DEPOIS VAI ATE ESTE LOCAL NA RAM E VAI COLOCAR O VALOR 1350 DENTRO DESTE LOCAL NA RAM
  std::cout << "******************INICIO DO JOGO******************" << std::endl;
  std::cout << "Vidas Jogador: " << NumVidas << std::endl;
  std::cout << "Pontuação: " << Score << std::endl;
  std::cout << "Tamanho da variavel NumVidas: " << sizeof(NumVidas) << std::endl;//sizeof é uma função que retorna o tamanho em bytes de uma variavel
   std::cout << "Tamanho da variavel Score: " << sizeof(Score) << std::endl;//sizeof é uma função que retorna o tamanho em bytes de uma variavel
  std::cout << "Endereço que que NumVidas Ocupa na memoria RAM: " << &NumVidas << std::endl;
  std::cout << "Endereço que que Score Ocupa na memoria RAM: " << &Score << std::endl;
  std::cout << "************************" << std::endl;


  std::cout << "******************DURANTE O JOGO******************" << std::endl;

//VA ATE A REGISO DE MEMORIA RORULADA COM O NOME DE SCORE E COLOQUE
//AGORA EM SOMA O VALOR QUE ESTA CONTIDO NELA MAIS 150
//SCORE = 1350 + 150
//SCORE = 1500
  Score = Score + 150; // Pontuação += 150;
  //VA ATE A REGISO DE MEMORIA RORULADA COM O NOME DE NUMVIDAS E COLOQUE
//AGORA EM SOMA O VALOR QUE ESTA CONTIDO NELA MAIS 150
//NUMVIDAS = 5 - 1
//NUMVIDAS = 4
  NumVidas = NumVidas - 1; //NumVidas -= 1;
  std::cout << "Vidas Jogador: " << NumVidas << std::endl;
  std::cout << "Pontuação: " << Score << std::endl;
  std::cout << "************************" << std::endl;


  system("PAUSE");
}
