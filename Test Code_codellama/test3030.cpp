vector<int> merge180Image(const vector<int>& isl180, const vector<int>& isr180) {
    vector<int> image(isl180.size() + isr180.size());
    for (int i = 0; i < isl180.size(); i++) {
        image[i] = isl180[i];
    }
    for (int i = 0; i < isr180.size(); i++) {
        image[i + isl180.size()] = isr180[i];
    }
    return image;
}
