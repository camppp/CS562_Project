#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the Euclidean distance between two points
double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

// Function to find the pair of points with the maximum distance between them
pair<pair<double, double>, pair<double, double>> max_distance_points(const vector<pair<double, double>>& points) {
    double max_distance = 0;
    pair<double, double> p1, p2;

    // Iterate over all pairs of points
    for (int i = 0; i < points.size(); i++) {
        for (int j = i + 1; j < points.size(); j++) {
            // Calculate the distance between the current pair of points
            double distance = distance(points[i].first, points[i].second, points[j].first, points[j].second);

            // If the distance is greater than the current maximum distance, update the maximum distance and the corresponding pair of points
            if (distance > max_distance) {
                max_distance = distance;
                p1 = points[i];
                p2 = points[j];
            }
        }
    }

    // Return the pair of points with the maximum distance between them
    return make_pair(p1, p2);
}

int main() {
    // Test the function with the given set of points
    vector<pair<double, double>> points = {
        {-0.0697622150950153008986, 0.046432560482317929183},
        {-0.0232708715407507060344, 0.0465333413404968638234},
        {0.02327087154075070603437, 0.0465333413404968638234},
        {0.0697622150950153008986, 0.0464325604823179291833},
        {0.1161024692216898182267, 0.046231217034791425205},
        {0.1621912712463770264451, 0.0459297470628552269276},
        {0.2079288030837679729796, 0.045528803483127572753},
        {0.2532160074213070237007, 0.0450292546498245100301},
        {0.2979548022551796483432, 0.0444321824740826399099},
        {0.3420482933139803129623, 0.043738880080758951608},
        {0.3854009839099910183841, 0.0429508490077806243141},
        {0.4279189817635698486723, 0.042069795954107501617},
        {0.4695102023527009595653, 0.0410976290833462117396}
    };

    pair<pair<double, double>, pair<double, double>> result = max_distance_points(points);
    cout << "The pair of points with the maximum distance between them is: " << result.first.first << ", " << result.first.second << " and " << result.second.first << ", " << result.second.second << endl;

    return 0;
}
