#include <vtkSmartPointer.h>
#include <vtkAssignAttribute.h>
#include <vtkAlgorithmOutput.h>
#include <vtkDataSetAttributes.h>
#include <vtkDataObject.h>

class AttributeAssigner {
public:
    void assignAttribute(vtkSmartPointer<vtkDataObject> validPart, const std::string& attributeName, vtkSmartPointer<vtkAlgorithmOutput> gFilter) {
        vtkSmartPointer<vtkAssignAttribute> assigner = vtkSmartPointer<vtkAssignAttribute>::New();

        if (validPart->GetPointData()->HasArray(attributeName.c_str())) {
            if (gFilter) {
                assigner->SetInputConnection(gFilter);
            } else {
                assigner->SetInputData(validPart);
            }
        } else {
            assigner->SetInputData(validPart);
        }

        // Perform additional operations with the assigner object if needed
        // ...
    }
};

int main() {
    // Example usage
    vtkSmartPointer<vtkDataObject> validPart = ...;  // Initialize validPart with appropriate data
    std::string attributeName = "m_datasetInfo.first";  // Replace with the actual attribute name
    vtkSmartPointer<vtkAlgorithmOutput> gFilter = ...;  // Initialize gFilter with appropriate filter output

    AttributeAssigner assigner;
    assigner.assignAttribute(validPart, attributeName, gFilter);

    // Perform additional operations with the assigner object if needed
    // ...

    return 0;
}
