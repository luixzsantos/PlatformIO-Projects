#include <iostream>

int main(){
  int Numero;
  Numero = 45;
  std::cout << "Valor Numero: " << Numero << std::endl;
  std::cout << "Tamanho da variavel Numero: " << sizeof(Numero) << " bytes" << std::endl;
  std::cout << "Endereço que que Numero Ocupa na memoria RAM: " << &Numero << std::endl;

  system("pause");
}
