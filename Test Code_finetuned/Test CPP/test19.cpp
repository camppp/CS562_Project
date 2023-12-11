import json

class Ask:
    def __init__(self):
        self.data_structure = []

    def populateNPF(self, entry):
        blocks = json.loads(entry)["blocks"]
        for block in blocks:
            self.data_structure.append(block)