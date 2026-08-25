#include <iostream>
#include <string>
#include <cstdlib>
#include <filesystem>

// give std::filesystem a nickname for easier access
namespace fs = std::filesystem;

// define the sayHello function for later use
void sayHello(std::string& name) {
    std::cout << "Hello, " << name << "!" << std::endl;
}

// define the run_ls function for later use
void run_ls() {
    for (const auto& entry : fs::directory_iterator(".")) {
        std::cout << entry.path().filename().string() << "\n";
    }
}

int main() {
    
    // Optional welcoming
    std::cout << "Welcome to Term++ v0.0.1 :D\n";

    // the main loop that runs the terminal
    while (true)
    {
        // declare the userInput variable for storing user's input; declare the name variable for storing the user's name
        std::string name;
        std::string userInput;

        // the prompt
        std::cout << "++> ";

        // start reading input from userInput
        std::cin >> userInput;

        // if-statement block
        if (userInput == "help")
        {
            std::cout << "-- Help Menu -- \n";
            std::cout << "version - display current build version of this project\n";
            std::cout << "help - display this help menu\n";
            std::cout << "hello - get greeted with your desired name\n";
            std::cout << "exit - exit the terminal\n";
            std::cout << "clear - clear the terminal\n";
            std::cout << "ls - list all of the available directories\n";
        } 
        else if (userInput == "version")
        {
            std::cout << "v0.0.1 (self-learning hobby for C++ practice :D)\n";
        }
        else if (userInput == "hello")
        {
            std::cout << "Enter name: ";
            std::cin >> name;
            sayHello(name);
        }
        else if (userInput == "exit")
        {
            std::cout << "Exiting... (return 0)\n";
            return 0;
        }
        else if (userInput == "clear")
        {
            #ifdef _WIN32
                std::system("cls");
            #else
                std::system("clear");
            #endif
        }
        else if (userInput == "ls")
        {
            run_ls();
        }
        else
        {
            std::cout << "Unknown command: " << userInput << std::endl;
        }
    }
}