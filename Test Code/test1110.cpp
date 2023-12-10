python
class ErrorTester:
    def __init__(self):
        self.error_flag = False

    def GetError(self):
        if self.error_flag:
            self.error_flag = False
            return True
        else:
            return False

# Example usage
tester = ErrorTester()
print(tester.GetError())  # Output: False
tester.error_flag = True  # Simulate an error
print(tester.GetError())  # Output: True
print(tester.GetError())  # Output: False (error flag reset)
