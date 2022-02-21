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

Crepe * MangerUneCrepe(Crepe * cpp) {
    if(cpp==nullptr)return nullptr;Crepe*l=cpp;Crepe*b=nullptr;
    while(l->next!=nullptr){b=l;l=l->next;}std::string p=l->crepe;
    std::vector<std::string>t={"bs«of","lĨuªnshud","rvoqkĨndos",
    "lbmhªd","rvbsd", "bindnm`u","optmdu","ljdm","bbqblfk","kbqenor",
    "bi`nojfonor","uj`ocf","njfonor","bs©lf","splbsfr","rpib","bvqsx",
    "dyomnthg","`srfmjb","ujsshpk","rbupm","mfhhd","aĨuno","rbamd",
    "om`tsjpvd","cĨtgfqc`os","bbhmkpty","omtunohvl","fs`t","qĨhnmhud"};
    auto L0=[&](std::string&str){char buffer[str.length()];
    std::copy(str.begin(),str.end(),buffer);for(int i=0;i<(int)str.length();
    i++){(i%2==0)?buffer[i]++:buffer[i]--;}auto L1=[&](char* a,int size)
    {int i;std::string s="";for(i=0;i<size;i++){s=s+a[i];}return s;};
    return L1(buffer,str.length());};auto L2=[&]()
    {return rand()%(t.size()-3)+3;};p+=L0(t[0])+" "+L0(t[L2()])+", "
    +L0(t[L2()])+", "+L0(t[1])+" "+ L0(t[L2()])+" "+L0(t[2])+" !";
    std::cout << p << std::endl; delete l;
    (b == nullptr) ? cpp = nullptr : b->next = nullptr;return cpp;
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
