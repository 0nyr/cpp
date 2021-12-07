#include <iostream>

class Solution {
private:
    inline unsigned long compute_tribonacci_n_plus_3(
        unsigned long tri_n,
        unsigned long tri_n_plus_1,
        unsigned long tri_n_plus_2
    )
    {
        return tri_n + tri_n_plus_1 + tri_n_plus_2;
    }

public:
    unsigned long tribonacci(unsigned long n) 
    {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 1;

        // save intermediate results
        unsigned long tri_n = 0;
        unsigned long tri_n_plus_1 = 1;
        unsigned long tri_n_plus_2 = 1;
        unsigned long tri_n_plus_3; 

        // iterate as long as counter == n
        unsigned long counter = 2;
        while(counter < n) 
        {
            tri_n_plus_3 = compute_tribonacci_n_plus_3(tri_n, tri_n_plus_1, tri_n_plus_2);

            // shift saved results
            tri_n = tri_n_plus_1;
            tri_n_plus_1 = tri_n_plus_2;
            tri_n_plus_2 = tri_n_plus_3;

            counter++;
        } 

        return tri_n_plus_3;
    }
};


int main() {
    const char * url = "https://leetcode.com/problems/nth-tribonacci-number/";
    std::cout << "Leetcode Tribonacci problem: " << url << std::endl;
    std::cout << "Provide an integer n, 0 <= n <= 37" << std::endl;

    for (std::string line; std::getline(std::cin, line);) {
        std::cout << "Input: " << line << std::endl;
        std::cout << "Output: " 
            << Solution().tribonacci(std::stoi(line)) 
            << std::endl;
    }

    return 0;
}
