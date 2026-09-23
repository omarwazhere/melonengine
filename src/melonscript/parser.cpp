#include <iostream>
#include <vector>

#include "../melon/melonlib.hpp"

token Parser::peak() {
    return tokens[pos];
}

token Parser::advance() {
    return tokens[pos++];
}

bool Parser::at_end() {
    return pos >= tokens.size();
}

bool Parser::check(tokenType type) {
    if (at_end()) return false;
    return tokens[pos].type == type;
}

melon::node Parser::parse_node() {
    if (check(tokenType::NUMBER)) {
        return melon::number{.value= std::stoi(advance().value)};
    }
    if (check(tokenType::STRING)) {
        return melon::string{.value= advance().value};
    }
    throw std::runtime_error("expected a node");
}

declareStatement Parser::parse_declare() {
    token typetok = advance();
    if (!check(tokenType::IDENTIFIER)) {
        throw std::runtime_error("expected an identifier");
    }

    token nametok = advance();

    if (!check(tokenType::EQUALS)) {
        throw std::runtime_error("expected '=' after identifier");
    }

    advance();
    melon::node value = parse_node();
    if (typetok.type == tokenType::INT_TOKEN) {
        return declareStatement{
            .type= varType::NUMBERTYPE,
            .var= numVariable{
                .name= nametok.value,
                .value= std::get<melon::number>(value).value
            }
        };
    }

    if (typetok.type == tokenType::STR_TOKEN) {
        return declareStatement{
            .type= varType::STRINGTYPE,
            .var= strVariable{
                .name= nametok.value,
                .value= std::get<melon::string>(value).value
            }
        };
    }
    throw std::runtime_error("expected type specifier");
}

assignStatement Parser::parse_assign() {
    token nametok = advance();
    if (!check(tokenType::EQUALS)) {
        throw std::runtime_error("expected '=' after identifier");
    }

    advance();
    melon::node value = parse_node();
    if (std::holds_alternative<melon::number>(value)) {
        return assignStatement {
            .var= numVariable {
                .name = nametok.value,
                .value = std::get<melon::number>(value).value
            }
        };
    }
    if (std::holds_alternative<melon::string>(value)) {
        return assignStatement {
            .var= strVariable {
                .name = nametok.value,
                .value = std::get<melon::string>(value).value
            }
        };
    }
    throw std::runtime_error("expected type specifier");
}

program Parser::parse_program() {
    program program;
    while (!at_end()) {
        tokenType current = peak().type;

        if (current == tokenType::EOF_TOKEN) {
            break;
        }

        if (current == tokenType::INT_TOKEN || current == tokenType::STR_TOKEN) {
            program.statements.push_back(parse_declare());
            continue;
        }                                          

        if (current == tokenType::IDENTIFIER) {
            program.statements.push_back(parse_assign());
            continue;
        }

        throw std::runtime_error("unexpected token in program");
    }
    return program;
}