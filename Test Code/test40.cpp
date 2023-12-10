class SettingsProvider {
public:
    // Constructor
    SettingsProvider() {
        // Initialize the number of button presses to 0
        num_button_presses = 0;
    }

    // Method to simulate a settings button being pressed
    void SendLearnMorePressedForTest() {
        // Increment the number of button presses
        num_button_presses++;

        // Set the last requested notifier ID to the ID of the settings button
        last_requested_notifier_id = NotifierId("id", NotifierType::APPLICATION);
    }

    // Method to return the total count of button presses
    int request_count() {
        return num_button_presses;
    }

    // Method to return the ID of the last settings button pressed
    NotifierId last_requested_notifier_id() {
        return last_requested_notifier_id;
    }

private:
    // Number of button presses
    int num_button_presses;

    // Last requested notifier ID
    NotifierId last_requested_notifier_id;
};
