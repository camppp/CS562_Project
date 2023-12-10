#include <string>
#include <vector>

std::vector<int> i_am_here(const std::string& movements) {
    std::vector<int> position = {0, 0};
    for (char movement : movements) {
        switch (movement) {
            case 'R':
                position[0] += 1;
                break;
            case 'L':
                position[0] -= 1;
                break;
            case 'r':
                position[1] += 1;
                break;
            case 'l':
                position[1] -= 1;
                break;
        }
    }
    return position;
}
