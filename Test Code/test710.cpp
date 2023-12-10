c
const char* convertSeverityToString(int severity, int type) {
    if (severity == GL_DEBUG_SEVERITY_HIGH && type == GL_DEBUG_TYPE_ERROR) {
        return "E";
    } else if (severity == GL_DEBUG_SEVERITY_LOW || severity == GL_DEBUG_SEVERITY_MEDIUM) {
        return "W";
    } else {
        return "N";
    }
}
