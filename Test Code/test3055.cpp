#include <vector>

// Define the Mesh class
class Mesh {
    // Implementation details for the Mesh class
};

// Define the Transform class
class Transform {
    // Implementation details for the Transform class
};

// Define the Framebuffer class
class Framebuffer {
public:
    void* GetColorAttachmentHandle() {
        // Implementation details for retrieving color attachment handle
        return nullptr; // Placeholder return value
    }
};

// Define the SceneRenderData struct
struct SceneRenderData {
    std::vector<std::pair<SharedPtr<Mesh>, ConstRef<Transform>>> meshDrawList;
    SharedPtr<Framebuffer> mainFramebuffer;
};

// Define the SharedPtr class
template <class T>
class SharedPtr {
    // Implementation details for the SharedPtr class
};

// Define the SceneRenderer class
class SceneRenderer {
public:
    SceneRenderer() : s_SceneRenderData({}), s_MainFramebuffer(nullptr) {}

    void SubmitMesh(SharedPtr<Mesh> mesh, ConstRef<Transform> transform) {
        s_SceneRenderData.meshDrawList.push_back({ mesh, transform });
    }

    void* GetFinalFramebufferColorAttachmentHandle() {
        return s_SceneRenderData.mainFramebuffer->GetColorAttachmentHandle();
    }

private:
    SceneRenderData s_SceneRenderData;
    SharedPtr<Framebuffer> s_MainFramebuffer;
};
