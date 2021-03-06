#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int numSites;
    cin >> numSites; cin.ignore();
    for (int i = 0; i < numSites; i++) {
        int siteId;
        int x;
        int y;
        int radius;
        cin >> siteId >> x >> y >> radius; cin.ignore();
    }

    // game loop
    while (1) {
        int gold;
        int touchedSite; // -1 if none
        cin >> gold >> touchedSite; cin.ignore();
        for (int i = 0; i < numSites; i++) {
            int siteId;
            int ignore1; // used in future leagues
            int ignore2; // used in future leagues
            int structureType; // -1 = No structure, 2 = Barracks
            int owner; // -1 = No structure, 0 = Friendly, 1 = Enemy
            int param1;
            int param2;
            cin >> siteId >> ignore1 >> ignore2 >> structureType >> owner >> param1 >> param2; cin.ignore();
        }
        int numUnits;
        cin >> numUnits; cin.ignore();
        for (int i = 0; i < numUnits; i++) {
            int x;
            int y;
            int owner;
            int unitType; // -1 = QUEEN, 0 = KNIGHT, 1 = ARCHER
            int health;
            cin >> x >> y >> owner >> unitType >> health; cin.ignore();
        }

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;


        // First line: A valid queen action
        // Second line: A set of training instructions
        cout << "WAIT" << endl;
        cout << "TRAIN" << endl;
    }
}