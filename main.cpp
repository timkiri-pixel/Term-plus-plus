#include <iostream>
#include <string>
#include <cstdlib>
#include <filesystem>
#include <sstream>
#include <fstream>

// give std::filesystem a nickname for easier access
namespace fs = std::filesystem;

// define the sayHello function for later use
void sayHello(std::string& name) {
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

// pwd function for later use
std::string run_pwd() {
    return fs::current_path().string();
}

int main() {
    
    // Optional welcoming
    std::cout << "Welcome to Term++ v0.0.4 :D\n";

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
        std::getline(std::cin, userInput);

        //iss implementation for cmd and arg reading
        std::istringstream input(userInput);

        std::string cmd;
        std::string arg;

        input >> cmd;
        input >> arg;

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
            std::cout << "cat - output the inside of a file\n";
        } 
        else if (cmd == "version")
        {
            std::cout << "v0.0.4\n";
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
            run_cat(arg);
        }
        else
        {
            std::cout << "Unknown command: " << cmd << std::endl;
        }
    }
}