struct SelectionTracker {
    std::map<std::string, std::map<std::string, int>> selectedItems;

    void setNumberOfSelected(const std::string& group, const std::string& brushingTarget, int count) {
        selectedItems[group][brushingTarget] = count;
    }

    int getNumberOfSelected(const std::string& group, const std::string& brushingTarget) {
        return selectedItems[group][brushingTarget];
    }

    bool isSelectionModified(const std::string& group, const std::string& brushingTarget) {
        return selectedItems[group][brushingTarget] != 0;
    }
};
