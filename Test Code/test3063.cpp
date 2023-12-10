#include <vector>
#include <algorithm>

using namespace std;

bool lb_comp(const pair<int, int>& p, int val) {
    return p.first < val;
}

vector<int> findValues(vector<pair<int, int>> intervals, vector<pair<int, int>> v, int N) {
    vector<int> answer(N);
    for (int i = 0; i < N; ++i) {
        int pos = lower_bound(v.begin(), v.end(), intervals[i].second, lb_comp) - v.begin();
        if (pos < N) {
            answer[i] = v[pos].second;
        } else {
            answer[i] = -1;
        }
    }
    return answer;
}
