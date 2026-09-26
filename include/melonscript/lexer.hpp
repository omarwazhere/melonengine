#pragma once

#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include <variant>
#include <vector>

enum tokenType {
    IDENTIFIERTK,  // ex name
    INTTK,         // ex 23
    FLOATTK,       // ex 89.21
    STRTK,         // ex "hello world"
    CHARTK,        // ex 'A'
    INTTYPE,       // int
    FLOATTYPE,     // float
    STRTYPE,       // str
    CHARTYPE,      // char
    EQUALSTK,      // =
    BINARYOP,      // +, -, *, /
    SEMI,          // ;
    OPEN_PAREN,    // (
    CLOSE_PAREN,   // )
    OPEN_CBRACE,   // {
    CLOSE_CBRACE,  // }
    EOFTK          // EOF
};

enum binaryOp {
    PLUS,
    MINUS,
    MULTIPLY,
    DIV
};

using tokenValue = std::variant<std::string, int, float, char, binaryOp, std::monostate>;

struct token {
    tokenType type;
    tokenValue value;
};

std::vector<token> tokenize(const std::string &path);

#endif // LEXER_HPP