#include <iostream>

class Constants {
public:
    static const int BAM_TAG_TYPE_ASCII = 1;
    static const int BAM_TAG_TYPE_INT8 = 2;
    static const int BAM_TAG_TYPE_UINT8 = 3;
};

int processOperation(int i, int type, int constant) {
    switch (type) {
        case Constants::BAM_TAG_TYPE_ASCII:
        case Constants::BAM_TAG_TYPE_INT8:
        case Constants::BAM_TAG_TYPE_UINT8:
            i += constant;
            break;
        default:
            // No operation for other types
            break;
    }
    return i;
}

int main() {
    // Example usage
    int initialI = 5;
    int type = Constants::BAM_TAG_TYPE_INT8;
    int constant = 3;
    int result = processOperation(initialI, type, constant);
    std::cout << "Final value of i: " << result << std::endl;
    return 0;
}
