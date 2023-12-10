class Extrapolator {
public:
    void Inform(int input, int output) {
        // Add the new data point to the list of data points
        data_points.push_back(std::make_pair(input, output));
    }

    int* Extrapolate(int input) {
        // Find the two closest data points to the given input
        auto it = std::lower_bound(data_points.begin(), data_points.end(), input,
                                   [](const std::pair<int, int>& p, int input) {
                                       return p.first < input;
                                   });
        if (it == data_points.end()) {
            // If the input is not within the range of the given data points, return nullptr
            return nullptr;
        }

        // Perform linear interpolation between the two closest data points
        int output = (it->second * (input - it->first) + (it + 1)->second * (it + 1)->first - it->first * (it + 1)->second) / (it->first - (it + 1)->first);

        // Return a pointer to the extrapolated output
        return &output;
    }

private:
    std::vector<std::pair<int, int>> data_points;
};
