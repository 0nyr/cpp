#include <string>
#include <iostream>
#include <vector>
#include <chrono>

class Solution {
    public:
        std::string longestCommonPrefix2(std::vector<std::string>& strs) {
            if (strs.size() == 0) {
                return "";
            } 
            if (strs.size() == 1) {
                return strs[0];
            }

            std::string prefix = strs[0];
            for (auto word : strs) {
                while (
                    word.find(prefix) != 0 // index not found in word
                ) { 
                    // remove last character of index
                    prefix = prefix.substr(0, prefix.size() - 1); 
                }
            }
            return prefix;
        }

        std::string longestCommonPrefix(std::vector<std::string>& strs) {
            if (strs.size() == 0) {
                return "";
            } 
            if (strs.size() == 1) {
                return strs[0];
            }

            std::string prefix = strs[0];
            for (std::string word : strs) {

                size_t index = 0;
                while (word[index] == prefix[index]) { 
                    index++;
                    if(index >= word.size() || index >= prefix.size()) {
                        break;
                    }
                }
                prefix = prefix.substr(0, index);
            }
            return prefix;
        }
};

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

    auto data = std::vector<std::string>{"flower","flow","flight"};
    tester.run<std::string>("fl", Solution().longestCommonPrefix(data));

    data = std::vector<std::string>{"dog","racecar","car"};
    tester.run<std::string>("", Solution().longestCommonPrefix(data));

    data = std::vector<std::string>{"flower","flow","flight", ""};
    tester.run<std::string>("", Solution().longestCommonPrefix(data));

    data = std::vector<std::string>{};
    tester.run<std::string>("", Solution().longestCommonPrefix(data));

    data = std::vector<std::string>{""};
    tester.run<std::string>("", Solution().longestCommonPrefix(data));

    data = std::vector<std::string>{"", "", ""};
    tester.run<std::string>("", Solution().longestCommonPrefix(data));

    data = std::vector<std::string>{"hello"};
    tester.run<std::string>("hello", Solution().longestCommonPrefix(data));

    data = std::vector<std::string>{"hello", "hello"};
    tester.run<std::string>("hello", Solution().longestCommonPrefix(data));

    data = std::vector<std::string>{"hello", "hello", "hello"};
    tester.run<std::string>("hello", Solution().longestCommonPrefix(data));

    data = std::vector<std::string>{"hello", "hello", "hello", "hello"};
    tester.run<std::string>("hello", Solution().longestCommonPrefix(data));

    // end timer
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_time = end_time - start_time;
    std::cout << "Elapsed time: " << elapsed_time.count() << " s" << std::endl;

    return 0;
}