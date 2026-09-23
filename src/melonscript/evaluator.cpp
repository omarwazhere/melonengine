#include <variant>
#include <vector>

#include "../melon/melonlib.hpp"

void evaluate(const program &program, Memory &memory) {
    for (auto &statement : program.statements) {


        if (std::holds_alternative<declareStatement>(statement)) {
            declareStatement thingy = std::get<declareStatement>(statement); // Havent found a better name ;)
            if (thingy.type == varType::NUMBERTYPE) {
                memory.newNum(std::get<numVariable>(thingy.var));
            } else if (thingy.type == varType::STRINGTYPE) {
                memory.newStr(std::get<strVariable>(thingy.var));
            }
        }


        else if (std::holds_alternative<assignStatement>(statement)) {
            assignStatement thingy = std::get<assignStatement>(statement); // ;)
            if (std::holds_alternative<strVariable>(thingy.var)) {
                strVariable var = std::get<strVariable>(thingy.var);
                std::vector<strVariable> strs = memory.getStrs();
                for (auto &str : strs) {
                    if (str.name == var.name) {
                        var.value = str.value; 
                    }
                }
            } 
            
            else if (std::holds_alternative<numVariable>(thingy.var)) {
                numVariable var = std::get<numVariable>(thingy.var);
                std::vector<numVariable> nums = memory.getNums();
                for (auto &num : nums) {
                    if (num.name == var.name) {
                        var.value = num.value; 
                    }
                }
            }
            
        }
    }
}