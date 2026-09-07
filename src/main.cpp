#include "commands.hpp"

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <vector>

int main() {

    // Optional welcoming
    std::cout << "Welcome to Term++ v0.0.5 :D (experimental branch)\n";

    // the main loop that runs the terminal
    while (true)
    {
        // declare the userInput variable for storing user's input; declare the name variable for storing the user's name
        std::string name;
        std::string userInput;

        // declare the folderName variable for storing the new folder's name
        std::string folderName;

        std::string path;

        // the prompt
        std::cout << run_pwd() << " ++> ";

        // start reading input from userInput
        if (!std::getline(std::cin, userInput)) {
            break;
        }

        //iss implementation for cmd and arg reading
        std::istringstream input(userInput);

        //std::string cmd;
        //std::string op;
        //std::string arg;
        //std::string delimiter;

        //input >> cmd;
        //input >> op;
        //input >> arg;
        //input >> delimiter;

        //if (arg.empty()) {
        //    arg = op;
        //    op.clear();
        //}

        std::vector<std::string> tokens;
        std::string token;

        while (input >> token) {
            tokens.push_back(token);
        }

        // if-statement block
        if (tokens[0] == "help")
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
        else if (tokens[0] == "version")
        {
            std::cout << "v0.0.5 (experimental branch)\n";
        }
        else if (tokens[0] == "hello")
        {
            if (tokens.size() == 1)
            {
                std::cout << "Usage: hello <name>\n";
            }
            else
            {
                sayHello(tokens[1]);
            }
        }
        else if (tokens[0] == "exit")
        {
            std::cout << "Exiting... (return 0)\n";
            return 0;
        }
        else if (tokens[0] == "clear")
        {
            #ifdef _WIN32
                std::system("cls");
            #else
                std::system("clear");
            #endif
        }
        else if (tokens[0] == "ls")
        {
            if (tokens.size() < 2)
            {
                run_ls(".");
            }
            else
            {
                run_ls(tokens[1]);
            }
        }
        else if (tokens[0] == "mkdir")
        {
            run_mkdir(tokens[1]);
        }
        else if (tokens[0] == "pwd")
        {
            std::cout << run_pwd() << '\n';
        }
        else if (tokens[0] == "cd")
        {
            if (tokens.size() == 2)
            {
                run_cd(tokens[1]);
            }
            else
            {
                std::cout << "Usage: cd <directory>\n";
            }
        }
        else if (tokens[0] == "touch")
        {
            run_touch(tokens[1]);
        }
        else if (tokens[0] == "cat")
        {
            if (tokens.size() == 2)
            {
                run_cat(tokens[1]);
            }
            else if (tokens.size() == 4 && tokens[1] == ">>")
            {
                if (tokens[3].size() > 2 &&
                    tokens[3][0] == '<' &&
                    tokens[3][1] == '<')
                {
                    std::string endWord = tokens[3].substr(2);

                    run_catAppend(tokens[2], endWord);
                }
                else
                {
                    std::cout << "Usage: cat >> <file> <<EOF\n";
                }
            }
            else
            {
                std::cout << "Usage: cat <file> or cat >> <file> <<EOF\n";
            }
        }
        else if (tokens[0] == "rm")
        {
            bool force = false;
            bool recursive = false;

            if (tokens.size() < 2) {
                std::cout << "Usage: rm [-r | -f | -rf] <file>\n";
            }
            else if (tokens.size() == 2) {
                run_rm(tokens[1], recursive, force);
            }
            else if (tokens[1] == "-r")
            {
                recursive = true;
                run_rm(tokens[2], recursive, force);
            }
            else if (tokens[1] == "-f") {
                force = true;
                run_rm(tokens[2], recursive, force);
            }
            else if (tokens[1] == "-rf") {
                recursive = true;
                force = true;
                run_rm(tokens[2], recursive, force);
            }
            else
            {
                std::cout << "Unknown command: " << tokens[0] << std::endl;
            }
        }
    }
}
