#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "../../include/melonscript.hpp"

void tokenizeline(std::vector<token> &out, std::string line);

std::vector<token> tokenize(const std::string &path) {
    std::vector<token> tokens;

    std::ifstream file(path);
    std::string line;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            tokenizeline(tokens, line);
        }
        
        file.close();
    } else {
        std::cerr << "Error opening file for reading! (File may not exist)\n";
    }
    
    return tokens;
}

void tokenizeline(std::vector<token> &out, std::string line) {
    char current;
    for (size_t i = 0; i < line.length(); ++i) {
        // TODO
    }
}