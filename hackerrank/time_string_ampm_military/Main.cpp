#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    int inputHour = stoi(s.substr(0, 2));
    string result = "";
    
    if(s[8] == 'P') {
        // PM section
        if(inputHour == 12) {
            return s.substr(0,8);
        } else {
            int hour = inputHour + 12;
            result = std::to_string(hour) + s.substr(2,6);
            return result;
        }
    } else {
        // AM section
        if(inputHour == 12) {
            return "00" + s.substr(2,6);
        } else {
            return s.substr(0,8);
        }
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
