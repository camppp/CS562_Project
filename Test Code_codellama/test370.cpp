class VideoCodec {
public:
    VideoCodec() {}
    ~VideoCodec() {}

    // Set the decoded image callback
    void SetDecodedImageCallback(DecodedImageCallback* callback) {
        m_callback = callback;
    }

private:
    // The decoded image callback
    DecodedImageCallback* m_callback;
};
