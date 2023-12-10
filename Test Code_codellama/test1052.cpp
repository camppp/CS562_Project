#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int main() {
    // Set the number of random numbers to collect
    const int NUM = 10;

    // Initiate the collection of random numbers
    for (size_t ii=0; ii<NUM; ++ii) {
        // Generate a random number between 1 and 100
        int random_number = rand() % 100 + 1;

        // Add the random number to the collection
        cout << "Random number " << ii+1 << ": " << random_number << endl;
    }

    // Calculate the sum of all collected numbers
    int sum = 0;
    for (size_t ii=0; ii<NUM; ++ii) {
        sum += random_numbers[ii];
    }
    cout << "Sum of all collected numbers: " << sum << endl;

    // Find the maximum and minimum values among the collected numbers
    int max = random_numbers[0];
    int min = random_numbers[0];
    for (size_t ii=0; ii<NUM; ++ii) {
        if (random_numbers[ii] > max) {
            max = random_numbers[ii];
        }
        if (random_numbers[ii] < min) {
            min = random_numbers[ii];
        }
    }
    cout << "Maximum value: " << max << endl;
    cout << "Minimum value: " << min << endl;

    // Sort the collected numbers in ascending order
    sort(random_numbers, random_numbers + NUM);
    for (size_t ii=0; ii<NUM; ++ii) {
        cout << "Sorted number " << ii+1 << ": " << random_numbers[ii] << endl;
    }

    return 0;
}
