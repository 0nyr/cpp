#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// namespace use: https://stackoverflow.com/questions/10950083/why-stdcout-instead-of-simply-cout 
using std::cin;
using std::cout;
using std::endl;
using std::cerr;

// enum class, used to avoid name collision: https://stackoverflow.com/questions/49921578/same-names-in-multiple-enum 
enum class Owner {
    NO_STRUCTURE = -1,
    FRIENDLY = 0,
    ENEMY = 1
};

enum class UnitType {
    QUEEN = -1,
    KNIGHT = 0,
    ARCHER = 1
};

enum class StructureType {
    NO_STRUCTURE = -1,
    BARRACKS = 2
};

enum class BarracksUnitType {
    NO_STRUCTURE = -1,
    KNIGHT = 0,
    ARCHER = 1
};

enum class UnitCost {
    KNIGHT = 80,
    ARCHER = 100
};

class Site {
    private:

    public:
        // basic info
        int id;
        int x;
        int y;
        int radius;

        // changing info
        int ignore1; // used in future leagues
        int ignore2; // used in future leagues
        int structureType; // -1 = No structure, 2 = Barracks
        int owner; // -1 = No structure, 0 = Friendly, 1 = Enemy
        int param1;
        int param2;

        // computed


        Site() {
            this->id = 0;
            this->x = 0;
            this->y = 0,
            this->radius = 0;
        }

        Site(
            int id, int x, int y, int radius
        ): 
            id(id), 
            x(x),
            y(y),
            radius(radius)
        {};

        ~Site() {};

        // operator overloading: https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm
        // example: https://www.tutorialspoint.com/cplusplus/relational_operators_overloading.htm 
        // WARN: not called using sort ! Because we have a vector of pointers
        bool operator <(const Site& site) {
            // One line if-else: https://stackoverflow.com/questions/46540099/c-if-else-if-else-in-one-line
            return (this->id < site.id) ? true : false;
        }

        static bool comparePtrToSite(Site* a, Site* b) {
            return (a->id < b->id) ? true : false;
        }

};

class Unit {
    public:
        int x;
        int y;
        int owner;
        int unitType; // -1 = QUEEN, 0 = KNIGHT, 1 = ARCHER
        int health;

        Unit() {
            this->x = 0;
            this->y = 0;
            this->owner = 0;
            this->unitType = 0;
            this->health = 0;
        }

        Unit(
            int x,
            int y,
            int owner,
            int unitType,
            int health
        ): 
            x(x),
            y(y),
            owner(owner),
            unitType(unitType),
            health(health)
        {};
};

class Queen: Unit {
    public:


};

// functions
int changeBuildTypeObjective(int currentBuildObjective) {
    int newTypeObjective;
    switch(currentBuildObjective) {
        case static_cast<int>(UnitType::KNIGHT) : 
            newTypeObjective = static_cast<int>(UnitType::ARCHER);
            break;
        case static_cast<int>(UnitType::ARCHER) :
            newTypeObjective = static_cast<int>(UnitType::KNIGHT);
            break;
        default :
            cerr << "error inside switch statement, value unexpected" << endl;
            break;
    }
    return newTypeObjective;
}

int main()
{
    int nbSites;
    cin >> nbSites; cin.ignore();
    std::vector<Site*> sites;
    for (int i = 0; i < nbSites; i++) {
        Site* site = new Site();
        cin >> site->id >> site->x >> site->y >> site->radius; cin.ignore();
        sites.push_back(site);
    }

    // sort sites by id
    // WARN: sort works on address of pointer values and do not call operator< of objects !
    // need to specify a custom comparator to the method
    // StackOverflow: https://stackoverflow.com/questions/7446743/sorting-vector-of-pointers 
    std::sort(sites.begin(), sites.end(), Site::comparePtrToSite);

    // tmp variables
    int buildId = 1;

    // personal variables
    int buildTypeObjective = static_cast<int>(UnitType::KNIGHT);



    // game loop
    while (1) {
        // get turn info
        int gold;
        int touchedSite; // -1 if none
        cin >> gold >> touchedSite; cin.ignore();

        for(int i = 0; i < nbSites; i++) {
            // declare tmp variables
            int id;
            int ignore1;
            int ignore2;
            int structureType;
            int owner;
            int param1;
            int param2;

            // get data
            cin >> 
            id >> 
            ignore1 >> 
            ignore2 >> 
            structureType >> 
            owner >> 
            param1 >> 
            param2; 
            cin.ignore();

            // update correct site data, NB: sites sorted by id
            Site* site = sites[id];
            site->ignore1 = ignore1;
            site->ignore2 = ignore2;
            site->structureType = structureType;
            site->owner = owner;
            site->param1 = param1;
            site->param2 = param2;
        }


        int nbUnits;
        cin >> nbUnits; cin.ignore();
        std::vector<Unit*> units;
        for(int i = 0; i < nbUnits; i++) {
            Unit* unit = new Unit();
            cin >> unit->x >> unit->y >> unit->owner >> unit->unitType >> unit->health; 
            cin.ignore();
            units.push_back(unit);
        }

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        // First line: A valid queen action
        // Second line: A set of training instructions

        // queen's logic
        Site* currentSite = sites.at(buildId);

        // static_cast with enum class: https://stackoverflow.com/questions/8357240/how-to-automatically-convert-strongly-typed-enum-into-int 
        if(currentSite->owner == static_cast<int>(Owner::FRIENDLY)) {
            cerr << "site[" << currentSite->id << "] is already owned by " << currentSite->owner << endl;
            buildTypeObjective = changeBuildTypeObjective(buildTypeObjective);
            buildId++;
            currentSite = sites.at(buildId);
        }

        if(currentSite->owner == static_cast<int>(Owner::NO_STRUCTURE)) {
            cout << "BUILD" << 
            " " <<
            currentSite->id <<
            " " <<
            "BARRACKS-";

            // alternate archer and knights
            switch(buildTypeObjective) {
                case static_cast<int>(UnitType::KNIGHT) : 
                    cout << "KNIGHT";
                    break;
                case static_cast<int>(UnitType::ARCHER) :
                    cout << "ARCHER";
                    break;
                default :
                    cerr << "error inside switch statement, value unexpected" << endl;
                    break;
            }
            cout << endl;

        } else {
            cerr << "Error: The selected site is already build." << endl;
            buildId++;
            cout << "WAIT" << endl;
        }

        // unit build logic
        int cost = 0;
        cout << "TRAIN";

        // could be optimised by having a list of build building
        for(Site* site : sites) {
            if(
                site->owner == static_cast<int>(Owner::FRIENDLY) && 
                site->structureType == static_cast<int>(StructureType::BARRACKS) &&
                site->param1 == 0
            ) {
                // compute future costs
                int futureCost = cost;
                switch(site->param2) {
                    case static_cast<int>(BarracksUnitType::KNIGHT) : 
                        futureCost += static_cast<int>(UnitCost::KNIGHT);
                        break;
                    case static_cast<int>(BarracksUnitType::ARCHER) :
                        futureCost += static_cast<int>(UnitCost::ARCHER);
                        break;
                    case static_cast<int>(BarracksUnitType::NO_STRUCTURE) :
                        break;
                    default :
                        cerr << "error inside switch statement, value unexpected" << endl;
                        break;
                }

                // add the barrack in requested building process if possible
                if(futureCost <= gold) {
                    cout << " " << site->id;
                    // add cost
                    cost = futureCost;
                }
            }
        }

        cout << endl;  

    }
}