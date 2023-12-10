class Device {
public:
    std::string name;
    int id;

    bool operator==(const Device& other) const {
        return id == other.id;
    }

    bool operator!=(const Device& other) const {
        return id != other.id;
    }

    bool operator<(const Device& other) const {
        return id < other.id;
    }
};
