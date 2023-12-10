#include <gtest/gtest.h>
#include <yoga/Yoga.h>

// Custom baseline function implementation
static float customBaselineFunc(YGNodeRef node, const float width, const float height) {
  // Calculate the baseline position based on the node's dimensions
  return height / 2;  // Example implementation: baseline positioned at half the height
}

// Unit test for the custom baseline function
TEST(CustomBaselineFuncTest, BaselineCalculation) {
  // Create a Yoga node for testing
  YGNodeRef testNode = YGNodeNew();
  
  // Set the dimensions of the test node
  YGNodeStyleSetWidth(testNode, 100);
  YGNodeStyleSetHeight(testNode, 50);
  
  // Calculate the baseline using the custom function
  float calculatedBaseline = customBaselineFunc(testNode, 100, 50);
  
  // Verify the correctness of the calculated baseline
  // For this example implementation, the baseline should be at 25 (half the height)
  EXPECT_EQ(calculatedBaseline, 25);
  
  // Clean up the test node
  YGNodeFree(testNode);
}
