#include "IcePerfBase.hpp"
#include <chrono>

class IcePerfDerived : public IcePerfBase
{
  public:
    void initLeader() noexcept override
    {
        auto start = std::chrono::high_resolution_clock::now();

        // Simulate leader process initialization
        // ...

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

        std::cout << "Leader process initialized in " << duration.count() << " milliseconds" << std::endl;
    }
};
