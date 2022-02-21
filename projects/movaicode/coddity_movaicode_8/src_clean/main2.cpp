#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <cassert>

/*
Continuing the minification process.
Here, we also replace if-else statements with
its one-liner version (condition) ? then : else;
*/

class Crepe {
    public: 
        std::string crepe = "";
        Crepe *next;
        Crepe() : crepe(crepe), next(nullptr) {};
        ~Crepe() { delete next; };
};

Crepe * MangerUneCrepe(Crepe * c) {
    if (c == nullptr) return nullptr;
    Crepe * lastCrepe = c;
    Crepe * beforeLastCrepe = nullptr;
    while (lastCrepe->next != nullptr) {
        beforeLastCrepe = lastCrepe;
        lastCrepe = lastCrepe->next;
    }
    std::string lastCrepePrepared = lastCrepe->crepe;
    std::vector<std::string> crepeToppings = {
"bs«of","rvoqkĨndos","lbmhªd","rvbsd", "bindnm`u","optmdu",
"ljdm","bbqblfk","kbqenor","bi`nojfonor","uj`ocf","njfonor",
"bs©lf","splbsfr","rpib","bvqsx","dyomnthg","`srfmjb",
"ujsshpk","rbupm","fs`t","mfhhd","aĨuno","om`tsjpvd","rbamd",
"cĨtgfqc`os","bbhmkpty","omtunohvl","lĨuªnshud","qĨhnmhud"
    };
    auto deodfuscateLambda = [&](std::string & str) {
        char buffer[str.length()];
        std::copy(str.begin(), str.end(), buffer);
        for (int i = 0; i < (int)str.length(); i++) {
            if (i % 2 == 0) {
                buffer[i]++;
            } else {
                buffer[i]--;
            }
        }
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
    auto shortcutLambda = [&]() {
        return rand() % (crepeToppings.size() - 3) + 3;
    };
    int topping1 = shortcutLambda();
    int topping2 = shortcutLambda();
    int topping3 = shortcutLambda();
    lastCrepePrepared += deodfuscateLambda(crepeToppings[0]) + 
        " " + deodfuscateLambda(crepeToppings[topping1]) + 
        ", " + deodfuscateLambda(crepeToppings[topping2]) + 
        ", " + deodfuscateLambda(crepeToppings[1]) + 
        " " + deodfuscateLambda(crepeToppings[topping3]) +
        " " + deodfuscateLambda(crepeToppings[2]) + " !";
    std::cout << lastCrepePrepared << std::endl;
    (beforeLastCrepe == nullptr) ? lastCrepe = nullptr : 
        beforeLastCrepe->next = nullptr;
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
