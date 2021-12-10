#include <iostream>
#include <vector>
#include <cmath>


class Solution {
private:
    std::vector<int> * ordered_solutions;

    /**
     * @brief This function returns the number of ways to climb to 
     * the nth stair. It is slow and inefficient.
     * 
     * @param n The number of stairs to climb.
     * @return The number of ways to climb to the top of the stairs 
     */
    int climbStairsRecursion(int n) {
        // filter init cases
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }

        int a = 1;
        int b = 2;
        int c = 0;
        for (int i = 3; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }

public:
    Solution() {
        ordered_solutions = new std::vector<int>();
        ordered_solutions->push_back(1);
        ordered_solutions->push_back(2);
    }
    ~Solution() {
        delete ordered_solutions;
    }

    int climbStairs(int n) {
        // return is already obtained
        if (n <= (int)ordered_solutions->size()) {
            return (*ordered_solutions)[n - 1];
        }

        // use caching to speed up
        // NOTE: here n is greater than the size of the vector
        // start at i = the size of the vector
        int i = ordered_solutions->size() + 1;
        int a = (*ordered_solutions)[ordered_solutions->size() - 2]; // element before the last
        int b = (*ordered_solutions)[ordered_solutions->size() - 1]; // last element
        int c = 0;
        // std::cout << "i: " << i << " a: " << a << " b: " << b << std::endl;
        for (; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
            // std::cout << "i: " << i << " a: " << a << " b: " << b << std::endl;

            // store the result
            ordered_solutions->push_back(c);
            // for(int j = 0; j < (int)ordered_solutions->size(); j++) {
            //     std::cout << "ordered_solutions[" << j << "]: " 
            //         << (*ordered_solutions)[j] << std::endl;
            // }
        }
        return c;
    }
};


#include <chrono>

void run_test(int test_number, int n, int expected_result) {
    std::cout << "Solution "<< test_number << ": ";
    std::cout << "(number of stairs n = " << n << ")" << std::endl;
    std::cout << "    -s expect: " << expected_result << std::endl;
    std::cout << "    -> output: " << Solution().climbStairs(n) << std::endl;
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
    run_test(s_nb++, 1, 1);
    run_test(s_nb++, 2, 2);
    run_test(s_nb++, 3, 3);
    run_test(s_nb++, 4, 5);
    run_test(s_nb++, 5, 8);
    run_test(s_nb++, 6, 13);
    run_test(s_nb++, 7, 21);
    run_test(s_nb++, 8, 34);
    run_test(s_nb++, 9, 55);
    run_test(s_nb++, 10, 89);

    run_test(s_nb++, 45, 1836311903);

    // end timer
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_time = end_time - start_time;
    std::cout << "Elapsed time: " << elapsed_time.count() << " s" << std::endl;

    return 0;
}