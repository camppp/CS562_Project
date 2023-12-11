class Connection:
    def __init__(self):
        self.__connected = False

    def connect(self):
        self.__connected = True

    def disconnect(self):
        self.__connected = False

    def isConnected(self):
        return self.__connected