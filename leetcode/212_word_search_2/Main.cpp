/* Word search II
@Author: Onyr (Florian Rascoussier)

Ideas:
    + eliminate words with characters that are not in the board
    + DFS: use DFS to search the board efficiently

*/


#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <algorithm>

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

    bool is_word_valid(
        std::string word, 
        std::vector<std::vector<char>> const& board,
        std::vector<char> const& all_characters_in_board
    ) {
        bool word_is_valid = true;
        for(char c : word) {
            if(std::find(
                all_characters_in_board.begin(), 
                all_characters_in_board.end(), 
                c
            ) == all_characters_in_board.end()) {
                // word contains a character not present in the board
                // eliminate it
                word_is_valid = false;
                break;
            }
        }
        return word_is_valid;
    }

    std::vector<char> create_vector_of_all_different_characters_in_board(
        std::vector<std::vector<char>> const& board
    ) {
        std::vector<char> all_characters;
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[i].size(); ++j) {
                // add character to vector if not already present
                if(
                std::find(
                    all_characters.begin(), all_characters.end(), 
                    board[i][j]
                ) == all_characters.end()) {
                    all_characters.push_back(board[i][j]);
                }
            }
        }
        return all_characters;
    }

public:
    std::vector<std::string> findWords(
        std::vector<std::vector<char>>& board, 
        std::vector<std::string>& words
    ) { 
        std::vector<std::string> present_words;

        // build vector of all characters in the board
        std::vector<char> all_characters_in_board = 
            create_vector_of_all_different_characters_in_board(board);
        
        // search each provided word in the board
        for (std::string& word : words) {
            // eliminate words with characters not present in the board
            bool word_is_valid = is_word_valid(
                word, board, all_characters_in_board
            );
            if(!word_is_valid) {
                // word is not valid, skip it
                continue;
            }

            // check if word is present in the board with DFS
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

    // start timer
    auto start_time = std::chrono::high_resolution_clock::now();
    
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

    
    // test 5
    std::vector<std::vector<char>> grid_5 = {
        {'b','a','b','a','b','a','b','a','b','a'},
        {'a','b','a','b','a','b','a','b','a','b'},
        {'b','a','b','a','b','a','b','a','b','a'},
        {'a','b','a','b','a','b','a','b','a','b'},
        {'b','a','b','a','b','a','b','a','b','a'},
        {'a','b','a','b','a','b','a','b','a','b'},
        {'b','a','b','a','b','a','b','a','b','a'},
        {'a','b','a','b','a','b','a','b','a','b'},
        {'b','a','b','a','b','a','b','a','b','a'},
        {'a','b','a','b','a','b','a','b','a','b'},
    };
    std::vector<std::string> words_5 = {
        "ababababaa","ababababab","ababababac","ababababad","ababababae",
        "ababababaf","ababababag","ababababah","ababababai","ababababaj",
        "ababababak","ababababal","ababababam","ababababan","ababababao",
        "ababababap","ababababaq","ababababar","ababababas","ababababat",
        "ababababau","ababababav","ababababaw","ababababax","ababababay",
        "ababababaz","ababababba","ababababbb","ababababbc","ababababbd",
        "ababababbe","ababababbf","ababababbg","ababababbh","ababababbi",
        "ababababbj","ababababbk","ababababbl","ababababbm","ababababbn",
        "ababababbo","ababababbp","ababababbq","ababababbr","ababababbs",
        "ababababbt","ababababbu","ababababbv","ababababbw","ababababbx",
        "ababababby","ababababbz","ababababca","ababababcb","ababababcc",
        "ababababcd","ababababce","ababababcf","ababababcg","ababababch",
        "ababababci","ababababcj","ababababck","ababababcl","ababababcm",
        "ababababcn","ababababco","ababababcp","ababababcq","ababababcr",
        "ababababcs","ababababct","ababababcu","ababababcv","ababababcw",
        "ababababcx","ababababcy","ababababcz","ababababda","ababababdb",
        "ababababdc","ababababdd","ababababde","ababababdf","ababababdg",
        "ababababdh","ababababdi","ababababdj","ababababdk","ababababdl",
        "ababababdm","ababababdn","ababababdo","ababababdp","ababababdq",
        "ababababdr","ababababds","ababababdt","ababababdu","ababababdv",
        "ababababdw","ababababdx","ababababdy","ababababdz","ababababea",
        "ababababeb","ababababec","ababababed","ababababee","ababababef",
        "ababababeg","ababababeh","ababababei","ababababej","ababababek",
        "ababababel","ababababem","ababababen","ababababeo","ababababep",
        "ababababeq","ababababer","ababababes","ababababet","ababababeu",
        "ababababev","ababababew","ababababex","ababababey","ababababez",
        "ababababfa","ababababfb","ababababfc","ababababfd","ababababfe",
        "ababababff","ababababfg","ababababfh","ababababfi","ababababfj",
        "ababababfk","ababababfl","ababababfm","ababababfn","ababababfo",
        "ababababfp","ababababfq","ababababfr","ababababfs","ababababft",
        "ababababfu","ababababfv","ababababfw","ababababfx","ababababfy",
        "ababababfz","ababababga","ababababgb","ababababgc","ababababgd",
        "ababababge","ababababgf","ababababgg","ababababgh","ababababgi",
        "ababababgj","ababababgk","ababababgl","ababababgm","ababababgn",
        "ababababgo","ababababgp","ababababgq","ababababgr","ababababgs",
        "ababababgt","ababababgu","ababababgv","ababababgw","ababababgx",
        "ababababgy","ababababgz","ababababha","ababababhb","ababababhc",
        "ababababhd","ababababhe","ababababhf","ababababhg","ababababhh",
        "ababababhi","ababababhj","ababababhk","ababababhl","ababababhm",
        "ababababhn","ababababho","ababababhp","ababababhq","ababababhr",
        "ababababhs","ababababht","ababababhu","ababababhv","ababababhw",
        "ababababhx","ababababhy","ababababhz","ababababia","ababababib",
        "ababababic","ababababid","ababababie","ababababif","ababababig",
        "ababababih","ababababii","ababababij","ababababik","ababababil",
        "ababababim","ababababin","ababababio","ababababip","ababababiq",
        "ababababir","ababababis","ababababit","ababababiu","ababababiv",
        "ababababiw","ababababix","ababababiy","ababababiz","ababababja",
        "ababababjb","ababababjc","ababababjd","ababababje","ababababjf",
        "ababababjg","ababababjh","ababababji","ababababjj","ababababjk",
        "ababababjl","ababababjm","ababababjn","ababababjo","ababababjp",
        "ababababjq","ababababjr","ababababjs","ababababjt","ababababju",
        "ababababjv","ababababjw","ababababjx","ababababjy","ababababjz",
        "ababababka","ababababkb","ababababkc","ababababkd","ababababke",
        "ababababkf","ababababkg","ababababkh","ababababki","ababababkj",
        "ababababkk","ababababkl","ababababkm","ababababkn","ababababko",
        "ababababkp","ababababkq","ababababkr","ababababks","ababababkt",
        "ababababku","ababababkv","ababababkw","ababababkx","ababababky",
        "ababababkz","ababababla","abababablb","abababablc","ababababld",
        "abababable","abababablf","abababablg","abababablh","ababababli",
        "abababablj","abababablk","ababababll","abababablm","ababababln",
        "abababablo","abababablp","abababablq","abababablr","ababababls",
        "abababablt","abababablu","abababablv","abababablw","abababablx",
        "abababably","abababablz","ababababma","ababababmb","ababababmc",
        "ababababmd","ababababme","ababababmf","ababababmg","ababababmh",
        "ababababmi","ababababmj","ababababmk","ababababml","ababababmm",
        "ababababmn","ababababmo","ababababmp","ababababmq","ababababmr",
        "ababababms","ababababmt","ababababmu","ababababmv","ababababmw",
        "ababababmx","ababababmy","ababababmz","ababababna","ababababnb",
        "ababababnc","ababababnd","ababababne","ababababnf","ababababng",
        "ababababnh","ababababni","ababababnj","ababababnk","ababababnl",
        "ababababnm","ababababnn","ababababno","ababababnp","ababababnq",
        "ababababnr","ababababns","ababababnt","ababababnu","ababababnv",
        "ababababnw","ababababnx","ababababny","ababababnz","ababababoa",
        "ababababob","ababababoc","ababababod","ababababoe","ababababof",
        "ababababog","ababababoh","ababababoi","ababababoj","ababababok",
        "ababababol","ababababom","ababababon","ababababoo","ababababop",
        "ababababoq","ababababor","ababababos","ababababot","ababababou",
        "ababababov","ababababow","ababababox","ababababoy","ababababoz",
        "ababababpa","ababababpb","ababababpc","ababababpd","ababababpe",
        "ababababpf","ababababpg","ababababph","ababababpi","ababababpj",
        "ababababpk","ababababpl","ababababpm","ababababpn","ababababpo",
        "ababababpp","ababababpq","ababababpr","ababababps","ababababpt",
        "ababababpu","ababababpv","ababababpw","ababababpx","ababababpy",
        "ababababpz","ababababqa","ababababqb","ababababqc","ababababqd",
        "ababababqe","ababababqf","ababababqg","ababababqh","ababababqi",
        "ababababqj","ababababqk","ababababql","ababababqm","ababababqn",
        "ababababqo","ababababqp","ababababqq","ababababqr","ababababqs",
        "ababababqt","ababababqu","ababababqv","ababababqw","ababababqx",
        "ababababqy","ababababqz","ababababra","ababababrb","ababababrc",
        "ababababrd","ababababre","ababababrf","ababababrg","ababababrh",
        "ababababri","ababababrj","ababababrk","ababababrl","ababababrm",
        "ababababrn","ababababro","ababababrp","ababababrq","ababababrr",
        "ababababrs","ababababrt","ababababru","ababababrv","ababababrw",
        "ababababrx","ababababry","ababababrz","ababababsa","ababababsb",
        "ababababsc","ababababsd","ababababse","ababababsf","ababababsg",
        "ababababsh","ababababsi","ababababsj","ababababsk","ababababsl",
        "ababababsm","ababababsn","ababababso","ababababsp","ababababsq",
        "ababababsr","ababababss","ababababst","ababababsu","ababababsv",
        "ababababsw","ababababsx","ababababsy","ababababsz","ababababta",
        "ababababtb","ababababtc","ababababtd","ababababte","ababababtf",
        "ababababtg","ababababth","ababababti","ababababtj","ababababtk",
        "ababababtl","ababababtm","ababababtn","ababababto","ababababtp",
        "ababababtq","ababababtr","ababababts","ababababtt","ababababtu",
        "ababababtv","ababababtw","ababababtx","ababababty","ababababtz",
        "ababababua","ababababub","ababababuc","ababababud","ababababue",
        "ababababuf","ababababug","ababababuh","ababababui","ababababuj",
        "ababababuk","ababababul","ababababum","ababababun","ababababuo",
        "ababababup","ababababuq","ababababur","ababababus","ababababut",
        "ababababuu","ababababuv","ababababuw","ababababux","ababababuy",
        "ababababuz","ababababva","ababababvb","ababababvc","ababababvd",
        "ababababve","ababababvf","ababababvg","ababababvh","ababababvi",
        "ababababvj","ababababvk","ababababvl","ababababvm","ababababvn",
        "ababababvo","ababababvp","ababababvq","ababababvr","ababababvs",
        "ababababvt","ababababvu","ababababvv","ababababvw","ababababvx",
        "ababababvy","ababababvz","ababababwa","ababababwb","ababababwc",
        "ababababwd","ababababwe","ababababwf","ababababwg","ababababwh",
        "ababababwi","ababababwj","ababababwk","ababababwl","ababababwm",
        "ababababwn","ababababwo","ababababwp","ababababwq","ababababwr",
        "ababababws","ababababwt","ababababwu","ababababwv","ababababww",
        "ababababwx","ababababwy","ababababwz","ababababxa","ababababxb",
        "ababababxc","ababababxd","ababababxe","ababababxf","ababababxg",
        "ababababxh","ababababxi","ababababxj","ababababxk","ababababxl",
        "ababababxm","ababababxn","ababababxo","ababababxp","ababababxq",
        "ababababxr","ababababxs","ababababxt","ababababxu","ababababxv",
        "ababababxw","ababababxx","ababababxy","ababababxz","ababababya",
        "ababababyb","ababababyc","ababababyd","ababababye","ababababyf",
        "ababababyg","ababababyh","ababababyi","ababababyj","ababababyk",
        "ababababyl","ababababym","ababababyn","ababababyo","ababababyp",
        "ababababyq","ababababyr","ababababys","ababababyt","ababababyu",
        "ababababyv","ababababyw","ababababyx","ababababyy","ababababyz",
        "ababababza","ababababzb","ababababzc","ababababzd","ababababze",
        "ababababzf","ababababzg","ababababzh","ababababzi","ababababzj",
        "ababababzk","ababababzl","ababababzm","ababababzn","ababababzo",
        "ababababzp","ababababzq","ababababzr","ababababzs","ababababzt",
        "ababababzu","ababababzv","ababababzw","ababababzx","ababababzy",
        "ababababzz","ababacabaa","ababacabab","ababacabac","ababacabad",
    };

    // test 4 solution
    std::vector<std::string> solution_5 = Solution().findWords(grid_5, words_5);
    std::cout << "Solution 5: " << std::endl;
    for (auto word : solution_5) {
        std::cout << "   + " << word << std::endl;
    }
    std::cout << std::endl;


    // end timer
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_time = end_time - start_time;
    std::cout << "Elapsed time: " << elapsed_time.count() << " s" << std::endl;

    return 0;
}
