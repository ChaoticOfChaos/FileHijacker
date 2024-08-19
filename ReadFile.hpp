// ReadFile.hpp

#ifndef READFILE_HPP
#define READFILE_HPP
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>

class readFileClass {
private:
	std::string path;
	std::vector<std::string> content;
	std::vector<std::vector<std::string>> contentCSV;
	int contentType;

public:

	readFileClass(std::string filePath, std::string contentType = "txt") {
		this->path = filePath;
		if (contentType == "txt") {
			this->contentType = 1;
		}
		else if (contentType == "csv") {
			this->contentType == 2;
		}
		else {
			std::cerr << "Content Type Not Avalieble" << std::endl;
			this->contentType = 1;
		}
	}

	int read() {
		if (this->contentType == 1) {
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
		else if (this->contentType == 2) {
			std::ifstream arq(this->path);

			if (!arq.is_open()) {
				std::cerr << "Erro" << std::endl;
				return 1;
			}

			std::vector<std::vector<std::string>> dados;

			std::string linha;
			while (std::getline(arq, linha)) {
				std::vector<std::string> linha_dados;
				std::istringstream linha_stream(linha);
				std::string campo;

				while (std::getline(linha_stream, campo, ',')) {
					linha_dados.push_back(campo);
				}

				dados.push_back(linha_dados);
			}

			arq.close();

			this->contentCSV = dados;

			return 0;
		}
	}

	std::vector<std::string> getValue() {
		if (this->contentType == 1) {
			return this->content;
		}
		else {
			std::cerr << "ERROR" << std::endl;
			std::cerr << "Content Type Error" << std::endl;
		}
	}

	std::vector<std::vector<std::string>> getValueCSV() {
		if (this->contentType == 2) {
			return this->contentCSV;
		}
		else {
			std::cerr << "ERROR" << std::endl;
			std::cerr << "Content Type Error" << std::endl;
		}
	}
};

#endif