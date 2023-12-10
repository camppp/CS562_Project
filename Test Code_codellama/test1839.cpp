CGDMLKludgeFix::CGDMLKludgeFix(const char* srcpath_) {
    srcpath = strdup(srcpath_);
    if (srcpath == nullptr) {
        throw std::runtime_error("Failed to allocate memory for srcpath");
    }
}
