#include "commands.hpp"

#include <iostream>
#include <string>
#include <cstdlib>
#include <filesystem>
#include <sstream>
#include <fstream>

int main() {
    
    // Optional welcoming
    std::cout << "Welcome to Term++ v0.0.5 :D\n";

    // the main loop that runs the terminal
    while (true)
    {
        // declare the userInput variable for storing user's input; declare the name variable for storing the user's name
        std::string userInput;

        // the prompt
        std::cout << run_pwd() << " ++> ";

        // start reading input from userInput
        if (!std::getline(std::cin, userInput)) {
            break;
        }

        //iss implementation for cmd and arg reading
        std::istringstream input(userInput);

        std::string cmd;
        std::string arg;
        std::string op;
        std::string delimiter;

        input >> cmd;
        input >> op;
        input >> arg;
        input >> delimiter;

        if (arg.empty()) {
            arg = op;
            op.clear();
        }

        // if-statement block
        if (cmd == "help")
        {
            std::cout << "-- Help Menu -- \n";
            std::cout << "version - display current build version of this project\n";
            std::cout << "help - display this help menu\n";
            std::cout << "hello - get greeted with your desired name\n";
            std::cout << "exit - exit the terminal\n";
            std::cout << "clear - clear the terminal\n";
            std::cout << "ls - list all of the available directories and the content of them\n";
            std::cout << "mkdir - make a directory\n";
            std::cout << "pwd - print the current directory\n";
            std::cout << "cd - change directory\n";
            std::cout << "touch - make a file\n";
            std::cout << "cat - output the inside of a file or input something into the file\n";
        } 
        else if (cmd == "version")
        {
            std::cout << "v0.0.5\n";
        }
        else if (cmd == "hello")
        {
            if (arg.empty())
            {
                std::cout << "Usage: hello <name>\n";
            }
            else 
            {
                sayHello(arg);
            }
        }
        else if (cmd == "exit")
        {
            std::cout << "Exiting... (return 0)\n";
            return 0;
        }
        else if (cmd == "clear")
        {
            #ifdef _WIN32
                std::system("cls");
            #else
                std::system("clear");
            #endif
        }
        else if (cmd == "ls")
        {
            if (arg.empty())
            {
                run_ls(".");
            }
            else
            {
                run_ls(arg);
            }
        }
        else if (cmd == "mkdir")
        {
            run_mkdir(arg);
        }
        else if (cmd == "pwd")
        {
            std::cout << run_pwd() << '\n';
        }
        else if (cmd == "cd")
        {
            run_cd(arg);
        }
        else if (cmd == "touch")
        {
            run_touch(arg);
        }
        else if (cmd == "cat")
        { 
            
            if (op.empty())
            {
                run_cat(arg);
            }
            else if (op == ">>")
            {
                if (delimiter.size() > 2 && delimiter[0] == '<' && delimiter[1] == '<') {
                    std::string endWord = delimiter.substr(2);

                    run_catAppend(arg, endWord);
                }
            }
            else
            {
                std::cout << "Usage: cat <file> or cat >> <file> <input>\n";
            }
        }
        else
        {
            std::cout << "Unknown command: " << cmd << std::endl;
        }
    }
}
