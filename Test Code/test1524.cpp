#include "NMEAParser.cpp"
#include <gtest/gtest.h>

// Test fixture for NMEAParser
class NMEAParserTest : public ::testing::Test {
protected:
    NMEAParser parser;
};

// Test cases for ParseDifferentialCorrectionAge function
TEST_F(NMEAParserTest, ValidInputs) {
    // Test valid inputs
    EXPECT_EQ(parser.ParseDifferentialCorrectionAge("123"), 123);
    EXPECT_EQ(parser.ParseDifferentialCorrectionAge("0"), 0);
    EXPECT_EQ(parser.ParseDifferentialCorrectionAge("999"), 999);
}

TEST_F(NMEAParserTest, EdgeCases) {
    // Test edge cases
    EXPECT_EQ(parser.ParseDifferentialCorrectionAge(""), -1);  // Empty string
    EXPECT_EQ(parser.ParseDifferentialCorrectionAge("1"), 1);  // Minimum valid value
    EXPECT_EQ(parser.ParseDifferentialCorrectionAge("65535"), 65535);  // Maximum valid value
}

TEST_F(NMEAParserTest, InvalidInputs) {
    // Test invalid inputs
    EXPECT_EQ(parser.ParseDifferentialCorrectionAge("abc"), -1);  // Non-numeric input
    EXPECT_EQ(parser.ParseDifferentialCorrectionAge("-1"), -1);  // Negative value
    EXPECT_EQ(parser.ParseDifferentialCorrectionAge("65536"), -1);  // Out-of-range value
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
