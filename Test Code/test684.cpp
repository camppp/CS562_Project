#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    ifstream file("copyright_notices.txt");
    string line;
    vector<int> years;

    // Read the file line by line
    while (getline(file, line)) {
        // Check if the line starts with "/*"
        if (line.find("/*") == 0) {
            // Extract the year range from the line
            stringstream ss(line);
            string year_range;
            getline(ss, year_range, ' ');
            year_range = year_range.substr(10, 10);

            // Split the year range into two parts
            vector<string> parts = split(year_range, '-');

            // Add the years to the vector
            years.push_back(stoi(parts[0]));
            years.push_back(stoi(parts[1]));
        }
    }

    // Sort the vector of years
    sort(years.begin(), years.end());

    // Determine the earliest and latest years
    int earliest_year = years[0];
    int latest_year = years[years.size() - 1];

    // Output the earliest and latest years
    cout << "Earliest year: " << earliest_year << endl;
    cout << "Latest year: " << latest_year << endl;

    return 0;
}
