void calculateWeights(vector<pair<int, int>>& merge_candidates, vector<double>& scores) {
    for (int i = 0; i < merge_candidates.size(); i++) {
        int system1 = merge_candidates[i].first;
        int system2 = merge_candidates[i].second;
        // Calculate the weight for the merge of system1 and system2
        double weight = calculateWeight(system1, system2);
        scores[i] = weight;
    }
}
