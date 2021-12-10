#include <iostream>
#include <vector>

class Solution {
public:
    double myPow(double const x, int n) {
        if (n == 0) return 1;
        double tmp = myPow(x, n / 2);
        if (n % 2 == 0) return tmp * tmp; // n is even
        else if (n > 0) return tmp * tmp * x; // n is odd and positive
        else return tmp * tmp / x; // n is odd and negative
    }
};


#include <chrono>

void run_test(int test_number, double x, int n, double expected_result) {
    std::cout << "Solution "<< test_number << ": ";
    std::cout << "(x = " << x << ")";
    std::cout << "(n = " << n << ")" << std::endl;
    std::cout << "    -s expect: " << expected_result << std::endl;
    std::cout << "    -> output: " << Solution().myPow(x, n) << std::endl;
    std::cout << std::endl; 
}

int main() {
    const char * url = "https://leetcode.com/problems/climbing-stairs/";
    std::cout << "Leetcode Climbing Stairs problem: " << url << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << std::endl;

    // start timer
    auto start_time = std::chrono::high_resolution_clock::now();

    int s_nb = 0;

    // test cases
    run_test(s_nb++, 0, 0, 1);
    run_test(s_nb++, 0, 1, 0);
    run_test(s_nb++, 2, -2, 0.25);
    run_test(s_nb++, 2, 10, 1024);
    run_test(s_nb++, 2.1, 3, 9.261);
    run_test(s_nb++, 1, 2147483647, 1);
    run_test(s_nb++, 2147483648, -2147483648, 0);

    // end timer
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_time = end_time - start_time;
    std::cout << "Elapsed time: " << elapsed_time.count() << " s" << std::endl;

    return 0;
}