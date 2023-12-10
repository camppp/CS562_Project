#include <iostream>
#include <ffmpeg/avcodec.h>
#include <ffmpeg/avformat.h>

class AVFrameWrapper {
public:
    AVFrameWrapper(FFmpegFunctions* ffmpegFunctions);
    ~AVFrameWrapper();

    void decodeAudioFrame(const uint8_t* data, int size);
    void decodeVideoFrame(const uint8_t* data, int size);
    void encodeAudioFrame(const uint8_t* data, int size);
    void encodeVideoFrame(const uint8_t* data, int size);

private:
    FFmpegFunctions* ffmpegFunctions_;
    AVFrame* audioFrame_;
    AVFrame* videoFrame_;
};

AVFrameWrapper::AVFrameWrapper(FFmpegFunctions* ffmpegFunctions) {
    ffmpegFunctions_ = ffmpegFunctions;
    audioFrame_ = av_frame_alloc();
    videoFrame_ = av_frame_alloc();
}

AVFrameWrapper::~AVFrameWrapper() {
    av_frame_free(&audioFrame_);
    av_frame_free(&videoFrame_);
}

void AVFrameWrapper::decodeAudioFrame(const uint8_t* data, int size) {
    av_init_packet(&audioFrame_->packet);
    audioFrame_->packet.data = (uint8_t*)data;
    audioFrame_->packet.size = size;
    int ret = avcodec_decode_audio4(ffmpegFunctions_->audioCodecContext, audioFrame_, &size, &audioFrame_->packet);
    if (ret < 0) {
        std::cerr << "Error decoding audio frame: " << ret << std::endl;
    }
}

void AVFrameWrapper::decodeVideoFrame(const uint8_t* data, int size) {
    av_init_packet(&videoFrame_->packet);
    videoFrame_->packet.data = (uint8_t*)data;
    videoFrame_->packet.size = size;
    int ret = avcodec_decode_video2(ffmpegFunctions_->videoCodecContext, videoFrame_, &size, &videoFrame_->packet);
    if (ret < 0) {
        std::cerr << "Error decoding video frame: " << ret << std::endl;
    }
}

void AVFrameWrapper::encodeAudioFrame(const uint8_t* data, int size) {
    av_init_packet(&audioFrame_->packet);
    audioFrame_->packet.data = (uint8_t*)data;
    audioFrame_->packet.size = size;
    int ret = avcodec_encode_audio2(ffmpegFunctions_->audioCodecContext, audioFrame_, &size, &audioFrame_->packet);
    if (ret < 0) {
        std::cerr << "Error encoding audio frame: " << ret << std::endl;
    }
}

void AVFrameWrapper::encodeVideoFrame(const uint8_t* data, int size) {
    av_init_packet(&videoFrame_->packet);
    videoFrame_->packet.data = (uint8_t*)data;
    videoFrame_->packet.size = size;
    int ret = avcodec_encode_video2(ffmpegFunctions_->videoCodecContext, videoFrame_, &size, &videoFrame_->packet);
    if (ret < 0) {
        std::cerr << "Error encoding video frame: " << ret << std::endl;
    }
}
