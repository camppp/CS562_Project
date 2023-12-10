#include <stdexcept>

class FrameTransformerException : public std::runtime_error {
public:
    FrameTransformerException(const char* error_message) : std::runtime_error(error_message) {}
};

class TransformationLibraryConnector {
public:
    virtual ~TransformationLibraryConnector() {}
};

class FrameTransformer : public TransformationLibraryConnector {
public:
    FrameTransformer() {}

    void transformCoordinates(const Coordinate& from_frame, const Coordinate& to_frame, Coordinate& result) {
        // Implement the frame transformation logic here
        // Throw a FrameTransformerException if an error occurs
    }

    void setTransformationLibrary(const std::string& library_name) {
        // Implement the plugin-specific implementation of the frame transformation logic here
    }
};
