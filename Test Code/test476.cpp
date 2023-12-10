#include <iostream>
#include <memory>
#include <queue>

class AACFrame {
public:
    int aac_frame_length;
    using Ptr = std::shared_ptr<AACFrame>;
};

class ResourcePoolHelper {
private:
    std::queue<std::shared_ptr<AACFrame>> pool;

public:
    std::shared_ptr<AACFrame> obtainObj() {
        if (pool.empty()) {
            return std::make_shared<AACFrame>();
        } else {
            auto obj = pool.front();
            pool.pop();
            // Reset the obtained object
            obj->aac_frame_length = 0; // Reset to default value
            return obj;
        }
    }

    void returnObj(std::shared_ptr<AACFrame> obj) {
        // Reset the object before returning it to the pool
        obj->aac_frame_length = 0; // Reset to default value
        pool.push(obj);
    }
};

class AACRtpDecoder {
private:
    ResourcePoolHelper<AACFrame> pool;

public:
    std::shared_ptr<AACFrame> obtainFrame() {
        auto frame = pool.obtainObj();
        frame->aac_frame_length = 7; // Set the specific value
        return frame;
    }
};

int main() {
    AACRtpDecoder decoder;
    auto frame = decoder.obtainFrame();
    std::cout << "AAC Frame Length: " << frame->aac_frame_length << std::endl;
    decoder.returnObj(frame); // Return the frame to the pool
    return 0;
}
