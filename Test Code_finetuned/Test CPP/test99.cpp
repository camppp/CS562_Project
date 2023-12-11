#include "gtest/gtest.h"
#include "convolution.h"

class ConvolutionTest : public ::testing::Test {
protected:
    Convolution conv;
};

TEST_F(ConvolutionTest, TestManipulation) {
    // Test moving tensor
    tensor::dims dims = {1, 1, 1, 1};
    tensor input(dims);
    tensor output(dims);
    conv.convolve(input, output);
    tensor moved_input = std::move(input);
    tensor moved_output = std::move(output);
    EXPECT_EQ(moved_input.dims(), dims);
    EXPECT_EQ(moved_output.dims(), dims);

    // Test copying tensor
    tensor copied_input(input);
    tensor copied_output(output);
    EXPECT_EQ(copied_input.dims(), dims);
    EXPECT_EQ(copied_output.dims(), dims);

    // Test with bias
    tensor bias(dims);
    conv.convolve(input, output, bias);
    EXPECT_EQ(output.dims(), dims);

    // Test cache behavior
    tensor cache_input(dims);
    tensor cache_output(dims);
    conv.convolve(cache_input, cache_output);
    // Add cache behavior checks here
}