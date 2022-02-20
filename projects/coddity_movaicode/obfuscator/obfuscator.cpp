#include <iostream>
#include <vector>

// this simple program is a CLI tool to obfuscate strings
// by shifting each character by 1
//    compile: g++ -o main obfuscator.cpp --ansi --pedantic -Wall --std=c++14
//    Add colorful output -D COLORS

// colors
#ifdef COLORS
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
#else
#define LIGHT_ORANGE ""
#define TURQUOISE ""
#define PALE_BLUE ""
#define RED ""
#define NO_COLOR ""
#define GREY ""
#define SILVER ""
#define LIGHT_BLUE ""
#define LIGHT_YELLOW ""

#define BOLD ""
#define UNDERLINE ""
#endif

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
        if (i % 2 == 0) {
            buffer[i]--;
        } else {
            buffer[i]++;
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
        if (i % 2 == 0) {
            buffer[i]++;
        } else {
            buffer[i]--;
        }
    }

    // reconvert char array to string
    std::string result(buffer);

    return convertToString(buffer, str.length());
}

void obfuscateAndPrintText(std::string & text)
{
    // print original argument string
    std::cout << LIGHT_YELLOW << " + arg: " 
        << text << NO_COLOR << "\n";

    // print obfuscated argument texts
    text = obfuscateString(text);

    std::cout << BOLD << LIGHT_BLUE 
        << "-----> Obfuscated: " << text 
        << NO_COLOR << "\n";
    
    // print deobfuscated argument texts
    text = deobfuscateString(text);
    std::cout << BOLD << TURQUOISE 
        << "-----> Deobfuscated: " << text 
        << NO_COLOR << "\n";
}

void obfuscateAndPrintTextRaw(std::string & text)
{
    // print obfuscated argument texts
    text = obfuscateString(text);
    std::cout << text << std::endl;
}

void deobfuscateAndPrintText(std::string & text)
{
    // print original argument string
    std::cout << LIGHT_YELLOW << " + arg: " 
        << text << NO_COLOR << "\n";

    // print deobfuscated argument texts
    text = deobfuscateString(text);

    std::cout << BOLD << LIGHT_BLUE 
        << "-----> Deobfuscated: " << text 
        << NO_COLOR << "\n";
    
    // print obfuscated argument texts
    text = obfuscateString(text);
    std::cout << BOLD << TURQUOISE 
        << "-----> Obfuscated: " << text 
        << NO_COLOR << "\n";
}

void obfuscateAndPrintArgs(int argc, char* argv[])
{
    // print program arguments
    std::cout << LIGHT_ORANGE << "<<<< You have entered " 
        << argc << " arguments >>>>" << NO_COLOR << std::endl;
    std::cout << PALE_BLUE << "<<<< OBFUSCATE MODE >>>>"
        << NO_COLOR << std::endl;
    
    for (int i = 0; i < argc; ++i)
    {
        std::string argument = std::string(argv[i]);
        obfuscateAndPrintText(argument);
    }
}

void deobfuscateAndPrintArgs(int argc, char* argv[])
{
    // print program arguments
    std::cout << LIGHT_ORANGE << "<<<< You have entered " 
        << argc << " arguments >>>>" << NO_COLOR << std::endl;
    std::cout << PALE_BLUE << "<<<< DE-OBFUSCATE MODE >>>>"
        << NO_COLOR << std::endl;
    
    for (int i = 0; i < argc; ++i)
    {
        std::string argument = std::string(argv[i]);
        deobfuscateAndPrintText(argument);
    }
}

int main(int argc, char** argv)
{
    // if more than 1 argument is passed
    if (argc > 1)
    {
        // check for -d (deobfuscate) flag
        for (int i = 0; i < argc; ++i)
        {
            std::string argument = std::string(argv[i]);
            if (argument == "-d")
            {
                deobfuscateAndPrintArgs(argc, argv);
                return 0;
            }
        }

        // check for -d (deobfuscate) flag
        for (int i = 0; i < argc; ++i)
        {
            std::string argument = std::string(argv[i]);
            if (argument == "-r")
            {
                std::vector<std::string> texts = {
                    "bs«of",
                    "rvoqkĨndos",
                    "rvbsd"
                };
                for(auto text : texts) {
                    deobfuscateAndPrintText(text);
                }
                return 0;
            }
        }

        // default: convert and print arguments
        obfuscateAndPrintArgs(argc, argv);
    }
    else
    {
        // print usage
        std::cout << LIGHT_ORANGE << "<<<< Usage: " 
            << argv[0] << " [arguments] >>>>" << NO_COLOR << "\n";

        // print default
        std::vector<std::string> texts = {
            "crêpe",
            "supplément",
            "sucre",
            "chocolat",
            "poulet",
            "miel",
            "caramel",
            "lardons",
            "champignons",
            "viande",
            "oignons",
            "crème",
            "tomates",
            "soja",
            "curry",
            "explosif",
            "arsenic",
            "vitriol",
            "savon",
            "gras",
            "neige",
            "béton",
            "plastique",
            "désherbant",
            "sable",
            "cailloux",
            "plutonium",
            "météorite",
            "régolite"
        };
        for(auto text : texts) {
            obfuscateAndPrintTextRaw(text);
        }
    }
    
    return 0;
}