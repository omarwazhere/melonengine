#pragma once

#ifndef PARSER_HPP
#define PARSER_HPP

#include "lexer.hpp"
#include "bytecode.hpp"

#include <cstdint>
#include <string>
#include <vector>

class Parser {
    size_t it = 0;
    std::vector<token> tokens;

    bool is_at_end();
    bool check(tokenType type);

    token peek();
    token advance();
    token match(tokenType type, std::string error);
    public:
        Parser(std::vector<token> tokens) : tokens(tokens) {};

        std::vector<instruction> parse_program();

        std::vector<instruction> parse_line();

        std::vector<instruction> parse_declare();
};

#endif // PARSER_HPP