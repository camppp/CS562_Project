#include <iostream>
#include <queue>
#include <cassert>

class LoopBuffer {
public:
    LoopBuffer(int max_frames) : max_frames_(max_frames) {}

    void queue_frame_in(int frame) {
        if (frames_queued_in_ < max_frames_) {
            input_buffer_.push(frame);
            frames_queued_in_++;
        } else {
            std::cerr << "Input buffer full. Frame dropped." << std::endl;
        }
    }

    int dequeue_frame_out() {
        if (!output_buffer_.empty()) {
            int frame = output_buffer_.front();
            output_buffer_.pop();
            frames_queued_out_--;
            return frame;
        } else {
            std::cerr << "Output buffer empty. Returning 0." << std::endl;
            return 0;
        }
    }

    int frames_queued() const {
        return frames_queued_in_ - frames_queued_out_;
    }

private:
    std::queue<int> input_buffer_;
    std::queue<int> output_buffer_;
    int max_frames_;
    int frames_queued_in_ = 0;
    int frames_queued_out_ = 0;
};

int main() {
    LoopBuffer loop_buffer(5);

    // Check zero frames queued.
    int rc = loop_buffer.frames_queued();
    assert(rc == 0);

    loop_buffer.queue_frame_in(10);
    loop_buffer.queue_frame_in(20);
    loop_buffer.queue_frame_in(30);

    rc = loop_buffer.frames_queued();
    assert(rc == 3);

    loop_buffer.dequeue_frame_out();
    loop_buffer.dequeue_frame_out();

    rc = loop_buffer.frames_queued();
    assert(rc == 1);

    loop_buffer.queue_frame_in(40);
    loop_buffer.queue_frame_in(50);
    loop_buffer.queue_frame_in(60);

    rc = loop_buffer.frames_queued();
    assert(rc == 4);

    std::cout << "All assertions passed." << std::endl;

    return 0;
}
