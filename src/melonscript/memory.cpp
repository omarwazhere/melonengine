#include <iostream>

#include "../melon/melonlib.hpp"

void Memory::newNum(numVariable var) {
    nums.push_back(var);
}

void Memory::newStr(strVariable var) {
    strs.push_back(var);
}

std::vector<strVariable> Memory::getStrs() {
    return strs;
}

std::vector<numVariable> Memory::getNums() {
    return nums;
}

void Memory::printVariables() {
    std::cout << "NUMBERS:\n";
    for (auto &v : nums) {
        std::cout << v.name << ": " << v.value.value << '\n';
    }

    std::cout << "STRINGS:\n";
    for (auto &v : strs) {
        std::cout << v.name << ": " << v.value.value << '\n';
    }
}