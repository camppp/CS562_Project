int nestedListSum(const vector<int>& nestedList) {
    int sum = 0;
    for (const auto& element : nestedList) {
        if (element.is_integer()) {
            sum += element.get<int>();
        } else if (element.is_list()) {
            sum += nestedListSum(element.get<vector<int>>());
        }
    }
    return sum;
}
