class EventSystem:
    def __init__(self):
        self.signals = {}
        self.slots = {}

    def connect(self, signal, slot):
        if signal not in self.signals:
            self.signals[signal] = []
        self.signals[signal].append(slot)

    def emit(self, signal):
        if signal in self.signals:
            for slot in self.signals[signal]:
                slot()

class Game:
    def __init__(self):
        self.event_system = EventSystem()

    def close(self):
        print("Closing game...")

    def continueGame(self):
        print("Continuing game...")

    def startNewGame(self):
        print("Starting new game...")

    def openSettings(self):
        print("Opening settings...")

    def connect_signals(self):
        self.event_system.connect("quit_btn", self.close)
        self.event_system.connect("continue_btn", self.continueGame)
        self.event_system.connect("new_game_btn", self.startNewGame)
        self.event_system.connect("settings_btn", self.openSettings)

    def emit_signal(self, signal):
        self.event_system.emit(signal)

# Example usage:
game = Game()
game.connect_signals()
game.emit_signal("new_game_btn")
