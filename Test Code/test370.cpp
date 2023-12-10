// VideoCodec.h
class DecodedImageCallback {
public:
    virtual void OnDecodedImage(const Image& image) = 0;
};

class Image {
    // Define image properties and methods
};

class VideoCodec {
private:
    DecodedImageCallback* callback_;

public:
    VideoCodec() : callback_(nullptr) {}

    // Method for setting the decoded image callback
    int SetDecodedImageCallback(DecodedImageCallback* callback) {
        callback_ = callback;
        return WEBRTC_VIDEO_CODEC_OK;
    }
};
