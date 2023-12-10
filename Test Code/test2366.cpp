#include <vector>

struct WifiP2pServiceRequest {
    unsigned char type;
    std::vector<unsigned char> value;
};

class WifiP2pServiceRequestList {
public:
    std::vector<WifiP2pServiceRequest> requestList;

    void ParseTlvs2ReqList(const std::vector<unsigned char> &tlvs) {
        size_t index = 0;
        while (index < tlvs.size()) {
            unsigned char type = tlvs[index++];
            unsigned char length = tlvs[index++];
            std::vector<unsigned char> value(tlvs.begin() + index, tlvs.begin() + index + length);
            index += length;
            requestList.push_back({type, value});
        }
    }
};
