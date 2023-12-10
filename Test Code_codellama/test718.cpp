class WaylandGLESRenderer {
public:
    WaylandGLESRenderer(Executor& executor, Config& config);
    virtual ~WaylandGLESRenderer() = default;

    virtual void render() = 0;

protected:
    Executor& executor_;
    Config& config_;
};

class WaylandFbdevGLESRenderer : public WaylandGLESRenderer {
public:
    WaylandFbdevGLESRenderer(Executor& executor, Config& config);
    ~WaylandFbdevGLESRenderer() = default;

    void render() override;

    const char* pluginGetName() override;
};
