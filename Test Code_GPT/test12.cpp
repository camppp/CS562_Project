#include <iostream>
#include <unordered_map>
#include <functional>
#include <chrono>
#include <thread>

class Bot {
public:
    // Dummy bot class for illustration purposes
    void applyImmediateEffect(const std::string& effect) {
        std::cout << "Immediate Effect Applied to Bot: " << effect << std::endl;
    }

    void applyDelayedEffect(const std::string& effect) {
        std::cout << "Delayed Effect Applied to Bot: " << effect << std::endl;
    }
};

class ConditionalEffectManager {
public:
    // Add a new periodic task to a bot spawner
    void addPeriodicTask(std::function<void()> task, std::chrono::seconds interval) {
        // Implement periodic task scheduling here (e.g., using std::thread)
        // ...

        // For illustration purposes, just execute the task immediately
        task();
    }

    // Apply immediate conditional effects to a bot
    void applyImmediateEffects(Bot& bot, const std::string& effect) {
        bot.applyImmediateEffect(effect);
    }

    // Apply delayed conditional effects to a bot after a specified delay
    void applyDelayedEffects(Bot& bot, const std::string& effect, std::chrono::seconds delay) {
        // Implement delayed effect scheduling here (e.g., using std::thread)
        // ...

        // For illustration purposes, just execute the delayed effect after the delay
        std::this_thread::sleep_for(delay);
        bot.applyDelayedEffect(effect);
    }
};

int main() {
    Bot bot;
    ConditionalEffectManager effectManager;

    // Example: Add a periodic task to the bot spawner
    effectManager.addPeriodicTask([&bot]() {
        // Perform periodic task logic (e.g., spawn new bots)
        std::cout << "Periodic Task: Spawn new bots" << std::endl;
    }, std::chrono::seconds(5));

    // Example: Apply immediate effects to the bot
    effectManager.applyImmediateEffects(bot, "ImmediateEffect1");
    effectManager.applyImmediateEffects(bot, "ImmediateEffect2");

    // Example: Apply delayed effects to the bot after a delay
    effectManager.applyDelayedEffects(bot, "DelayedEffect1", std::chrono::seconds(3));
    effectManager.applyDelayedEffects(bot, "DelayedEffect2", std::chrono::seconds(6));

    return 0;
}
