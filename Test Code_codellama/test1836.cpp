void Rotatable::get_rotatables(const vec<lbool>& model, VarSet& rotatables) {
    // Initialize the rotatables set to all variables
    rotatables = VarSet(input_cnf.nVars());

    // Iterate over the variables in the CNF formula
    for (int i = 0; i < input_cnf.nVars(); i++) {
        // Check if the variable is not a constant
        if (input_cnf.isConstant(i)) {
            // If the variable is a constant, remove it from the rotatables set
            rotatables.remove(i);
        } else {
            // If the variable is not a constant, check if it is rotatable
            bool is_rotatable = true;
            for (int j = 0; j < input_cnf.nClauses(); j++) {
                // Check if the variable appears in the current clause
                if (input_cnf.getClause(j).contains(i)) {
                    // If the variable appears in the current clause, check if flipping its truth value affects the satisfiability of the clause
                    if (input_cnf.getClause(j).isSatisfiable(model, i)) {
                        // If flipping the variable's truth value does not affect the satisfiability of the clause, the variable is not rotatable
                        is_rotatable = false;
                        break;
                    }
                }
            }
            // If the variable is rotatable, add it to the rotatables set
            if (is_rotatable) {
                rotatables.add(i);
            }
        }
    }
}
