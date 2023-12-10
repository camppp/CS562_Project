#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> sortDiagonals(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();

    auto sort_diagonal = [&](int i, int j) {
        vector<int> d;
        for (int k = i, l = j; k < m && l < n; k++, l++)
            d.push_back(mat[k][l]);
        sort(d.begin(), d.end());
        for (int p = 0; p < d.size(); p++)
            mat[i++][j++] = d[p];
    };

    for (int i = 0; i < n; i++)
        sort_diagonal(0, i);
    for (int i = 1; i < m; i++)
        sort_diagonal(i, 0);

    return mat;
}
