python
class ParallelProcessingSystem:
    def __init__(self):
        self.systemIDs = set()

    def registerSystemID(self, systemID):
        self.systemIDs.add(systemID)

    def removeSystemID(self, systemID):
        if systemID in self.systemIDs:
            self.systemIDs.remove(systemID)
        else:
            print("System ID not found.")

    def isSystemIDRegistered(self, systemID):
        return systemID in self.systemIDs

    def getTotalSystemIDCount(self):
        return len(self.systemIDs)

# Example usage
parallelSystem = ParallelProcessingSystem()
parallelSystem.registerSystemID("TestSystemParallel1")
parallelSystem.registerSystemID("TestSystemParallel2")
parallelSystem.registerSystemID("TestSystemParallel3")
print(parallelSystem.getTotalSystemIDCount())  # Output: 3
print(parallelSystem.isSystemIDRegistered("TestSystemParallel2"))  # Output: True
parallelSystem.removeSystemID("TestSystemParallel2")
print(parallelSystem.getTotalSystemIDCount())  # Output: 2
print(parallelSystem.isSystemIDRegistered("TestSystemParallel2"))  # Output: False
