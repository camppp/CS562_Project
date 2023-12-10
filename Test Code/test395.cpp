#include <iostream>
#include <string>

int countConditionalCompilationDirectives(const std::string& codeSnippet) {
    int count = 0;
    size_t pos = 0;
    while ((pos = codeSnippet.find("#ifdef", pos)) != std::string::npos) {
        count++;
        pos += 6; // Move past the "#ifdef" directive
    }
    return count;
}

int main() {
    std::string codeSnippet = "int main(){\n#ifdef LOCAL\n    freopen(\"/Users/didi/ACM/in.txt\", \"r\", stdin);\n#endif\n    // Other code\n#ifdef DEBUG\n    cout << \"Debug mode\" << endl;\n#endif\n}";
    int directiveCount = countConditionalCompilationDirectives(codeSnippet);
    std::cout << directiveCount << std::endl;
    return 0;
}
