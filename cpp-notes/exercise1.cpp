
#include <iostream>
/*Desenvolva um programa que escreve na tela a frase: Vou aprender a programar na Linguagem C++*/
int main()
{

  std::cout << "Vou \n aprender \n a \n programar\n na\n linguagem\n c++" <<std::endl;
  /*OU, ambos os jeitos funcionam*/
  std:: cout
  << "Vou" <<  "\n"
  << " aprender" << "\n"
  << " a" << "\n"
  << " programar" << "\n"
  << " na" << "\n"
  << " Linguagem" << "\n"
  << " C++" << "\n";
//cor de fundo 4 = vermelho
//cor de letra 7 = branco
  system("color 47");//obs:: color se coloca como String também
  return 0;
}
