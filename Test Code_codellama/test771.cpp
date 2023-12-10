#include <iostream>
#include <string>
#include <vector>
#include <BAMUtils.h>
#include <DelegateEditors.h>

class FileProcessor {
public:
    void processFiles(const std::vector<std::string>& filePaths) {
        for (const auto& filePath : filePaths) {
            if (isBAMFile(filePath)) {
                convertBAMFile(filePath);
            } else if (isU2File(filePath)) {
                editU2File(filePath);
            } else {
                std::cerr << "Unsupported file type: " << filePath << std::endl;
            }
        }
    }

private:
    bool isBAMFile(const std::string& filePath) {
        return filePath.ends_with(".bam");
    }

    bool isU2File(const std::string& filePath) {
        return filePath.ends_with(".u2");
    }

    void convertBAMFile(const std::string& filePath) {
        BAMUtils::ConvertFileTask task(filePath);
        task.run();
    }

    void editU2File(const std::string& filePath) {
        DelegateEditors::Editor editor(filePath);
        editor.edit();
    }
};

int main() {
    std::vector<std::string> filePaths = {"file1.bam", "file2.u2", "file3.bam"};
    FileProcessor processor;
    processor.processFiles(filePaths);
    return 0;
}
