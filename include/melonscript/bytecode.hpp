#ifndef BYTECODE_HPP
#define BYTECODE_HPP

#include <cstdint>

enum opCode : uint8_t {
    HALT = 0,
    PUSH = 1,
    POP = 2,
    ADDOP = 3,
    SUBOP = 4,
    MULOP = 5,
    DIVOP = 6,
    PRINT = 7,
    PRINTLN = 8,
    STORE = 9,
    LOAD = 10
};

struct instruction {
    opCode code;
    int value = 0;
};

#endif // BYTECODE_HPP