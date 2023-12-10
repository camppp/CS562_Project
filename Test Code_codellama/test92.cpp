void trackMessageCount(MessageType type) {
    if (type == kTestChainTrade || type == kTestWpingRequest) {
        if (af_recv_start_time == 0) {
            af_recv_start_time = GetCurrentTimeMsec();
        }
        af_recv_count++;
    }
    return std::make_pair(af_recv_count, GetCurrentTimeMsec() - af_recv_start_time);
}
