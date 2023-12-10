class PatternDetector {
public:
    int appId;

    void setAppId(const std::string& clientID) {
        appId = std::stoi(clientID);
    }
};
