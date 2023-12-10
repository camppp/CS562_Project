#include <iostream>
#include <functional>
#include <chrono>
#include <thread>

class CCallbackTimer {
public:
    using CallbackFunction = std::function<void()>;

    void RegisterCallback(CallbackFunction callback, std::chrono::milliseconds delay) {
        m_callback = std::move(callback);
        m_delay = delay;
    }

    void Start() {
        m_running = true;
        m_thread = std::thread([this]() {
            std::this_thread::sleep_for(m_delay);
            if (m_running && m_callback) {
                m_callback();
            }
        });
    }

    void Stop() {
        m_running = false;
        if (m_thread.joinable()) {
            m_thread.join();
        }
    }

    void Reset() {
        Stop();
        m_callback = nullptr;
        m_delay = std::chrono::milliseconds(0);
    }

private:
    CallbackFunction m_callback;
    std::chrono::milliseconds m_delay;
    std::thread m_thread;
    bool m_running = false;
};

// Test class for CCallbackTimer
class CCallbackTimerTest {
public:
    void TestAll() {
        TestConstruct();
        TestTimer();
    }

    void TestConstruct() {
        const std::string functionName = "CCallbackTimerTest::TestConstruct";
        std::cout << functionName << " - start" << std::endl;
        CCallbackTimer timer;
        // Add test cases for timer construction
    }

    void TestTimer() {
        CCallbackTimer timer;
        timer.RegisterCallback([]() {
            std::cout << "Callback executed after 2 seconds" << std::endl;
        }, std::chrono::seconds(2));

        timer.Start();
        std::this_thread::sleep_for(std::chrono::seconds(3));  // Wait for callback execution
        timer.Stop();

        // Add assertions to validate timer functionality
    }
};

int main() {
    CCallbackTimerTest test;
    test.TestAll();
    return 0;
}
