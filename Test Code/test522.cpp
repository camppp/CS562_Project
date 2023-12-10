class ShadowMapper : public Shader {
public:
    ShadowMapper(Engine* engine, const core::sync::EndCaller<core::sync::EndCallerIgnore>& caller)
        : Shader(engine, caller) {
        // Load the shader code using the function loader from the engine
        FunctionLoader* function_loader = engine->get_function_loader();
        function_loader->load_shader_code("shadow_mapping.glsl", &shader_code);
    }

private:
    // Shader code loaded from the function loader
    std::string shader_code;
};
