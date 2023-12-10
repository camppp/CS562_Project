#include <iostream>
#include <vector>

std::vector<double> calculateMeasures(const std::vector<double>& ripknl, const std::vector<double>& frank, double areaDens) {
    std::vector<double> measures(2);
    for (int i = 0; i < ripknl.size(); i++) {
        measures[0] += ripknl[i];
        measures[1] += frank[i];
    }
    measures[0] *= areaDens;
    measures[1] *= areaDens;
    return measures;
}
