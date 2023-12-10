#include <iostream>
#include <vector>
#include <cassert>

// Define the PathLocation struct
struct PathLocation {
  double latitude;
  double longitude;
  std::vector<std::pair<double, double>> edges;
  std::vector<std::pair<double, double>> filtered_edges;
};

// Define the PBF representation of the PathLocation struct
struct PBFPathLocation {
  double latitude;
  double longitude;
  std::vector<std::pair<double, double>> edges;
  std::vector<std::pair<double, double>> filtered_edges;
};

// Implement the PathLocation::toPBF function
PBFPathLocation PathLocation::toPBF() const {
  PBFPathLocation pbf_location;
  pbf_location.latitude = latitude;
  pbf_location.longitude = longitude;
  pbf_location.edges = edges;
  pbf_location.filtered_edges = filtered_edges;
  return pbf_location;
}

int main() {
  // Create a PathLocation object
  PathLocation location;
  location.latitude = 37.7749;
  location.longitude = -122.4194;
  location.edges = {{37.7749, -122.4194}, {37.7749, -122.4194}};
  location.filtered_edges = {{37.7749, -122.4194}, {37.7749, -122.4194}};

  // Convert the PathLocation object to a PBF representation
  PBFPathLocation pbf_location = location.toPBF();

  // Validate the PBF representation
  assert(pbf_location.latitude == location.latitude);
  assert(pbf_location.longitude == location.longitude);
  assert(pbf_location.edges.size() == location.edges.size());
  assert(pbf_location.filtered_edges.size() == location.filtered_edges.size());
  for (int i = 0; i < pbf_location.edges.size(); i++) {
    assert(pbf_location.edges[i].first == location.edges[i].first);
    assert(pbf_location.edges[i].second == location.edges[i].second);
  }
  for (int i = 0; i < pbf_location.filtered_edges.size(); i++) {
    assert(pbf_location.filtered_edges[i].first == location.filtered_edges[i].first);
    assert(pbf_location.filtered_edges[i].second == location.filtered_edges[i].second);
  }

  return 0;
}
