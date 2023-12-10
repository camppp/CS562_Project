#include <iostream>
#include <cmath>

int main() {
    double x1, y1, x2, y2;
    
    std::cout << "Enter the x-coordinate of point P: ";
    std::cin >> x1;
    std::cout << "Enter the y-coordinate of point P: ";
    std::cin >> y1;
    
    std::cout << "Enter the x-coordinate of point Q: ";
    std::cin >> x2;
    std::cout << "Enter the y-coordinate of point Q: ";
    std::cin >> y2;
    
    // Calculate the distance using the Euclidean distance formula
    double distance = std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
    
    std::cout << "The distance between point P and point Q is: " << distance << std::endl;
    
    return 0;
}
