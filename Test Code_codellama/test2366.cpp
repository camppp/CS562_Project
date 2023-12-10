void WifiP2pServiceRequestList::ParseTlvs2ReqList(const vector<unsigned char>& tlvs) {
    // Iterate through the TLVs and extract the type, length, and value
    for (size_t i = 0; i < tlvs.size(); i += 2) {
        // Extract the type and length from the current TLV
        unsigned char type = tlvs[i];
        unsigned char length = tlvs[i + 1];

        // Extract the value from the current TLV
        vector<unsigned char> value(tlvs.begin() + i + 2, tlvs.begin() + i + 2 + length);

        // Construct a request list entry based on the extracted information
        WifiP2pServiceRequestListEntry entry;
        entry.type = type;
        entry.length = length;
        entry.value = value;

        // Add the entry to the request list
        requestList.push_back(entry);
    }
}
