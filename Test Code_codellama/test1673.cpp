vector<int> findMissingNumbers(const vector<string>& dict) {
    vector<int> missingNumbers;

    // Iterate through the dictionary
    for (int i = 1; i <= 1000; i++) {
        // If the current number is not in the dictionary, add it to the missing numbers vector
        if (find(dict.begin(), dict.end(), to_string(i)) == dict.end()) {
            missingNumbers.push_back(i);
        }
    }

    // Sort the missing numbers vector in ascending order
    sort(missingNumbers.begin(), missingNumbers.end());

    return missingNumbers;
}
