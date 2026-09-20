#pragma once

#ifndef MELONSCRIPT_HPP
#define MELONSCRIPT_HPP

#include <string>
#include <vector>

enum tokenType {
    IDENTIFIER,
    STRING,
    NUMBER,
    EQUALS,
    INT_TOKEN,
    STR_TOKEN,
    EOF_TOKEN
};

struct token {
    tokenType type;
    std::string value;
};

std::vector<token> tokenize(std::string source);

#endif