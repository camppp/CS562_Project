#include <iostream>
#include <string>

using namespace std;

bool test_user_dic(const string& word) {
    tsc_cookie cookie;
    tscUninit(cookie);

    // Initialize the user dictionary
    if (tscInit(cookie) != 0) {
        cout << "Error initializing user dictionary" << endl;
        return false;
    }

    // Check if the word exists in the dictionary
    if (tscFind(cookie, word) != 0) {
        cout << "Word not found in user dictionary" << endl;
        return false;
    }

    // Clean up the user dictionary
    tscUninit(cookie);

    return true;
}
