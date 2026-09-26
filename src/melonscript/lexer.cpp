#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <variant>
#include <vector>

#include "../melon/melonlib.hpp"

void tokenizeline(std::vector<token> &out, const std::string &line);

std::vector<token> tokenize(const std::string &path) {
	std::ifstream file(path);
    if (!file) {
        throw std::runtime_error("file not found");
    }

    std::vector<token> tokens;
    std::string line;
    while (std::getline(file, line)) {
        tokenizeline(tokens, line);
    }
    file.close();
    tokens.emplace_back(token{.type= tokenType::EOFTK, .value= std::monostate{}});
    return tokens;
}

void tokenizeline(std::vector<token> &out, const std::string &line) {
    char current;
    for (size_t i = 0; i < line.length(); ++i) {
        current = line[i];

        if (current == '#') {
            break;
        }

        if (current == ' ') {
            continue;
        }

        if (current == '=') {
            out.emplace_back(token{.type= tokenType::EQUALSTK, .value= std::monostate{}});
            continue;
        }

        if (current == ';') {
            out.emplace_back(token{.type= tokenType::SEMI, .value= std::monostate{}});
            continue;
        }

        if (current == '(') {
            out.emplace_back(token{.type= tokenType::OPEN_PAREN, .value= std::monostate{}});
            continue;
        }

        if (current == ')') {
            out.emplace_back(token{.type= tokenType::CLOSE_PAREN, .value= std::monostate{}});
            continue;
        }

        if (current == '{') {
            out.emplace_back(token{.type= tokenType::OPEN_CBRACE, .value= std::monostate{}});
            continue;
        }

        if (current == '}') {
            out.emplace_back(token{.type= tokenType::CLOSE_CBRACE, .value= std::monostate{}});
            continue;
        }

        if (current == '+' || current == '-' || current == '*' || current == '/') {
            out.emplace_back(token{.type= tokenType::BINARYOP, .value=
            current == '+' ? binaryOp::PLUS : current == '-' ? binaryOp::MINUS :
            current == '*' ? binaryOp::MULTIPLY : binaryOp::DIV
            });
            continue;
        }

        if (std::isalpha(current)) {
            std::string word;
            while (i < line.length() && std::isalnum(line[i])) {
                word += line[i];
                ++i;
            }

            if (word == "int") {
                out.emplace_back(token{.type= tokenType::INTTYPE, .value= std::monostate{}});
                continue;
            }

            if (word == "str") {
                out.emplace_back(token{.type= tokenType::STRTYPE, .value= std::monostate{}});
                continue;
            }

            if (word == "float") {
                out.emplace_back(token{.type= tokenType::FLOATTYPE, .value= std::monostate{}});
                continue;
            }

            if (word == "char") {
                out.emplace_back(token{.type= tokenType::CHARTYPE, .value= std::monostate{}});
                continue;
            }

            out.emplace_back(token{.type= tokenType::IDENTIFIERTK, .value= word});
            continue;
        }

        if (std::isdigit(current)) {
            std::string word;
            bool is_float = false;
            bool had_decimal = false;

            while (i < line.length()) {
                char ch = line[i];

                if (std::isdigit(static_cast<unsigned char>(ch))) {
                    word += ch;
                    ++i;
                    continue;
                }

                if (ch == '.' && !had_decimal) {
                    word += ch;
                    had_decimal = true;
                    ++i;
                    continue;
                }

                break;
            }

            if (i + 1 < line.size()) {
                if (line[i + 1] == 'f') {
                    is_float = true;
                }
            }

            if (is_float) {
                out.emplace_back(token{.type= tokenType::FLOATTK, .value= std::stof(word)});
                continue;
            }
            out.emplace_back(token{.type= tokenType::INTTK, .value= std::stoi(word)});
            continue;
        }

        if (current == '"') {
            ++i;
            std::string value;

            while (i < line.size() && line[i] != '"') {
                value += line[i];
                ++i;
            }

            if (i >= line.size()) {
                throw std::runtime_error("expected closing quote");
            }

            out.emplace_back(token{.type = tokenType::STRTK, .value = value});
            continue;
        }

        if (current == '\'') {
            ++i;
            if (i >= line.size()) {
                throw std::runtime_error("expected character");
            }

            char character = line[i];

            if (i + 1 < line.size()) {
                if (line[++i] == '\'') {
                    out.emplace_back(token{.type= tokenType::CHARTK, .value= character});
                    continue;
                }
            }
            throw std::runtime_error("expected closing quote");
        } 

        throw std::runtime_error(std::string("bad token: ") + current);
    }
}