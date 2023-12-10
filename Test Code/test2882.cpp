#include <vector>
#include <numeric>

class AlarmList {
public:
    std::vector<int> items;

    int calculateSum() const {
        return std::accumulate(items.begin(), items.end(), 0);
    }
};
