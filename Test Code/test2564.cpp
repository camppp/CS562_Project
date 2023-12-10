#include <iostream>

class InnerCombineShader {
public:
    InnerCombineShader() {}
    InnerCombineShader create() {
        return InnerCombineShader();
    }
};

int main() {
    InnerCombineShader shader = InnerCombineShader().create();
    std::cout << "Created inner combine shader" << std::endl;
    return 0;
}
