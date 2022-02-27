#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            // negative number is never a palindrome
            return false;
        }

        std::string textX = std::to_string(x);
        return isPalindrome(textX);
    }
    bool isPalindrome(std::string textX) {
        int length = textX.length();
        for (int i = 0; i < length / 2; i++) {
            if (textX[i] != textX[length - i - 1]) {
                return false;
            }
        }
        return true;
    }
};

void test(int n, bool expectedResult) {
    Solution solution;
    std::cout << "Solution " << n << ": ";
    std::cout << "(n = " << n << ")" << std::endl;
    std::cout << "    -s expect: " << expectedResult << std::endl;
    std::cout << "    -> output: " << solution.isPalindrome(n) << std::endl;
    std::cout << std::endl; 
}


int main() {

    test(121, true);
    test(1221, true);
    test(1222, false);
    test(1223, false);
    test(-121, false);
    test(12321, true);

    return 0;
}