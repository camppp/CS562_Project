#include <iostream>
#include <vector>

typedef double Real; // Define the type of real numbers

// Implement the subvector function
std::vector<Real>& subvector(const std::vector<Real>& v, size_t start, size_t end) {
    static std::vector<Real> sub;
    sub.clear();
    for (size_t i = start; i < end; ++i) {
        sub.push_back(v[i]);
    }
    return sub;
}

// Implement the r_sum function
Real r_sum(const std::vector<Real>& v1, const std::vector<Real>& v2) {
    Real sum = 0;
    size_t n = std::min(v1.size(), v2.size());
    for (size_t i = 0; i < n; ++i) {
        sum += v1[i] * v2[i];
    }
    return sum;
}

int main() {
    // Example usage
    std::vector<Real> y = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<Real> w = {0.5, 1.5, 2.5, 3.5, 4.5};

    // Using subvector and r_sum functions
    size_t head = 1, tail = 4;
    const std::vector<Real>& w_sub = subvector(w, head, tail);
    Real result = r_sum(w_sub, w_sub);

    // Output the result
    std::cout << "Result: " << result << std::endl;

    return 0;
}
