#include "bounding_box_node.hpp"

namespace sge {
    SDL_Point BoundingBoxNode::get_box() const {
        // Assuming the top-left corner of the bounding box is at (0, 0)
        return size;
    }
}
