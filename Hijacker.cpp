// Arquivo Main, Responsável por importar o Hijack.hpp e Fazer Tudo Funcionar

#include <iostream>

#include <string>
#include <vector>

#include "Hijack.hpp"

// Funções simples eu optei por fazer no código main, para poupar tempo

// Função feita apenas para não bagunçar tanto o código
void Banner() {
	std::cout << "Hijacker\n";
	std::cout << "By ChaoticOfChaos\n";
	std::cout << "Github: " << "https://github.com/chaoticofchaos/\n";
}

// Função para caso esqueça de algo
void Help() {
	std::cout << "? - Help\n";
	std::cout << "Banner - Banner\n";
	std::cout << "Clear - Clear Terminal\n";
	std::cout << "Config.Extensions - Open Extensions Blacklist Config File\n";
	std::cout << "Config.Folders - Open Folders Config File\n";
	std::cout << "End - Close Hijacker\n";
	std::cout << "Forge - Create Hijacker File\n";
	std::cout << "Hijack - Hijack All Files in Hijack File\n";
	std::cout << "Inpect - Inspect Hijack File\n";
	std::cout << "Search - Start Hijack\n";
}

// Função inicial, aonde a magia acontece
int main() {
	std::vector<std::string> LIST;
	bool Ready = false;
	bool Ready2 = false;
	Banner();

	while (true) {
		std::string userInput;
		std::cout << "-> ";
		std::cin >> userInput;

		if (userInput == "?") {
			Help();
		}
		else if (userInput == "banner") {
			Banner();
		}
		else if (userInput == "config.extensions") {
			system("start ./Extensions.txt");
		}
		else if (userInput == "config.folders") {
			system("start ./Folders.txt");
		}
		else if (userInput == "end" || userInput == "close" || userInput == "exit") {
			break;
		}
		else if (userInput == "forge") {
			if (Ready) {
				FileSearch(LIST);
				Ready2 = true;
			}
			else {
				std::cout << "Type 'Search' First\n";
			}
		}
		else if (userInput == "hijack") {
			if (Ready2) {
				HIJACK();
			}
			else {
				std::cout << "Type 'forge' First\n";
			}
		}
		else if (userInput == "inspect") {
			std::string fileName;
			std::cout << "Hijack File to Inspect -> ";
			std::cin >> fileName;

			std::string command = "start ./" + fileName;
			system(command.c_str());
		}
		else if (userInput == "search") {
			LIST = Search();
			Ready = true;
		}
		else if (userInput == "clear") {
			system("cls");
		}
		else {
			std::cout << "Invalid Command. Type 'help' to commands\n";
		}

		std::cout << "\n";
	}

	return 0;
}

// Caso Tenha Algo a Melhorar no Código, aceito Feedback
// Forged by ChaoticofChaos