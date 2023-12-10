template <typename... Args>
void complete(Args&&... args)
{
  // Transition the state to completed
  state_ = completed;

  // Invoke the callback function with the provided arguments
  callback_(std::forward<Args>(args)...);

  // Reset the state to starting
  state_ = starting;
}
