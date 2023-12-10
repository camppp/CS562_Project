#include <iostream>
#include <vtkGeoProjection.h>

void DisplayGeoProjections() {
  int np = vtkGeoProjection::GetNumberOfProjections();
  std::cout << "Supported projections:\n";
  for (int i = 0; i < np; ++i) {
    vtkGeoProjection* projection = vtkGeoProjection::New();
    projection->SetProjection(i);
    std::cout << "Projection Name: " << projection->GetName() << std::endl;
    std::cout << "Projection Description: " << projection->GetDescription() << std::endl;
    // You can add more details here based on the VTK library's projection properties
    projection->Delete();
  }
}
