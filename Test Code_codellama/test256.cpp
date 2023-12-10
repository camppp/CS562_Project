void processFormula(const vector<string>& v_formula, double& val) {
    if (v_formula[0] == "-") {
        v_formula.erase(v_formula.begin());
        val = -val;
    }
    find_block_tail(v_formula);
}
