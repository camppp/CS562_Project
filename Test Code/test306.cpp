python
class TestRegistry:
    def __init__(self):
        self.tests = []

    def addTest(self, test):
        self.tests.append(test)

    def runAllTests(self):
        for test in self.tests:
            test.runTest()

    def getTestResults(self):
        results = []
        for test in self.tests:
            results.append(test.getTestResult())
        return results
