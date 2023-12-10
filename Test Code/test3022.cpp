#include <mutex>
#include <random>

class ct_RndStore {
private:
    std::mutex co_Mutex;
    int so_Data;

public:
    // Constructor to initialize so_Data with a random number
    ct_RndStore() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dis(1, 100);
        so_Data = dis(gen);
    }

    // Method to swap random number data between two ct_RndStore instances
    void Swap(ct_RndStore &co_swap) {
        co_Mutex.lock();
        co_swap.co_Mutex.lock();
        std::swap(so_Data, co_swap.so_Data);
        co_swap.co_Mutex.unlock();
        co_Mutex.unlock();
    }
};
