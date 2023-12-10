#include <iostream>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;

vector<string> getFilesList(const string& dir) {
    vector<string> files;
    WIN32_FIND_DATA findData;
    HANDLE hFind = FindFirstFile(dir.c_str(), &findData);
    if (hFind == INVALID_HANDLE_VALUE) {
        cout << "Error: " << GetLastError() << endl;
        return files;
    }

    do {
        if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            // If the file is a directory, recursively search it
            vector<string> tempPath = getFilesList(dir + "\\" + findData.name);
            files.insert(files.end(), tempPath.begin(), tempPath.end());
        } else {
            // If the file is a regular file, add it to the list
            files.push_back(dir + "\\" + findData.name);
        }
    } while (FindNextFile(hFind, &findData));

    FindClose(hFind);
    return files;
}
