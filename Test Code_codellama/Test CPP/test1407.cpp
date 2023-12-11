#include <iostream>
#include <map>
#include <thread>

class ThreadLocalStorage
{
public:
    ThreadLocalStorage() {}
    ~ThreadLocalStorage() {}

    void set(int value)
    {
        // Use a map to store the TLS variable for each thread
        std::map<std::thread::id, int> tls;

        // Get the current thread ID
        std::thread::id id = std::this_thread::get_id();

        // Set the TLS variable for the current thread
        tls[id] = value;
    }

    int get()
    {
        // Use a map to store the TLS variable for each thread
        std::map<std::thread::id, int> tls;

        // Get the current thread ID
        std::thread::id id = std::this_thread::get_id();

        // Return the TLS variable for the current thread
        return tls[id];
    }
};
