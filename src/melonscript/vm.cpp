#include <iostream>

#include "../melon/melonlib.hpp"

void virtualMachine::push(int32_t val) {
    stack.push(val);
}

int32_t virtualMachine::pop() {
    if (stack.empty()) {
        throw std::runtime_error("Cannot pop item from stack.");
    }

    int32_t temp = stack.top();
    stack.pop();
    return temp;
}

void virtualMachine::run() {
    ip = 0;
    is_running = true;
    int32_t a;
    int32_t b;
    while (ip < instructions.size() && is_running) {
        instruction current = instructions[ip++];
        switch (current.code) {
            case opCode::OP_HALT:
                is_running = false;
                break;
            case opCode::OP_PUSH:
                push(current.value);
                break;
            case opCode::OP_POP:
                pop();
                break;
            case opCode::OP_ADD:
                a = pop();
                b = pop();
                push(a + b);
                break;
            case opCode::OP_SUB:
                a = pop();
                b = pop();
                push(a - b);
                break;
            case opCode::OP_MUL:
                a = pop();
                b = pop();
                push(a * b);
                break;
            case opCode::OP_DIV:
                a = pop();
                b = pop();
                push(a / b);
                break;
            case opCode::OP_PRINT:
                std::cout << pop();
                break;
            case opCode::OP_PRINTLN:
                std::cout << pop() << '\n';
                break;
            default:
                throw std::runtime_error("Unknown op code");
        }
    }
}