#include <vector>

std::vector<int> generateMeshIndices(int Meridians, int k) {
    std::vector<int> Indices;

    for (int l = 0; l < Meridians; l++) {
        int a = (k * (Meridians + 1)) + l;
        int b = a + Meridians + 1;

        Indices.push_back(a);
        Indices.push_back(b);
        Indices.push_back(a + 1);

        Indices.push_back(b);
        Indices.push_back(a + 1);
        Indices.push_back(b + 1);
    }

    return Indices;
}
