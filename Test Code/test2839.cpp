void compareFunctionPointer(void* func, int* result) {
    if (func == reinterpret_cast<void*>(&updateThread::sendInfo)) {
        *result = 2;
    }
}
