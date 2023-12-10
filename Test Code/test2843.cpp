template <typename... Args>
void complete(Args&&... args)
{
  if (state_ == starting)
  {
    state_ = completed;
    std::apply(callback_, std::forward_as_tuple(std::forward<Args>(args)...));
    state_ = starting;
  }
}
