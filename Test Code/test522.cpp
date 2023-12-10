#include <iostream>
#include <string>

// Assume the definition of core::sync::EndCaller and core::sync::EndCallerIgnore

namespace core {
    namespace sync {
        // Definition of EndCaller and EndCallerIgnore
    }
}

namespace engine {
    class FunctionLoader {
    public:
        void load(const std::function<void()>& callback) {
            // Implementation of shader code loading
            callback();  // Simulate calling the callback after loading
        }
    };
}

class Engine {
public:
    engine::FunctionLoader* get_function_loader() {
        // Return the function loader
        return &functionLoader;
    }
    // Other member functions and variables
private:
    engine::FunctionLoader functionLoader;
};

class Shader {
public:
    Shader(Engine* engine, const core::sync::EndCaller<core::sync::EndCallerIgnore>& caller) {
        // Constructor implementation
    }
    // Other member functions and variables
};

namespace gearoenix {
    namespace gles2 {
        namespace shader {
            const std::string GX_GLES2_SHADER_SRC_DEFAULT_VERTEX_STARTING = "vertex shader code";  // Assume the vertex shader code

            class ShadowMapper : public Shader {
            public:
                ShadowMapper(Engine* const e, const core::sync::EndCaller<core::sync::EndCallerIgnore>& c) noexcept
                    : Shader(e, c)
                {
                    e->get_function_loader()->load([this] {
                        const std::string vertex_shader_code = GX_GLES2_SHADER_SRC_DEFAULT_VERTEX_STARTING;
                        // Load the shader code and perform other initialization
                        std::cout << "ShadowMapper shader code loaded" << std::endl;
                    });
                }
            };
        }
    }
}

int main() {
    Engine engine;
    core::sync::EndCaller<core::sync::EndCallerIgnore> caller;
    gearoenix::gles2::shader::ShadowMapper shadowMapper(&engine, caller);
    // Use the shadowMapper for shadow mapping
    return 0;
}
