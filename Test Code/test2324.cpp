#include <iostream>

enum GstVideoFormat {
    GST_VIDEO_FORMAT_BGR,
    GST_VIDEO_FORMAT_I420
};

int get_channels_num(GstVideoFormat format) {
    switch (format) {
        case GST_VIDEO_FORMAT_BGR:
            return 3; // BGR format has 3 color channels (Blue, Green, Red)
        case GST_VIDEO_FORMAT_I420:
            return 3; // I420 format also has 3 color channels
        default:
            throw std::runtime_error("Unsupported color format.");
    }
}

int main() {
    // Test the get_channels_num function
    std::cout << "Number of channels for GST_VIDEO_FORMAT_BGR: " << get_channels_num(GST_VIDEO_FORMAT_BGR) << std::endl;
    std::cout << "Number of channels for GST_VIDEO_FORMAT_I420: " << get_channels_num(GST_VIDEO_FORMAT_I420) << std::endl;

    return 0;
}
