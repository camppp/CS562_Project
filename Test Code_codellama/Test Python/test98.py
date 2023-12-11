import unittest

class TestSuite:
    def __init__(self):
        self.tests = []

    def addTests(self, tests):
        self.tests.extend(tests)

    def runTests(self):
        for test in self.tests:
            test.run()
            print(f"{test.id()}: {test.shortDescription()}")

test_suite = TestSuite()
test_suite.addTests(unittest.makeSuite(test_cli.TestCli))
test_suite.runTests()