#include <iostream>
#include <string>
#include "gtest/gtest.h"

void runServerGroupTests(const std::string& serverGroupName) {
    testing::InitGoogleTest();
    int argc = 1;
    char* argv[] = {const_cast<char*>("test")};
    testing::InitGoogleTest(&argc, argv);

    testing::TestEventListeners& listeners = testing::UnitTest::GetInstance()->listeners();
    testing::EmptyTestEventListener* listener = new testing::EmptyTestEventListener();
    listeners.Append(listener);

    testing::UnitTest::GetInstance()->Run();

    std::cout << "Server Group: " << serverGroupName << std::endl;
    const testing::TestResult* result = testing::UnitTest::GetInstance()->ad_hoc_test_result();
    for (int i = 0; i < result->total_part_count(); ++i) {
        const testing::TestPartResult& part = result->GetTestPartResult(i);
        std::cout << "Test Case: " << part.file_name() << "." << part.test_name() << " - " << (part.failed() ? "Failed" : "Passed") << std::endl;
    }
}
