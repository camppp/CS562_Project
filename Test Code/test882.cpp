#include <cld2/compact_lang_det.h>
#include <cld2/encodings.h>
#include <string>
#include <iostream>

int main() {
    std::string text = "Your input text goes here";  // Replace with the actual input text

    CLD2::Language langs[3] = {CLD2::UNKNOWN_LANGUAGE, CLD2::UNKNOWN_LANGUAGE, CLD2::UNKNOWN_LANGUAGE};
    int percents[3] = {0, 0, 0};
    double scores[3] = {0.0, 0.0, 0.0};

    bool reliable = false;
    int text_bytes;
    int valid_prefix_bytes;
    CLD2::ResultChunkVector chunks;

    CLD2::ExtDetectLanguageSummaryCheckUTF8(text.data(), text.size(), true, &CLD2::NO_HINT, 0, &langs[0], &percents[0], &scores[0], &chunks, &text_bytes, &reliable, &valid_prefix_bytes);

    // Output the language detection summary
    for (int i = 0; i < 3; ++i) {
        if (langs[i] != CLD2::UNKNOWN_LANGUAGE) {
            std::cout << "Detected language: " << CLD2::LanguageCode(langs[i]) << std::endl;
            std::cout << "Percentage of text in this language: " << percents[i] << "%" << std::endl;
            std::cout << "Reliability of detection: " << (reliable ? "High" : "Low") << std::endl;
            break;  // Only output the first detected language
        }
    }

    return 0;
}
