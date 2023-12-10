#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>

double calculatePresentationTimestamp(AVCodecContext *pCodecCtx, AVFrame *frame, AVPacket packet, AVFormatContext *pFormatCtx, double current_time) {
    int frameFinished;
    avcodec_decode_video2(pCodecCtx, frame->data, &frameFinished, &packet);

    if (frameFinished) {
        double pts2 = av_frame_get_best_effort_timestamp(frame) * av_q2d(pFormatCtx->streams[packet.stream_index]->time_base);
        return pts2;
    } else {
        // Handle case when frame decoding is not finished
        return -1; // Or any appropriate error code or value
    }
}
