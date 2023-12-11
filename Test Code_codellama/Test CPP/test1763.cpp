#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

string generateRandomSequence(int n) {
    string result;
    srand(time(0));

    for (int i = 0; i < n; i++) {
        int r = rand() % 2;
        if (r == 0) {
            result += '!';
        } else {
            result += '0' + rand() % 10;
        }
    }

    return result;
}

int main() {
    int n = 10;
    string sequence = generateRandomSequence(n);
    cout << sequence << endl;
    return 0;
}
