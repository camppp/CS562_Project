#include "cxx/cxx_compiler_info.h"
#include "dart_analyzer/dart_analyzer_compiler_info.h"
#include "fake/fake_compiler_info.h"

class CompilerInfoState {
public:
    void UpdateCxxCompilerInfo(CxxCompilerInfo* cxx_compiler_info) {
        cxx_compiler_info_ = cxx_compiler_info;
    }

    void UpdateDartAnalyzerCompilerInfo(DartAnalyzerCompilerInfo* dart_analyzer_compiler_info) {
        dart_analyzer_compiler_info_ = dart_analyzer_compiler_info;
    }

    void UpdateFakeCompilerInfo(FakeCompilerInfo* fake_compiler_info) {
        fake_compiler_info_ = fake_compiler_info;
    }

    CompilerInfo* GetCompilerInfo(const std::string& compiler_type) {
        if (compiler_type == "cxx") {
            return cxx_compiler_info_;
        } else if (compiler_type == "dart_analyzer") {
            return dart_analyzer_compiler_info_;
        } else if (compiler_type == "fake") {
            return fake_compiler_info_;
        } else {
            return nullptr;
        }
    }

private:
    CxxCompilerInfo* cxx_compiler_info_;
    DartAnalyzerCompilerInfo* dart_analyzer_compiler_info_;
    FakeCompilerInfo* fake_compiler_info_;
};
