#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

int main() {
    // Define the start and end times of the process
    chrono::time_point<chrono::system_clock> start, end;
    start = chrono::system_clock::now();
    // Perform the operation on the data structure
    vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i < data.size(); i++) {
        if (data[i] % 2 == 0) {
            // Skip the even numbers
            continue;
        }
        // Perform the operation on the odd numbers
        data[i] *= 2;
    }
    // Calculate the time difference between the start and end times
    end = chrono::system_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "Time difference: " << elapsed.count() << " years" << endl;
    return 0;
}
