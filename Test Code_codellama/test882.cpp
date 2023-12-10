#include <iostream>
#include <string>
#include <cld2.h>

using namespace std;

int main() {
    // Initialize arrays for storing detected languages, percentages, and scores
    string detected_languages[10];
    double percentages[10];
    double scores[10];

    // Get input text from the user
    string text;
    cout << "Enter text: ";
    getline(cin, text);

    // Use CLD2 library to detect language of the text
    CLD2::ExtDetectLanguageSummaryCheckUTF8(text, detected_languages, percentages, scores);

    // Print summary of language detection results
    cout << "Detected languages: ";
    for (int i = 0; i < 10; i++) {
        cout << detected_languages[i] << " (" << percentages[i] << "%)" << endl;
    }
    cout << "Reliability: " << scores[0] << endl;

    return 0;
}
