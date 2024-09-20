#include <iostream>
#include <bitset>
#include <cstdio>

int main() {
    const int N = 10; // Number of nodes (less than 64)
    const int total_bits = 64;
    
    std::bitset<total_bits> visited; // bitset with 64 bits
    
    // Let's assume nodes 1, 3, and 5 are visited
    visited.set(1);
    visited.set(3);
    visited.set(5);

    // Create a mask that only considers the first N bits
    // You do:
    // 1ULL =           0000000000000000000000000000000000000000000000000000000000000001
    // 1ULL << N =      0000000000000000000000000000000000000000000000000000010000000000
    // 1ULL << N - 1 =  0000000000000000000000000000000000000000000000000000001111111111
    std::bitset<total_bits> mask((1ULL << N) - 1); // This creates a bitset where the first N bits are set to 1

    // print the mask in binary
    printf("Mask: %s\n", mask.to_string().c_str());

    // Now we want to iterate over non-visited nodes only in the range [0, N-1]
    std::bitset<total_bits> non_visited = (~visited) & mask; // Invert visited and apply the mask

    std::cout << "Non-visited nodes: ";
    for (int i = 0; i < N; ++i) {
        if (non_visited.test(i)) {
            std::cout << i << " "; // Process the non-visited node
        }
    }
    std::cout << std::endl;

    return 0;
}
