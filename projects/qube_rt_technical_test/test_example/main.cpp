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
    int closest2zero = 0;

    int n;
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t; cin.ignore();

        if (i == 0) {
            closest2zero = t;
        } else {
            if (abs(t) < abs(closest2zero)) {
                closest2zero = t;
            } else if (abs(t) == abs(closest2zero)) {
                if (t >= 0) {
                    closest2zero = t;
                }
            }
        }
    }

    cout << closest2zero << endl;
    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

}