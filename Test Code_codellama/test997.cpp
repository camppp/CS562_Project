std::chrono::milliseconds CalculateElapsedTime(std::chrono::system_clock::time_point currentTime, std::chrono::system_clock::time_point m_startTime, std::chrono::milliseconds m_accumulatedTime, bool m_running) {
    std::scoped_lock lock(m_mutex);

    // If the current time is before the start time, then the FPGA clock rolled over.
    // Compensate by adding the ~71 minutes that it takes to roll over to the current time.
    if (currentTime < m_startTime) {
        currentTime += kRolloverTime;
    }

    // Calculate the elapsed time since the start time
    auto elapsedTime = currentTime - m_startTime;

    // If the time tracking system is running, add the accumulated time to the elapsed time
    if (m_running) {
        elapsedTime += m_accumulatedTime;
    }

    return elapsedTime;
}
