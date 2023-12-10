#include <vtkGeoProjection.h>
#include <vtkGeoProjectionFactory.h>
#include <vtkSmartPointer.h>
#include <vtkObjectFactory.h>

void DisplayGeoProjections()
{
  // Create a new instance of the VTK GeoProjectionFactory
  vtkSmartPointer<vtkGeoProjectionFactory> factory = vtkSmartPointer<vtkGeoProjectionFactory>::New();

  // Get the list of supported projections
  std::vector<std::string> projections = factory->GetProjections();

  // Loop through each projection and display its details
  for (const std::string& projection : projections)
  {
    // Create a new instance of the projection
    vtkSmartPointer<vtkGeoProjection> geoProjection = factory->CreateProjection(projection);

    // Display the projection's name and description
    std::cout << "Projection: " << geoProjection->GetName() << std::endl;
    std::cout << "Description: " << geoProjection->GetDescription() << std::endl;

    // Display any other relevant details
    std::cout << "Center: " << geoProjection->GetCenter() << std::endl;
    std::cout << "Scale: " << geoProjection->GetScale() << std::endl;

    // Clean up the projection instance
    geoProjection->Delete();
  }
}
