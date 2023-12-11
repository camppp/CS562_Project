#include <iostream>
#include <vector>

using namespace std;

vector<float> applyAssignments(vector<float> JB, vector<float> w, vector<float> p, vector<float> x, vector<float> dwdx) {
    for (int i = 0; i < JB.size(); i++) {
        if (i == 2 + 2 * 10) {
            JB[i] = -w[1];
        } else if (i == 2 + 3 * 10) {
            JB[i] = -p[0] * p[1];
        } else if (i == 3 + 1 * 10) {
            JB[i] = 1.0;
        } else if (i == 3 + 2 * 10) {
            JB[i] = 1.0;
        } else if (i == 3 + 3 * 10) {
            JB[i] = p[0];
        } else if (i == 4 + 0 * 10) {
            JB[i] = -x[4] * dwdx[1];
        }
    }
    return JB;
}

int main() {
    vector<float> JB = {0.0};
    vector<float> w = {2.0, 3.0, 4.0, 5.0, 6.0};
    vector<float> p = {1.0, 2.0, 3.0};
    vector<float> x = {0.5, 1.5, 2.5, 3.5, 4.5};
    vector<float> dwdx = {0.1, 0.2, 0.3, 0.4, 0.5};

    vector<float> result = applyAssignments(JB, w, p, x, dwdx);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
