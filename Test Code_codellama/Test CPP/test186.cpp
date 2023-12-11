#include <GLFW/glfw3.h>

namespace Silice3D {

class Timer {
public:
  Timer() : last_time_(0), current_time_(0), dt_(0), stopped_(true) {}

  void Start() {
    if (stopped_) {
      last_time_ = glfwGetTime();
      stopped_ = false;
    }
  }

  void Stop() {
    if (!stopped_) {
      current_time_ += dt_;
      stopped_ = true;
    }
  }

  void Reset() {
    last_time_ = 0;
    current_time_ = 0;
    dt_ = 0;
    stopped_ = true;
  }

  double Elapsed() const {
    if (stopped_) {
      return current_time_;
    } else {
      return current_time_ + (glfwGetTime() - last_time_);
    }
  }

private:
  double last_time_;
  double current_time_;
  double dt_;
  bool stopped_;
};

}  // namespace Silice3D
