#include <string>
#include <sstream>

class CChat {
private:
    int nVersion;
    int nTime;
    int nID;
    bool bPrivate;
    std::string sPayload;
    std::string sFromNickName;
    std::string sToNickName;
    std::string sDestination;

public:
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
        std::stringstream ss;
        ss << "CChat(\n"
           << "    nVersion     = " << nVersion << "\n"
           << "    nTime        = " << nTime << "\n"
           << "    nID          = " << nID << "\n"
           << "    bPrivate     = " << bPrivate << "\n"
           << "    sPayload     = " << sPayload << "\n"
           << "    sFromNickName= " << sFromNickName << "\n"
           << "    sToNickName  = " << sToNickName << "\n"
           << "    sDestination = " << sDestination << "\n"
           << ")";
        return ss.str();
    }
};
