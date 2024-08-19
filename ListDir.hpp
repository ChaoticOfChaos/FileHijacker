// ListDir.hpp

#ifndef LISTDIR_HPP
#define LISTDIR_HPP

#include <filesystem>
#include <vector>
#include <string>

namespace fs = std::filesystem;

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


bool is_a_file(std::string path) {
	if (fs::exists(path)) {
		return fs::is_regular_file(path);
	}
}

#endif