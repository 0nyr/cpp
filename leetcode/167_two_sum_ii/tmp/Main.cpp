#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

// header for top level functions
template <typename T>
void print_vector(std::vector<T> const& vector);

class Solution {
private:
    /**
     * @brief Binary Search (Recherche Dichotomique): 
     * Search a sorted array by repeatedly dividing 
     * the search interval in half. Begin with an interval covering the 
     * whole array. If the value of the search key is less than the item 
     * in the middle of the interval, narrow the interval to the lower 
     * half. Otherwise, narrow it to the upper half. Repeatedly check 
     * until the value is found or the interval is empty.
     * 
     * NOTE: We remove the element at the indexMiddle after each
     * iteration, hence the interval is shrinking of minimum one element
     * per iteration.
     * 
     * @param value 
     * @return int The index of the found element, -1 if not found.
     */
    int binarySearchRecursive(
        std::vector<int> const& numbers, 
        int const target,
        int indexMin,
        int indexMax
    ) {
        if (indexMax >= indexMin) {
            int indexMiddle = indexMax - ((indexMax - indexMin)/2);
            if(numbers[indexMiddle] == target) return indexMiddle;
            if(target < numbers[indexMiddle]) {
                indexMax = indexMiddle - 1;
            } else {
                indexMin = indexMiddle + 1;
            }
            // continue recursion
            binarySearchRecursive(numbers, target, indexMin, indexMax);
        }
        return -1;
    }

public:
    /**
     * @brief Find the index of the pair of numbers whose sum gives 
     * the target.
     * This algorithm uses pure bruteforce
     *  + time complexity: BigO(n²)
     *  + memory complexity: BigO(1)
     * 
     * @param nums The vector of all the different possible numbers,*
     * sorted in non-decreasing order.
     * @param target The target sum to find.
     * @return std::vector<int> 
     */
    std::vector<int> twoSum(std::vector<int> const& nums, int const target) {
        std::vector<int> result;

        for (int i = 0; i < (int)nums.size(); i++) {
            // considering current number, we can expect a specific rest
            int targetRest = target - nums[i];

            // search only on the next element stating after index i
            int searchIndex = binarySearchRecursive(
                nums, targetRest, i + 1, nums.size()
            );
            if (searchIndex != -1) {
                // WARN: read the description, we are looking for a pair !
                result = {i, searchIndex};
                return result;
            }
        }
        return result; // never supposed to get there unless no solution are found
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
    if(nums.size() < 12) print_vector(nums);
    std::cout << std::endl;
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
    const char * url = "https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/";
    std::cout << "Leetcode Two Sum II problem: " << url << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << std::endl;

    // start timer
    auto start_time = std::chrono::high_resolution_clock::now();

    std::vector<int> testVector;
    std::vector<int> resultVector;

    // test cases
    testVector = {2, 7, 11, 15};
    resultVector = {1, 2};
    run_test(testVector, 9, resultVector);

    testVector = {2,3,4};
    resultVector = {1, 3};
    run_test(testVector, 6, resultVector);

    testVector = {-1,0};
    resultVector = {1, 2};
    run_test(testVector, -1, resultVector);

    testVector = {};
    for(int i = 2; i < 100000; i += 2) {
        testVector.push_back(i);
    }
    testVector.push_back(0);
    testVector.push_back(1000001);
    resultVector = {};
    run_test(testVector, 1000001, resultVector);

    // end timer
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_time = end_time - start_time;
    std::cout << "Elapsed time: " << elapsed_time.count() << " s" << std::endl;

    return 0;
}