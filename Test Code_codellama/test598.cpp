#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

vector<vector<int>> process_image(vector<vector<tuple<int, int, int>>> image, int img_bytes_per_line) {
    vector<vector<int>> grayscale_image(image.size(), vector<int>(image[0].size()));

    for (int i = 0; i < image.size(); i++) {
        for (int j = 0; j < image[i].size(); j++) {
            int r = image[i][j].first;
            int g = image[i][j].second;
            int b = image[i][j].third;

            int grayscale = (r + g + b) / 3;

            grayscale_image[i][j] = grayscale;
        }
    }

    return grayscale_image;
}
