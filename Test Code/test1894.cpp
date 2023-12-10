#include <iostream>
#include <vector>

using namespace std;

vector<int> groupNumbers(vector<int> numbers) {
    vector<int> evenNumbers;
    vector<int> oddNumbers;

    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] % 2 == 0) {
            evenNumbers.push_back(numbers[i]);
        } else {
            oddNumbers.push_back(numbers[i]);
        }
    }

    return {evenNumbers, oddNumbers};
}

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto groupedNumbers = groupNumbers(numbers);

    cout << "Even numbers: ";
    for (int i = 0; i < groupedNumbers[0].size(); i++) {
        cout << groupedNumbers[0][i] << " ";
    }
    cout << endl;

    cout << "Odd numbers: ";
    for (int i = 0; i < groupedNumbers[1].size(); i++) {
        cout << groupedNumbers[1][i] << " ";
    }
    cout << endl;

    return 0;
}
