class CrackleException(Exception):
    pass

class CrackleDatabaseException(CrackleException):
    def __init__(self, message):
        self.message = message
        super().__init__(self.message)

class CrackleInputException(CrackleException):
    def __init__(self, message):
        self.message = message
        super().__init__(self.message)