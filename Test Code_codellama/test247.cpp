#include <gtest/gtest.h>

struct StanfordImporterTest : public TestSuite::Tester {
  // Test case 1: invalid file signature
  void testInvalidSignature() {
    // Set up the test case
    std::string filePath = "path/to/invalid/file.stanford";
    std::string expectedError = "Invalid file signature";

    // Run the test
    auto importer = StanfordImporter(filePath);
    auto result = importer.import();

    // Check the result
    EXPECT_EQ(result.error(), expectedError);
  }

  // Test case 2: invalid file format
  void testFormatInvalid() {
    // Set up the test case
    std::string filePath = "path/to/invalid/file.stanford";
    std::string expectedError = "Invalid file format";

    // Run the test
    auto importer = StanfordImporter(filePath);
    auto result = importer.import();

    // Check the result
    EXPECT_EQ(result.error(), expectedError);
  }

  // Test case 3: unsupported file format
  void testFormatUnsupported() {
    // Set up the test case
    std::string filePath = "path/to/unsupported/file.stanford";
    std::string expectedError = "Unsupported file format";

    // Run the test
    auto importer = StanfordImporter(filePath);
    auto result = importer.import();

    // Check the result
    EXPECT_EQ(result.error(), expectedError);
  }

  // Test case 4: missing file format
  void testFormatMissing() {
    // Set up the test case
    std::string filePath = "path/to/missing/file.stanford";
    std::string expectedError = "Missing file format";

    // Run the test
    auto importer = StanfordImporter(filePath);
    auto result = importer.import();

    // Check the result
    EXPECT_EQ(result.error(), expectedError);
  }

  // Test case 5: file format detected too late
  void testFormatTooLate() {
    // Set up the test case
    std::string filePath = "path/to/too/late/file.stanford";
    std::string expectedError = "File format detected too late";

    // Run the test
    auto importer = StanfordImporter(filePath);
    auto result = importer.import();

    // Check the result
    EXPECT_EQ(result.error(), expectedError);
  }
};

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
