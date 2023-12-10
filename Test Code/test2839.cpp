void compareFunctionPointer(void* func, int* result) {
    typedef void (updateThread::*_t)(std::string);
    if (*reinterpret_cast<_t*>(func) == static_cast<_t>(&updateThread::sendInfo)) {
        *result = 2;
    }
}
