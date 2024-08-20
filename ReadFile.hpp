// M�dulo respons�vel por ler arquivos txt, como o "Folders.txt" e "Extensions.txt"
// M�dulo que j� existe no meu github: https://github.com/chaoticofchaos/CppReadFile/
// S� que com modifica��es, como por exemplo, n�o ler arquivos .csv

#ifndef READFILE_HPP
#define READFILE_HPP
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>

// Classe respons�vel por colocar o arquivo no c�digo
class readFileClass {
private:
	std::string path;
	std::vector<std::string> content;

public:

	// Fun��o inicial, �nico argumento � o caminho do arquivo
	readFileClass(std::string filePath) {
		this->path = filePath;
	}

	// Fun��o usada para ler o arquivo, caso haja algum problema, ela ir� retornar o valor 1, caso n�o, 0
	int read() {
		std::ifstream arquivo(this->path);

		if (!arquivo.is_open()) {
			std::cerr << "Erro ao Abrir o Arquivo" << std::endl;
			return 1;
		}

		std::string linha;

		while (std::getline(arquivo, linha)) {
			this->content.push_back(linha);
		}

		arquivo.close();

		return 0;
	}

	// Fun��o usada para obter o valor do arquivo. Caso haja problema com o .read(), ele ir� retornar uma string nula
	std::vector<std::string> getValue() {
		return this->content;
	}
};

#endif