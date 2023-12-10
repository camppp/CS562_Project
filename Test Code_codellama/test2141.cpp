#include <iostream>
#include <cassert>

enum AuditionType { NONE, SELF, COMMUNITY };

void audition(int step, int C, int notes[], int inputs[]) {
    int off = step > 0 ? C * step : 0;
    switch (Config::audition()) {
        case NONE:
            // No action
            break;
        case SELF:
            // Copy range of notes from notes array to inputs array
            for (int i = 0; i < C; i++) {
                inputs[i] = notes[i + off];
            }
            break;
        case COMMUNITY:
            // Assertion to indicate that community auditions are not supported
            assert(false);
            break;
    }
}
