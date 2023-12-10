#include <vector>
using namespace std;

vector<int> calculateAnswer(int x) {
    int a[210] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4, 6, 2, 6, 4, 3, 3};
    int val[210][210];
    int b[210];
    vector<int> parent[210];
    int ans[110];
    int at = 0;
    int n = 25;

    for (int i = 1; i <= n; i++) {
        if (i == x) continue;
        if (a[i] > a[x]) {
            val[x][a[i]] = 1;
            at++;
        } else if (a[i] < a[x]) {
            val[x][a[i]] = -1;
            at--;
        } else {
            parent[x].push_back(i);
        }
    }
    ans[at] = parent[x].size();

    vector<int> result;
    for (int i = 0; i < 110; i++) {
        result.push_back(ans[i]);
    }
    return result;
}
