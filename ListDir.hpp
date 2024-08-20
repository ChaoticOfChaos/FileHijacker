// Módulo responsável por duas funções.
// 1. Listar todos os arquivos e pastas dentro de um deretório
// 2. Verificar se um item é uma pasta ou um arquivo

#ifndef LISTDIR_HPP
#define LISTDIR_HPP

#include <filesystem>
#include <vector>
#include <string>

namespace fs = std::filesystem;

// Função responsável por listar todos os itens em um diretório
std::vector<std::string> ListDir(std::string path) {
    std::vector<std::string> response;
    try {
        for (const auto& entry : fs::directory_iterator(path)) {
            response.push_back(entry.path().filename().string());
        }
    }
    catch (const fs::filesystem_error& e) {
        std::cerr << "Erro ao acessar o diretório: " << e.what() << std::endl;
    }
    return response;
}

// Função responsável por verificar se um caminho é uma pasta ou um arquivo
bool is_a_file(std::string path) {
	if (fs::exists(path)) {
		return fs::is_regular_file(path);
    }
    else {
        return false;
    }
}

#endif