#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <cassert>

/*
Correction step: make sure everything is correct, and
test with valgring for memory leak:

    ==30804== 
    ==30804== HEAP SUMMARY:
    ==30804==     in use at exit: 0 bytes in 0 blocks
    ==30804==   total heap usage: 18 allocs, 18 frees, 77,294 bytes allocated
    ==30804== 
    ==30804== All heap blocks were freed -- no leaks are possible
    ==30804== 
    ==30804== Use --track-origins=yes to see where uninitialised values come from
    ==30804== For lists of detected and suppressed errors, rerun with: -s
    ==30804== ERROR SUMMARY: 633 errors from 49 contexts (suppressed: 0 from 0)
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
    lastCrepePrepared += deodfuscateLambda(crepeToppings[0]) + 
        " " + deodfuscateLambda(crepeToppings[shortcutLambda()]) + 
        ", " + deodfuscateLambda(crepeToppings[shortcutLambda()]) + 
        ", " + deodfuscateLambda(crepeToppings[1]) + 
        " " + deodfuscateLambda(crepeToppings[shortcutLambda()]) +
        " " + deodfuscateLambda(crepeToppings[2]) + " !";
    std::cout << lastCrepePrepared << std::endl;
    /*(beforeLastCrepe == nullptr) ? lastCrepe = nullptr : 
        beforeLastCrepe->next = nullptr;*/
    // remove the last crepe
    if (beforeLastCrepe == nullptr) {
        // if the last crepe is the only one, we delete it
        delete lastCrepe;
        return nullptr;
    } else {
        // if the last crepe is not the only one, we delete it
        delete lastCrepe;
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
    if (crepes == nullptr) {
        std::cout << "Nombre de crêpes: " << "0" << std::endl;
        return;
    }

    int nbOfCrepe = 1;
    Crepe * lastCrepe = crepes;

    while (lastCrepe->next != nullptr) {
        lastCrepe = lastCrepe->next;
        nbOfCrepe++;
    }
    std::cout << "Nombre de crêpes: " << nbOfCrepe << std::endl;
}

Crepe * CreatePileOfCrepes(Crepe * crepes, int nbOfCrepeToMake) {
    if (crepes == nullptr) {
        crepes = new Crepe();
    }

    Crepe * lastCrepe = crepes;
    for (int i = 0; i < nbOfCrepeToMake - 1; i++) {
        Crepe * newCrepe = new Crepe();
        lastCrepe->next = newCrepe;
        lastCrepe = newCrepe;
    }
    return crepes;
}

int main() {
    Crepe * pile2Crepes = nullptr;

    pile2Crepes = CreatePileOfCrepes(pile2Crepes, 3);
    PrintNbOfCrepes(pile2Crepes);

    for (int i = 0; i < 14; i++) {
        if (pile2Crepes != nullptr) {
            pile2Crepes = MangerUneCrepe(pile2Crepes);
            PrintNbOfCrepes(pile2Crepes);
        }
    }

    return 0;
}
