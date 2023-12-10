#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("file_names.txt");
    std::string fileName, fromPath = "/source/", toPath = "/destination/";

    if (file.is_open()) {
        while (getline(file, fileName)) {
            try {
                if (fileName.substr(0, 1) == "P") {
                    std::string modifiedFileName = ".conll" + fileName.substr(7);
                    fromPath += modifiedFileName;
                    toPath += modifiedFileName;

                    // Perform operations using the modified file names
                    // ...

                    // Report the processing results
                    std::cout << "File " << modifiedFileName << " processed successfully." << std::endl;
                }
            } catch (const std::exception& e) {
                std::cerr << "Exception occurred: " << e.what() << std::endl;
            }
        }
        file.close();
    } else {
        std::cerr << "Unable to open file_names.txt" << std::endl;
    }

    return 0;
}
