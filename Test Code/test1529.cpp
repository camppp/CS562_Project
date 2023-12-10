#include <iostream>
#include <vector>

using namespace std;

vector<int> maxPensAndPencils(int T, vector<int> p, vector<int> f, vector<int> cs, vector<int> cw, vector<int> s, vector<int> w) {
    vector<int> result(T);

    for (int i = 0; i < T; i++) {
        int pens = min(p[i], s[i] / cs[i]);
        int pencils = min(f[i], w[i] / cw[i]);
        result[i] = min(pens, pencils);
    }

    return result;
}

int main() {
    int T;
    cin >> T;

    vector<int> p(T), f(T), cs(T), cw(T), s(T), w(T);

    for (int i = 0; i < T; i++) {
        cin >> p[i] >> f[i] >> cs[i] >> cw[i] >> s[i] >> w[i];
    }

    vector<int> result = maxPensAndPencils(T, p, f, cs, cw, s, w);

    for (int i = 0; i < T; i++) {
        cout << result[i] << " ";
    }

    return 0;
}
