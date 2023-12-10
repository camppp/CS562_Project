class NeuralNetworkModel {
public:
    // Add a DepthToSpace layer to the model
    void AddDepthToSpaceLayer(const DepthToSpaceDescriptor& descriptor, const std::string& name = "") {
        // Add the layer to the model
        layers_.push_back(std::make_shared<DepthToSpaceLayer>(descriptor, name));
    }

    // Add a DepthwiseConvolution2d layer to the model
    void AddDepthwiseConvolution2dLayer(const DepthwiseConvolution2dDescriptor& descriptor, const std::string& name = "") {
        // Add the layer to the model
        layers_.push_back(std::make_shared<DepthwiseConvolution2dLayer>(descriptor, name));
    }

    // Visualize the model's architecture
    void VisualizeModel() {
        // Print the architecture of the model
        std::cout << "Model Architecture:" << std::endl;
        for (const auto& layer : layers_) {
            std::cout << "Layer: " << layer->getName() << std::endl;
        }
    }

private:
    // Vector of layers in the model
    std::vector<std::shared_ptr<Layer>> layers_;
};
