python
class Log_Entry:
    def __init__(self):
        self.name = None
        self.location = None

    def setName(self, name):
        self.name = name

    def setNameByLocation(self, name, location):
        if self.name is None:
            self.name = name
            self.location = location

class Bindings_Storage:
    def __init__(self):
        self.bindings = {}

    def addBinding(self, logEntry, location):
        self.bindings[logEntry] = location

    def removeBinding(self, logEntry):
        if logEntry in self.bindings:
            del self.bindings[logEntry]

    def getLocation(self, logEntry):
        if logEntry in self.bindings:
            return self.bindings[logEntry]
        else:
            if logEntry.name is not None:
                return logEntry.location
            else:
                return None

# Usage
log1 = Log_Entry()
log1.setName("Log1")
log2 = Log_Entry()
log2.setNameByLocation("Log2", "Location2")

bindings = Bindings_Storage()
bindings.addBinding(log1, "Location1")
bindings.addBinding(log2, "Location3")

print(bindings.getLocation(log1))  # Output: Location1
print(bindings.getLocation(log2))  # Output: Location3

log2.setName("NewLog2")
print(bindings.getLocation(log2))  # Output: Location2
bindings.removeBinding(log2)
print(bindings.getLocation(log2))  # Output: Location2 (from setNameByLocation)
