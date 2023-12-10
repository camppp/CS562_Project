#include <iostream>
#include <vector>
#include <string>

class AppListItem {
public:
    std::string name;
    // Constructor and other members can be added as per the actual implementation
};

class AppListManager {
private:
    std::vector<AppListItem> items;

public:
    void addItem(const AppListItem& item) {
        items.push_back(item);
    }

    void removeItem(const AppListItem& item) {
        for (auto it = items.begin(); it != items.end(); ++it) {
            if (it->name == item.name) {
                items.erase(it);
                break;
            }
        }
    }

    std::vector<AppListItem> getItems() const {
        return items;
    }

    void displayItems() const {
        for (const auto& item : items) {
            std::cout << item.name << std::endl;
        }
    }
};

int main() {
    AppListManager manager;
    AppListItem item1{"App1"};
    AppListItem item2{"App2"};

    manager.addItem(item1);
    manager.addItem(item2);

    manager.displayItems();

    manager.removeItem(item1);

    manager.displayItems();

    return 0;
}
