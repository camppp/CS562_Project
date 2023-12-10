void Stream::configureStream(StringMap settings) {
    // Read the MJPG stream enabled setting
    bool enabled = settings.get("streams.Mjpg.enabled") == "true";

    // Read the MJPG stream port, quality, and fps settings
    int port = settings.get("streams.Mjpg.streamPort").toInt();
    int quality = settings.get("streams.Mjpg.quality").toInt();
    int fps = settings.get("streams.Mjpg.fps").toInt();

    // Check if the port number is within the well-known ports range
    if (port < 0 || port > 1023) {
        throw std::invalid_argument("Invalid port number");
    }

    // Configure the MJPG stream
    if (enabled) {
        // Start the MJPG stream
        startMjpgStream(port, quality, fps);
    } else {
        // Stop the MJPG stream
        stopMjpgStream();
    }
}
