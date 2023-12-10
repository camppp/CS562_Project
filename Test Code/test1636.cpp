#include <iostream>
#include <string>
#include <vector>

class UniqueIdManager {
private:
    int nextFreeId_;
    int nextStep_;
    std::vector<int> idCollection_;

public:
    UniqueIdManager(int initialId, int stepSize) : nextFreeId_(initialId), nextStep_(stepSize) {}

    void addNewest(std::string str) {
        idCollection_.push_back(nextFreeId_);
        nextFreeId_ += nextStep_;
    }

    int getNewestId() {
        if (idCollection_.empty()) {
            std::cerr << "No IDs added yet." << std::endl;
            return -1; // or throw an exception
        }
        return idCollection_.back();
    }
};

int main() {
    UniqueIdManager idManager(1000, 5);
    idManager.addNewest("New ID added");
    idManager.addNewest("Another new ID added");
    std::cout << "Newest ID: " << idManager.getNewestId() << std::endl;
    return 0;
}
