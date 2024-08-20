// M�dulo repons�vel pela blacklist do "Extensions.txt"
// No caso, O que faz n�o aparecer arquivos indesejados, como fotos nos arquivos de sequestro

#ifndef BLACKLIST_HPP
#define BLACKLIST_HPP

#include <string>
#include <vector>

// Fun��o usada para verificar se uma string termina com alguma extens�o espec�fica 
bool ends_with(const std::string& value, const std::string& ending) {
	if (ending.size() > value.size()) return false;
	return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
}

// Fun��o usada para percorrer a blacklist, e de quebra verificar se algum item da blacklist aparece aqui
bool BlackList(std::string value, std::vector<std::string> blacklist) {
	for (std::string v : blacklist) {
		if (ends_with(value, v) == true) {
			return true;
		}
	}
	return false;
}

#endif