void unpack(begin_lhs, end_lhs, get_rhs) {
    // Create a sequence block to store the new assignments
    SequenceBlock<Assignment> assignments;

    // Iterate through the lhs expressions and create new assignments for each pair
    for (auto it = begin_lhs; it != end_lhs; ++it) {
        // Get the current lhs and rhs expressions
        auto lhs = *it;
        auto rhs = get_rhs(lhs);

        // Create a new non-blocking assignment for the current lhs/rhs pair
        Assignment assignment(lhs, rhs);

        // Add the new assignment to the sequence block
        assignments.push_back(assignment);
    }

    // Clear the rhs collection
    get_rhs.clear();

    // Return the sequence block containing the new assignments
    return assignments;
}
