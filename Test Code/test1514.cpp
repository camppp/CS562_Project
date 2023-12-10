#include <string>

class CChat {
public:
    CChat(int version, int time, int id, bool private, const std::string& payload, const std::string& fromNickName, const std::string& toNickName, const std::string& destination)
        : nVersion(version), nTime(time), nID(id), bPrivate(private), sPayload(payload), sFromNickName(fromNickName), sToNickName(toNickName), sDestination(destination) {}

    void SetPayload(const std::string& payload) {
        sPayload = payload;
    }

    void SetNickNames(const std::string& from, const std::string& to) {
        sFromNickName = from;
        sToNickName = to;
    }

    void SetDestination(const std::string& destination) {
        sDestination = destination;
    }

    std::string ToString() const {
        return "Chat message: " + sPayload + " from " + sFromNickName + " to " + sToNickName + " at " + std::to_string(nTime) + " (version " + std::to_string(nVersion) + ")";
    }

private:
    int nVersion;
    int nTime;
    int nID;
    bool bPrivate;
    std::string sPayload;
    std::string sFromNickName;
    std::string sToNickName;
    std::string sDestination;
};
