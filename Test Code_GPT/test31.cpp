#include <iostream>
#include <string>

// NotifierId class definition
class NotifierId {
public:
    enum NotifierType {
        APPLICATION,
        // Add other notifier types if needed
    };

    NotifierId(NotifierType type, const std::string& id) : type_(type), id_(id) {}

    bool operator==(const NotifierId& other) const {
        return type_ == other.type_ && id_ == other.id_;
    }

private:
    NotifierType type_;
    std::string id_;
};

// SettingsProvider class definition
class SettingsProvider {
public:
    SettingsProvider() : buttonPressCount(0), lastButtonPressId(NotifierId::APPLICATION, "default_id") {}

    void SendLearnMorePressedForTest(const NotifierId& buttonId) {
        buttonPressCount++;
        lastButtonPressId = buttonId;
    }

    int request_count() const {
        return buttonPressCount;
    }

    NotifierId last_requested_notifier_id() const {
        return lastButtonPressId;
    }

private:
    int buttonPressCount;
    NotifierId lastButtonPressId;
};

int main() {
    // Unit tests
    SettingsProvider settingsProvider;

    // Test 1
    NotifierId testButtonId(NotifierId::APPLICATION, "id");
    settingsProvider.SendLearnMorePressedForTest(testButtonId);
    if (settingsProvider.request_count() == 1 &&
        settingsProvider.last_requested_notifier_id() == testButtonId) {
        std::cout << "Test 1 Passed\n";
    } else {
        std::cout << "Test 1 Failed\n";
    }

    // Additional tests can be added as needed

    return 0;
}
