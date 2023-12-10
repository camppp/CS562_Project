#include <babylon/babylon.h>

class SimpleMeshesScene : public IRenderableScene {
public:
    SimpleMeshesScene(ICanvas* canvas) : IRenderableScene(canvas) {
        // Register the GLTFFileLoader as a scene loader plugin
        registerSceneLoaderPlugin(new GLTFFileLoader());
    }

    ~SimpleMeshesScene() = default;
};
