#include <iostream>
#include <cstdlib>

typedef unsigned long long U64;
typedef U64 bitboard;

// Function to generate a 64-bit random bitboard
bitboard rand64() {
    return (static_cast<U64>(std::rand()) |
            (static_cast<U64>(std::rand()) << 15) |
            (static_cast<U64>(std::rand()) << 30) |
            (static_cast<U64>(std::rand()) << 45) |
            (static_cast<U64>(std::rand() & 0xf) << 60));
}

// Function to generate a 64-bit random bitboard with a few set bits
bitboard rand64_fewbits() {
    return rand64() & rand64() & rand64();
}

int main() {
    // Test the rand64_fewbits function
    bitboard result = rand64_fewbits();
    std::cout << "Random bitboard with few set bits: " << result << std::endl;
    return 0;
}
