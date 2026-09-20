#include <iostream>
#include <string>
#include <fstream>

#include "melon/melonlib.hpp"

World *world = nullptr;
unsigned int current_id = 0;

void printfile(const std::string& path);

int main() {
    std::string command;
    std::string currentDirectory = "C:";
    while (true) {
        std::cout << currentDirectory << "> ";
        std::cin >> command;
        if (command == "help") {
            printfile("../docs/help.txt");
        } else if (command == "info") {
            printfile("../docs/info.txt");
        } else if (command == "cd") {
            std::cin >> currentDirectory;
        } else if (command == "prepare") {
            std::ofstream main(currentDirectory + "/main.txt");
            main << "# THIS IS THE MAIN FILE";
            main.close();
        } else {
            std::cout << "Unknown command";
        }
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