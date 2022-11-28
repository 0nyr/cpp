/*******
 * Read input from cin
 * Use cout << ... to output your result to STDOUT.
 * Use cerr << ... to output debugging information to STDERR
 * ***/
#include <iostream>
#include <limits>
#include <string>
#include <cmath>
#include <sstream>
//#include "exercise.hpp"

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}

void ContestExerciseImpl::main() {
    string line;
    std::getline(std::cin, line);
    int c1 = stoi(line);
    std::getline(std::cin, line);
    int c2 = stoi(line);
    
    std::cout << ceil((c1 + c2) / float(2)) << std::endl;
}