template <typename TRet>
void processValue(void* val, size_t bytes, std::vector<TRet>& result) {
    if (bytes) {
        result.push_back(*(TRet*)&val);
    }
}
