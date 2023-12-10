#include <iostream>
#include <fstream>
#include <vector>

class ColorOutputManager {
private:
    bool m_useStandardOutput;
    std::vector<std::tuple<int, int, int>> m_colorBuffer;
    std::ostream& m_outputStream;

public:
    ColorOutputManager(bool useStandardOutput) : m_useStandardOutput(useStandardOutput), m_outputStream(useStandardOutput ? std::cout : std::ofstream("output.txt")) {}

    void writeToBuffer(const int r, const int g, const int b) {
        m_colorBuffer.emplace_back(r, g, b);
    }

    void flush() {
        for (const auto& color : m_colorBuffer) {
            if (m_useStandardOutput) {
                std::cout << std::get<0>(color) << " " << std::get<1>(color) << " " << std::get<2>(color) << "\n";
            } else {
                m_outputStream << std::get<0>(color) << " " << std::get<1>(color) << " " << std::get<2>(color) << "\n";
            }
        }
        m_colorBuffer.clear();
    }
};
