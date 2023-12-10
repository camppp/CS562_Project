#include <iostream>

// Define the StreamStateListener class
class StreamStateListener {
public:
    virtual void onStateChanged() = 0;
};

// Define the StreamStateKernel class
class StreamStateKernel {
private:
    StreamStateListener* listener_;

public:
    // Constructor
    StreamStateKernel(StreamStateListener* listener) : listener_(listener) {}

    // Method to set the listener
    void setListener(StreamStateListener* listener) {
        listener_ = listener;
    }

    // Method to get the listener
    StreamStateListener* getListener() {
        return listener_;
    }
};

// Sample usage of the StreamStateKernel class
int main() {
    // Create a StreamStateListener object
    class MyStreamStateListener : public StreamStateListener {
    public:
        void onStateChanged() override {
            std::cout << "Stream state changed" << std::endl;
        }
    };

    // Create a StreamStateKernel object with a listener
    MyStreamStateListener listener;
    StreamStateKernel kernel(&listener);

    // Get the current listener and call the onStateChanged method
    StreamStateListener* currentListener = kernel.getListener();
    currentListener->onStateChanged();

    // Set a new listener and call the onStateChanged method
    class NewStreamStateListener : public StreamStateListener {
    public:
        void onStateChanged() override {
            std::cout << "New stream state changed" << std::endl;
        }
    };
    NewStreamStateListener newListener;
    kernel.setListener(&newListener);
    currentListener = kernel.getListener();
    currentListener->onStateChanged();

    return 0;
}
