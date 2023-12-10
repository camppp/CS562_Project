#include <vector>
#include <utility>

struct Hit {
    int time;
    // other attributes if any
};

std::pair<int, int> findMinMaxHitIndices(const std::vector<Hit>& hits) {
    int minIdx = 0, maxIdx = 0;
    for (int i = 1; i < hits.size(); ++i) {
        if (hits[i].time < hits[minIdx].time) {
            minIdx = i;
        }
        if (hits[i].time > hits[maxIdx].time) {
            maxIdx = i;
        }
    }
    return std::make_pair(minIdx, maxIdx);
}
