#include <iostream>
#include <vector>

typedef std::vector<unsigned int> vec_type;

unsigned int calculateSum(const vec_type& vec) {
    unsigned int sum = 0;
    for (unsigned int num : vec) {
        sum += num;
    }
    return sum;
}

int main() {
    vec_type v = {1, 2, 3, 4, 5};
    unsigned int result = calculateSum(v);
    std::cout << "Sum: " << result << std::endl;
    return 0;
}
