#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <codecvt>
#include <locale>

class File {
private:
    std::string filePath;

public:
    File(const std::string& path) : filePath(path) {}

    std::ofstream getWriteStream() {
        return std::ofstream(filePath);
    }

    void removeFile() {
        std::remove(filePath.c_str());
    }
};

class OnScopeExit {
public:
    OnScopeExit(std::function<void()> func) : func(func) {}
    ~OnScopeExit() { func(); }

private:
    std::function<void()> func;
};

class Utf32To8WriteResource {
private:
    std::ofstream outputStream;

public:
    Utf32To8WriteResource(const std::string& filePath) : outputStream(filePath) {}

    std::ostream& writeStream() {
        return outputStream;
    }
};

File prepWritePath(const std::string& fileName, const std::string& expected) {
    std::string filePath = fileName + ".txt";
    std::ofstream file(filePath);
    file << expected;
    file.close();
    return File(filePath);
}

int main() {
    std::string expected = "Sample text";
    File fileA = prepWritePath("test_a", expected);
    File fileB = prepWritePath("test_b", expected);
    OnScopeExit removeFileA([=]() mutable { fileA.removeFile(); });
    OnScopeExit removeFileB([=]() mutable { fileB.removeFile(); });

    std::ofstream fileWriteStream = fileA.getWriteStream();
    Utf32To8WriteResource uriWriteResource(fileB.getWriteStream());
    std::ostream& uriWriteStream = uriWriteResource.writeStream();

    fileWriteStream << "Writing to file A";
    uriWriteStream << "Writing to file B";

    return 0;
}
