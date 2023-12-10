void OveruseDetector::UpdateState(double offset) {
    int64_t nowMs = GetCurrentTimeMs();  // Assume a function to get the current time in milliseconds

    if (lastUpdateMs == -1) {
        lastUpdateMs = nowMs;
        prevOffset = offset;
        return;  // Initial state, no update needed
    }

    double timeDelta = static_cast<double>(nowMs - lastUpdateMs);
    double derivative = (offset - prevOffset) / timeDelta;

    if (derivative > threshold) {
        timeOverUsing += timeDelta;
        overuseCounter++;
    } else {
        timeOverUsing = std::max(0.0, timeOverUsing - timeDelta);
    }

    if (timeOverUsing > overusingTimeThreshold) {
        hypothesis = BW_OVERUSING;
    } else {
        hypothesis = BW_NORMAL;
    }

    lastUpdateMs = nowMs;
    prevOffset = offset;
}
