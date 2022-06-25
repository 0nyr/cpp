#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <regex>

int main() {

    std::vector<std::string> words = {
        "happyness",
        "loving",
        "recension",
        "modification"
    };

    // sort the list in increasing order
    std::sort(words.begin(), words.end());

    // sort the list in decreasing order
    std::sort(words.begin(), words.end(), std::greater<std::string>());

    // match regex pattern
    // print words that finish in 'ing'
    std::regex pattern("ing$");
    for (auto word : words) {
        if (std::regex_search(word, pattern)) {
            std::cout << word << std::endl;
        }
    }

    // https://cplusplus.com/reference/regex/regex_search/
    std::string s ("this subject has a submarine as a subsequence");
    std::smatch m; // match for string
    std::regex e ("\\b(sub)([^ ]*)");   // matches words beginning by "sub"

    while (std::regex_search(s,m,e)) {
        std::cout << "-> matched word: " << m.format("$0") << std::endl;

        // print submatches
        for (auto x:m) { std::cout << x << " "; }
        std::cout << std::endl;

        // advance string past match
        s = m.suffix().str();
    }

    // using explicit flags:
    const char cstr[] = "subject has subordinate in suburb of submarine city";
    std::cmatch cm;    // same as std::match_results<const char*> cm;
    std::regex e1 ("(sub)(.*)");

    std::regex_match (cstr, cm, e1, std::regex_constants::match_default );

    std::cout << "the matches were: ";
    for (unsigned i=0; i<cm.size(); ++i) {
        std::cout << "[" << cm[i] << "] ";
    }
    std::cout << std::endl;

    return 0; 
}