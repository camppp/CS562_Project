#include <stddef.h>

struct State {
    int arg_count;
    int arg_pos;
    int stack_diff;
};

int calculateOffset(struct State *state) {
    int offset = (state->arg_count - state->arg_pos + state->stack_diff + 1) * sizeof(void *);
    if (offset >= 0x80) {
        return 7;
    } else {
        return 4;
    }
}
