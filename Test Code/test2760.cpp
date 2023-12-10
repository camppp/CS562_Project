#include <gtest/gtest.h>
#include <thread>

// Paste the Channel class implementation here

TEST(ChannelTest, Creation) {
    Channel<int> channel;
    std::thread sender([&channel] {
        channel.send(42);
    });
    std::thread receiver([&channel] {
        int message = channel.receive();
        ASSERT_EQ(message, 42);
    });
    sender.join();
    receiver.join();
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
