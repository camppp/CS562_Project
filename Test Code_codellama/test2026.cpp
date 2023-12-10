void OveruseDetector::UpdateState(double offset) {
    // Update the timestamp of the last update
    lastUpdateMs = GetCurrentTimeMs();

    // Calculate the time difference between the current update and the previous update
    double timeDiff = (lastUpdateMs - prevUpdateMs) / 1000.0;

    // Calculate the average offset over the last time interval
    double avgOffset = (offset + prevOffset) / 2.0;

    // Update the previous offset value
    prevOffset = offset;

    // Check if the network is overused based on the current offset and the previous offset
    if (offset > threshold && avgOffset > threshold) {
        // Increment the overuse counter
        overuseCounter++;

        // Update the time overusing value
        timeOverUsing += timeDiff;

        // Check if the network has been overused for the specified time threshold
        if (timeOverUsing >= overusingTimeThreshold) {
            // Set the hypothesis to overused
            hypothesis = BandwidthUsage::Overused;
        }
    } else {
        // Reset the overuse counter and time overusing value
        overuseCounter = 0;
        timeOverUsing = 0;

        // Set the hypothesis to normal
        hypothesis = BandwidthUsage::Normal;
    }
}
