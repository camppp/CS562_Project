#include <string>

std::string imageTypeToString(int type) {
    switch (type) {
        case CV_8U:
            return "CV_8UC1";
        case CV_8S:
            return "CV_8SC1";
        case CV_16U:
            return "CV_16UC1";
        case CV_16S:
            return "CV_16SC1";
        case CV_32S:
            return "CV_32SC1";
        case CV_32F:
            return "CV_32FC1";
        case CV_64F:
            return "CV_64FC1";
        default:
            return "Unknown";
    }
}
