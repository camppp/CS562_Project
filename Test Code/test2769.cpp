class Bindings_Storage:
    def __init__(self):
        self.bindings = {}

    def addBinding(self, logEntry, location):
        self.bindings[logEntry] = location

    def removeBinding(self, logEntry):
        del self.bindings[logEntry]

    def getLocation(self, logEntry):
        return self.bindings.get(logEntry)
