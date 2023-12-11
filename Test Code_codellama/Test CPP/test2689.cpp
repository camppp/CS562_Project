value_t copy_value(context_t &context, const value_t &value) {
    // Create a new value object within the given context
    value_t new_value = value_t(context);

    // Copy the contents of the original value object into the new value object
    new_value = value;

    // Return the new value object
    return new_value;
}
