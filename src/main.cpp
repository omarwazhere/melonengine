#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <variant>
#include <vector>

#include "melon/melonlib.hpp"

World *world = nullptr;
unsigned int current_id = 0;

bool valid_program();
void run_program();
void print_tokens(std::vector<token> tokens);

// MAIN CLI
int main() {
    std::string command;
    std::string currentDirectory;
    std::cout << "Welcome to melon CLI! type 'help' to show avalible commands\n";
    while (true) {
        std::cout << currentDirectory << "> ";
        std::getline(std::cin, command);
        if (command == "info") {
            std::cout << info;
        }

        if (command == "help") {
            std::system("help");

            std::cout << help;
            continue;
        }

        if (command.starts_with("cd ")) {
            std::filesystem::path newDirectory = command.substr(3);

            std::error_code error;
            std::filesystem::current_path(newDirectory, error);

            if (error) {
                std::cout << "Could not change directory: "
                          << error.message() << '\n';
            } else {
                currentDirectory = command.substr(3);
            }

            continue;
        }

        if (command == "prepare") {
            std::ofstream main(currentDirectory + "/main.txt");
            main << "# THIS IS THE MAIN FILE";
            main.close();
            continue;
        }

        if (command == "run") {
            if (valid_program()) {
                run_program();
            } else {
                std::cout << "folder is not prepared, type 'prepare' to make it ready to run\n";
            }
            continue;
        }

        if (command == "exit") {
            break;
        }

        std::system(command.c_str());
    }
    return 0;
}

bool valid_program() {
    std::filesystem::path main = "main.txt";
    if (std::filesystem::exists(main)) { // And other files but later
        return true;
    }
    return false;
}

void run_program() {
    const std::vector<token> tokens = tokenize("main.txt");

    // TEST
    std::vector<instruction> instructions = {
        {opCode::PUSH, 0},
        {opCode::PRINTLN},
        {opCode::JUMP, 0}
    };
    virtualMachine sillyVM(instructions);
    sillyVM.run();
}

void print_tokens(std::vector<token> tokens) {
    for (const token &tok : tokens) {
        std::string type;

        switch (tok.type) {
            case IDENTIFIERTK: type = "IDENTIFIER"; break;
            case INTTK: type = "INTEGER"; break;
            case FLOATTK: type = "FLOATING POINT NUMBER"; break;
            case STRTK: type = "STRING"; break;
            case CHARTK: type = "CHARACTER"; break;
            case INTTYPE: type = "INT TYPE"; break;
            case FLOATTYPE: type = "FLOAT TYPE"; break;
            case STRTYPE: type = "STR TYPE"; break;
            case CHARTYPE: type = "CHAR TYPE"; break;
            case EQUALSTK: type = "EQUALS"; break;
            case BINARYOP: type = "BINARY OP"; break;
            case SEMI: type = "SEMICOLON"; break;
            case OPEN_PAREN: type = "OPEN PARENTHESES"; break;
            case CLOSE_PAREN: type = "CLOSE PARENTHESES"; break;
            case OPEN_CBRACE: type = "OPEN CURLY BRACE"; break;
            case CLOSE_CBRACE: type = "CLOSE CURLY BRACE"; break;
            case EOFTK: type = "END OF FILE"; break;
        }

        std::cout << type << '\n';
    }
}