#include <iostream>
#include <cmath>

class GridParameters {
public:
    double get_deltax_eq() {
        return 10.0;
    }

    double get_deltay() {
        return 10.0;
    }
};

class UserGrid {
public:
    UserGrid(GridParameters param, int season) {
        // Initialize the user grid based on the grid parameters and season
    }

    double get_rdx() {
        return 30.0 / param.get_deltax_eq();
    }

    double get_rdy() {
        return 30.0 / param.get_deltay();
    }
};

std::pair<double, double> calculateScalingFactors(GridParameters param, int season) {
    UserGrid userGrid = UserGrid(param, season);
    return std::make_pair(userGrid.get_rdx(), userGrid.get_rdy());
}

int main() {
    GridParameters param;
    int season = 1;
    std::pair<double, double> scalingFactors = calculateScalingFactors(param, season);
    std::cout << "Scaling factors: " << scalingFactors.first << ", " << scalingFactors.second << std::endl;
    return 0;
}
