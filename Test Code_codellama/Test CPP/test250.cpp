vector<std::tuple<unique_ptr<IOBuf>, bool, TestStreamingCallback>> encodeFlightData(const vector<Header>& headers, const vector<string>& values, int headerTableSize) {
    vector<std::tuple<unique_ptr<IOBuf>, bool, TestStreamingCallback>> data;
    for (int i = 0; i < values.size(); i++) {
        // Encode the current value using the header table size
        auto encodedValue = encodeValue(values[i], headerTableSize);
        if (!encodedValue.second) {
            // Encoding failed, return an empty vector
            return data;
        }
        // Create a new IOBuf for the encoded value
        auto buf = folly::IOBuf::create(encodedValue.first.size());
        buf->append(encodedValue.first.data(), encodedValue.first.size());
        // Create a new TestStreamingCallback for streaming purposes
        auto callback = TestStreamingCallback();
        // Add the encoded value and callback to the data vector
        data.push_back(std::make_tuple(std::move(buf), true, std::move(callback)));
    }
    return data;
}
