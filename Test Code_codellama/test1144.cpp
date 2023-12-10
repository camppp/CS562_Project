class CompilerInfoState {
public:
    // Constructor
    CompilerInfoState() : cxx_compiler_info_(nullptr), dart_analyzer_compiler_info_(nullptr), fake_compiler_info_(nullptr) {}

    // Destructor
    ~CompilerInfoState() {
        delete cxx_compiler_info_;
        delete dart_analyzer_compiler_info_;
        delete fake_compiler_info_;
    }

    // Update C++ compiler information
    void UpdateCxxCompilerInfo(CxxCompilerInfo* cxx_compiler_info) {
        delete cxx_compiler_info_;
        cxx_compiler_info_ = cxx_compiler_info;
    }

    // Update Dart analyzer compiler information
    void UpdateDartAnalyzerCompilerInfo(DartAnalyzerCompilerInfo* dart_analyzer_compiler_info) {
        delete dart_analyzer_compiler_info_;
        dart_analyzer_compiler_info_ = dart_analyzer_compiler_info;
    }

    // Update fake compiler information
    void UpdateFakeCompilerInfo(FakeCompilerInfo* fake_compiler_info) {
        delete fake_compiler_info_;
        fake_compiler_info_ = fake_compiler_info;
    }

    // Get compiler information
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
