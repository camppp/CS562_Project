#include <iostream>

// RendererAPI enum class
enum class RendererAPI
{
    OpenGL,
    DirectX,
    Vulkan
};

// Renderer class
class Renderer
{
private:
    // Private static member variable for the current rendering API
    static RendererAPI s_RendererAPI;

public:
    // Public static method for setting the current rendering API
    static void SetRendererAPI(RendererAPI api)
    {
        s_RendererAPI = api;
    }

    // Public static method for getting the current rendering API
    static RendererAPI GetRendererAPI()
    {
        return s_RendererAPI;
    }
};

// Private static member variable for the current rendering API
RendererAPI Renderer::s_RendererAPI = RendererAPI::OpenGL;
