python
class MemoryModeControl:
    def __init__(self):
        self.default_mode = 0
        self.current_mode = self.default_mode

    def setMemoryMode(self, mode: int):
        self.current_mode = mode

    def getMemoryMode(self) -> int:
        return self.current_mode

    def resetMemoryMode(self):
        self.current_mode = self.default_mode

# Usage
mmc = MemoryModeControl()
mmc.setMemoryMode(1)
print(mmc.getMemoryMode())  # Output: 1

mmc.setMemoryMode(2)
print(mmc.getMemoryMode())  # Output: 2

mmc.resetMemoryMode()
print(mmc.getMemoryMode())  # Output: 0
