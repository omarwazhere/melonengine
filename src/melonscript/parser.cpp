#include <string>
#include <iostream>
#include <vector>

#include "../melon/melonlib.hpp"

bool Parser::is_at_end() {
    if (tokens[it].type == tokenType::EOFTK) {
        return true;
    }
    return false;
}

bool Parser::check(tokenType type) {
    if (tokens[it].type == type && !is_at_end()) {
        return true;
    }
    return false;
}

token Parser::peek() {
    if (!is_at_end()) {
        return tokens[it];
    }
    throw std::runtime_error("REACHED END WITHOUT TERMINATING");
}

token Parser::advance() {
    if (!is_at_end()) {
        token current = tokens[it++];
        return current;
    }
    throw std::runtime_error("REACHED END WITHOUT TERMINATING");
}

token Parser::match(tokenType type, std::string error) {
    if (check(type)) {
        return advance();
    } 
    throw std::runtime_error(error);
}

std::vector<instruction> Parser::parse_program() {
    std::vector<instruction> instructions;
    std::vector<instruction> line;
    while (!is_at_end()) {
        line = parse_line();
        instructions.insert(instructions.end(), line.begin(), line.end());
        line.clear();
    }
    return instructions;
}

std::vector<instruction> Parser::parse_line() {
    std::vector<instruction> instructions;
    if (peek().type == tokenType::INTTYPE) {
        instructions = parse_declare();
    }
    match(tokenType::SEMI, "EXPECTED SEMICOLON AT END OF LINE");
    return instructions;
}

std::vector<instruction> Parser::parse_declare() {
    advance();
    int name = std::get<int>(match(tokenType::INTTK, "EXPECTED STORE LOCATION").value);
    match(tokenType::EQUALSTK, "EXPECTED = AFTER STORE LOCATION");
    int value = std::get<int>(match(tokenType::INTTK, "EXPECTED VALUE").value);
    return {
        {PUSH, value},
        {STORE, name}
    };
} 