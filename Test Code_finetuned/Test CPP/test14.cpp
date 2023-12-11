class Bot:
    def __init__(self, name):
        self.name = name
        self.immediate_effects = []
        self.delayed_effects = []

    def apply_immediate_effect(self, effect):
        self.immediate_effects.append(effect)

    def apply_delayed_effect(self, effect):
        self.delayed_effects.append(effect)

    def apply_effects(self):
        for effect in self.immediate_effects:
            effect.apply(self)
        self.immediate_effects = []

        for effect in self.delayed_effects:
            if effect.is_ready():
                effect.apply(self)
                self.delayed_effects.remove(effect)

class Effect:
    def __init__(self, condition, action):
        self.condition = condition
        self.action = action

    def is_ready(self):
        return self.condition()

    def apply(self, bot):
        self.action(bot)

class BotSpawner:
    def __init__(self):
        self.bots = []

    def add_bot(self, bot):
        self.bots.append(bot)

    def apply_effects(self):
        for bot in self.bots:
            bot.apply_effects()

    def periodic_task(self):
        self.apply_effects()