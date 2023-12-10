#include <vector>
#include <string>
#include <iostream>

namespace codewars {
    namespace fourkyu {
        namespace path_finder4 {
            std::vector<int> i_am_here(const std::string& movements) {
                int x = 0, y = 0;
                int i = 0;
                while (i < movements.size()) {
                    char direction = movements[i];
                    int distance = 0;
                    i++;
                    while (i < movements.size() && isdigit(movements[i])) {
                        distance = distance * 10 + (movements[i] - '0');
                        i++;
                    }
                    if (direction == 'R') {
                        x += distance;
                    } else if (direction == 'L') {
                        x -= distance;
                    } else if (direction == 'r') {
                        x += distance;
                        y += distance;
                    } else if (direction == 'l') {
                        x -= distance;
                        y -= distance;
                    }
                }
                return {x, y};
            }
        }
    }
}

// Test cases
int main() {
    using namespace codewars::fourkyu::path_finder4;
    // Test case 1
    std::vector<int> result1 = i_am_here("");
    std::cout << result1[0] << " " << result1[1] << std::endl;  // Output: 0 0

    // Test case 2
    std::vector<int> result2 = i_am_here("RLrl");
    std::cout << result2[0] << " " << result2[1] << std::endl;  // Output: 0 0

    // Test case 3
    std::vector<int> result3 = i_am_here("r5L2l4");
    std::cout << result3[0] << " " << result3[1] << std::endl;  // Output: 4 3

    return 0;
}
