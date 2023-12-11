function load_kaltura_video_library($libraryName) {
    // Load the Kaltura video client library using elgg_load_library
    $result = elgg_load_library($libraryName);

    // Check if the library was loaded successfully
    if ($result === false) {
        // Log an error message
        elgg_log("Failed to load Kaltura video client library: $libraryName", "ERROR");
        return false;
    }

    // Return true if the library was loaded successfully
    return true;
}