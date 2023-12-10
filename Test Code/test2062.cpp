#include <vtkMatrix4x4.h>
#include <vector>

class SurfaceRegistration {
private:
    std::vector<vtkMatrix4x4*> m_MatrixList;
    vtkMatrix4x4* m_ResultMatrix;

public:
    // Method to add a matrix landmark to the m_MatrixList
    void AddMatrixLandmark(vtkMatrix4x4* landmark) {
        m_MatrixList.push_back(landmark);
    }

    // Method to perform the surface registration using the matrix list and landmarks
    void PerformRegistration() {
        // Perform surface registration using the m_MatrixList and landmarks
        // Update m_ResultMatrix with the result of the registration process
        // Example: m_ResultMatrix = performSurfaceRegistration(m_MatrixList);
    }

    // Method to return the result of the surface registration as a vtkMatrix4x4 pointer
    vtkMatrix4x4* GetResult() {
        return m_ResultMatrix;
    }
};
