#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> findWords(
        std::vector<std::vector<char>>& board, 
        std::vector<std::string>& words) 
    {
        return words;
    }
};


int main() {
    const char * url = "https://leetcode.com/problems/word-search-ii/";
    std::cout << "Leetcode Word Search II problem: " << url << std::endl;
    std::cout << "Provide an integer n, 0 <= n <= 37" << std::endl;

    // test data
    std::vector<std::vector<char>> grid_1 = {
        {'o','a','a','n'},
        {'e','t','a','e'},
        {'i','h','k','r'},
        {'i','f','l','v'}
    };
    std::vector<std::string> words_1 = {"oath","pea","eat","rain"};

    // test 1 solution
    std::vector<std::string> solution_1 = Solution().findWords(grid_1, words_1);
    std::cout << "Solution 1: " << std::endl;
    for (auto word : solution_1) {
        std::cout << word << std::endl;
    }

    return 0;
}
