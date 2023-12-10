#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void report_bitstream_distribution_xml_file_head(const std::string& file_name, const std::string& timestamp = "") {
    std::ofstream xml_file;
    xml_file.open(file_name + ".xml");

    // Write the XML file header
    xml_file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << std::endl;
    xml_file << "<bitstream_distribution>" << std::endl;
    xml_file << "<file_name>" << file_name << "</file_name>" << std::endl;
    if (!timestamp.empty()) {
        xml_file << "<timestamp>" << timestamp << "</timestamp>" << std::endl;
    }

    // Write the bit distribution information
    xml_file << "<bit_distribution>" << std::endl;
    xml_file << "<0_count>0</0_count>" << std::endl;
    xml_file << "<1_count>0</1_count>" << std::endl;
}
