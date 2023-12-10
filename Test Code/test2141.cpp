#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

enum class Audition { NONE, SELF, COMMUNITY };

class Config {
public:
    static Audition audition() {
        // Implement the logic to return the type of audition (NONE, SELF, or COMMUNITY)
        // Example: return Audition::SELF;
    }
};

void handleAudition(const std::vector<int>& notes, std::vector<int>& inputs, int step, int C) {
    if (step > 0) {
        uint off = (step - 1) * C;

        switch (Config::audition()) {
            case Audition::NONE:
                // No action needed for NONE audition type
                break;
            case Audition::SELF:
                // Copy a range of notes from the 'notes' array to the 'inputs' array
                std::copy(notes.begin() + off, notes.begin() + off + C, inputs.begin());
                break;
            case Audition::COMMUNITY:
                // Trigger an assertion to indicate that community auditions are not supported
                assert(false);
                break;
        }
    }
}

int main() {
    // Example usage
    std::vector<int> notes = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> inputs(3);  // Assuming the size of 'inputs' array is known
    int step = 2;
    int C = 3;

    handleAudition(notes, inputs, step, C);

    // Print the contents of the 'inputs' array after handling the audition
    for (int note : inputs) {
        std::cout << note << " ";
    }
    std::cout << std::endl;

    return 0;
}
