#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, vector<tuple<string, string, string, string>>> parseFirearmData(const vector<string>& firearmStrings) {
    map<string, vector<tuple<string, string, string, string>>> firearmData;

    for (const string& firearmString : firearmStrings) {
        string manufacturer, model, caliber, barrelLength, attachment;
        stringstream ss(firearmString);
        ss >> manufacturer >> model >> caliber >> barrelLength >> attachment;

        vector<tuple<string, string, string, string>>& firearmDataForManufacturer = firearmData[manufacturer];
        firearmDataForManufacturer.push_back(make_tuple(model, caliber, barrelLength, attachment));
    }

    return firearmData;
}

int main() {
    vector<string> firearmStrings = {
        "CUP_CZ_BREN2_556_11_GL",
        "CUP_CZ_BREN2_556_14_GL",
        "CUP_arifle_HK416_CQB_M203_Black",
        "CUP_arifle_HK416_CQB_M203_Desert",
        "CUP_arifle_HK416_CQB_M203_Wood",
        "CUP_arifle_HK416_CQB_AG36",
        "CUP_arifle_HK416_CQB_AG36_Desert"
    };

    map<string, vector<tuple<string, string, string, string>>> firearmData = parseFirearmData(firearmStrings);

    for (const auto& manufacturerData : firearmData) {
        cout << manufacturerData.first << ": " << endl;
        for (const auto& firearmData : manufacturerData.second) {
            cout << "  " << get<0>(firearmData) << ", " << get<1>(firearmData) << ", " << get<2>(firearmData) << ", " << get<3>(firearmData) << endl;
        }
    }

    return 0;
}
