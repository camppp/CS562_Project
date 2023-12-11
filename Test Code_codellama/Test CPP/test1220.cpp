c
double calculatePresentationTimestamp(AVCodecContext *pCodecCtx, AVFrame *frame, AVPacket packet, AVFormatContext *pFormatCtx, double current_time)
{
    // Check if the frame decoding is finished
    if (frameFinished)
    {
        // Calculate the presentation timestamp (PTS) using the av_frame_get_best_effort_timestamp and av_q2d functions
        double pts2 = av_frame_get_best_effort_timestamp(frame, pCodecCtx->time_base, AV_TIME_BASE_Q);
        pts2 = av_q2d(pts2);

        // Log the current time and the calculated presentation timestamp (PTS)
        av_log(pFormatCtx, AV_LOG_INFO, "Current time: %f, PTS: %f\n", current_time, pts2);

        // Return the calculated presentation timestamp (PTS)
        return pts2;
    }
    else
    {
        // Return 0 if the frame decoding is not finished
        return 0;
    }
}
