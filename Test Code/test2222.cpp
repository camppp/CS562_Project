python
class EventSystem:
    def __init__(self):
        self.connections = {}

    def connect(self, signal, slot):
        if signal in self.connections:
            self.connections[signal].append(slot)
        else:
            self.connections[signal] = [slot]

    def emit(self, signal):
        if signal in self.connections:
            for slot in self.connections[signal]:
                slot()


class Game:
    def close(self):
        print("Closing the game")

    def continueGame(self):
        print("Continuing the game")

    def startNewGame(self):
        print("Starting a new game")

    def openSettings(self):
        print("Opening game settings")


# Creating instances of EventSystem and Game
event_system = EventSystem()
game = Game()

# Connecting signals to slots
event_system.connect("quit_btn", game.close)
event_system.connect("continue_btn", game.continueGame)
event_system.connect("new_game_btn", game.startNewGame)
event_system.connect("settings_btn", game.openSettings)

# Emitting the new_game_btn signal
event_system.emit("new_game_btn")
