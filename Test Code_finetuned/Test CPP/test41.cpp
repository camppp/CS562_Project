template <typename TRet>
void processValue(void* val, size_t bytes, std::vector<TRet>& result) {
    if (bytes!= 0) {
        TRet* ptr = static_cast<TRet*>(val);
        result.push_back(*ptr);
    }
}