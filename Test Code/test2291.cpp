#include <iostream>
#include <string>
#include <vector>

class MediaManager {
 public:
  MediaManager(int writer_capacity) : writer_capacity_(writer_capacity) {}

  void setWriterCapacityForTesting(int capacity) {
    writer_capacity_ = capacity;
  }

  bool initialize() {
    // Initialize the video decoder
    video_decoder_ = CreateRemoteVideoDecoder();

    // Set the color space information
    color_space_ = gfx::ColorSpace();

    // Request overlay information
    RequestOverlayInfoCB();

    // Set the writer capacity for testing purposes
    if (writer_capacity_)
      client_->set_writer_capacity_for_testing(writer_capacity_);

    return true;
  }

 private:
  int writer_capacity_;
  VideoDecoder video_decoder_;
  gfx::ColorSpace color_space_;
};
