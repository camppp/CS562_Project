function load_kaltura_video_library($libraryName) {
    // Check if the library is already loaded
    if (elgg_is_library_loaded($libraryName)) {
        return true;
    }

    // Load the library
    $libraryPath = elgg_get_plugins_path(). "kaltura_video/lib/". $libraryName. ".php";

    if (file_exists($libraryPath)) {
        include($libraryPath);
        elgg_load_library($libraryName);
        return true;
    } else {
        return false;
    }
}