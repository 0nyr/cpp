#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <cassert>

/*
this is the lambda conversion step.
The idea is to make the code shorter as well as 
making it even more convoluted
*/

class Crepe {
    public: 
        std::string crepe = "";
        Crepe *next;
        Crepe() : crepe(crepe), next(nullptr) {};
        ~Crepe() { delete next; };
};

std::string convertToString(char* a, int size)
{
    int i;
    std::string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
} 

// try C++ lambdas here, before making a macro
/*
#define CONVERT_TO_STRING(buffer,bufferLength) ({int i;
    std::string s = ""; for (i = 0; i < size; i++) {s = s + a[i];}return s;})
#define debug(text) (std::cout << LIGHT_ORANGE << "[debug]: " << text << " (" << __FILE__ << ":" << __LINE__ << ")" << NO_COLOR << std::endl)
*/


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
    return convertToString(buffer, str.length());
    auto convert = [&](char* a, int size) {
        int i;
        std::string s = "";
        for (i = 0; i < size; i++) {
            s = s + a[i];
        }
        return s;
    };
    return convert(buffer, str.length());
}



/**
 * @brief Remove the last crepe from the list
 * 
 * @param crepes a list of crepes
 * @return Crepe* the remaining list of crepes
 */
Crepe * MangerUneCrepe(Crepe * c) {
    // return nullptr if no crepes
    if (c == nullptr) {
        return nullptr;
    }

    // get last and before last crepes
    Crepe * lastCrepe = c;
    Crepe * beforeLastCrepe = nullptr;

    while (lastCrepe->next != nullptr) {
        beforeLastCrepe = lastCrepe;
        lastCrepe = lastCrepe->next;
    }

    // Add topping to last crepe
    std::string lastCrepePrepared = lastCrepe->crepe;

    // add a random topping to the last crepe
    std::vector<std::string> crepeToppings = {
        "bs«of",
        "rvoqkĨndos",
        "lbmhªd",
        "rvbsd",
        "bindnm`u",
        "optmdu",
        "ljdm",
        "bbqblfk",
        "kbqenor",
        "bi`nojfonor",
        "uj`ocf",
        "njfonor",
        "bs©lf",
        "splbsfr",
        "rpib",
        "bvqsx",
        "dyomnthg",
        "`srfmjb",
        "ujsshpk",
        "rbupm",
        "fs`t",
        "mfhhd",
        "aĨuno",
        "om`tsjpvd",
        "cĨtgfqc`os",
        "rbamd",
        "bbhmkpty",
        "omtunohvl",
        "lĨuªnshud",
        "qĨhnmhud"
    };

    // +x since we use the first x elements of the vector differently
    int topping1 = (rand() % (crepeToppings.size() - 3)) + 3; 
    int topping2 = (rand() % (crepeToppings.size() - 3)) + 3;
    int topping3 = (rand() % (crepeToppings.size() - 3)) + 3;

    auto deodfuscateLambda = [&](std::string & str)
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
        return convertToString(buffer, str.length());
        auto convert = [&](char* a, int size) {
            int i;
            std::string s = "";
            for (i = 0; i < size; i++) {
                s = s + a[i];
            }
            return s;
        };
        return convert(buffer, str.length());
    };

    lastCrepePrepared += deodfuscateLambda(crepeToppings[0]) + 
        " " + deodfuscateLambda(crepeToppings[topping1]) + 
        ", " + deodfuscateLambda(crepeToppings[topping2]) + 
        ", " + deodfuscateLambda(crepeToppings[1]) + 
        " " + deodfuscateLambda(crepeToppings[topping3]) +
        " " + deodfuscateLambda(crepeToppings[2]) + " !";

    std::cout << lastCrepePrepared << std::endl;

    // remove the last crepe
    if (beforeLastCrepe == nullptr) {
        // if the last crepe is the only one, we delete it
        lastCrepe = nullptr;
    } else {
        // if the last crepe is not the only one, we delete it
        beforeLastCrepe->next = nullptr;
    }

    return c;
}

void AddCrepesToPile(Crepe * crepes, int nbOfCrepeToMake) {
    Crepe * lastCrepe = crepes;
    while (lastCrepe->next != nullptr) {
        lastCrepe = lastCrepe->next;
    }

    for (int i = 0; i < nbOfCrepeToMake; i++) {
        Crepe * newCrepe = new Crepe();
        lastCrepe->next = newCrepe;
        lastCrepe = newCrepe;
    }
}

void PrintNbOfCrepes(Crepe * crepes) {
    int nbOfCrepe = 0;
    Crepe * lastCrepe = crepes;
    while (lastCrepe->next != nullptr) {
        lastCrepe = lastCrepe->next;
        nbOfCrepe++;
    }
    std::cout << "Nombre de crêpes: " << nbOfCrepe << std::endl;
}

void CreatePileOfCrepes(Crepe * crepes, int nbOfCrepeToMake) {
    Crepe * lastCrepe = crepes;
    while (lastCrepe->next != nullptr) {
        lastCrepe = lastCrepe->next;
    }

    for (int i = 0; i < nbOfCrepeToMake; i++) {
        Crepe * newCrepe = new Crepe();
        lastCrepe->next = newCrepe;
        lastCrepe = newCrepe;
    }
}

int main() {
    Crepe * pile2Crepes = new Crepe();

    CreatePileOfCrepes(pile2Crepes, 10);
    PrintNbOfCrepes(pile2Crepes);

    for (int i = 0; i < 7; i++) {
        MangerUneCrepe(pile2Crepes);
        PrintNbOfCrepes(pile2Crepes);
    }

    return 0;
}
