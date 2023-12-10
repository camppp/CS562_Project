#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

long randomWriteThenRead(int blockSize) {
    // Open file for writing
    ofstream outFile("test.txt", ios::out | ios::binary);

    // Generate random data
    srand(time(0));
    char* data = new char[blockSize];
    for (int i = 0; i < blockSize; i++) {
        data[i] = rand() % 256;
    }

    // Perform random writes
    for (int i = 0; i < 1000; i++) {
        outFile.write(data, blockSize);
    }

    // Close file
    outFile.close();

    // Open file for reading
    ifstream inFile("test.txt", ios::in | ios::binary);

    // Read data back from file
    char* readData = new char[blockSize];
    inFile.read(readData, blockSize);

    // Close file
    inFile.close();

    // Measure time taken for write and read operations
    clock_t start = clock();
    for (int i = 0; i < 1000; i++) {
        outFile.write(data, blockSize);
        inFile.read(readData, blockSize);
    }
    clock_t end = clock();

    // Calculate total time taken
    long totalTime = (end - start) / (double)CLOCKS_PER_SEC * 1000;

    // Clean up
    delete[] data;
    delete[] readData;

    return totalTime;
}
