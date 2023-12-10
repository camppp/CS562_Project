#include <string>
#include <opencv2/core/core.hpp>

std::string imageTypeToString(int type) {
    std::string r;
    switch (type) {
        case CV_8U: r = "CV_8U"; break;
        case CV_8S: r = "CV_8S"; break;
        case CV_16U: r = "CV_16U"; break;
        case CV_16S: r = "CV_16S"; break;
        case CV_32S: r = "CV_32S"; break;
        case CV_32F: r = "CV_32F"; break;
        case CV_64F: r = "CV_64F"; break;
        default:     r = "User"; break;
    }

    int chans{ 1 + (type >> CV_CN_SHIFT) };
    r += "C" + std::to_string(chans);
    return r;
}
