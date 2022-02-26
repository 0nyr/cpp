# 🌵 Coddity Movaicode #8

My personal participation to the challenge.

(Crêpe++)--

## 📎 Énoncé du sujet : mange_une_crepe()

> Taken from the challenge README

Tous à poêle ! C'est l'heure de faire des crêpes !

Mais bon, s'agit pas que de les faire, à un moment donné faut le manger eul bazar.

Alors pour cette édition, vas y pas qu'on va se faire une
petite fonction à pas piquer des hannetons qui va taper une crêpe dans
l'assiette. Let me introduce you la fonction **mange_une_crepe()**
qui va retirer la dernière crêpe de la pile de crêpes (une liste de N
strings "crêpe"). Après vous vous la tartinez comme vous voulez, ça nous
regarde pas.

```python
def mange_une_crepe(pile_de_crepes: List[str]) -> List[str]:
    '''
    Entrée : une liste de string "crêpe" représentant la pile de crêpes
    Comportement : retire la dernière "crêpe" de la pile de crêpes
    Sortie : une liste de string "crêpe" représentant la pile de crêpes restantes
    '''
    return pile_de_crepes
```

*Et bien évidemment, de la manière la plus exécrable, la plus compliquée ou la moins optimisée possible.*

## 🍪 TODOs

* [X] Convert the function `convertToString()` into a lambda expression.
* [X] Convert the converted lambda expression into a macro.
* [X] Minify the code.

## 🚀️ My submission: (Crêpe++)-- ou le côté obscur de la force

Le C++ est un joli langage, bien que complexe. Il offre une syntaxe puissante, permettant de faire du code très optimisé pour tous les magiciens du code en mal de grands pouvoirs.

J'aurais pu, comme @[finxol](https://github.com/finxol) choisir la voie de la rapidité. Avec C++ et les `lambda expressions`, on peut parvenir à un nombre de bytes encore inférieux à sa solution python (17 bytes), ou même celle de @[Shynif](https://github.com/Shynif) en JavaScript (15 bytes):

Solution en **14 bytes** pour elever le dernier élément d'une liste (plus de détail sur le code [ici](https://github.com/0nyr/cpp/tree/main/projects/movaicode/shortest_vect_pop)):

```cpp
[&]{a.p();}();
```

Cependant,, un grand pouvoir implique une grande irresponsabilité! J'ai donc choisi le côté obscur de la ~force~ crêpe en faisant du  C++ obscur (manual obfuscating) ❗️

> Code complet et non obscurci avec les explication dispobible [ici](https://github.com/0nyr/cpp/tree/main/projects/movaicode/coddity_movaicode_8).

```cpp
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
```



## ⭐️ Explications

Quelques explications sur le code.

J'ai eu envie de faire du C/C++ *obfuscated* en regardant [cette vidéo](https://youtu.be/rwOI1biZeD8) de la très bonne chaîne YouTube [Bisqwit](https://www.youtube.com/channel/UCKTehwyGCKF-b2wo0RKwrcg).

L'idée de base de ce code est assez simple. Il s'agit de construire une liste chaînée basique. Une fois la liste chaînée de `Crepe*` construite, on peut alors appeler la fonction `Crepe * MangerUneCrepe(Crepe * cpp)`. On sélectionne alors 4 ingrédients aléatoires sous forme de `std::string` afin de prépaper la crêpe avant de la manger en affichant le message de la crêpe et de ses ingrédients. Ne reste qu'à `delete` la dernière crêpe et à modifier le pointeur de la crêpe précédente (`nullptr`) (plus quelques cas de bord à gérer). Quand on appelera la fonction qui permet de manger une crêpe, on aura donc un message aléatoire de la forme:

```shell
crêpe lardons, soja, météorite supplément béton !
```

La liste des ingrédients est la suivante:

```cpp
std::vector<std::string> crepeToppings = {
    "sucre",
    "chocolat",
       ...
    "météorite",
    "régolite"
};
```

Comme je veux faire du code "*obfuscated*", je ne veux pas qu'on puisse lire facilement le code, et encore moins les ingrédients, car ceux-ci sont parfois surprenants et je veux laisser la surprise intacte.

Je crée alors un petit programme CLI `obfuscator` qui va me permettre d'*obfuscate* simplement des strings (par défaut), mais aussi de les *deobfuscate*.

```shell
(base)  ❮ onyr ★  kenzae❯ ❮ obfuscator❯❯ ./main hello world
<<<< You have entered 3 arguments >>>>
<<<< OBFUSCATE MODE >>>>

 + arg: hello
-----> Obfuscated: gfkmn
-----> Deobfuscated: hello
 + arg: world
-----> Obfuscated: vpqmc
-----> Deobfuscated: world
```

En passant le flag `-d`, le programme *deobfuscate* les paramètres:

```shell
(base)  ❮ onyr ★  kenzae❯ ❮ obfuscator❯❯ ./main -d gfkmn vpqmc
<<<< You have entered 4 arguments >>>>
<<<< DE-OBFUSCATE MODE >>>>

 + arg: gfkmn
-----> Deobfuscated: hello
-----> Obfuscated: gfkmn
 + arg: vpqmc
-----> Deobfuscated: world
-----> Obfuscated: vpqmc
```

La fonction `std::string obfuscateString(std::string & str)` est assez simple, et va simplement décaler les caractères dans le tableau de `char` de la `std::string` fournie en paramètre.

```cpp
// shift each char by +1 or -1 depending on its position
for (int i = 0; i < (int)str.length(); i++) {
    if (i % 2 == 0) {
        buffer[i]--;
    } else {
        buffer[i]++;
    }
}
```

Cet algorithme a le mérite d'être simple mais offre le double avantage d'être simplement **réversible** ainsi que de fournir des versions différents de mêmes lettres car le décalage dépend de la position de la lettre dans la *string*.

On va donc pouvoir *obfuscate* notre *vector* de *string* avec ce petit programme. On va également ajouter les termes `"crêpe", "supplément", "mangée"` au début de notre *vector* afin de masquer ces mots de la même façon. Il faudra simplement veiller à ne pas pouvoir les sélectionner aléatoirement. On se retrouve avec une liste d'ingrédient incompréhensible que l'on devra *deobfuscate* avant d'afficher.

```cpp
std::vector<std::string> crepeToppings = {
    "bs«of",
    "rvoqkĨndos",
    "lbmhªd",
    "bbqblfk",
       ...
    "qĨhnmhud"
};
```

Maintenant, il ne reste qu'à écrire la fonction `Crepe * MangerUneCrepe(Crepe * c)`.

```cpp
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
          ...
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
```

On rentre alors dans la dernière partie, celle du processus de *manual obfuscation*. 'applique les principes de la [vidéo](J
