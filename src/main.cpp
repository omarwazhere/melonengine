#include <iostream>
#include <string>
#include <fstream>

#include "melon/melonlib.hpp"

World *world = nullptr;
unsigned int current_id = 0;

void printfile(const std::string& path);

int main() {
    std::string command;
    std::string currentDirectory;
    while (true) {
        std::cout << currentDirectory << "> ";
        std::getline(std::cin, command);
        if (command == "info") {
            printfile("../docs/info.txt");
        }

        if (command == "help") {
            std::system("help");

            printfile("../docs/help.txt");
            continue;
        }

        if (command.starts_with("cd")) {
            currentDirectory = command.substr(3);
            std::system(("cd /d \"" + currentDirectory + "\"").c_str());
            continue;
        }

        if (command == "prepare") {
            std::ofstream main(currentDirectory + "/main.txt");
            main << "# THIS IS THE MAIN FILE";
            main.close();
            continue;
        }

        if (command == "exit") {
            break;
        }

        std::system(command.c_str());
    }
    return 0;
}

void printfile(const std::string &path) {
    std::ifstream file(path);
    std::string line;
    if (file.is_open()) {
        while (std::getline(file, line)) {
            std::cout << line << '\n';
        }
        
        file.close();
    } else {
        std::cerr << "Error opening file for reading! (File may not exist)\n";
    }
}