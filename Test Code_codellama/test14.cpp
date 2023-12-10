class ConditionalEffectManager {
public:
    // Adds a new periodic task to a bot spawner
    void addPeriodicTask(BotSpawner* spawner, PeriodicTask task) {
        spawner->addPeriodicTask(task);
    }

    // Applies immediate conditional effects to a bot
    void applyImmediateEffects(Bot* bot, std::vector<ConditionalEffect> effects) {
        for (auto& effect : effects) {
            effect.apply(bot);
        }
    }

    // Applies delayed conditional effects to a bot
    void applyDelayedEffects(Bot* bot, std::vector<ConditionalEffect> effects) {
        for (auto& effect : effects) {
            effect.apply(bot, true);
        }
    }

private:
    // Data structure to store the conditional effects for each bot
    std::unordered_map<Bot*, std::vector<ConditionalEffect>> effects;
};
