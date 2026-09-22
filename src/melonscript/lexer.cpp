#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "../../include/melonscript.hpp"

void tokenizeline(std::vector<token> &out, std::string line);

// Tokenize a full file
std::vector<token> tokenize(const std::string &path) {
    std::vector<token> tokens;

    std::ifstream file(path);
    std::string line;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            tokenizeline(tokens, line);
        }
        
        file.close();

        // TEST
        std::string typestr;
        for (const auto &token : tokens) {
            switch (token.type) {
                case tokenType::IDENTIFIER:
                    typestr = "identifier";
                    break;
                case tokenType::STRING:
                    typestr = "string";
                    break;
                case tokenType::NUMBER:
                    typestr = "number";
                    break;
                case tokenType::EQUALS:
                    typestr = "equals";
                    break;
                case tokenType::INT_TOKEN:
                    typestr = "int type";
                    break;
                case tokenType::STR_TOKEN:
                    typestr = "str type";
                    break;
                case tokenType::EOF_TOKEN:
                    typestr = "EOF";
                    break;
                default:
                    break;
            }
            std::cout << "type: " << typestr << ", value: " << token.value << '\n';
        }
    } else {
        std::cerr << "Error opening file for reading! (File may not exist)\n";
    }
    
    return tokens;
}

// Tokenize a line
void tokenizeline(std::vector<token> &out, std::string line) {
    char current;
    for (size_t i = 0; i < line.length(); ++i) {
        current = line[i];

        if (std::isspace(current)) {
            continue; // skip whitespace
        }

        if (current == '=') {
            out.emplace_back(token{.type= tokenType::EQUALS, .value= ""});
            continue;
        }

        if (current == '#') {
            break;
        }

        if (std::isalpha(current)) {
            std::string word = "";
            while (i < line.length() && std::isalnum(current)) {
                current = line[i];
                word += current;
                ++i;
            }
            --i;
            
            if (word == "str") {
                out.emplace_back(token{.type= tokenType::STR_TOKEN, .value= ""});
            } else if (word == "int") {
                out.emplace_back(token{.type= tokenType::INT_TOKEN, .value= ""});
            } else {
                out.emplace_back(token{.type= tokenType::IDENTIFIER, .value= word});
            }
            continue;
        }

        if (std::isdigit(current)) {
            std::string number = "";
            while (i < line.length() && std::isdigit(current)) {
                current = line[i];
                number += current;
                ++i;
            }
            --i;
            
            out.emplace_back(token{.type= tokenType::NUMBER, .value= number});
            continue;
        }

        if (current == '"') {
            std::string string;
            ++i;
            while (i < line.length() && current != '"') {
                current = line[i];
                string += current;
                ++i;
            }
            
            out.emplace_back(token{.type= tokenType::STRING, .value= string});

            continue;
        }

        throw std::runtime_error("Unexpected character: " + std::string(1, current));
    }

    out.emplace_back(token{.type= tokenType::EOF_TOKEN, .value= ""});
}