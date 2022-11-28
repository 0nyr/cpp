#include <iostream>
#include "boost/dynamic_bitset.hpp"

using namespace std;
int main () {
    cout << sizeof(bool) << " byte" << endl;

    // create a bitset with 4 bits
    boost::dynamic_bitset<> bitset(4);

    // set the bits
    bitset[0] = 1;

    bool testBool = true;
    bitset[1] = testBool; // boost makes the conversion alone

    // print the bits
    cout << bitset << endl; // 0011
}
