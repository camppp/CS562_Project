const char* convertSeverityToString(int severity, int type) {
    const char* severityString = "N";
    if (severity == GL_DEBUG_SEVERITY_HIGH || type == GL_DEBUG_TYPE_ERROR) {
        severityString = "E";
    } else if (severity == GL_DEBUG_SEVERITY_LOW || severity == GL_DEBUG_SEVERITY_MEDIUM) {
        severityString = "W";
    }
    return severityString;
}
