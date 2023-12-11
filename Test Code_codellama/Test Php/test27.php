class CrackleException(Exception):
    def __init__(self, message):
        self.message = message

class CrackleDatabaseException(CrackleException):
    def __init__(self, message):
        super().__init__(message)

class CrackleInputException(CrackleException):
    def __init__(self, message):
        super().__init__(message)