#include <iostream>
#include <vector>
#include <cmath>


class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        int a = 0, b = 1, c = 0;
        for(int i = 2; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};


#include <chrono>

void run_test(int test_number, int n, int expected_result) {
    std::cout << "Solution "<< test_number << ": ";
    std::cout << "(n = " << n << ")" << std::endl;
    std::cout << "    -s expect: " << expected_result << std::endl;
    std::cout << "    -> output: " << Solution().fib(n) << std::endl;
    std::cout << std::endl; 
}

int main() {
    const char * url = "https://leetcode.com/problems/fibonacci-number/";
    std::cout << "Leetcode Fibonacci Number problem: " << url << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << std::endl;

    // start timer
    auto start_time = std::chrono::high_resolution_clock::now();

    int s_nb = 0;

    // test cases
    run_test(++s_nb, 0, 0);
    run_test(++s_nb, 1, 1);
    run_test(++s_nb, 2, 2);
    run_test(++s_nb, 3, 3);
    run_test(++s_nb, 4, 5);
    run_test(++s_nb, 5, 8);
    run_test(++s_nb, 30, 1346269);

    // end timer
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_time = end_time - start_time;
    std::cout << "Elapsed time: " << elapsed_time.count() << " s" << std::endl;

    return 0;
}