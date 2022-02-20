#include <iostream>

// this simple program is a CLI tool to obfuscate strings
// by shifting each character by 1
//   compile: g++ -o obfuscate obfuscator.cpp --ansi --pedantic -Wall --std=c++14

// colors
#define LIGHT_ORANGE "\e[38;5;216m"
#define TURQUOISE "\e[38;5;43m"
#define PALE_BLUE "\e[38;5;159m"
#define RED "\e[38;5;196m"
#define NO_COLOR "\e[0m"
#define GREY "\e[38;5;8m"
#define SILVER "\e[38;5;7m"
#define LIGHT_BLUE "\e[38;5;32m"
#define LIGHT_YELLOW "\e[38;5;228m"

#define BOLD "\e[1m"
#define UNDERLINE "\e[4m"

std::string convertToString(char* a, int size)
{
    int i;
    std::string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}

std::string obfuscateString(std::string & str)
{
    // convert string to char array
    char buffer[str.length()];
    std::copy(str.begin(), str.end(), buffer);

    // shift each char by 1
    for (int i = 0; i < (int)str.length(); i++) {
        for (int j = 0; j < i; j++) {
            buffer[i]--;
        }
    }

    // reconvert char array to string
    std::string result(buffer);

    return convertToString(buffer, str.length());
}

std::string deobfuscateString(std::string & str)
{
    // convert string to char array
    char buffer[str.length()];
    std::copy(str.begin(), str.end(), buffer);

    // shift each char by 1 times its position in the string
    for (int i = 0; i < (int)str.length(); i++) {
        for (int j = 0; j < i; j++) {
            buffer[i]++;
        }
    }

    // reconvert char array to string
    std::string result(buffer);

    return convertToString(buffer, str.length());
}

int main(int argc, char** argv)
{
    // print program arguments
    std::cout << LIGHT_ORANGE << "<<<< You have entered " 
        << argc << " arguments >>>>" << NO_COLOR << "\n" ;
  
    for (int i = 0; i < argc; ++i)
    {
        // print original argument string
        std::cout << LIGHT_YELLOW << "argv[" << i << "]: " 
            << argv[i] << NO_COLOR << "\n";

        // print obfuscated argument texts
        std::string argument = std::string(argv[i]);
        argument = obfuscateString(argument);

        std::cout << BOLD << LIGHT_BLUE 
            << "-----> Obfuscated: " << argument 
            << NO_COLOR << "\n";
        
        // print deobfuscated argument texts
        argument = deobfuscateString(argument);
        std::cout << BOLD << TURQUOISE 
            << "-----> Deobfuscated: " << argument 
            << NO_COLOR << "\n";
    }

    
    return 0;
}