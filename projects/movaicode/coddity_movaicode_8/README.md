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

Solution en **14 bytes** pour elever le dernier élément d'une liste (plus de détail sur le code [ici](:

```cpp
[&]{a.p();}();
```

Cependant,, un grand pouvoir implique une grande irresponsabilité! J'ai donc choisi le côté obscur de la ~force~ crêpe ❗️

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
