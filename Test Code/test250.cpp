vector<std::tuple<unique_ptr<IOBuf>, bool, TestStreamingCallback>> encodeFlightData(const vector<Header>& headers, const vector<string>& values, int headerTableSize) {
  vector<std::tuple<unique_ptr<IOBuf>, bool, TestStreamingCallback>> data;
  for (size_t i = 0; i < values.size(); i++) {
    // Encode flight data using headers, values, and headerTableSize
    // Assume encoding logic here
    unique_ptr<IOBuf> encodedData = encodeData(headers, values[i], headerTableSize);
    bool success = (encodedData != nullptr); // Example success check
    TestStreamingCallback callback; // Example callback creation
    data.push_back(std::make_tuple(std::move(encodedData), success, callback));
  }
  return data;
}
