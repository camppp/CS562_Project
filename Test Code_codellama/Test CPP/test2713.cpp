class FingGrpVisMixIn {
public:
    void setOrient(std::string _orient) {
        orient = _orient;
    }

    bool hasOrient() {
        return !orient.empty();
    }

    std::string getOrient() {
        return orient;
    }

private:
    std::string orient;
};
