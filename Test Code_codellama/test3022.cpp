#include <mutex>
#include <random>

class ct_RndStore {
public:
    ct_RndStore() : so_Data(0) {}

    void generate_random_number() {
        std::lock_guard<std::mutex> lock(co_Mutex);
        so_Data = std::uniform_int_distribution<int>(0, 100)(std::mt19937{std::random_device{}()});
    }

    void swap_data(ct_RndStore& other) {
        std::lock_guard<std::mutex> lock(co_Mutex);
        std::swap(so_Data, other.so_Data);
    }

private:
    int so_Data;
    std::mutex co_Mutex;
};
