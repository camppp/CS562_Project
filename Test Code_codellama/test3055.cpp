#include <vector>

class Mesh;
class Transform;
class Framebuffer;

struct MeshDrawData {
    SharedPtr<Mesh> mesh;
    ConstRef<Transform> transform;
};

class SceneRenderer {
public:
    void SubmitMesh(SharedPtr<Mesh> mesh, ConstRef<Transform> transform);
    void *GetFinalFramebufferColorAttachmentHandle();

private:
    std::vector<MeshDrawData> meshDrawList;
    SharedPtr<Framebuffer> mainFramebuffer;
};

void SceneRenderer::SubmitMesh(SharedPtr<Mesh> mesh, ConstRef<Transform> transform)
{
    meshDrawList.push_back({ mesh, transform });
}

void *SceneRenderer::GetFinalFramebufferColorAttachmentHandle()
{
    return mainFramebuffer->GetColorAttachmentHandle();
}
