#include <iostream>

int main() {
    int gh_stars;
    std::cin >> gh_stars;

    if (gh_stars < 100) {
        std::cout << "Not popular yet." << std::endl;
    } else if (gh_stars >= 100 && gh_stars <= 1000) {
        std::cout << "Getting noticed." << std::endl;
    } else {
        std::cout << "Well-known repository." << std::endl;
    }

    return 0;
}
