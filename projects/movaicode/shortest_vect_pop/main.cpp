#include <vector>
#include <iostream>

// compile: g++ -o main main.cpp --ansi --pedantic -Wall --std=c++11

class VectorWrapper {
    public:
        std::vector<int> vect;
        VectorWrapper() {};
        void p() {
            vect.pop_back();
        }
};

int main() {
    VectorWrapper a;
    for(int i=0; i<10; i++) {
        a.vect.push_back(i);
    }
    
    std::cout << "ints size: " << a.vect.size() << std::endl;
    [&]{a.p();}();
    std::cout << "ints size: " << a.vect.size() << std::endl;
    a.vect.pop_back();
    std::cout << "ints size: " << a.vect.size() << std::endl;
}