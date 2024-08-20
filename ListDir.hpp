// M�dulo respons�vel por duas fun��es.
// 1. Listar todos os arquivos e pastas dentro de um deret�rio
// 2. Verificar se um item � uma pasta ou um arquivo

#ifndef LISTDIR_HPP
#define LISTDIR_HPP

#include <filesystem>
#include <vector>
#include <string>

namespace fs = std::filesystem;

// Fun��o respons�vel por listar todos os itens em um diret�rio
std::vector<std::string> ListDir(std::string path) {
    std::vector<std::string> response;
    try {
        for (const auto& entry : fs::directory_iterator(path)) {
            response.push_back(entry.path().filename().string());
        }
    }
    catch (const fs::filesystem_error& e) {
        std::cerr << "Erro ao acessar o diret�rio: " << e.what() << std::endl;
    }
    return response;
}

// Fun��o respons�vel por verificar se um caminho � uma pasta ou um arquivo
bool is_a_file(std::string path) {
	if (fs::exists(path)) {
		return fs::is_regular_file(path);
    }
    else {
        return false;
    }
}

#endif