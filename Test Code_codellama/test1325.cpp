#include <vector>
#include <iostream>

// Implementation of the subvector function
std::vector<Real>& subvector(const std::vector<Real>& v, size_t start, size_t end) {
    static std::vector<Real> sub;
    sub.clear();
    for (size_t i = start; i < end; ++i) {
        sub.push_back(v[i]);
    }
    return sub;
}

// Implementation of the r_sum function
Real r_sum(const std::vector<Real>& v1, const std::vector<Real>& v2) {
    Real sum = 0;
    size_t n = std::min(v1.size(), v2.size());
    for (size_t i = 0; i < n; ++i) {
        sum += v1[i] * v2[i];
    }
    return sum;
}

int main() {
    // Test the subvector function
    std::vector<Real> v = {1, 2, 3, 4, 5};
    std::vector<Real>& sub = subvector(v, 1, 3);
    std::cout << "Subvector: ";
    for (Real x : sub) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // Test the r_sum function
    std::vector<Real> v1 = {1, 2, 3};
    std::vector<Real> v2 = {4, 5, 6};
    Real sum = r_sum(v1, v2);
    std::cout << "Sum: " << sum << std::endl;

    return 0;
}
