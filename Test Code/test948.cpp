#include <unordered_map>
#include <string>

enum class BrushingTarget { Column, Row }; // Define the brushing targets

class BrushingDataStructure {
private:
    std::unordered_map<std::string, std::unordered_map<BrushingTarget, int>> selectedItems_;
    std::unordered_map<std::string, std::unordered_map<BrushingTarget, bool>> selectionModified_;

public:
    void setNumberOfSelected(const std::string& group, BrushingTarget brushingTarget, int count) {
        selectedItems_[group][brushingTarget] = count;
        selectionModified_[group][brushingTarget] = true; // Mark selection as modified
    }

    int getNumberOfSelected(const std::string& group, BrushingTarget brushingTarget) {
        return selectedItems_[group][brushingTarget];
    }

    bool isSelectionModified(const std::string& group, BrushingTarget brushingTarget) {
        bool modified = selectionModified_[group][brushingTarget];
        if (modified) {
            selectionModified_[group][brushingTarget] = false; // Reset selection modification flag
        }
        return modified;
    }
};

// Usage example
int main() {
    BrushingDataStructure brushingData;

    // Update the number of selected items for groupA and Column brushing target
    brushingData.setNumberOfSelected("groupA", BrushingTarget::Column, 5);

    // Check if the selection has been modified for groupA and Column brushing target
    if (brushingData.isSelectionModified("groupA", BrushingTarget::Column)) {
        // Perform necessary actions when selection is modified
    }

    // Get the number of selected items for groupA and Column brushing target
    int selectedCount = brushingData.getNumberOfSelected("groupA", BrushingTarget::Column);
    return 0;
}
