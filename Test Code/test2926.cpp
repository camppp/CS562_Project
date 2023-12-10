#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
#include <boost/format.hpp>

class mdm_exception : public std::exception {
public:
    mdm_exception(const std::string& func, const boost::format& message) {
        std::cerr << "Exception in function " << func << ": " << message << std::endl;
    }
};

class mdm_AIF {
public:
    std::vector<double> AIFTimes_;  // Predefined vector of times

    void writeIFToFile(const std::vector<double> &if_to_save, const std::string &filename) {
        std::ofstream aifStream(filename, std::ios::out);

        if (if_to_save.size() != AIFTimes_.size()) {
            throw mdm_exception(__func__, boost::format(
                "Size of IF values (%1%) does not match number of times (%2%)")
                % if_to_save.size() % AIFTimes_.size());
        }

        for (const auto& value : if_to_save) {
            aifStream << value << std::endl;
        }
    }
};

int main() {
    mdm_AIF aifObject;
    aifObject.AIFTimes_ = {1, 2, 3, 4, 5};  // Example predefined AIFTimes

    std::vector<double> ifValues = {0.1, 0.2, 0.3, 0.4, 0.5};  // Example AIF values
    std::string filename = "aif_values.txt";  // Example filename

    try {
        aifObject.writeIFToFile(ifValues, filename);
        std::cout << "AIF values successfully written to file." << std::endl;
    }
    catch (const mdm_exception& e) {
        // Exception handling
    }

    return 0;
}
