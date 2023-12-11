#include <iostream>
#include <vector>

template <typename DataType>
class Octree {
public:
  // Constructor to create an Octree with a specified data type and depth.
  Octree(DataType dtype, int depth) {
    this->dtype = dtype;
    this->depth = depth;
    this->data = std::vector<DataType>(8, 0);
  }

  // Method to insert a value into the Octree at a specified position.
  void insertValue(int x, int y, int z, int value) {
    // Check if the position is within the bounds of the Octree.
    if (x < 0 || x >= this->depth || y < 0 || y >= this->depth || z < 0 || z >= this->depth) {
      std::cout << "Error: Position is out of bounds." << std::endl;
      return;
    }

    // Calculate the index of the child node that the value should be inserted into.
    int childIndex = (x / this->depth) + (y / this->depth) * 2 + (z / this->depth) * 4;

    // Insert the value into the child node.
    this->data[childIndex] = value;
  }

  // Method to retrieve the value at a specified position in the Octree.
  int retrieveValue(int x, int y, int z) {
    // Check if the position is within the bounds of the Octree.
    if (x < 0 || x >= this->depth || y < 0 || y >= this->depth || z < 0 || z >= this->depth) {
      std::cout << "Error: Position is out of bounds." << std::endl;
      return 0;
    }

    // Calculate the index of the child node that the value should be retrieved from.
    int childIndex = (x / this->depth) + (y / this->depth) * 2 + (z / this->depth) * 4;

    // Retrieve the value from the child node.
    return this->data[childIndex];
  }

  // Method to remove the value at a specified position in the Octree.
  void removeValue(int x, int y, int z) {
    // Check if the position is within the bounds of the Octree.
    if (x < 0 || x >= this->depth || y < 0 || y >= this->depth || z < 0 || z >= this->depth) {
      std::cout << "Error: Position is out of bounds." << std::endl;
      return;
    }

    // Calculate the index of the child node that the value should be removed from.
    int childIndex = (x / this->depth) + (y / this->depth) * 2 + (z / this->depth) * 4;

    // Remove the value from the child node.
    this->data[childIndex] = 0;
  }

private:
  // The data type of the Octree.
  DataType dtype;

  // The depth of the Octree.
  int depth;

  // The data stored in the Octree.
  std::vector<DataType> data;
};
