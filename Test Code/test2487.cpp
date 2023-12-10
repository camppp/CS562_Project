// Define the base class MediaSoupClientError
class MediaSoupClientError {
public:
    explicit MediaSoupClientError(const char* description) : description_(description) {}

    const char* getDescription() const {
        return description_;
    }

private:
    const char* description_;
};

// Define the derived class MediaSoupClientUnsupportedError
class MediaSoupClientUnsupportedError : public MediaSoupClientError {
public:
    explicit MediaSoupClientUnsupportedError(const char* description)
        : MediaSoupClientError(description) {
    }
};
