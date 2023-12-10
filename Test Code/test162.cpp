#include <iostream>
#include <vector>
#include <algorithm>

class KMeansClustering {
private:
    std::vector<int> _ignores;
    // Assume _dataframe is an instance of a DataFrame class

public:
    void RemoveIgnore(std::string &ignores) {
        int att = _dataframe.GetAttributeIndex(ignores);
        auto result = std::find(_ignores.begin(), _ignores.end(), att);
        if (result != _ignores.end()) {
            _ignores.erase(result); // Add this line to remove the attribute index
        }
    }
};
