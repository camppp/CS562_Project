#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, string> parseFilePath(const string& filePath) {
    unordered_map<string, string> result;

    // Find the first occurrence of "<gh_stars>" in the file path
    size_t ghStarsPos = filePath.find("<gh_stars>");

    // If "<gh_stars>" is not found, return an empty map
    if (ghStarsPos == string::npos) {
        return result;
    }

    // Extract the filename and directory path from the file path
    string filename = filePath.substr(0, ghStarsPos);
    string directoryPath = filePath.substr(ghStarsPos + 9);

    // Find the first occurrence of "<stars_count>" in the file path
    size_t starsCountPos = directoryPath.find("<stars_count>");

    // If "<stars_count>" is not found, return an empty map
    if (starsCountPos == string::npos) {
        return result;
    }

    // Extract the number of GitHub stars from the file path
    string starsCount = directoryPath.substr(starsCountPos + 11);

    // Add the extracted information to the result map
    result["filename"] = filename;
    result["directory_path"] = directoryPath;
    result["stars_count"] = starsCount;

    return result;
}

int main() {
    string filePath = "chrome/chrome_cleaner/os/process.cc<gh_stars>1000+";
    unordered_map<string, string> result = parseFilePath(filePath);

    cout << "Filename: " << result["filename"] << endl;
    cout << "Directory path: " << result["directory_path"] << endl;
    cout << "Number of GitHub stars: " << result["stars_count"] << endl;

    return 0;
}
