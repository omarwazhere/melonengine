#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

#include "melon/melonlib.hpp"

World *world = nullptr;
unsigned int current_id = 0;

bool valid_program();
void run_program();

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
    tokenize("main.txt");
}