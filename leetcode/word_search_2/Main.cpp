#include <iostream>
#include <vector>
#include <string>

class Position {
public:
    int x;
    int y;
    Position(int x, int y) : x(x), y(y) {}
};

class Solution {
private:
    bool dfs(
        std::vector<std::vector<char>> const& board, 
        std::vector<std::vector<bool>>& visited, 
        std::string const& word,
        int index_considered_letter_in_word,
        Position const position_last_letter_found
    ) {
        if(index_considered_letter_in_word == 0) {
            // iterate over all starting positions
            return dfs_start(
                board, visited, word, 
                index_considered_letter_in_word, 
                position_last_letter_found
            );
            std::cout << std::endl;
        } else {
            // explore a specific position until word is found or not
            return dfs_worker(
                board, visited, word, 
                index_considered_letter_in_word, 
                position_last_letter_found
            );
        }
    }

    bool dfs_start(
        std::vector<std::vector<char>> const& board, 
        std::vector<std::vector<bool>>& visited, 
        std::string const& word,
        int index_considered_letter_in_word,
        Position const position_last_letter_found
    ) {
        // explore all starting positions
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[i].size(); ++j) {
                if(board[i][j] == word[0]) {
                    // found new stating position, explore it
                    // reset visited matrix AND ADD current starting position !!!
                    visited = create_visited_matrix(board); 
                    visited[i][j] = true;

                    if(dfs(
                        board, visited, word, 1, 
                        Position(i, j)
                    )) {
                        return true;
                    }
                }
            }
        }
        // all starting positions were explored and no match found
        return false;
    }

    bool dfs_worker(
        std::vector<std::vector<char>> const& board, 
        std::vector<std::vector<bool>>& visited, 
        std::string const& word,
        int index_considered_letter_in_word,
        Position const position_last_letter_found
    ) {
        // return true if match found when all letters have already matched
        if (index_considered_letter_in_word == word.size()) {
            return true;
        } else {
            // continue exploring (recursion)
            // explore all possible non starting (adjascent) positions
            for(int i = -1; i <= 1; ++i) {
                for(int j = -1; j <= 1; ++j) {
                    if(i == j || i == -j) { // skip diagonals
                        // skip current position
                        continue;
                    }
                    int x = position_last_letter_found.x + i;
                    int y = position_last_letter_found.y + j;

                    if(
                        // check if position is within board
                        x >= 0 && x < board.size() && 
                        y >= 0 && y < board[x].size()
                    ) {

                        // for(int p = 0; p < index_considered_letter_in_word; ++p) {
                        //     std::cout << "*";
                        // }
                        // std::cout << "(" << x << ", " << y << ")";

                        if(board[x][y] == word[index_considered_letter_in_word]) {
                            // found new position, explore it
                            if(visited[x][y]) {
                                // already visited, skip it
                                // std::cout << " <already visited>" << std::endl;
                                continue;
                            }
                            // std::cout << std::endl;
                            visited[x][y] = true;
                            //position_last_letter_found = Position(x, y);

                            // for(int p = 0; p < index_considered_letter_in_word; ++p) {
                            //     std::cout << "-";
                            // }
                            // std::cout << "> [" << x << ",  " << y << "]";
                            // std::cout << " (last position [" << position_last_letter_found.x;
                            // std::cout << ", " << position_last_letter_found.y << "])" << std::endl;

                            // recursion
                            if(dfs(
                                board, visited, word, 
                                index_considered_letter_in_word + 1, 
                                Position(x, y)
                            )) {
                                return true;
                            }

                            // backtrack
                            visited[x][y] = false;
                        } 
                        // else {
                        //     // wrong letter, skip it
                        //     std::cout << " <wrong letter>" << std::endl;
                        // }
                    }
                }
            }

            // no match found, return false
            return false;
        }
    }

    /**
     * @brief Create a visited matrix object with the same size of the board.
     * The matrix is initialized with false.
     * 
     * @param board 
     * @return A new initialised visited matrix. 
     */
    std::vector<std::vector<bool>> create_visited_matrix(
        std::vector<std::vector<char>> const& board
    ) {
        std::vector<std::vector<bool>> visited(
            board.size(), 
            std::vector<bool>(
                board[0].size(), false
            )
        );
        return visited;
    }

public:
    std::vector<std::string> findWords(
        std::vector<std::vector<char>>& board, 
        std::vector<std::string>& words
    ) { 
        std::vector<std::string> present_words;

        // search each provided word in the board
        for (std::string& word : words) {
            std::vector<std::vector<bool>> visited;
            Position position_last_letter_found = Position(-1, -1);

            if (dfs(board, visited, word, 0, position_last_letter_found)) 
            {
                present_words.push_back(word);
            }
        }

        return present_words;
    }
};





int main() {
    const char * url = "https://leetcode.com/problems/word-search-ii/";
    std::cout << "Leetcode Word Search II problem: " << url << std::endl;
    
    // test 1
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
        std::cout << "   + " << word << std::endl;
    }
    std::cout << std::endl;


    // test 2
    std::vector<std::vector<char>> grid_2 = {
        {'a','a'},
    };
    std::vector<std::string> words_2 = {"aaa"};

    // test 2 solution
    std::vector<std::string> solution_2 = Solution().findWords(grid_2, words_2);
    std::cout << "Solution 2: " << std::endl;
    for (auto word : solution_2) {
        std::cout << "   + " << word << std::endl;
    }
    std::cout << std::endl;


    // test 3
    std::vector<std::vector<char>> grid_3 = {
        {'a','b'},
        {'c','d'},
    };
    std::vector<std::string> words_3 = {"abcd"};

    // test 3 solution
    std::vector<std::string> solution_3 = Solution().findWords(grid_3, words_3);
    std::cout << "Solution 3: " << std::endl;
    for (auto word : solution_3) {
        std::cout << "   + " << word << std::endl;
    }
    std::cout << std::endl;
    

    // test 4
    std::vector<std::vector<char>> grid_4 = {
        {'a','b', 'c'},
        {'a','e', 'd'},
        {'a','f', 'g'},
    };
    std::vector<std::string> words_4 = {"eaabcdgfa", "eaafgdcba"};

    // test 4 solution
    std::vector<std::string> solution_4 = Solution().findWords(grid_4, words_4);
    std::cout << "Solution 4: " << std::endl;
    for (auto word : solution_4) {
        std::cout << "   + " << word << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
