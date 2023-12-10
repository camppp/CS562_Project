#include <boost/fusion/sequence/intrinsic/segments.hpp>
#include <vector>
#include <variant>

int nestedListSum(const std::variant<int, std::vector<std::variant<int, std::vector<int>>>>& nestedList) {
    int sum = 0;
    if (std::holds_alternative<int>(nestedList)) {
        sum += std::get<int>(nestedList);
    } else {
        const auto& list = std::get<std::vector<std::variant<int, std::vector<int>>>>(nestedList);
        for (const auto& item : list) {
            sum += nestedListSum(item);
        }
    }
    return sum;
}

int main() {
    std::variant<int, std::vector<std::variant<int, std::vector<int>>>> nestedList = std::vector<std::variant<int, std::vector<int>>>{1, std::vector<int>{2, 3, std::vector<int>{4, 5}}};
    int result = nestedListSum(nestedList);
    std::cout << "Sum of nested list: " << result << std::endl;
    return 0;
}
