#include <iostream>
#include <string>
#include <cstdlib>

void sayHello(std::string& name) {
    std::cout << "Hello, " << name << "!" << std::endl;
}

int main() {
    
    // Optional welcoming
    std::cout << "Welcome to Term++ v0.0.1 :D\n";

    while (true)
    {
        // input string variable for storing input and starting the terminal's prompt
        std::string name;
        std::string userInput;

        // if-statements block for logic
        std::cout << "++> ";

        // start reading input from userInput
        std::cin >> userInput;

        if (userInput == "help")
        {
            std::cout << "-- Help Menu -- \n";
            std::cout << "version - display current build version of this project\n";
            std::cout << "help - display this help menu\n";
            std::cout << "hello - get greeted with your desired name\n";
            std::cout << "exit - exit the terminal\n";
            std::cout << "clear - clear the terminal\n";
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
        else
        {
            std::cout << "Unknown command: " << userInput << std::endl;
        }
    }
}