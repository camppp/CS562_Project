// Define the enum class for different rendering APIs
enum class RendererAPI {
    OpenGL,
    DirectX,
    Vulkan
};

// Implement the Renderer class
class Renderer {
private:
    static RendererAPI s_RendererAPI;

public:
    // Set the rendering API
    static void SetRendererAPI(RendererAPI api) {
        s_RendererAPI = api;
    }

    // Get the current rendering API
    static RendererAPI GetRendererAPI() {
        return s_RendererAPI;
    }
};

// Usage example
int main() {
    // Set the rendering API to OpenGL
    Renderer::SetRendererAPI(RendererAPI::OpenGL);

    // Get the current rendering API
    RendererAPI currentAPI = Renderer::GetRendererAPI();

    // Output the current rendering API
    switch (currentAPI) {
        case RendererAPI::OpenGL:
            std::cout << "Current rendering API: OpenGL" << std::endl;
            break;
        case RendererAPI::DirectX:
            std::cout << "Current rendering API: DirectX" << std::endl;
            break;
        case RendererAPI::Vulkan:
            std::cout << "Current rendering API: Vulkan" << std::endl;
            break;
    }

    return 0;
}
