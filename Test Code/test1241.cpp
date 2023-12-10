#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<double> performOperations(vector<double> div, int offset, double n, int VERB) {
    vector<double> result = div;  // Create a copy of the input array

    for (int ix = 0; ix < div.size() - offset; ix++) {
        if (result[offset + ix] <= 0 || n == 0) {
            result[offset + ix] = 1.0;
        } else {
            result[offset + ix] = sqrt(result[offset + ix] / n);
        }
        if (VERB > 2) {
            cerr << "\t" << result[offset + ix];
        }
    }
    if (VERB > 2) {
        cerr << endl;
    }

    return result;
}

int main() {
    vector<double> div = {4.0, 9.0, 16.0, 25.0, 36.0};
    int offset = 1;
    double n = 2.0;
    int VERB = 3;

    vector<double> modifiedArray = performOperations(div, offset, n, VERB);

    for (double val : modifiedArray) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
