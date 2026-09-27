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
            case opCode::HALT:
                is_running = false;
                break;
            case opCode::PUSH:
                push(current.value);
                break;
            case opCode::POP:
                pop();
                break;
            case opCode::ADDOP:
                a = pop();
                b = pop();
                push(a + b);
                break;
            case opCode::SUBOP:
                a = pop();
                b = pop();
                push(a - b);
                break;
            case opCode::MULOP:
                a = pop();
                b = pop();
                push(a * b);
                break;
            case opCode::DIVOP:
                a = pop();
                b = pop();
                push(a / b);
                break;
            case opCode::PRINT:
                std::cout << pop();
                break;
            case opCode::PRINTLN:
                std::cout << pop() << '\n';
                break;
            case opCode::STORE:
                if (current.value >= globals.size()) {
                    globals.push_back(pop());
                } else {
                    globals[current.value] = pop();
                }
                break;
            case opCode::LOAD:
                push(globals[current.value]);
                break;
            case opCode::JUMP:
                ip = current.value;
                break;
            default:
                throw std::runtime_error("Unknown op code");
        }
    }
}