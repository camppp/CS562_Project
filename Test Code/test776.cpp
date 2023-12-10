void logWarning(std::stringstream& stream) {
    SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, "%s", stream.str().c_str());

    if (SDL_WasInit(SDL_INIT_VIDEO))
        displayWarning(stream);
    // No action needed if video subsystem is not initialized
}
