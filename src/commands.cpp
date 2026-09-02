#include "commands.hpp"

#include <iostream>
#include <string>
#include <filesystem>
#include <sstream>
#include <istream>
#include <fstream>

namespace fs = std::filesystem;

// define the sayHello function for later use
void sayHello(const std::string& name) {
    std::cout << "Hello, " << name << "!" << std::endl;
}

// define the run_ls function for later use
void run_ls(const std::string& path = ".") {
    for (const auto& entry : fs::directory_iterator(path)) {
        std::cout << entry.path().filename().string() << "\n";
    }
}

// mkdir function for later use
void run_mkdir(const std::string& arg) {
    try {
        fs::create_directory(arg);
    } catch (fs::filesystem_error& e) {
        std::cout << "ERROR: dir already exists.\n";
    }
}

// cd function for later use
void run_cd(const std::string& arg) {
    try {
        fs::current_path(arg);
    } catch (fs::filesystem_error& e) {
        std::cout << "ERROR: nonexistent dir.\n";
    }
}

// touch function for later use
void run_touch(const std::string& arg) {
    std::ofstream file(arg);

    if (!file) {
        std::cout << "Could not create file.\n";
    }
}

// cat function for later use
void run_cat(const std::string& arg) {
    std::ifstream file(arg);

    if (!file) {
        std::cout << "File not found\n";
        return;
    }

    std::string line;

    while(std::getline(file, line)) {
        std::cout << line << "\n";
    }
}

void run_catAppend(const std::string& arg, const std::string& delimiter) {
    std::ofstream file(arg, std::ios::app);

    if (!file) {
        std::cout << "File not found\n";
        return;
    }

    std::string line;

    while (std::getline(std::cin, line)) {
        
        if (line == delimiter) {
            break;
        }

        file << line << '\n';
    }

    std::cin.clear();
}

// pwd function for later use
std::string run_pwd() {
    return fs::current_path().string();
}