#include <iostream>
#include <thread>
#include <chrono>

class RawFetcher {
public:
    bool Start() {
        // Simulating asynchronous data fetching process
        std::thread fetching_thread([this]() {
            std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulating data fetching time
            std::cout << "Data fetching completed" << std::endl;
        });
        fetching_thread.detach(); // Allowing the thread to run asynchronously

        return true;
    }
};

int main() {
    RawFetcher* raw_fetcher = new RawFetcher();
    bool result = raw_fetcher->Start();
    if (result) {
        std::cout << "Data fetching process initiated" << std::endl;
    } else {
        std::cout << "Failed to initiate data fetching process" << std::endl;
    }

    // Other operations

    delete raw_fetcher;
    return 0;
}
