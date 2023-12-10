#include <chrono>

std::chrono::milliseconds CalculateElapsedTime(std::chrono::system_clock::time_point currentTime, std::chrono::system_clock::time_point m_startTime, std::chrono::milliseconds m_accumulatedTime, bool m_running) {
  if (m_running) {
    // If the current time is before the start time, then the FPGA clock rolled
    // over. Compensate by adding the rollover time to the current time.
    if (currentTime < m_startTime) {
      currentTime += std::chrono::minutes(71);  // Assuming kRolloverTime is 71 minutes
    }

    return std::chrono::duration_cast<std::chrono::milliseconds>((currentTime - m_startTime) + m_accumulatedTime);
  } else {
    return std::chrono::milliseconds(0);  // If not running, elapsed time is 0
  }
}
