#include <string>

class WaylandGLESRenderer {
public:
    WaylandGLESRenderer(Executor& executor, Config& config) : executor_(executor), config_(config) {}

    virtual ~WaylandGLESRenderer() {}

    virtual void render() = 0;

protected:
    Executor& executor_;
    Config& config_;
};

class WaylandFbdevGLESRenderer : public WaylandGLESRenderer {
public:
    WaylandFbdevGLESRenderer(Executor& executor, Config& config) : WaylandGLESRenderer(executor, config) {}

    virtual ~WaylandFbdevGLESRenderer() {}

    virtual void render() override {
        // Implementation for rendering using GLES in a Wayland environment
    }

    virtual t_ilm_const_string pluginGetName() const {
        return "WaylandFbdevGLESRenderer";
    }
};
