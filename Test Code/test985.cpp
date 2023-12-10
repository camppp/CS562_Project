python
import random

class Die:
    def __init__(self, numSides):
        self.numSides = numSides

    def roll(self):
        return random.randint(1, self.numSides)
