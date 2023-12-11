#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void initializeMatrix(vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            matrix[i][j] = rand() % 10 + 1;
        }
    }
}

vector<vector<int>> matrixMultiplication(vector<vector<int>>& A, vector<vector<int>>& B) {
    if (A.size() != B.size() || A[0].size() != B[0].size()) {
        throw runtime_error("Dimensions of matrices do not match");
    }

    vector<vector<int>> C(A.size(), vector<int>(B[0].size()));
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B[0].size(); j++) {
            for (int k = 0; k < A[0].size(); k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

int main() {
    srand(time(0));

    vector<vector<int>> A(3, vector<int>(3));
    vector<vector<int>> B(3, vector<int>(3));

    initializeMatrix(A);
    initializeMatrix(B);

    vector<vector<int>> C = matrixMultiplication(A, B);

    for (int i = 0; i < C.size(); i++) {
        for (int j = 0; j < C[i].size(); j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
