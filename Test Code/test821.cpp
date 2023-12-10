#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    int N, M;
    input >> N >> M;

    vector<string> repos(N);
    vector<int> stars(N);

    for (int i = 0; i < N; i++) {
        input >> repos[i] >> stars[i];
    }

    for (int i = 0; i < M; i++) {
        int A, B;
        input >> A >> B;

        int total = 0;
        for (int j = 0; j < N; j++) {
            if (stars[j] >= A && stars[j] <= B) {
                total += stars[j];
            }
        }

        output << total << endl;
    }

    return 0;
}
