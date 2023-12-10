class Image {
public:
    void destroy() {
        // Implementation for destroying the image
    }
};

class ImageView {
public:
    void destroy() {
        // Implementation for destroying the image view
    }
};

class Sampler {
public:
    bool create() {
        // Implementation for creating the sampler
        return false; // Placeholder return value for demonstration
    }
};

void createResourceManagementSystem() {
    Sampler sampler;
    Image image;
    ImageView imageView;

    bool samplerCreated = sampler.create();
    if (!samplerCreated) {
        GLOG_CRITICAL("Failed to create sampler.");
        imageView.destroy();
        image.destroy();
    } else {
        image.destroy();
    }
}
