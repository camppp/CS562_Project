#include <chrono>

namespace kTest::utility
{
    class ProfilerTester : public TesterBase
    {
    public:
        ProfilerTester() : start_time_(std::chrono::high_resolution_clock::now()) {}
        ~ProfilerTester() override {}

    protected:
        void Prepare() noexcept override
        {
            end_time_ = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> elapsed = end_time_ - start_time_;
            std::cout << "Execution time: " << elapsed.count() << " ms" << std::endl;
        }

    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> start_time_;
        std::chrono::time_point<std::chrono::high_resolution_clock> end_time_;
    };
}
