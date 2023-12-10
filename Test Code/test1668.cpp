#include <vector>
#include <sstream>

using namespace std;

vector<double> processLocations(vector<vector<double>>& loc, int line) {
    vector<double> averages(6, 0.0);

    for (int j = 0; j < line; ++j) {
        string loc_0, loc_1, loc_2, loc_3, loc_4, loc_5;
        stringstream ss_0;
        ss_0.clear();
        ss_0 << loc[j][0];
        loc_0 = ss_0.str();

        stringstream ss_1;
        ss_1.clear();
        ss_1 << loc[j][1];
        loc_1 = ss_1.str();

        stringstream ss_2;
        ss_2.clear();
        ss_2 << loc[j][2];
        loc_2 = ss_2.str();

        stringstream ss_3;
        ss_3.clear();
        ss_3 << loc[j][3];
        loc_3 = ss_3.str();

        stringstream ss_4;
        ss_4.clear();
        ss_4 << loc[j][4];
        loc_4 = ss_4.str();

        stringstream ss_5;
        ss_5.clear();
        ss_5 << loc[j][5];
        loc_5 = ss_5.str();

        for (int k = 0; k < 6; ++k) {
            averages[k] += loc[j][k];
        }
    }

    for (int k = 0; k < 6; ++k) {
        averages[k] /= line;
    }

    return averages;
}
