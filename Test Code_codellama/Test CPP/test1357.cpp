#include <vector>
#include <string>
#include <stdexcept>

class BlobReader {
public:
    BlobReader() = default;

    void parse(const std::vector<char>& blob) {
        // Extract shape, precision, and layout information from the input blob
        std::string shape_str(blob.begin(), blob.begin() + 4);
        std::string precision_str(blob.begin() + 4, blob.begin() + 8);
        std::string layout_str(blob.begin() + 8, blob.end());

        // Convert shape, precision, and layout strings to integers
        int shape[4];
        for (int i = 0; i < 4; i++) {
            shape[i] = std::stoi(shape_str.substr(i * 4, 4));
        }
        int precision = std::stoi(precision_str);
        int layout = std::stoi(layout_str);

        // Populate data descriptor with extracted information
        DataDesc desc;
        desc.setShape(shape);
        desc.setPrecision(precision);
        desc.setLayout(layout);

        // Handle any potential errors or exceptional cases
        try {
            // Check if the input blob is valid
            if (blob.size() != 12) {
                throw std::invalid_argument("Invalid input blob size");
            }

            // Check if the extracted information is valid
            if (shape[0] <= 0 || shape[1] <= 0 || shape[2] <= 0 || shape[3] <= 0) {
                throw std::invalid_argument("Invalid shape information");
            }
            if (precision <= 0) {
                throw std::invalid_argument("Invalid precision information");
            }
            if (layout <= 0) {
                throw std::invalid_argument("Invalid layout information");
            }
        } catch (const std::invalid_argument& e) {
            // Handle any potential errors or exceptional cases
            std::cerr << "Error: " << e.what() << std::endl;
            return;
        }

        // Set the data descriptor
        setDataDesc(desc);
    }

    void setDataDesc(const DataDesc& desc) {
        // Set the data descriptor
        data_desc_ = desc;
    }

private:
    DataDesc data_desc_;
};
