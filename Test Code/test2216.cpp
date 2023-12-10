template <typename Executor, typename Receiver>
struct AsOperation
{
  Executor ex_;
  Receiver receiver_;

  // Constructor to initialize the executor and receiver
  AsOperation(Executor e, Receiver r)
    : ex_(e), receiver_(r)
  {
    // Your implementation here
  }
};
