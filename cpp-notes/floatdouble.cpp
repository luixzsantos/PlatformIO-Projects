#include <iostream>
#include <iomanip>

int main() {
    int Numero;
    float Numero2;
    double Numero3 = 45345.904555;

    Numero = 45;
    Numero2 = 55.56;

    std::cout << "Valor Numero: " << Numero << std::endl;
    std::cout << "Tamanho da variavel Numero: "
              << sizeof(Numero) << " bytes" << std::endl;
    std::cout << "Endereco que Numero ocupa na memoria RAM: "
              << &Numero << std::endl;

    std::cout << "Valor Numero2: " << Numero2 << std::endl;
    std::cout << "Tamanho da variavel Numero2: "
              << sizeof(Numero2) << " bytes" << std::endl;
    std::cout << "Endereco que Numero2 ocupa na memoria RAM: "
              << &Numero2 << std::endl;

    std::cout << "Valor Numero3: "
              << std::setprecision(12) << Numero3 << std::endl;
    std::cout << "Tamanho da variavel Numero3: "
              << sizeof(Numero3) << " bytes" << std::endl;
    std::cout << "Endereco que Numero3 ocupa na memoria RAM: "
              << &Numero3 << std::endl;

    return 0;
}
