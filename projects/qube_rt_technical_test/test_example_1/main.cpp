#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int determineClosestToZero(vector<int> temperatures) {
    int closestToZero = 0;
    for (size_t i = 0; i < temperatures.size(); i++) {
        if (i == 0) {
            closestToZero = temperatures[i];
        } else {
            if (abs(temperatures[i]) < abs(closestToZero)) {
                closestToZero = temperatures[i];
            } else if (abs(temperatures[i]) == abs(closestToZero)) {
                if (temperatures[i] >= 0) {
                    closestToZero = temperatures[i];
                }
            }
        }
    }
    return closestToZero;
}

int main()
{
    int n;
    vector<int> temperatures;
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t; cin.ignore();
        temperatures.push_back(t);
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << determineClosestToZero(temperatures) << endl;
}