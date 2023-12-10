#include <vector>
#include <cstdint>

// Define the structure for periodic tasks
struct PeriodicTask {
    float cooldown;
    float when;
    // Add any other necessary fields
};

// Define the structure for immediate conditional effects
struct AddCond {
    // Define the fields for immediate conditional effects
};

// Define the structure for delayed conditional effects
struct DelayedAddCond {
    // Define the fields for delayed conditional effects
};

class BotConditionalEffectsManager {
private:
    std::vector<PeriodicTask> periodicTasks;
    // Add any other necessary data structures

public:
    // Method to add a new periodic task to a bot spawner
    void addPeriodicTask(float cooldown, float when) {
        // Implement the logic to add a new periodic task
    }

    // Method to apply immediate conditional effects to a bot
    void applyImmediateEffects(CTFBot* bot, std::vector<AddCond>& addConds) {
        // Implement the logic to apply immediate conditional effects to the bot
    }

    // Method to apply delayed conditional effects to a bot
    void applyDelayedEffects(CTFBot* bot, std::vector<DelayedAddCond>& delayedAddConds) {
        // Implement the logic to apply delayed conditional effects to the bot
    }
};
