#include <iostream>
#include <string>

class BackupItem {
private:
    std::string data;

public:
    BackupItem() : data("") {}

    void setData(const std::string& newData) {
        if (newData.length() > MAX_BACKUP_ITEM_DATA_LEN) {
            data = newData.substr(0, MAX_BACKUP_ITEM_DATA_LEN);
        } else {
            data = newData;
        }
    }

    std::string getData() const {
        return data;
    }
};

int main() {
    BackupItem item;
    item.setData("This is a test data for backup item.");
    std::cout << item.getData() << std::endl;  // Output: "This is a test data for backup item."
    item.setData("This is a longer test data for backup item exceeding the maximum length.");
    std::cout << item.getData() << std::endl;  // Output: "This is a longer test data for backup item exceeding the maximum length."
    return 0;
}
