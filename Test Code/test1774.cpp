class CustomActorImpl {
  // Implementation details for CustomActor
};

namespace Internal {
  class CustomActor {
    // Internal details for CustomActor
  };
}

class Actor {
  // Base class for actors
};

class CustomActor : public Actor {
public:
  // Constructor taking a reference to CustomActorImpl
  CustomActor(CustomActorImpl& implementation)
    : Actor(Internal::CustomActor::New(implementation).Get()), mInternal(Internal::CustomActor::New(implementation)) {
  }

  // Constructor taking a pointer to Internal::CustomActor
  CustomActor(Internal::CustomActor* internal)
    : Actor(internal), mInternal(internal) {
  }

  ~CustomActor() {
    // Check if the destructor is called from CustomActorImpl
    if (mInternal->IsInCustomActorImplDestructor()) {
      // Handle the potential issue by preventing the creation of a new handle to CustomActor
      throw std::logic_error("Creating a new handle to CustomActor within CustomActorImpl destructor is not allowed.");
    }
  }

private:
  Internal::CustomActor* mInternal;
};
