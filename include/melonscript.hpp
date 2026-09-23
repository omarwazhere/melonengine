#pragma once

#ifndef MELONSCRIPT_HPP
#define MELONSCRIPT_HPP

#include <string>
#include <variant>
#include <vector>

struct token;

struct numVariable;
struct strVariable;
struct declareStatement;
struct assignStatement;

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

std::vector<token> tokenize(const std::string &path);

enum varType {
    STRINGTYPE,
    NUMBERTYPE
};

using variable = std::variant<numVariable, strVariable>;
using statement = std::variant<assignStatement, declareStatement>;

namespace melon {
    struct number {
        int value;
    };
    struct string {
        std::string value;
    };

    using node = std::variant<number, string>;
}

// Number variable structure
struct numVariable {
    std::string name;
    melon::number value;
};

// String variable structure
struct strVariable {
    std::string name;
    melon::string value;
};

using variable = std::variant<numVariable, strVariable>;

// Assign variable statement
struct assignStatement {
    variable var;
};

// Variable declare statement
struct declareStatement {
    varType type;
    variable var;
};

// Statement variant
using statement = std::variant<assignStatement, declareStatement>;

// Program structure
struct program {
    std::vector<statement> statements;
};

// Parser class
class Parser {
    private:
        std::vector<token> tokens;
        size_t pos;
    public:
        Parser(std::vector<token> tokens);

        bool check(tokenType type);
        bool at_end();
        token peak();
        token advance();

        declareStatement parse_declare();
        assignStatement parse_assign();

        melon::node parse_node();

        program parse_program();
};


// MEMORY
class Memory {
    private:
        std::vector<strVariable> strs;
        std::vector<numVariable> nums;
    public:
        Memory() {};

        void newNum(numVariable var);
        void newStr(strVariable var);
        void printVariables(); // TEST
};

#endif