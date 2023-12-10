class StreamStateKernel {
 public:
  StreamStateKernel(StreamStateListener* listener) : listener_(listener) {}

  void setListener(StreamStateListener* listener) {
    listener_ = listener;
  }

  StreamStateListener* getListener() {
    return listener_;
  }

 private:
  StreamStateListener* listener_;
};
