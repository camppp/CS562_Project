class ResourceManager {
public:
    ResourceManager() {}
    ~ResourceManager() {}

    void createSampler(Sampler& sampler, Image& image, ImageView& imageView) {
        if (!sampler.create()) {
            // Handle failure to create sampler
            imageView.destroy();
            image.destroy();
        } else {
            // Destroy image
            image.destroy();
        }
    }
};
