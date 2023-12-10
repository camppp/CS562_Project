#include <iostream>
#include <list>

class ContextMenu {
private:
    std::list<std::string> items;

public:
    void addItem(const std::string& item) {
        items.push_back(item);
    }

    void show() {
        for (const auto& item : items) {
            std::cout << item << std::endl;
        }
    }

    void handleSelection(const std::string& item) {
        std::cout << "Selected item: " << item << std::endl;
    }
};
