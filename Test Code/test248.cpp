python
class KeyReservationSystem:
    def __init__(self):
        self.reserved_keys = {}

    def placeReservation(self, peerNodeId, keyId):
        if keyId is not None and keyId in self.reserved_keys:
            self.reserved_keys[keyId].add(peerNodeId)
        elif keyId is not None:
            self.reserved_keys[keyId] = {peerNodeId}

    def releaseKey(self, keyId):
        if keyId in self.reserved_keys:
            del self.reserved_keys[keyId]

    # Additional method to check if a key is reserved
    def isKeyReserved(self, keyId):
        return keyId in self.reserved_keys

# Example usage
reservation_system = KeyReservationSystem()
reservation_system.placeReservation("peer1", "key1")
reservation_system.placeReservation("peer2", "key1")
print(reservation_system.isKeyReserved("key1"))  # Output: True
reservation_system.releaseKey("key1")
print(reservation_system.isKeyReserved("key1"))  # Output: False
