#include <Eigen/Core>
#include "boss/id_context.h"

namespace fps_mapper {
  using namespace std;

  class MapNode {
  public:
    MapNode(const Eigen::Isometry3f& transform, int id, boss::IdContext* context) {
      // Base class constructor implementation
      // Initialize MapNode with the provided parameters
    }
  };

  class LocalMap : public MapNode {
  public:
    LocalMap(const Eigen::Isometry3f& transform, int id, boss::IdContext* context) : MapNode(transform, id, context) {
      // Constructor delegation to the base class MapNode
    }
  };
}
