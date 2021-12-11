#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

// header for top level functions
template <typename T>
void print_vector(std::vector<T> const& vector);

class Solution {
public:
    /**
     * @brief Find the index of the pair of numbers whose sum gives 
     * the target.
     * This algorithm uses pure bruteforce
     *  + time complexity: BigO(n²)
     *  + memory complexity: BigO(1)
     * 
     * @param nums The vector of all the different possible numbers.
     * @param target The target sum to find.
     * @return std::vector<int> 
     */
    std::vector<int> twoSum(std::vector<int> const& nums, int const target) {
        // WARN: read the description, we are looking for a pair !!!
        std::vector<int> result;

        for (int i = 0; i < (int)nums.size(); i++) {
            for (int j = i; j < (int)nums.size(); j++) {
                if(i == j) continue; // same element, skip
                int tmp = nums[i] + nums[j];
                if (tmp == target) {
                    // return the index of the matching pair
                    result = {i, j}; 
                    return result;
                }
            }
        }
        return result;
    }
};


#include <chrono>

template <typename T>
void print_vector(std::vector<T> const& vector) {
    std::cout << "{";
    int i = 0;
    while (i < (int)vector.size()) {
        std::cout << vector[i];
        if (i < (int)vector.size() - 1) {
            std::cout << ", ";
        }
        i++;
    }
    std::cout << "}";
}

int globalTestNumber {0}; // global test number
void run_test(
    std::vector<int>& nums, // WARN: not const
    int target,
    std::vector<int> const& expected_result
) {
    std::cout << "Solution "<< globalTestNumber << ": " << std::endl;
    globalTestNumber++;

    // params
    std::cout << "  + nums: ";
    print_vector(nums);
    std::cout << ")" << std::endl;
    std::cout << "  + target: " << target << std::endl;

    // results
    std::cout << "    > expect: ";
    print_vector(expected_result);
    std::cout << std::endl;
    std::cout << "    > output: ";
    print_vector(Solution().twoSum(nums, target));
    std::cout << std::endl;
    std::cout << std::endl; 
}

int main() {
    const char * url = "https://leetcode.com/problems/two-sum/";
    std::cout << "Leetcode Two Sum problem: " << url << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << std::endl;

    // start timer
    auto start_time = std::chrono::high_resolution_clock::now();

    std::vector<int> testVector;
    std::vector<int> resultVector;

    // test cases
    testVector = {2, 7, 11, 15};
    resultVector = {0, 1};
    run_test(testVector, 9, resultVector);

    testVector = {3,2,4};
    resultVector = {1, 2};
    run_test(testVector, 6, resultVector);

    testVector = {3,3};
    resultVector = {0, 1};
    run_test(testVector, 6, resultVector);

    testVector = {2,5,5,11};
    resultVector = {1, 2};
    run_test(testVector, 10, resultVector);

    // end timer
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_time = end_time - start_time;
    std::cout << "Elapsed time: " << elapsed_time.count() << " s" << std::endl;

    return 0;
}