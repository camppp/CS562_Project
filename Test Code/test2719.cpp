#include <iostream>

// Assume MeshId is a typedef or class representing the identifier of a 3D mesh
typedef int MeshId;

class Instance {
private:
    bool is_static;
    MeshId mesh_id;

public:
    Instance(MeshId id, bool isStatic) : mesh_id(id), is_static(isStatic) {}

    bool isStatic() const {
        return is_static;
    }

    void setStatic(bool b) {
        is_static = b;
    }

    MeshId getMeshId() const {
        return mesh_id;
    }
};

int main() {
    // Example usage
    MeshId mesh1 = 1;
    Instance instance1(mesh1, true);
    std::cout << "Instance 1 is static: " << instance1.isStatic() << std::endl;

    instance1.setStatic(false);
    std::cout << "Instance 1 is static: " << instance1.isStatic() << std::endl;

    MeshId mesh2 = 2;
    Instance instance2(mesh2, false);
    std::cout << "Instance 2 mesh ID: " << instance2.getMeshId() << std::endl;

    return 0;
}
