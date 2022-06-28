#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    string str1;
    getline(cin, str1);
    string str2;
    getline(cin, str2);
    string str3;
    getline(cin, str3);
    int c=0;

    if(str1 == "Overlapping"){
        for(int i=0;i<str3.size();i++){
            if(str3.substr(i,str2.size()) == str2){c++;}
        }
    } else {
        string currS=str3;
        for(int i=0;i<str3.size();i++){
            if(currS.substr(i,str2.size()) == str2){
                c++;
                currS=currS.substr(i+str2.size(), currS.size());
            }
        }
    }
    cout << c << endl;
}