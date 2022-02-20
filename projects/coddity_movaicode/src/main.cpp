#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <cassert>

class Crepe {
    public: 
        std::string crepe = "";
        Crepe *next;
        Crepe() : crepe(crepe), next(nullptr) {};
        ~Crepe() { delete next; };
};

/**
 * @brief Remove the last crepe from the list
 * 
 * @param crepes a list of crepes
 * @return Crepe* the remaining list of crepes
 */
Crepe * MangerUneCrepe(Crepe * crepes) {
    // return nullptr if no crepes
    if (crepes == nullptr) {
        return nullptr;
    }

    // get last and before last crepes
    Crepe * lastCrepe = crepes;
    Crepe * beforeLastCrepe = nullptr;

    while (lastCrepe->next != nullptr) {
        beforeLastCrepe = lastCrepe;
        lastCrepe = lastCrepe->next;
    }

    // Add topping to last crepe
    std::string lastCrepePrepared = lastCrepe->crepe;

    // add a random topping to the last crepe
    std::vector<std::string> crepeToppings = {
        "crêpe",
        "supplément",
        "mangée",
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

    // +x since we use the first x elements of the vector differently
    int topping1 = (rand() % (crepeToppings.size() - 3)) + 3; 
    int topping2 = (rand() % (crepeToppings.size() - 3)) + 3;
    int topping3 = (rand() % (crepeToppings.size() - 3)) + 3;

    lastCrepePrepared += crepeToppings[0] + 
        " " + crepeToppings[topping1] + 
        ", " + crepeToppings[topping2] + 
        ", " + crepeToppings[1] + 
        " " + crepeToppings[topping3] +
        " " + crepeToppings[2] + " !";

    std::cout << lastCrepePrepared << std::endl;

    // remove the last crepe
    if (beforeLastCrepe == nullptr) {
        // if the last crepe is the only one, we delete it
        lastCrepe = nullptr;
    } else {
        // if the last crepe is not the only one, we delete it
        beforeLastCrepe->next = nullptr;
    }

    return crepes;
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
