#include <string>
#include <optional>
#include <absl/time/time.h>

class RealTimeDomain {
 public:
  RealTimeDomain(const std::string& name) : name_(name) {}

  const char* GetName() const { return name_.c_str(); }

  bool MaybeFastForwardToWakeUp(absl::optional<DelayedWakeUp> next_wake_up, bool quit_when_idle_requested) {
    if (!next_wake_up) {
      return false;
    }

    // Check if the next wake-up event is in the future
    if (next_wake_up->time > absl::Now()) {
      return false;
    }

    // Check if the system is in a state where fast-forwarding is allowed
    if (quit_when_idle_requested && IsIdle()) {
      return false;
    }

    // Fast-forward to the next wake-up event
    absl::Now() = next_wake_up->time;
    return true;
  }

 private:
  std::string name_;
};
