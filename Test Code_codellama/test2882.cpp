class AlarmList {
public:
    // Constructor
    AlarmList() {}

    // Add an alarm item to the list
    void addItem(int value) {
        items.push_back(value);
    }

    // Calculate the sum of all integer values in the list
    int calculateSum() {
        int sum = 0;
        for (const auto& int_item : items) {
            sum += int_item;
        }
        return sum;
    }

private:
    // Vector of alarm items
    std::vector<int> items;
};
