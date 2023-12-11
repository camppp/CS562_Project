class LightTransformer {
public:
    virtual void transform(LightEffect effect) = 0;
};

class LightTransitionTransformer : public LightTransformer {
public:
    void transform(LightEffect effect) override {
        // Implement default transition behavior here
    }
};

class LightOutput {
public:
    std::unique_ptr<LightTransformer> create_default_transition() {
        return std::make_unique<LightTransitionTransformer>();
    }
};
