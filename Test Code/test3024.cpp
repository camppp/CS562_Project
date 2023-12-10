#include <cstddef>

namespace query {
  struct gqlite_node {
    char* id;
    // other members
  };

  struct gqlite_result {
    gqlite_node* nodes;
    size_t count;
    // other members
  };

  class GMemory {
  public:
    static void deallocate(char* ptr) {
      // Implementation of deallocate function
    }
  };

  void release_vertexes(gqlite_result& results) {
    if (results.count) {
      for (size_t idx = 0; idx < results.count; ++idx) {
        GMemory::deallocate(results.nodes[idx].id);
      }
      delete[] results.nodes;
    }
  }
} // namespace query
