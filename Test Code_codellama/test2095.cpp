#include "filter.h"

class RateLimitingFilter : public Network::Filter {
public:
  RateLimitingFilter(uint32_t max_requests_per_second)
      : max_requests_per_second_(max_requests_per_second) {}

  Network::FilterStatus onNewConnection() override {
    // Check if the number of requests in the last second exceeds the limit
    if (num_requests_in_last_second_ >= max_requests_per_second_) {
      return Network::FilterStatus::StopIteration;
    }

    // Increment the number of requests in the last second
    ++num_requests_in_last_second_;

    // Continue processing the connection
    return Network::FilterStatus::Continue;
  }

  Network::FilterStatus onData(Buffer::OwnedImpl& data, bool end_stream) override {
    // Check if the number of requests in the last second exceeds the limit
    if (num_requests_in_last_second_ >= max_requests_per_second_) {
      return Network::FilterStatus::StopIteration;
    }

    // Increment the number of requests in the last second
    ++num_requests_in_last_second_;

    // Continue processing the data
    return Network::FilterStatus::Continue;
  }

private:
  uint32_t max_requests_per_second_;
  uint32_t num_requests_in_last_second_ = 0;
};
