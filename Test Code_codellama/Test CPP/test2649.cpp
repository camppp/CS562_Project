bool compare(const Meta& a_Meta1, const Meta& a_Meta2) {
    // Handle special cases
    if (a_Meta1.is_special() || a_Meta2.is_special()) {
        return false;
    }

    // Perform raw comparison
    return a_Meta1.get_value() < a_Meta2.get_value();
}
