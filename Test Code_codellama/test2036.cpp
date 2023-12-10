#include <SDL.h>

namespace sge {
    class BoundingBoxNode {
        public:
            SDL_Point get_box() const {
                return size;
            }

        private:
            SDL_Point size;
    };
}
