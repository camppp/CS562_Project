#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "frame_drawer.h"
#include "mock_frame_drawer.h"

using ::testing::_;
using ::testing::InSequence;
using ::testing::Return;

class FrameDrawerTest : public ::testing::Test {
protected:
  MockFrameDrawer mock_frame_drawer;
  VideoStream stream;

  void SetUp() override {
    // Set up the video stream
    stream = VideoStream();
    stream.set_frame_rate(30);
    stream.set_width(1920);
    stream.set_height(1080);
    stream.set_format(VideoFormat::YUV420);

    // Set up the frame drawer
    mock_frame_drawer.set_stream(stream);
  }
};

TEST_F(FrameDrawerTest, DrawFrame) {
  // Set up the expectations
  InSequence s;
  EXPECT_CALL(mock_frame_drawer, DrawFrame(_, _)).Times(1);
  EXPECT_CALL(mock_frame_drawer, get_time()).WillOnce(Return(1000));

  // Draw the frame
  mock_frame_drawer.DrawFrame(stream.get_frame(0), 1000);

  // Verify the behavior of the frame drawer
  EXPECT_EQ(mock_frame_drawer.get_frame_count(), 1);
  EXPECT_EQ(mock_frame_drawer.get_time(), 1000);
}
