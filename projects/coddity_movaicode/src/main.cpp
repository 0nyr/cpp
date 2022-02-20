#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>



/*
Entrée : une liste de string "crêpe" représentant la pile de crêpes
Comportement : retire la dernière "crêpe" de la pile de crêpes
Sortie : une liste de string "crêpe" représentant la pile de crêpes restantes

Idée: pour retirer le dernier élément de la liste, on doit modifier le 
pointeur de la cellule précédente (double linked list).

pour cela, on a besoin de connaître la taille de la liste, 
son avant dernier élément.  

utiliser des macros, des constexpr afin de simplement remplacer le pointeur
de l'avant dernière crepe


Créer ensuite une fonction qui crée ce programme, le makefile, le fichier 
cpp puis exécute la string en tant que code...
*/

class Crepe {
    public: 
        std::string crepe = "";
        Crepe *next;
        Crepe() : crepe(crepe), next(nullptr) {};
        ~Crepe() { delete next; };
};

class CrepeFactory {
    public:
        CrepeFactory() {
            crepeToppings = {
                "crêpe",
                "supplément",
                "sucre",
                "chocolat fondu",
                "poulet",
                "miel",
                "caramel",
                "lardons",
                "champignons",
                "viande",
                "oignons",
                "tomate",
                "creme fraiche",
                "creme hidratante",
                "sauce tomate",
                "sauce soja",
                "sauce curry",
                "sauce poivre",
                "arsenic",
                "sel 'La Bedaine'",
                "vase",
                "vitriol",
                "éclats de savon",
                "gras",
                "neige",
                "béton",
                "plastique",
                "désherbant",
                "sable",
                "cailloux",
                "plutonium",
                "météorite",
                "éclats de CD cassé",
                "matière marron",
                "pourdre de régolite",
                "pépites d'or"
            };
            nbOfCrepeToppings = crepeToppings.size();
        };
        ~CrepeFactory() {};
        void MakeCrepes(int nbOfCrepeToMake, Crepe * crepes) {
            // init random engine
            std::random_device rd;     // only used once to initialise (seed) engine
            std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)

            // make random crepe
            for (int i = 0; i < nbOfCrepeToMake; i++) {
                std::string preparation = "";

                // get a random number between 0 and nbOfCrepeToppings
                
                std::uniform_int_distribution<int> uni(0, nbOfCrepeToppings); // guaranteed unbiased

                auto random_integer = uni(rng);

                Crepe crepe;
                crepe.next = nullptr;
            }
        };


        std::vector<std::string> crepeToppings;
        int nbOfCrepeToppings;
        static int const nbOfCrepeToppingsPerCrepe = 3;
};

Crepe * MangerUneCrepe(Crepe * crepes) {
    // obtenir la dernière crêpe et l'avant-dernière crêpe
    Crepe * lastCrepe = crepes;
    Crepe * beforeLastCrepe = nullptr;

    while (lastCrepe->next != nullptr) {
        beforeLastCrepe = lastCrepe;
        lastCrepe = lastCrepe->next;
    }

    // ajouter le topping à la dernière crêpe
    std::string lastCrepePrepared = lastCrepe->crepe;

    // add a random topping to the last crepe
    std::vector<std::string> crepeToppings = {
        "sucre",
        "chocolat fondu",
        "poulet",
        "miel",
        "caramel",
        "lardons",
        "champignons",
        "viande",
        "oignons",
        "tomate",
        "creme fraiche",
        "creme hidratante",
        "sauce tomate",
        "sauce soja",
        "sauce curry",
        "sauce poivre",
        "arsenic",
        "sel 'La Bedaine'",
        "vase",
        "vitriol",
        "éclats de savon",
        "gras",
        "neige",
        "béton",
        "plastique",
        "désherbant",
        "sable",
        "cailloux",
        "plutonium",
        "météorite",
        "éclats de CD cassé",
        "matière marron",
        "pourdre de régolite",
        "pépites d'or"
    };    int timeNumber = clock();

    int topping1 = rand() % crepeToppings.size();
    int topping2 = rand() % crepeToppings.size();
    int topping3 = rand() % crepeToppings.size();

    lastCrepePrepared += " " + crepeToppings[topping1] + 
        " " + crepeToppings[topping2] + 
        " " + crepeToppings[topping3];



    // retirer la dernière crêpe
    if (beforeLastCrepe == nullptr) {
        // si la dernière crêpe est la seule crêpe
        lastCrepe = nullptr;
    } else {
        // si la dernière crêpe n'est pas la seule, on la retire
        beforeLastCrepe->next = nullptr;
    }

    return crepes;
}

int main() {
    // Création de la pile de crêpes
    Crepe * pile2Crepes = new Crepe();

    /*CrepeFactory crepeFactory;
    for (int i=0; i<crepeFactory.nbOfCrepeToppings; i++) {
        std::string crepeTopping = obfuscateString(crepeFactory.crepeToppings[i]);
        std::cout << crepeTopping << std::endl;
    }*/

    std::vector<std::string> crepeToppingsObfuscated = {
        "tvdsf",
        "dipdpmbu!gpoev",
        "qpvmfu",
        "njfm",
        "dbsbnfm",
        "mbsepot",
        "dibnqjhopot",
        "wjboef",
        "pjhopot",
        "upnbuf",
        "dsfnf!gsbjdif",
        "dsfnf!ijesbubouf",
        "tbvdf!upnbuf",
        "tbvdf!tpkb",
        "tbvdf!dvssz",
        "tbvdf!qpjwsf",
        "bstfojd",
        "tfm!(Mb!Cfebjof(",
        "wbtf",
        "wjusjpm",
        "Īdmbut!ef!tbwpo",
        "hsbt",
        "ofjhf",
        "cĪupo",
        "qmbtujrvf",
        "eĪtifscbou",
        "tbcmf",
        "dbjmmpvy",
        "qmvupojvn",
        "nĪuĪpsjuf",
        "Īdmbut!ef!DE!dbttĪ",
        "nbujĩsf!nbsspo",
        "qpvsesf!ef!sĪhpmjuf",
        "qĪqjuft!e(ps",
    };



    return 0;
}
