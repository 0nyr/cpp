#include <iostream> // WARN - if not included, std doesn't contains cout, cin and endl

// demonstrating the use of global variables
// using namespace std; WARN - considered bad practice
using std::cout;
using std::cin;
using std::endl;

int firstNumber = 0;
int secondNumber = 0;
int multiplicationResult = 0;

void MultiplyNumbers() {
    cout << "Enter the first number: ";
    cin >> firstNumber;
    cout << "Enter the second number: ";
    cin >> secondNumber;

    multiplicationResult = firstNumber*secondNumber;

    cout << "Displaying from the MultiplyNumbers function: ";
    cout << firstNumber << " * " << secondNumber;
    cout << " = " << multiplicationResult << endl;
}

int main() {
    cout << "This program multiply the 2 provided numbers" << endl;
    MultiplyNumbers();

    cout << "Displaying from the main(): ";
    cout << firstNumber << " * " << secondNumber;
    cout << " = " << multiplicationResult << endl;

    return 0;
}
