#include <iostream> // WARN - if not included, std doesn't contains cout, cin and endl

/* This program returns the max number possible to represent given a certain number 
 * of bits */

using std::cout;
using std::cin;
using std::endl;

int nbBits = 0;
int maxDecimalNumber = 0;

int getBitNumber() {
	int givenNumber;
    cout << "Enter number of bits ";
    cin >> givenNumber;
    return givenNumber;
}

int powInt(int base, int exponent) {
	if(exponent == 0) {
		return 1;
	}
	
	int sum = 1;
	for(int i = 0; i < exponent; i++) {
		sum = sum*base;
	}
	return sum;
}

void testPowInt() {
	// test de powInt() avec 2^0 == 1 et 11^7 == 19487171
	if((powInt(2, 0) != 1) || (powInt(11, 7) != 19487171)) {
		cout << "WARN : the powInt() function did not pass the test" << endl;
	}
}

int computeMaxNumberDecimal(int numberOfBits) {
	int sum = 0;
	// WARN : no -1 as for n bits, we have n operations
	for(int i = 0; i < numberOfBits; i++) {
		sum += powInt(2, i);
		cout << sum << endl;
	}
	return sum;
	
}

int main() {
	// run tests
	testPowInt();
	cout << "test powInt() : " << powInt(2, 0) << endl;
	
	// run program
    cout << "This program returns the max number possible to represent given a certain number of bits" << endl;
		
    nbBits = getBitNumber();
    maxDecimalNumber = computeMaxNumberDecimal(nbBits);

	cout << "max number in decimal basis for ";
	cout << nbBits << " : ";
	cout << maxDecimalNumber << endl;

    return 0;
}
