#ifndef VM_HPP
#define VM_HPP

#include "bytecode.hpp"

#include <stack>
#include <vector>
#include <cstdint>

class virtualMachine {
    std::vector<instruction> instructions;
    std::stack<int32_t> stack;
    bool is_running = false;
    size_t ip = 0;

    int32_t pop();
    void push(int32_t val);
    public:
        virtualMachine(std::vector<instruction> instructions);

        void run();
};

#endif // VM_HPP