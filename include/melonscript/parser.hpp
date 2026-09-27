#pragma once

#ifndef PARSER_HPP
#define PARSER_HPP

#include "lexer.hpp"
#include "bytecode.hpp"

#include <cstdint>
#include <string>
#include <vector>

class Parser {
    size_t it;
    std::vector<token> tokens;

    token peek();
    token advance();
    token eat(tokenType type, std::string value = "", std::string error);
    public:
        Parser(std::vector<token> tokens);

        std::vector<instruction> parse_program();

        std::vector<instruction> parse_line();

        std::vector<instruction> parse_declare();
};

#endif // PARSER_HPP