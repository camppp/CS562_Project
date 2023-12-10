#include <iostream>
#include <fstream>
#include <unordered_map>

void report_bitstream_distribution_xml_file_head(std::fstream& fp, bool include_time_stamp) {
    if (include_time_stamp) {
        fp << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
        fp << "<bitstream_distribution_report timestamp=\"" << getCurrentTimeStamp() << "\">\n";
    } else {
        fp << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
        fp << "<bitstream_distribution_report>\n";
    }
    fp << "  <introduction>This report shows the distribution of bits (0s and 1s) in the file.</introduction>\n";
    fp << "</bitstream_distribution_report>\n";
}

void calculate_bit_distribution(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (file.is_open()) {
        std::unordered_map<char, int> bitFrequency{{'0', 0}, {'1', 0}};
        char c;
        while (file.get(c)) {
            if (c == '0' || c == '1') {
                bitFrequency[c]++;
            }
        }
        file.close();

        std::ofstream reportFile("bit_distribution_report.xml");
        if (reportFile.is_open()) {
            report_bitstream_distribution_xml_file_head(reportFile, true);
            reportFile << "  <bit_distribution>\n";
            for (const auto& pair : bitFrequency) {
                reportFile << "    <bit value=\"" << pair.first << "\">" << pair.second << "</bit>\n";
            }
            reportFile << "  </bit_distribution>\n";
            reportFile << "</bitstream_distribution_report>\n";
            reportFile.close();
            std::cout << "Bit distribution report generated successfully." << std::endl;
        } else {
            std::cerr << "Error: Unable to create the report file." << std::endl;
        }
    } else {
        std::cerr << "Error: Unable to open the file for reading." << std::endl;
    }
}

int main() {
    std::string filename = "input_file.bin";  // Replace with the actual file name
    calculate_bit_distribution(filename);
    return 0;
}
