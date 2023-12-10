#include <iostream>

namespace Morpheus {

    class RendererAPI {
    public:
        enum class API {
            None = 0,
            Vulkan,
            DirectX,
            OpenGL
        };

    private:
        static API s_RenderAPI;

    public:
        static void SetAPI(API api) {
            s_RenderAPI = api;
        }

        static API GetAPI() {
            return s_RenderAPI;
        }
    };

    // Set the default rendering API to Vulkan
    RendererAPI::API RendererAPI::s_RenderAPI = RendererAPI::API::Vulkan;

} // namespace Morpheus

int main() {
    using namespace Morpheus;

    // Set the rendering API to DirectX
    RendererAPI::SetAPI(RendererAPI::API::DirectX);

    // Retrieve and print the current rendering API
    std::cout << "Current Rendering API: ";
    switch (RendererAPI::GetAPI()) {
        case RendererAPI::API::Vulkan:
            std::cout << "Vulkan";
            break;
        case RendererAPI::API::DirectX:
            std::cout << "DirectX";
            break;
        case RendererAPI::API::OpenGL:
            std::cout << "OpenGL";
            break;
        default:
            std::cout << "None";
            break;
    }
    std::cout << std::endl;

    return 0;
}
