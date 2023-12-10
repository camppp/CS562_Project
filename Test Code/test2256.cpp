bool validateInputParameters(const vector<double>& x, int np, const string& method) {
    // Check 1: Vector x should not be empty
    if (x.empty()) {
        return false;
    }

    // Check 2: Integer np should be greater than 0
    if (np <= 0) {
        return false;
    }

    // Check 3: String method should not be empty
    if (method.empty()) {
        return false;
    }

    // If all checks pass, return true
    return true;
}
