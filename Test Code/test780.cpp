#include <stdexcept>

/// Exception class for frame transformation errors.
class FrameTransformerException : public std::runtime_error {
public:
  explicit FrameTransformerException(const char* error_message)
      : std::runtime_error(error_message) {}

  ~FrameTransformerException() noexcept override = default;
};

/// Interface class for plugin-specific implementation of frame transformations.
class TransformationLibraryConnector {
public:
  virtual ~TransformationLibraryConnector() = default;
  // Add virtual methods for plugin-specific frame transformation logic.
};

/// Class for managing frame transformations and plugin-specific implementation.
class FrameTransformer : public TransformationLibraryConnector {
public:
  // Implement methods for transforming coordinates between frames.
  // Add methods for managing the plugin-specific implementation.

  // Example method for transforming coordinates between frames.
  virtual void transformCoordinates() {
    // Implement coordinate transformation logic.
  }
};
