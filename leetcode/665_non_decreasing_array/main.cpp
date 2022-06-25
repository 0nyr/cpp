#include <string>
#include <iostream>
#include <vector>
#include <chrono>

class Solution {
    public:
        /** Given an array nums with n integers, your task is to check 
         * if it could become non-decreasing by modifying at most one element.
         * 
         * A good solution is explained here: https://leetcode.com/problems/non-decreasing-array/discuss/2193070/C%2B%2B-oror-Simple-Code-oror-Full-Explanation
         */
        bool checkPossibility(std::vector<int>& nums) {
            if (nums.size() <= 1) {
                return true;
            }
            bool is_one_preceeding_decrease_case = false;
            // i from first to one before last 
            for (size_t i = 0; i < nums.size() - 1; i++) {
                if (nums[i] > nums[i + 1]) {
                    // check no preceding decrease case
                    if (is_one_preceeding_decrease_case) { return false; }
                    is_one_preceeding_decrease_case = true;

                    // check no immediate following increase case
                    // example: [5, 7, 1, 8] -> True 
                    // example: [5, 7, 1, 6] -> False
                    // it is False if the next second element is smaller
                    // than current element (here the 7)
                    if (// before and after elements are decreasing
                        i != 0 && nums[i - 1] > nums[i + 1] &&
                        // there are at least 2 following elements
                        i < nums.size() - 2 &&
                        // and current element greater than second next one
                        nums[i] > nums[i + 2]
                    ) {
                        return false;
                    }
                }
            }
            // if not enough increasing cases, then it's ok
            return true;
        }
};

class Tester {
    private:
        int testNumber = 1;
    
    public:
        Tester() {}

        template <typename T>
        void run(T & expected, T & output) {
            std::cout << ">>> Test " << this->testNumber++ << ": " << std::endl;
            std::cout << "    --expect: " << expected << std::endl;
            std::cout << "    --output: " << output << std::endl;
            if (expected != output) {
                std::cout << "    ❌ --FAILED " << std::endl;
            } else {
                std::cout << "    ✅ --OK " << std::endl;
            }
            std::cout << std::endl; 
        }

        /** For simple types like int or bool */
        template <typename T>
        void run(T expected, T output) {
            std::cout << ">>> Test " << this->testNumber++ << ": " << std::endl;
            std::cout << "    --expect: " << expected << std::endl;
            std::cout << "    --output: " << output << std::endl;
            if (expected != output) {
                std::cout << "    ❌ --FAILED " << std::endl;
            } else {
                std::cout << "    ✅ --OK " << std::endl;
            }
            std::cout << std::endl; 
        }
};

int main() {
    const char * url = "https://leetcode.com/problems/non-decreasing-array/";
    std::cout << "Leetcode Non-decreasing Array: " << url << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << std::endl;

    // test cases
    Tester tester = Tester();

    auto data = std::vector<int>{4};
    tester.run<bool>(true, Solution().checkPossibility(data));

    data = std::vector<int>{4, 2};
    tester.run<bool>(true, Solution().checkPossibility(data));

    data = std::vector<int>{4, 2, 3};
    tester.run<bool>(true, Solution().checkPossibility(data));

    data = std::vector<int>{5, 7, 1};
    tester.run<bool>(true, Solution().checkPossibility(data));

    data = std::vector<int>{3, 4, 2};
    tester.run<bool>(true, Solution().checkPossibility(data));

    data = std::vector<int>{3, 2, 1};
    tester.run<bool>(false, Solution().checkPossibility(data));

    data = std::vector<int>{1, 4, 2, 3};
    tester.run<bool>(true, Solution().checkPossibility(data));

    data = std::vector<int>{3, 4, 2, 3};
    tester.run<bool>(false, Solution().checkPossibility(data));

    data = std::vector<int>{1, 3, 2, 4};
    tester.run<bool>(true, Solution().checkPossibility(data));

    data = std::vector<int>{1, 3, 2, 2};
    tester.run<bool>(true, Solution().checkPossibility(data));

    data = std::vector<int>{1, 3, 2, 1};
    tester.run<bool>(false, Solution().checkPossibility(data));

    data = std::vector<int>{1, 1, 1, 1};
    tester.run<bool>(true, Solution().checkPossibility(data));

    data = std::vector<int>{5, 7, 1, 8};
    tester.run<bool>(true, Solution().checkPossibility(data));

    data = std::vector<int>{5, 7, 1, 8, 9, 1};
    tester.run<bool>(false, Solution().checkPossibility(data));

    // start timer
    auto start_time = std::chrono::high_resolution_clock::now();

    std::vector<int> testVector;
    std::vector<int> resultVector;

    // run many times for better time measurement
    auto datas = std::vector<std::vector<int>>({
        {5, 7, 1, 8, 9, 1},
        {3, 2, 1},
        {4}
    });
    for (size_t i = 0; i < 10000000; i++) {
        Solution().checkPossibility(datas[0]);
        Solution().checkPossibility(datas[1]);
        Solution().checkPossibility(datas[2]);
    }

    // end timer
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_time = end_time - start_time;
    std::cout << "Elapsed time: " << elapsed_time.count() << " s" << std::endl;

    return 0;
}