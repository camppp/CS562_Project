#include <array>

std::array<uint64_t, 5> x448FieldAdd(const std::array<uint64_t, 5>& x, const std::array<uint64_t, 5>& y) {
    const uint64_t P = (1ULL << 56) - 1; // Prime number 2^448 - 2^224 - 1
    std::array<uint64_t, 5> result;
    uint64_t carry = 0;

    for (int i = 0; i < 5; ++i) {
        uint64_t xi = x[i];
        uint64_t yi = y[i];
        uint64_t sum = xi + yi + carry;
        result[i] = sum & P;
        carry = sum >> 56;
    }

    return result;
}

std::array<uint64_t, 5> x448FieldSub(const std::array<uint64_t, 5>& x, const std::array<uint64_t, 5>& y) {
    const uint64_t P = (1ULL << 56) - 1; // Prime number 2^448 - 2^224 - 1
    std::array<uint64_t, 5> result;
    uint64_t borrow = 0;

    for (int i = 0; i < 5; ++i) {
        uint64_t xi = x[i];
        uint64_t yi = y[i];
        uint64_t diff = xi - yi - borrow;
        result[i] = diff & P;
        borrow = (diff >> 63) & 1;
    }

    return result;
}
