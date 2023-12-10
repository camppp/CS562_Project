void Rotatable::get_rotatables(const vec<lbool>& model, VarSet& rotatables) {
  for (Var index = 1; index < model.size(); ++index) {
    // Check if flipping the variable affects the satisfiability
    CNF modified_cnf = input_cnf;  // Create a copy of the original CNF
    modified_cnf[index].clear();    // Remove the variable from the clauses
    modified_cnf[index ^ 1].clear();  // Remove the negation of the variable from the clauses

    Minisat::Solver solver;
    for (auto& clause : modified_cnf) {
      Minisat::vec<Minisat::Lit> clause_literals;
      for (auto lit : clause) {
        clause_literals.push(lit_Undef);
        if (lit != lit_Undef) {
          clause_literals.last() = Minisat::mkLit(abs(lit) - 1, lit < 0);
        }
      }
      solver.addClause(clause_literals);
    }

    solver.setConfBudget(10000);  // Set a conflict budget to limit solving time
    solver.solve();  // Attempt to solve the modified CNF

    if (solver.okay()) {
      // The CNF is still satisfiable after removing the variable, so it's rotatable
      rotatables.add(index);
    }
  }
}
