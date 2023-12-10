#include <iostream>
#include <string>

namespace Morpheus {

    class RendererAPI {
    public:
        // Add a new enum value for each supported rendering API
        enum class API {
            Vulkan,
            DirectX,
            OpenGL
        };

        // Add a static member variable to store the current rendering API
        static API currentAPI;

        // Add a function to retrieve the current rendering API
        static API getCurrentAPI() {
            return currentAPI;
        }
    };

    // Define the static member variable for the current rendering API
    RendererAPI::API RendererAPI::currentAPI = RendererAPI::API::Vulkan;

} // namespace Morpheus
