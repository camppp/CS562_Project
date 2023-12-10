#include <iostream>

class dynamic_global_property_object {
public:
    // Constructor
    dynamic_global_property_object() {}

    // Member functions
    void set_global_state(int state) {
        global_state = state;
    }

    int get_global_state() {
        return global_state;
    }

    void increment_global_state() {
        global_state++;
    }

    void decrement_global_state() {
        global_state--;
    }

private:
    // Global state
    int global_state;
};
