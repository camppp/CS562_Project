#include <future>
#include <chrono>
#include <iostream>

namespace pc {
  enum class future_status { ready, timeout };

  template <typename T>
  class future {
    // Implementation of future class
  };

  template <typename Clock, typename Duration>
  class timed_waiter {
  public:
    using future_status = pc::future_status;

    timed_waiter(pc::future<T>& future) : future_(future) {}

    future_status wait_until(const std::chrono::time_point<Clock, Duration>& timeout_time) {
      if (future_.wait_until(timeout_time) == std::future_status::ready) {
        return future_status::ready;
      } else {
        return future_status::timeout;
      }
    }

    future_status wait_for(const std::chrono::duration<rep, period>& rel_time) {
      if (future_.wait_for(rel_time) == std::future_status::ready) {
        return future_status::ready;
      } else {
        return future_status::timeout;
      }
    }

  private:
    pc::future<T>& future_;
  };
}  // namespace pc
