#ifndef BYTECODE_HPP
#define BYTECODE_HPP

#include <cstdint>

enum opCode : uint8_t {
    OP_HALT = 0,
    OP_PUSH = 1,
    OP_POP = 2,
    OP_ADD = 3,
    OP_SUB = 4,
    OP_MUL = 5,
    OP_DIV = 6,
    OP_PRINT = 7,
    OP_PRINTLN = 8
};

struct instruction {
    opCode code;
    int value = 0;
};

#endif // BYTECODE_HPP