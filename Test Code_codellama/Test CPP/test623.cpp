#include <vtkAssignAttribute.h>
#include <vtkPolyData.h>
#include <vtkSmartPointer.h>

class AssignAttribute {
public:
  AssignAttribute(vtkSmartPointer<vtkPolyData> polyData, vtkSmartPointer<vtkFilter> gFilter) {
    this->polyData = polyData;
    this->gFilter = gFilter;
  }

  void assignAttribute(const char* arrayName) {
    // Check if the array exists in the geometry data
    if (polyData->GetPointData()->HasArray(arrayName)) {
      // Set the input connection of the vtkAssignAttribute object to the output port of the given filter
      vtkSmartPointer<vtkAssignAttribute> assignAttribute = vtkSmartPointer<vtkAssignAttribute>::New();
      assignAttribute->SetInputConnection(gFilter->GetOutputPort());
      assignAttribute->SetAttributeType(vtkAssignAttribute::POINT_DATA);
      assignAttribute->SetAttributeName(arrayName);
      assignAttribute->Update();
    } else {
      // Set the input connection of the vtkAssignAttribute object to the output port of the valid part's geometry data
      vtkSmartPointer<vtkAssignAttribute> assignAttribute = vtkSmartPointer<vtkAssignAttribute>::New();
      assignAttribute->SetInputConnection(polyData->GetOutputPort());
      assignAttribute->SetAttributeType(vtkAssignAttribute::POINT_DATA);
      assignAttribute->SetAttributeName(arrayName);
      assignAttribute->Update();
    }
  }

private:
  vtkSmartPointer<vtkPolyData> polyData;
  vtkSmartPointer<vtkFilter> gFilter;
};
