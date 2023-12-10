class KeyReservationSystem:
    def __init__(self):
        self.reservations = {}

    def placeReservation(self, peerNodeId, keyId):
        if keyId not in self.reservations:
            self.reservations[keyId] = {}
        self.reservations[keyId][peerNodeId] = True

    def releaseKey(self, keyId):
        if keyId in self.reservations:
            del self.reservations[keyId]

    def getReservations(self, keyId):
        if keyId in self.reservations:
            return self.reservations[keyId]
        else:
            return None
