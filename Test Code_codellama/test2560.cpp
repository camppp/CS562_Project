#include <iostream>
#include <fstream>

class ColorOutputManager {
public:
    ColorOutputManager(bool useStandardOutput) : useStandardOutput_(useStandardOutput) {}

    void writeToBuffer(int r, int g, int b) {
        buffer_.push_back(r);
        buffer_.push_back(g);
        buffer_.push_back(b);
    }

    void flush() {
        if (useStandardOutput_) {
            for (int i = 0; i < buffer_.size(); i++) {
                std::cout << buffer_[i] << " ";
            }
        } else {
            std::ofstream file("output.txt");
            for (int i = 0; i < buffer_.size(); i++) {
                file << buffer_[i] << " ";
            }
            file.close();
        }
        buffer_.clear();
    }

private:
    bool useStandardOutput_;
    std::vector<int> buffer_;
};
