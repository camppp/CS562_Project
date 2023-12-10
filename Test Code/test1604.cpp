#include <iostream>
#include <vector>

class OrthographicCamera {
private:
    float near_plane;
    float far_plane;

public:
    OrthographicCamera(float near, float far) : near_plane(near), far_plane(far) {}

    float get_near_plane() const {
        return near_plane;
    }

    float get_far_plane() const {
        return far_plane;
    }

    void set_far_plane(float new_far_plane) {
        far_plane = new_far_plane;
    }

    // Other member functions for camera operations

    // Function to calculate and return the projection matrix for the orthographic camera
    std::vector<std::vector<float>> get_projection_matrix() const {
        float left = -1.0f;
        float right = 1.0f;
        float bottom = -1.0f;
        float top = 1.0f;

        std::vector<std::vector<float>> projection_matrix(4, std::vector<float>(4, 0.0f));
        projection_matrix[0][0] = 2.0f / (right - left);
        projection_matrix[1][1] = 2.0f / (top - bottom);
        projection_matrix[2][2] = -2.0f / (far_plane - near_plane);
        projection_matrix[3][0] = -(right + left) / (right - left);
        projection_matrix[3][1] = -(top + bottom) / (top - bottom);
        projection_matrix[3][2] = -(far_plane + near_plane) / (far_plane - near_plane);
        projection_matrix[3][3] = 1.0f;

        return projection_matrix;
    }
};

int main() {
    OrthographicCamera camera(1.0f, 100.0f);
    std::cout << "Near Plane: " << camera.get_near_plane() << std::endl;
    std::cout << "Far Plane: " << camera.get_far_plane() << std::endl;

    camera.set_far_plane(150.0f);
    std::cout << "Updated Far Plane: " << camera.get_far_plane() << std::endl;

    std::vector<std::vector<float>> projectionMatrix = camera.get_projection_matrix();
    std::cout << "Projection Matrix:" << std::endl;
    for (const auto &row : projectionMatrix) {
        for (const auto &element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
