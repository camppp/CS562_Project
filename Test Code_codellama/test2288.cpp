int tallest_building_index(vector<int> buildings) {
    int tallest = 0;
    int index = 0;
    for (int i = 0; i < buildings.size(); i++) {
        if (buildings[i] > tallest) {
            tallest = buildings[i];
            index = i;
        }
    }
    return index;
}
