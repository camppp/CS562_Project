#include <string>
#include <vector>

// Define the placement strategy enum class
enum class PlacementStrategy {
  Random,
  Spread,
  Pack,
  Sticky
};

// Define the placement group table data struct
struct PlacementGroupTableData {
  std::string name;
  PlacementStrategy strategy;
  std::vector<std::string> bundles;
};

// Define the GcsPlacementGroup class
class GcsPlacementGroup {
 public:
  // Constructor
  GcsPlacementGroup(const std::string &name,
                    const PlacementStrategy &strategy,
                    const std::vector<std::string> &bundles)
      : name_(name), strategy_(strategy), bundles_(bundles) {}

  // Get the placement strategy associated with the placement group
  PlacementStrategy GetStrategy() const { return strategy_; }

  // Get the placement group table data
  const PlacementGroupTableData &GetPlacementGroupTableData() const {
    return data_;
  }

 private:
  // The placement group name
  std::string name_;

  // The placement strategy associated with the placement group
  PlacementStrategy strategy_;

  // The placement group table data
  PlacementGroupTableData data_;

  // The bundles associated with the placement group
  std::vector<std::string> bundles_;
};

// Implement the GetStrategy() member function
PlacementStrategy GcsPlacementGroup::GetStrategy() const {
  return strategy_;
}

// Implement the GetPlacementGroupTableData() member function
const PlacementGroupTableData &GcsPlacementGroup::GetPlacementGroupTableData() const {
  return data_;
}
