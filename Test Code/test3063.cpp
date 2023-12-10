vector<int> findValues(vector<pair<int, int>> intervals, vector<pair<int, int>> v, int N) {
    vector<int> answer(N, -1);
    for (int i = 0; i < N; i++) {
        int start = intervals[i].first;
        int end = intervals[i].second;
        int index = lower_bound(v.begin(), v.end(), start,
                                [](const pair<int, int>& p, int x) {
                                    return p.first < x;
                                }) - v.begin();
        if (index < v.size() && v[index].first >= start) {
            answer[i] = v[index].second;
        }
    }
    return answer;
}
