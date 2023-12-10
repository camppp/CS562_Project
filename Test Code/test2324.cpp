int get_channels_num(GstVideoFormat format) {
    switch (format) {
        case GST_VIDEO_FORMAT_BGR:
            return 3;
        case GST_VIDEO_FORMAT_I420:
            return 3;
        default:
            return 0;
    }
}
