#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <duktape.h>

class JavaScriptFunctionExecutor {
public:
    JavaScriptFunctionExecutor(const std::string& scriptPath) : scriptPath_(scriptPath) {
        ctx_ = duk_create_heap_default();
    }

    ~JavaScriptFunctionExecutor() {
        if (ctx_) {
            duk_destroy_heap(ctx_);
        }
    }

    bool loadScript(const std::string& scriptPath) {
        std::ifstream file(scriptPath);
        if (file) {
            std::string scriptContent((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
            duk_eval_string(ctx_, scriptContent.c_str());
            return true;
        } else {
            return false;
        }
    }

    bool executeFunction(const std::string& functionName, const std::vector<std::string>& arguments, std::string& returnValue) {
        duk_push_global_object(ctx_);
        duk_get_prop_string(ctx_, -1, functionName.c_str());

        if (duk_is_function(ctx_, -1)) {
            for (const auto& arg : arguments) {
                duk_push_string(ctx_, arg.c_str());
            }

            if (duk_pcall(ctx_, arguments.size()) == DUK_EXEC_SUCCESS) {
                returnValue = duk_to_string(ctx_, -1);
                duk_pop(ctx_);
                return true;
            } else {
                duk_pop(ctx_);
                return false;
            }
        } else {
            duk_pop_2(ctx_);
            return false;
        }
    }

private:
    std::string scriptPath_;
    duk_context* ctx_;
};
