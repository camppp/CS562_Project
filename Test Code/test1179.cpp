#include <cstddef>
#include <cmath>

class MortonHashTable {
private:
    size_t size; // Number of items in the hash table

public:
    // Constructor and other methods are not shown for brevity

    size_t SizeInBytes() const
    {
        // Calculate the size of the hash table in bytes based on the number of items and the given configuration
        // Morton3_8 - 3-slot buckets with 8-bit fingerprints: 11.7 bits/item (load factor = 0.95)
        double bitsPerItem = 11.7;
        double loadFactor = 0.95;
        double totalBits = size * bitsPerItem / loadFactor;
        size_t totalBytes = static_cast<size_t>(std::ceil(totalBits / 8));
        return totalBytes;
    }
};
