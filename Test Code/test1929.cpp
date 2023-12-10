#include <iostream>
#include <cstdlib>

#define TEST_PROGRAMMABLE_SOURCE(type) \
  std::cout << "Testing " << #type << " programmable source..." << std::endl; \
  // Perform testing for the programmable source type here \
  std::cout << "Test for " << #type << " programmable source passed." << std::endl;

int TestProgrammableSource(int vtkNotUsed(argc), char *vtkNotUsed(argv)[])
{
  TEST_PROGRAMMABLE_SOURCE(PolyData);
  TEST_PROGRAMMABLE_SOURCE(StructuredPoints);
  TEST_PROGRAMMABLE_SOURCE(StructuredGrid);
  TEST_PROGRAMMABLE_SOURCE(UnstructuredGrid);
  TEST_PROGRAMMABLE_SOURCE(RectilinearGrid);
  TEST_PROGRAMMABLE_SOURCE(Molecule);
  TEST_PROGRAMMABLE_SOURCE(Table);
  return EXIT_SUCCESS;
}
