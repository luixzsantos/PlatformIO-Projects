#include <iostream>
//A diretiva de pré-processador #include
//Não é uma biblioteca
//iostream - arquivo de cabeçalho que contém definições para objetos de entrada e saída

//nao é uma boa pratica usar o namespace

int main()
//Função principal. todo programa C++ começa
//com esta função principal main()
{//chaves
	//{ Indica o início do bloco de código da função main()

	//cout comando de saida de dados
	//neste caso esta solicitando para colocar na saida padrão(tela)
	std::cout << "primeiro codigo" << std::endl;
	//endl indica para inserir uma quebra de linha da ("String")
	system("PAUSE");
	//chama o shell do windows  (DOS)
	//e coloca este comando PAUSE
	return 0;
	//Retorna para o sistema operacional zero
	//zero é o padrão para informar que deu certo
	// assim se a função main der certo ela retorna 0
}// indica o final de um bloco

//CTRL + SHIFT + B - COMPILAR O CODIGO FONTE
//CTRL + F5 - EXECUTAR O PROGRAMA
//CTRL + K + C - COMENTAR CODIGO
//CTRL + C NO FICAL DA LINHA COPIA ELA TODA
