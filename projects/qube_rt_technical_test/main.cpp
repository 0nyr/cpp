#include <string>
#include <iostream>
#include <vector>
#include <chrono>




class Tester {
    private:
        int testNumber = 1;
    
    public:
        Tester() {}

        template <typename T>
        void run(T & expected, T & output) {
            // header of test case
            std::string testResult = (expected == output) ? "✅ OK" : "❌ FAILED";
            std::cout << "Test " << this->testNumber++ << ": ";
            std::cout << testResult << std::endl;

            // results
            std::cout << "    --expect: " << expected << std::endl;
            std::cout << "    --output: " << output << std::endl;

            std::cout << std::endl; 
        }

        /** For simple types like int or bool */
        template <typename T>
        void run(T expected, T output) {
            std::cout << "Test " << this->testNumber++ << ": " << std::endl;
            std::cout << "    --expect: " << expected << std::endl;
            std::cout << "    --output: " << output << std::endl;
            if (expected != output) {
                std::cout << "    ❌ FAILED " << std::endl;
            } else {
                std::cout << "    ✅ OK " << std::endl;
            }
            std::cout << std::endl; 
        }
};

int main() {
    const char * url = "https://leetcode.com/problems/longest-common-prefix/";
    std::cout << "Leetcode Longest Common Prefix: " << url << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << std::endl;

    // start timer
    auto start_time = std::chrono::high_resolution_clock::now();

    std::vector<int> testVector;
    std::vector<int> resultVector;

    // test cases
    Tester tester = Tester();

    // end timer
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_time = end_time - start_time;
    std::cout << "Elapsed time: " << elapsed_time.count() << " s" << std::endl;

    return 0;
}
