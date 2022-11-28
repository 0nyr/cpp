/*******
 * Read input from cin
 * Use cout << ... to output your result to STDOUT.
 * Use cerr << ... to output debugging information to STDERR
 * ***/
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>


int main() {
    int nb_bots = 0;

   std::string line;
	while (std::getline(std::cin, line))
	{
		if (line.empty() || line.length() < 5)
            continue;
        
        for (int i = 1; i <= 5; i++)
        {
            if (!isdigit(line[line.length() - i])) {
                break;
            }
            // when all 5 chars are digits, we have a bot
            if (i == 5) {
                nb_bots++;
            }
        }
	}

    std::cout << nb_bots << std::endl;
    return 0;
}