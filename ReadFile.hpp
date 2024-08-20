// Módulo responsável por ler arquivos txt, como o "Folders.txt" e "Extensions.txt"
// Módulo que já existe no meu github: https://github.com/chaoticofchaos/CppReadFile/
// Só que com modificações, como por exemplo, não ler arquivos .csv

#ifndef READFILE_HPP
#define READFILE_HPP
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>

// Classe responsável por colocar o arquivo no código
class readFileClass {
private:
	std::string path;
	std::vector<std::string> content;

public:

	// Função inicial, único argumento é o caminho do arquivo
	readFileClass(std::string filePath) {
		this->path = filePath;
	}

	// Função usada para ler o arquivo, caso haja algum problema, ela irá retornar o valor 1, caso não, 0
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

	// Função usada para obter o valor do arquivo. Caso haja problema com o .read(), ele irá retornar uma string nula
	std::vector<std::string> getValue() {
		return this->content;
	}
};

#endif