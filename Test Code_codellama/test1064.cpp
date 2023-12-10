#include <vector>
#include <string>

class AppListItem {
public:
    std::string name;
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
            if (*it == item) {
                items.erase(it);
                break;
            }
        }
    }

    std::vector<AppListItem> getItems() {
        return items;
    }

    void displayItems() {
        for (const auto& item : items) {
            std::cout << item.name << std::endl;
        }
    }
};
