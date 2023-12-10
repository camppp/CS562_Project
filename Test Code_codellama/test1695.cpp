std::vector<int> generateMeshIndices(int Meridians, int k) {
    std::vector<int> Indices;
    for (int i = 0; i < Meridians; i++) {
        for (int j = 0; j < Meridians; j++) {
            int index = i * Meridians + j;
            Indices.push_back(index);
        }
    }
    return Indices;
}
